#include "easyfind.hpp"
#include <vector>
#include <iostream>
#include <list>
#include <set>

int main()
{
	std::vector<int>	vec;
	std::list<int>		lst;
	std::set<int>		st;

	for (size_t i = 0; i < 15; i++)
	{
		vec.push_back(i);
		lst.push_front(i);
		st.insert(i);
	}

	std::cout << "---VECTOR---" << std::endl;
	try
	{
		std::vector<int>::iterator it;
		it = easyFind(vec, 14);
		std::cout << *it << std::endl;
		it = easyFind(vec, 15);
		std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "---LIST---" << std::endl;
	try
	{
		std::list<int>::iterator it;
		it = easyFind(lst, 11);
		std::cout << *it << std::endl;
		it = easyFind(lst, 15);
		std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "---SET---" << std::endl;
	try
	{
		st.insert(2);
		std::set<int>::iterator it;
		it = easyFind(st, 12);
		std::cout << *it << std::endl;
		it = easyFind(st, 15);
		std::cout << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
