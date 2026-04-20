#pragma once
/*#ifndef ITER_HPP
# define ITER_HPP
*/

# include <iostream>

template <typename T, typename F>
void	iter(T* array, int const size, F f)
{
	for (int i = 0; i < size; i++)
		f(array[i]);
}

template <typename T, typename F>
void	iter(T const* array, int const size, F f)
{
	for (int i = 0; i < size; i++)
		f(array[i]);
}

template <typename T>
void	printRainbow(T element)
{
	static const int colors[] = {
		196, 202, 208, 214, 220, 226, 190, 154, 118, 82, 46, 47, 48, 49, 50, 51,
		45, 39, 33, 27, 21, 57, 93, 129, 165, 201, 200, 199, 198, 197
	};
	static const int num_colors = sizeof(colors) / sizeof(colors[0]);
	static int index = 0;
	static bool increase = true;

	std::cout << "\033[38;5;" << colors[index] << "m" << element << "\033[0m";

	if (increase) {
		index++;
		if (index >= num_colors - 1) increase = false;
	} else {
		index--;
		if (index <= 0) increase = true;
	}
}

void	toUpper(char& c)
{
	c = c - 32;
}

//#endif
