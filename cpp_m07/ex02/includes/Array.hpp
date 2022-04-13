#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template<typename T>
class Array
{
public:
	Array(): arr(nullptr), size_(0) {};
	Array(unsigned int n): size_(n) {
		this->arr = new T[n];
	};
	Array(const Array<T> &other): arr(new T[other.size_]), size_(other.size_) {
		for (unsigned int i = 0; i < size_; i++)
		{
			this->arr[i] = other.arr[i];
		}
	};
	Array<T>& operator=(const Array<T>& other) {
		if (this->arr)
			delete this->arr;
		this->size_ = other.size_;
		this->arr = new T[other.size_];
		for (unsigned int i = 0; i < this->size_; ++i)
		{
			this->arr[i] = other.arr[i];
		}
	};

	class OutOfRangeException;
	T& operator[](unsigned int i) {
		if (i >= this->size_)
			throw OutOfRangeException();
		return (this->arr[i]);
	};
	~Array() {
		if (this->arr)
			delete this->arr;
	};

	unsigned int size() const {
		return (this->size_);
	};

private:
	T				*arr;
	unsigned int	size_;
};

template <typename T>
class Array<T>::OutOfRangeException: public std::exception
{
public:
	virtual const char *what() const throw() {
		return("Out of range");
	}
};

#endif
