#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <iostream>

template <typename T>
class Array
{
	private :
		T*				array_;
		unsigned int	size_;
	public :
		Array();
		Array(unsigned int n);
		Array(Array const & src);
		~Array();

		Array&			operator=(Array const & rhs);
		T&				operator[](unsigned int index);
		T const &		operator[](unsigned int index) const;
		unsigned int	size(void) const;
		void			display(void) const;
};

template <typename T>
Array<T>::Array() : array_(0), size_(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : array_(0), size_(n)
{
	if (size_ > 0)
		array_ = new T[size_];
}

template <typename T>
Array<T>::Array(Array const & src) : array_(0), size_(src.size_)
{
	if (size_ > 0)
	{
		array_ = new T[size_];
		for (unsigned int i = 0; i < size_; ++i)
			array_[i] = src.array_[i];
	}
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->array_;
}

template <typename T>
Array<T>&	Array<T>::operator=(Array const & rhs)


{
	if (this != &rhs)
	{
		T *newArray = 0;
		if (rhs.size_ > 0)
		{
			newArray = new T[rhs.size_];
			for (unsigned int i = 0; i < rhs.size_; ++i)
				newArray[i] = rhs.array_[i];
		}
		delete[] this->array_;
		this->array_ = newArray;
		this->size_ = rhs.size_;
	}
	return *this;
}

template <typename T>
T&		Array<T>::operator[](unsigned int index)
{
	if (index >= this->size_)
		throw std::exception();
	return this->array_[index];
}

template <typename T>
T const &	Array<T>::operator[](unsigned int index) const
{
	if (index >= this->size_)
		throw std::exception();
	return this->array_[index];
}

template <typename T>
unsigned int	Array<T>::size(void) const
{
	return this->size_;
}

template <typename T>
void			Array<T>::display(void) const
{
	for (unsigned int i = 0; i < size_; i++)
		std::cout << array_[i] << std::endl;//est-ce le const accesseur qui est appelle ?
}

#endif
