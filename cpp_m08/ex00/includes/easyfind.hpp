#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

class NoMatchException: public std::exception
{
	virtual const char *what() const throw(){
		return ("Container has no match!");
	}
};

template <typename T>
typename T::iterator easyFind(T &arr, int const match)
{
	typename T::iterator ret = std::find(arr.begin(), arr.end(), match);
	if (ret == arr.end())
		throw NoMatchException();
	return (ret);
}

#endif
