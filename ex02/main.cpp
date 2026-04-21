#include "Array.hpp"
#include <iostream>
#include <string.hpp>
#include <iomanip>

int	main(void)
{
	{
		titlePut("1 : Class Array with int type by default constructor");
		Array<int>	empty();
		std::cout << std::left << setw(15) << "empty.size =" << empty.size;
		delete empty;
	}
	{
		titlePut("2 : Class Array with int type by constructor with n element");
		Array<int>	numbers(5);
		numbers.display();

		titlePut("3 : fill the array with number");
		for (int i = 0; i < numbers.size; i++)
			number[i] = i * 100;
		numbers.display();

		titlePut("4 : copy by copy constructor with deep copy demonstration");
		Array<int>	copy(nubers);
		numbers[0] = 999;
		std::cout << setw(15) << "numbers[0] =" << numbers[0] << " (modified original)" << std::endl;
		std::cout << setw(15) << "copy[0] =" << copy[0] << " (must stay old value)" << std::endl;

		titlePut("6 : out of boud access");
		try
		{
			std::cout << numbers[42] << std::endl
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
		word[0] = "hello";
		word[1] = "cpp";
		word[2] = "template";
		word.display();
	}
}

static int	titlePut(std::string const title)
{
	std::cout << "\n-----   " << title << "   -----" << std::endl;
}

