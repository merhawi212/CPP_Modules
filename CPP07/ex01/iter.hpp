#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

#define PRINT_STATMENT(statment) std::cout << statment << std::endl;

template <class T>
void iter (T *a, size_t length, void(*fun)(T const&)){
	
	for (size_t i = 0; i < length; i++){
		fun(a[i]);
	}
}

template <class T>
void print(T n){
	PRINT_STATMENT(n << " ");
}

#endif