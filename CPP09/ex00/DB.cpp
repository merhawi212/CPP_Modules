#include "BitcoinExchange.hpp"

bool isDBHeaderValid(const std::string &line){
	std::istringstream iss(line);
	std::string date;
	std::string exchange_rate;

	if (std::getline(iss, date, ',') && iss >> exchange_rate){
		date = trim(date);
		toLowercase(date);

		exchange_rate = trim(exchange_rate);
		toLowercase(exchange_rate);

		if (date == "date" &&  exchange_rate =="exchange_rate")
			return true; // header is valid
	}
	return false; // header is not valid
}

int readDB(std::map<time_t, double> &exchangeRate_db)
{
	std::ifstream DBFile("data.csv");
	if (!DBFile.is_open())
	{
		std::cerr << "Error: Unable to open db" << std::endl;
		return -1;
	}

	std::string line;
	std::getline(DBFile, line);
	 
	if (!isDBHeaderValid(line))
	{
		std::cerr << "Error: Invalid db header: " << line << std::endl;
		DBFile.close(); // Close the db file.
		return -1;
	}
	while (std::getline(DBFile, line))
	{
		if (line.empty() || isWhitespace(line)) {
            // Empty line or contains only whitespace characters
            continue;
        }
	
		std::istringstream iss(line);
		std::string date_str;
		double rate;
		time_t date; //epoch format
		if (std::getline(iss, date_str, ',') && iss >> rate)
		{
			/*
			 Most of the time, data in db is validated. So, no need to validate or maniplate it while reading.
			*/
			date = toEpoch(date_str); //date will be in epoch format
			exchangeRate_db.insert(std::pair<time_t, double>(date, rate));
			
		}
		else
		{
			std::cerr << "Error: bad data in db: " << line << std::endl;
			DBFile.close(); // Close the db file.
			return -1;
		}
	}
	if (exchangeRate_db.empty())
	{
		std::cerr << "Error: DB is empty. " << std::endl;
		DBFile.close(); // Close the db file.
		return -1;
	}
	DBFile.close(); // Close the db file when done.
	return 0;
}