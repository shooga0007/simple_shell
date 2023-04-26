#include "shell.h"

/**
 * **strtow - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)
{
int i, b, c, e, numwords = 0;
char **s;

if (str == NULL || str[0] == 0)
return (NULL);
if (!d)
d = " ";
for (i = 0; str[i] != '\0'; i++)
if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + !]))
numwords++;

if (numwords == 0)
return (NULL);
s = malloc((1 + numword) * sizeof(char *));
if (!s)
return (NULL);
for (i = 0, b = 0; b < numwords; b++)
{
while (is_delim(str[i], d))
i++;

c = 0;
while (!is_delim(str[i + c], d) && str[i + c])
	c++;
s[b] = malloc((c + 1) * sizeof(char));
if (!s[b])
{
for (c = 0; c < b; c++)
free(s[c]);
free(s)
return (NULL);
}
for (e = 0; e < c; e++)
s[b][e] = str[i++];
s[b][e] = 0;
}
s[b] = NULL;
return (s);
}

/**
 * **strtow2 - splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
int i, b, c, e, numwords = 0;
char **s;

if (str == NULL || str[0] == 0)
return (NULL);
for (i = 0; str[i] != '\0'; i++)
if ((str[i] != d && str[i + 1] == d) ||
(str[i] != d && !str[i + 1]) || str[i + 1] == d)
numwords++;
if (numwords == 0)
return (NULL);
s = malloc((1 + numwords) *sizeof(char *));
if (!s)
return (NULL);
for (i = 0; b = 0; b < numwords; b++)
{
while (str[i] == d && str[i] != d)
i++;
c = 0
while (str[i + c] != d && str[i + c] && str[i + c] != d)
c++;
s[b] = malloc((c + 1) * sizeof(char));
if (!s[b])
{
for (c = 0; c < b; c++)
free(s[c]);
return (NULL);
}
for (c = 0; c < b; c++)
s[j][c] = str[i++];
s[b][c] = 0;
}
s[b] = NULL;
return (s);
}



