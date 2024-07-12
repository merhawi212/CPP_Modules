#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#define PRINT_STATMEMNT(statment)  std::cout << statment << std::endl;

# include <iostream>
# include <string>
# include <list>
# include <vector>
# include <algorithm>
# include <iterator>
# include <numeric> 

class NumberNotFoundException : public std::exception{
	public:
		virtual const char * what () const throw (){
			return ("NumberNotFoundException: Number not  found in the container!");
		}
};

template <typename T>
int easyfind(T container, int num) {
   typename T::const_iterator iter = std::find(container.begin(), container.end(), num);
   if (iter != container.end()){
            return *iter;
    }else{
         //throw NumberNotFoundException if the number does not exist in the container
         throw NumberNotFoundException();
    }

}
#endif 

