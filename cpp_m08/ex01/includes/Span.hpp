#ifndef SPAN_HPP
# define SPAN_HPP

# include <string>
# include <vector>
# include <iostream>

# define ERROR_NO_DATA "Not enough data to find distance!"
# define ERROR_NO_SPACE "No more space in the Span!"

class Span
{
public:
	Span();
	Span( unsigned int N );
	Span( Span const & src );
	~Span();
	Span &		operator=( Span const & rhs );

	class TooFewData: public std::exception
	{
		virtual const char* what() const throw() {
			return (ERROR_NO_DATA);
		}
	};
	class NotEnoughSpace: public std::exception
	{
		virtual const char* what() const throw() {
			return (ERROR_NO_SPACE);
		}
	};

	void addNumber(int const add);

	int shortestSpan() const;
	int longestSpan() const;

	template <typename T>
	void addNumber(T begin, T end)
	{
		std::vector<int> tmp(begin, end);
		for (size_t i = 0; i < tmp.size(); i++)
		{
			if (i == this->arrSize)
				throw Span::NotEnoughSpace();
			this->arr.push_back(tmp[i]);
		}
	}

private:
	std::vector<int>	arr;
	unsigned int		arrSize;
};

// class Span::TooFewData: public std::exception
// {
// 	virtual const char* what() const throw() {
// 		return (ERROR_NO_DATA);
// 	}
// };

// class Span::NotEnoughSpace: public std::exception
// {
// 	virtual const char* what() const throw() {
// 		return (ERROR_NO_SPACE);
// 	}
// };


#endif /* ************************************************************ SPAN_H */
