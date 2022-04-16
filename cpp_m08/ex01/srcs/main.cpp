#include "Span.hpp"
#include <list>

int main() {
	Span sp = Span(10000);
	Span sp1 = Span(5);
	sp.addNumber(5);
	try
	{
		sp.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::list<int> i;
	for (unsigned int l = 0; l < 1000; l++)
		i.push_back(l + 1312314);
	try
	{
		/* code */
		sp.addNumber(i.begin(), i.end());
		sp1.addNumber(i.begin(), i.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << sp1.shortestSpan() << std::endl;
	std::cout << sp1.longestSpan() << std::endl;
	return 0;
}
