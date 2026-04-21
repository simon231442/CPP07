#include "Array.hpp"
#include <iostream>
#include <string>

static void printTitle(const std::string &title)
{
	std::cout << "\n===== " << title << " =====" << std::endl;
}

int main(void)
{
	printTitle("1) Default constructor (empty array)");
	Array<int> empty;
	std::cout << "empty.size() = " << empty.size() << std::endl;

	printTitle("2) Constructor with n elements (default initialized)");
	Array<int> numbers(5);
	std::cout << "numbers.size() = " << numbers.size() << std::endl;
	for (unsigned int i = 0; i < numbers.size(); ++i)
		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;

	printTitle("3) Fill values via operator[]");
	for (unsigned int i = 0; i < numbers.size(); ++i)
		numbers[i] = static_cast<int>(i * 10);
	for (unsigned int i = 0; i < numbers.size(); ++i)
		std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;

	printTitle("4) Copy constructor must be deep copy");
	Array<int> copy(numbers);
	numbers[0] = 999;
	std::cout << "numbers[0] = " << numbers[0] << " (modified original)" << std::endl;
	std::cout << "copy[0]    = " << copy[0] << " (must stay old value)" << std::endl;

	printTitle("5) Assignment operator must be deep copy");
	Array<int> assigned;
	assigned = numbers;
	numbers[1] = 777;
	std::cout << "numbers[1]  = " << numbers[1] << " (modified original)" << std::endl;
	std::cout << "assigned[1] = " << assigned[1] << " (must stay copied value)" << std::endl;

	printTitle("6) Const access (const operator[])");
	const Array<int> constArray(copy);
	std::cout << "constArray[2] = " << constArray[2] << std::endl;

	printTitle("7) Out of bounds must throw std::exception");
	try
	{
		std::cout << numbers[42] << std::endl;
		std::cout << "ERROR: exception was expected but not thrown" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "OK: caught std::exception for out-of-bounds access" << std::endl;
		(void)e;
	}

	printTitle("8) Works with another type (std::string)");
	Array<std::string> words(3);
	words[0] = "hello";
	words[1] = "cpp";
	words[2] = "templates";
	for (unsigned int i = 0; i < words.size(); ++i)
		std::cout << "words[" << i << "] = " << words[i] << std::endl;

	return 0;
}

