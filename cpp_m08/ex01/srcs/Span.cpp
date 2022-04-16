#include "Span.hpp"
#include <algorithm>

Span::Span()
{
}

Span::Span( unsigned int N )
{
	this->arrSize = N;
	this->arr.reserve(N);
}

Span::Span( const Span & src ): arr(src.arr)
{
	this->arrSize = src.arrSize;
}

Span::~Span()
{
}

Span &				Span::operator=( Span const & rhs )
{
	if ( this == &rhs ) return *this;
	for (unsigned int i = 0; i < rhs.arrSize; ++i)
	{
		if (this->arrSize == i)
			throw NotEnoughSpace();
		this->arr[i] = rhs.arr[i];
	}
	return *this;
}

void Span::addNumber(int const add) {
	if (this->arr.size() + 1 == this->arrSize)
		throw NotEnoughSpace();
	this->arr.push_back(add);
}

int Span::shortestSpan() const {
	if (this->arr.size() < 2)
		throw TooFewData();

	std::vector<int> tmp = this->arr;

	std::sort(tmp.begin(), tmp.end());
	if (this->arr.size() == 2)
		return (tmp[1] - tmp[0]);
	std::vector<int>::iterator it = tmp.begin();
	int rez = tmp[1] - tmp[0];
	for (;it + 1 < tmp.end() && rez != 0; it++)
	{
		if (*(it + 1) - *it < rez)
			rez = *(it + 1) - *it;
	}
	return (rez);
}

int Span::longestSpan() const {
	if (this->arr.size() < 2)
		throw TooFewData();

	std::vector<int> sorted = this->arr;
	std::sort(sorted.begin(), sorted.end());
	return (*(sorted.end() - 1) - *sorted.begin());
}
