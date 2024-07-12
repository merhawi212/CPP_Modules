#include "BitcoinExchange.hpp"

bool isValidNumber( std::string& str, double& value) {
    char* endptr;
    value = std::strtod(str.c_str(), &endptr);
    return (*endptr == '\0') && (endptr != str.c_str());
}

bool isHeaderValid(const std::string& col1, const std::string& col2){
	if (col1 == "date" && col2 == "value") {
		return true;
	} 
	else {
		std::cerr << "Error: invalid header is provided." << std::endl;
		return false;// Stop processing the file. There must be a header..
	}
}

bool isInputValueValid(std::string& str, double& value){
	if (!isValidNumber(str, value)) {
		std::cerr << "Error:invalid number found." << std::endl;
		return false; // Skip invalid numbers
	}
	if (value <= 0) {
		std::cerr << "Error: not a positive number." << std::endl;
		return false; // Skip non-positive numbers
	}
	if (value > 1000) {
		std::cerr << "Error: too large a number." << std::endl;
		return false; // Skip excessively large numbers
	}
	return true; // It's valid input, process it.
}

// Function to find the closest lower date in the map
std::map<time_t, double>::iterator findClosestLowerDate(std::map<time_t, double>& exchangeRate_db, time_t date) {
    std::map<time_t, double>::iterator it = exchangeRate_db.lower_bound(date); //lower_bound will return >= date, not less than
	//it == exchangeRate_db.end() eithere no record in the db or its < the input date
    if (it == exchangeRate_db.end() || it->first != date) { 
		//it == exchangeRate_db.begin(), there is no record less than the input date.
        if (it == exchangeRate_db.begin()) {
            return exchangeRate_db.end(); // No valid lower date found
        }
        --it;
    }
    return it;
}


void calculateValue(std::map<time_t, double>::iterator& rateIt, double value, const std::string& date_str){
  	double rate = rateIt->second;
	double calculatedValue = rate * value;
    PRINT_STATMEMNT(date_str << " => " << value << " = " << calculatedValue);
}

// Function to process each line of the input file
bool processLine(const std::string& line, std::map<time_t, double>& exchangeRate_db, int& counter) {
    std::istringstream iss(line);
    std::string date_str;
    std::string value_str;

    if (std::getline(iss, date_str, '|') && iss >> value_str) {
        date_str = trim(date_str);
        value_str = trim(value_str);
        toLowercase(date_str);
        toLowercase(value_str);

		if (counter == 0){
			if (!isHeaderValid(date_str, value_str)){
				return false; //Invalid header, stop execution.
			}
			return true; //Valid Header
		}
		
		time_t date  = toEpoch(date_str);
		if (date == time_t(0)) {
			std::cerr << "Error: invalid date found." << std::endl;
			return true; // Skip invalid dates
		}
		double value;
		if (!isInputValueValid(value_str, value)) {
			return true; // Skip this line input value is not valid
		}
		// Find the rate for the exact date or the closest lower date
		std::map<time_t, double>::iterator rateIt = exchangeRate_db.find(date);
		if (rateIt == exchangeRate_db.end()) {
			rateIt = findClosestLowerDate(exchangeRate_db, date);
			if (rateIt == exchangeRate_db.end()) {
				std::cerr << "Error: No valid rate found for date => " << date_str << std::endl;
				return true; // Skip lines with no valid rate
			}
		}
		calculateValue(rateIt, value, date_str);

    } else {
        std::cerr << "Error: bad input => " << line << std::endl;
        return true; // Skip malformed lines
    }
    return true; // Line processed successfully
}

// Function to read the input file and process each line
int readInputFile(std::map<time_t, double> exchangeRate_db, const std::string& filename) {
	// Convert string filename to const char*
    const char* filename_cstr = filename.c_str();

    std::ifstream inputFile(filename_cstr);
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open file: " << filename_cstr << std::endl;
        return -1;
    }

    std::string line;
	int counter = 0;
    while (std::getline(inputFile, line)) {
        if (line.empty() || isWhitespace(line)) {
            continue; // Skip empty or whitespace-only lines
        }
	
        if (!processLine(line, exchangeRate_db, counter)) {
            inputFile.close();
            return -1; // Return on any processing error
        }
		counter++;
    }
    inputFile.close();
	if (counter == 0){
		std::cerr << "Error: header not found." << std::endl;
		return -1;// Stop processing the file. There must be a header..
	}
    return 0; // Successfully processed all lines
}

int btcExchange(const std::string filename)
{
	std::map<time_t, double> exchangeRate_db;
	if (readDB(exchangeRate_db) == -1)
		return -1;
	if (readInputFile(exchangeRate_db, filename) == -1)
		return -1;
	return 0;
}


/*

void display(std::map<time_t, double> &exchangeRate_db)
{
	std::map<time_t, double>::const_iterator iter = exchangeRate_db.begin();
	int c = 0;
	while (iter != exchangeRate_db.end())
	{
		PRINT_STATMEMNT("Date: " << dateToString(iter->first) << ", Value: " << iter->second << "\n");
		++iter;
		if (c == 3)
			break;
		c++;
	}
}

std::string dateToString(time_t time)
{
	std::tm *tm = std::localtime(&time);
	if (!tm)
	{
		return ""; // Handle error
	}
	std::ostringstream oss;
	oss << std::put_time(tm, "%Y-%m-%d");
	return oss.str();
}
*/

