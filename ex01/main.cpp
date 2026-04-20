#include "iter.hpp"
#include <iostream>

int		main(int ac, char **av)
{
	{
		if (ac == 2)
		{
			std::string word(av[1]);
			iter(word.c_str(), word.length(), printRainbow<const char>);
		}
		else if (ac > 2)
			iter(&av[1], ac - 1, printRainbow<std::string>);
	}
	std::cout << std::endl;
	{
		if (ac != 2)
			return 0;
		std::string word(av[1]);
		iter(&word[0], word.length(), ::toUpper);
		iter(word.c_str(), word.length(), printRainbow<const char>);
	}



	return 0;
}
