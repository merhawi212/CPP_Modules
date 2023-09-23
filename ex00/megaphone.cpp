#include <iostream>
#include <cctype>
int main(int argc, char **argv)
{
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else {
		int i = 0;
		int j;
		while (++i < argc)
		{
			j = -1;
			while (argv[i][++j])
				std::cout << (char) std::toupper(argv[i][j]);
		}
		std::cout << std::endl;
	}
	return 0;

}