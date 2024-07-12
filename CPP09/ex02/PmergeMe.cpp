#include "PmergeMe.hpp"

// Function to print a vector or list
template<typename T>
void printContainer(const T& container) {
    for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}


int do_pmergeMe(const int argc,   char** argv){
	// First container is vector
	std::vector<int> vec;
	if (parseInput(argc, argv, vec)){
		return -1;
	}

	std::cout << "Before:\t";
	printContainer(vec);

	double start, end;
    start = get_timestamp();
    mergeInsertSort(vec, 0, vec.size() - 1); //mergeInsertSort for vector container 
    end = get_timestamp();

	std::cout << "After:\t";
	printContainer(vec);
	std::cout << "Time to process a range of "<< vec.size() << " elements with std::vector<int> :\t" << formatTime(end - start) << std::endl;

	// second container is list
	std::list<int> lst(vec.begin(), vec.end());
	std::list<int>::iterator first = lst.begin(), last = lst.end();
    --last; // Adjust end to point to the last element

	start = get_timestamp();
    mergeInsertSort(lst, first,last); //mergeInsertSort for list container 
	end = get_timestamp();


	std::cout << "Time to process a range of "<< lst.size() << " elements with std::list<int> :\t" << formatTime(end - start)  << std::endl;
	
	return 0;
}

