#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>

template <class T>
void swap (T &a, T &b){
	T c;
	c = a;
	a = b;
	b = c;

}

template <class T>
T min (T a, T b){

	return (a < b ? a : b);
}

template <class T>
T max (T a, T b){
	
	return (a > b ? a : b);
}



#endif