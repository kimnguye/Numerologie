#include <string>
#include <iostream>

int	letter_to_number(char c)
{
	int i;
	if (c == 32)
		return 0;
	if (c >= '0' && c <= '9')
		return c - '0';
	if (c >= 97 && c <= 122)
		c -= 32;
	if (c < 65 || c > 90)
		return 0;
	i = (c - 64) % 9;
	if (i == 0)
		return 9;
	return i;
}

int	add_the_letters(int argc, char ** argv)
{
	int	number = 0;
	for (int j = 1; j < argc; j++)
	{
		std::string	input = argv[j];
		for (std::size_t i = 0; i <= input.length(); i++)
			number += letter_to_number(argv[j][i]);
	}
	return number;
}

int	final_number(int big)
{
	if (big > 9)
		return final_number(final_number(big % 10) + final_number(big / 10));
	else
		return big;
}

int	convertissor(int argc, char ** argv)
{
	return (final_number(add_the_letters(argc, argv)));
}

int main (int argc, char **argv)
{
	if (argc < 2)
		return 1;

	std::cout << "Your number is: " << convertissor(argc, argv) << std::endl;
	return 0;
}
