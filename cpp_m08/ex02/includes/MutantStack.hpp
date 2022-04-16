#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{

public:

	MutantStack() {}
	MutantStack( MutantStack const & src ) {
		this->c = src.c;
		// std::cout << "hi\n";
	}
	virtual ~MutantStack() {}

	MutantStack &		operator=( MutantStack const & rhs ) { this->c = rhs.c; return *this; }

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

	iterator begin( void ) { return this->c.begin(); }
	iterator end( void ) { return this->c.end(); }

	reverse_iterator rbegin( void ) { return this->c.rbegin(); }
	reverse_iterator rend( void ) { return this->c.rend(); }
};

#endif /* ***************************************************** MUTANTSTACK_H */
