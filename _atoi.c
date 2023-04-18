#include "shell.h"

/**
 * check_if_interactive - checks if the shell is in interactive mode
 * @shell_info: pointer to ShellInfo struct
 *
 * Return: 1 if shell is in interactive mode, 0 otherwise
 */
int check_if_interactive(ShellInfo *shell_info)
{
	return (isatty(STDIN_FILENO) && shell_info->readfd <= 2);
}

/**
 * is_delimiter - checks if a character is a delimiter
 * @c: the character to check
 * @delimiters: the delimiter string
 *
 * Return: 1 if the character is a delimiter, 0 otherwise
 */
int is_delimiter(char c, char *delimiters)
{
	while (*delimiters)
		if (*delimiters++ == c)
			return (1);
	return (0);
}

/**
 * is_alphabetic - checks if a character is alphabetic
 * @c: the character to check
 *
 * Return: 1 if the character is alphabetic, 0 otherwise
 */
int is_alphabetic(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * string_to_integer - converts a string to an integer
 * @s: the string to be converted
 *
 * Return: the converted number, or 0 if no numbers in the string
 */
int string_to_integer(char *s)
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
