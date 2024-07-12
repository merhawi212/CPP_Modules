#include "PmergeMe.hpp"

double	get_timestamp(void){
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (now.tv_sec * 1e6 + now.tv_usec); //Microsecond
}

bool	is_only(std::string str, std::string chars){
	for (size_t i = 0; i < str.length(); i++)
	{
		if (chars.find(str[i]) == std::string::npos)
			return false; // Not from the Chars
	}
	return true; //From Chars
}


std::string formatTime(double elapsed_us) {
    double time = elapsed_us;
    std::string unit = "us";
    
    if (time >= 1e6) {
        time /= 1e6;
        unit = "s";
    } else if (time >= 1e3) {
        time /= 1e3;
        unit = "ms";
    }
    
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(6) << time << " " << unit;
    return oss.str();
}

int parseInput(int argc,  char ** &av, std::vector<int> &vec)
{
	std::string num_str;
	long num;
	for (int i = 1; i < argc; i++)
	{
		num_str = av[i];
		if (num_str.empty() || !is_only(num_str, "0123456789"))
		{
			std::cerr << "Error" << std::endl;
			return -1; // Exit
		}
		
		std::istringstream ss(num_str);
		ss >> num;

		if (num > INT_MAX)
		{
			std::cerr << "Error: Number out of bound." << std::endl;
			return -1;
		}
		// if (std::find(vec.begin(), vec.end(), num) == vec.end())
		vec.push_back(num); //Push number to vector
	
	}
	return 0;
}