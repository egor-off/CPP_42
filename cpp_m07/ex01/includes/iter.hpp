#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void iter(T *arr, unsigned int size, void (*func)(T const &el))
{
	for (unsigned int i = 0; i < size; ++i)
		(*func)(arr[i]);
}

#endif
