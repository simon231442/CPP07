#ifndef ITER_HPP
# define ITER_HPP

template <typename T> <typename U>
void	iter(T* array, int const size, U f)	
{
	for (int i = 0; i < size; i++)
		f(array[i]);
}

#endif
