#include "shell.h"
/**
 * _atoi - converts a str to an int
 * @s: the string to be converted
 * Return 0 if no num 
 */
int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
/**
 * is_delim - checks if char is a delimeter
 * @c: the char to check
 * @delim: delimeter str
 * Return: 1 if true or 0 in null
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - checks for alpha char
 * @c: char to input
 * Return: 1 if alphabetic, or 0
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
/**
 * interactive - returns true if shell is mode interactive
 * @info: struct address
 *
 * Return: 1, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

