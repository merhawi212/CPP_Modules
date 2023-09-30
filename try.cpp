#include "Account.hpp"

int main(){
	std::time_t now = std::time(0);
	std::tm* timestamp = std::localtime(&now);

	std::cout<<timestamp->tm_year;
}