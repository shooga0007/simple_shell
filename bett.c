#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, or else 0
 */

int interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);

}

/**
 * is_delim - check if char is a delimeter
 * @c: check the char
 * @delim: the deli is a string
 * Return: 1 if true, or 0 if false
 */

int is_delim(char c, char *delim)
{
while (*delim)
if (*delim++ == c)
return (1);
return (0);
}

/**
 * _isalpha - checks for alphabetic character
 * @c: Character to input
 * Return: 1 if c is alphabetic, or 0 if false
 */

int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}

/**
 * _bett - converts string value to an integer value
 * @s: converted strings
 * Return: 0 if the string has no number, convert number otherwise
 */

int _bett(char *s)
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
result += -1;
}
else if (flag == 1)
flag = 2;
}
if (sign == -1)
output = -result;
else
output =  result;
return (output);
}
