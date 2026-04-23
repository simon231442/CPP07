#include "Array.hpp"
#include <iostream>
#include <string>
#include <iomanip>

static void	titlePut(std::string const title)
{
	std::cout << "\n-----   " << title << "   -----" << std::endl;
}

int			main(void)
{
	{
		titlePut("1 : Class Array with int type by default constructor");
		Array<int>	empty;
		std::cout << std::left << std::setw(15) << "empty.size =" << empty.size();
	}
	{
		titlePut("2 : Class Array with int type by constructor with n element");
		Array<int>	numbers(5);
		numbers.display();

		titlePut("3 : fill the array with number");
		for (unsigned int i = 0; i < numbers.size(); i++)
			numbers[i] = i * 100;
		numbers.display();

		titlePut("4 : copy by copy constructor with deep copy demonstration");
		Array<int>	copy(numbers);
		copy[1] = 999;
		std::cout << std::setw(15) << "numbers[1] =" << numbers[1] << " (must stay old value)" << std::endl;
		std::cout << std::setw(15) << "copy[1] =" << copy[1] << " (modified copy)" << std::endl;

		titlePut("6 : out of boud access");
		try
		{
			std::cout << numbers[42] << std::endl;
			std::cout << "ERROR: exception was expeted" << std::endl;
		}
		catch (const std::exception & e)
		{
			std::cout << "Exception caught as expected" << std::endl;
			(void)e;
		}
	}
	{
		titlePut("7 : Class Array with std::string type by default constructor");
		Array<std::string>	words(3);
		words[0] = "hello";
		words[1] = "cpp";
		words[2] = "template";
		words.display();
	}
}


