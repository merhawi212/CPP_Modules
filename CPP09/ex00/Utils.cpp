#include "BitcoinExchange.hpp"

time_t toEpoch(const std::string &dateStr)
{
	time_t time = time_t(0);
	if (dateStr.size() != 10)
		return time;
	struct tm tm = {};
	const char *c_str = dateStr.c_str();
	if (strptime(c_str, "%Y-%m-%d", &tm) != NULL)
	{
		 // Validate the parsed values (year, month, day) 1900 - 2025
        if (tm.tm_year < 0 || tm.tm_year > 125 || tm.tm_mon < 0 || tm.tm_mon > 11 || tm.tm_mday < 1 || tm.tm_mday > 31) {
            return time_t(0); // Invalid date, return time_t(0)
        }
		 // Check for leap year and validate February 29th
        int year = tm.tm_year + 1900;
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (tm.tm_mon == 1 && tm.tm_mday == 29 && !isLeapYear) {
            return time; // Invalid leap day for non-leap years, return 0
        }
		time = mktime(&tm);
	}
	return time;
}


// Function to check if a string consists only of whitespace characters
bool isWhitespace(const std::string& str) {
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!std::isspace(static_cast<unsigned char>(*it))) {
            return false;
        }
    }
    return true;
}

std::string ltrim(const std::string &str){

	 size_t start = str.find_first_not_of(" \t\r\n");
    return (start == std::string::npos) ? "" : str.substr(start);
}

std::string rtrim(const std::string &str){

	 size_t end = str.find_last_not_of(" \t\r\n");
    return (end == std::string::npos) ? "" : str.substr(0, end + 1);
}

std::string trim(const std::string &str){

    return rtrim(ltrim(str));
}

char toLower(unsigned char c){
	return std::tolower(c);
}

void toLowercase(std::string& str) {
    for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
        *it = std::tolower(static_cast<unsigned char>(*it));
    }
}

