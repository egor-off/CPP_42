#include "MutantStack.hpp"
#include <list>
#include <string>

template <typename T>
void print_stack(T &stack)
{
	typename T::iterator it = stack.begin();
	typename T::iterator ite = stack.end();

	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
}

template <typename T>
void print_stack_reverse(T &stack)
{
	typename T::reverse_iterator rit = stack.rbegin();
	typename T::reverse_iterator rite = stack.rend();

	while (rit != rite)
	{
		std::cout << *rit << std::endl;
		rit++;
	}
}

int main(void) {
	{
		MutantStack<int> myStack;

		myStack.push(27);
		myStack.push(8);
		std::cout << "---chack top(), pop(), size(), empty()---" << std::endl;
		std::cout << myStack.top() << std::endl;
		myStack.pop();
		std::cout << myStack.size() << std::endl;
		std::cout << (myStack.empty() ? "empty" : "not empty") << std::endl;
		std::cout << "------more push()------" << std::endl;
		myStack.push(1);
		myStack.push(2);
		myStack.push(3);
		myStack.push(4);
		print_stack(myStack);
		std::cout << "--------copy constructor--------" << std::endl;
		MutantStack<int> s = myStack;
		print_stack(s);
		s.pop();
		s.pop();
		s.pop();
		std::cout << "--------delete 3 elements--------" << std::endl;
		print_stack(s);
		std::cout << "--------reverse print---------" << std::endl;
		print_stack_reverse(s);

		MutantStack<int> s2;
		std::cout << "--------copy assigment--------" << std::endl;
		s2 = s;
		s2.pop();
		print_stack(s);
		std::cout << "--------------------------------" << std::endl;
		print_stack(s2);
		std::cout << "--------------------------------" << std::endl;
		MutantStack<int>::iterator it = s.begin();
		it++;
		std::cout << *it << std::endl;
		it--;
		std::cout << *it << std::endl;
		++it;
		--it;
		std::cout << *it << std::endl;
	}
	{
		std::list<int> lst;

		lst.push_back(8);
		lst.push_back(9);
		lst.push_back(66);
		lst.push_back(737);
		lst.push_back(20);

		std::cout << "----ELEMENTS_OF_LIST_WITH_BEGIN()_AND_END()----" << std::endl;
		print_stack(lst);
		std::cout << "----ELEMENTS_OF_LIST_WITH_RBEGIN()_AND_REND()----" << std::endl;
		print_stack_reverse(lst);
	}
	return 0;
}
