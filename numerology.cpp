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

int	master_numbers(int big)
{
	if (big > 9 && (big % 11 != 0 || big > 33))
		return master_numbers(master_numbers(big / 10) + master_numbers(big % 10));
	return big;
}

int	reduced_number(int big)
{
	if (big > 9)
		return reduced_number(reduced_number(big % 10) + reduced_number(big / 10));
	return big;
}

int	horizontal_method(int argc, char ** argv)
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

int	vertical_method(int argc, char ** argv)
{
	int	number [argc - 1];

	for (int i = 0; i < argc - 1; i++)
		number[i] = 0;
	for (int j = 1; j < argc; j++)
	{
		std::string	input = argv[j];
		for (std::size_t i = 0; i <= input.length(); i++)
			number [j - 1] += letter_to_number(argv[j][i]);
	}
	for (int i = 0; i < argc - 1; i++)
		number[i] = master_numbers(number[i]);
	int res = 0;
	for (int i = 0; i < argc - 1; i++)
		res += number[i];
	return res;
}

int main (int argc, char **argv)
{
	if (argc < 2)
		return 1;

	/*Méthode horizontale*/
	std::cout << "\n*** HORIZONTAL METHOD ***" << std::endl;
	int	num = horizontal_method(argc, argv);
	int	master = master_numbers(num);
	std::cout << "Your number is: " << num << std::endl;
	if (master % 11 == 0)
		std::cout << "Your master number is: " << master << std::endl;
	else
		std::cout << "Your reduced number is: " << reduced_number(num) << std::endl;

	/*Méthode verticale*/
	std::cout << "\n*** VERTICAL METHOD ***" << std::endl;
	num = vertical_method(argc, argv);
	master = master_numbers(num);
	std::cout << "Your number is: " << num << std::endl;
	if (master % 11 == 0)
		std::cout << "Your master number is: " << master << std::endl;
	else
		std::cout << "Your reduced number is: " << reduced_number(num) << std::endl;

	/*Méthode directe*/

	return 0;
}
