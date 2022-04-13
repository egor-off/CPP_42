#include "iter.hpp"
#include <iostream>

template<typename T>
void func(T const &el){
	std::cout << el + 1 << " ";
}

int main( void ) {

	int arr1[4] = {11, 22, 43, 55};
	float arr2[3] = {8.4, 58.4, 28.5};
	iter(arr1, 4, &func);
	std::cout << "\n";
	iter(arr2, 3, &func);
	std::cout << "\n";
	char s[] = "abcdef";
	iter(s, std::strlen(s), &func);
	std::cout << "\n";
	return (0);
}
