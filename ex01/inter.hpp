#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T> <typename U>
void	iter(T* array, int const size,U f)	
{
	for (int i = 0; i < size; i++)
		f(array[i]);
}

template <typename T>
void	printRainbow(T element)
{
	static	int		color = 31;
	static	bool	increase = true;

	std::cout << "\033[1;" << color << "m" << element << "\033[0m";

	increase = (color == 37) ? false : true;
	increase = (color == 31) ? true : false;
	(increase) ? color++ : color--;
}

#endif
