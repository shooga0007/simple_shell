#include "shell.h"

/**
 * is_chain - test if current char in buffer is a chain delimeter
 * @info: the parameter struct
 * @buf: the char buffer
 * @p: address of current position in buf
 *
 * Return: 1 if chain delimeter, 0 otherwise
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
size_t h = *p;

if (buf[h] == '|' && buf[h + 1] == '|')
{
buf[h] = 0;
h++;
info->cmd_buf_type = CMD_OR;
}
else if (buf[h] == '&' && buf[h + 1] == '&')
{
buf[h] = 0;
h++;
info->cmd_buf_type = CMD_AND;
}
else if (buf[h] == ';') /* found end of this command */
{
buf[h] = 0; /* replace semicolon with null */
info->cmd_buf_type = CMD_CHAIN;
}
else
return (0);
*p = h;
return (1);
}

/**
 * check_chain - checks we should continue chaining based on last status
 * @info: the parameter struct
 * @buf: the char buffer
 * @p: address of current position in buf
 * @n: starting position in buf
 * @len: length of buf
 *
 * Return: Void
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t n, size_t len)
{
size_t h = *p;

if (info->cmd_buf_type == CMD_AND)
{
if (info->status)
{
buf[n] = 0;
h = len;
}
}
if (info->cmd_buf_type == CMD_OR)
{
if (!info->status)
{
buf[n] = 0;
h = len;
}
}

*p = h;
}

/**
 * replace_alias - replaces an aliases in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_alias(info_t *info)
{
int n;
list_t *node;
char *p;

for (n = 0; n < 10; n++)
{
node = node_starts_with(info->alias, info->argv[0], '=');
if (!node)
return (0);
free(info->argv[0]);
p = _strchr(node->str, '=');
if (!p)
return (0);
p = _strdup(p + 1);
if (!p)

return (0);
info->argv[0] = p;
}
return (1);
}

/**
 * replace_vars - replaces vars in the tokenized string
 * @info: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_vars(info_t *info)
{
int n = 0;
list_t *node;

for (n = 0; info->argv[n]; n++)
{
if (info->argv[n][0] != '$' || !info->argv[n][1])
continue;

if (!_strcmp(info->argv[n], "$?"))
{
replace_string(&(info->argv[n]),
_strdup(convert_number(info->status, 10, 0)));
continue;
}
if (!_strcmp(info->argv[n], "$$"))
{
replace_string(&(info->argv[n]),
_strdup(convert_number(getpid(), 10, 0)));
continue;
}
node = node_starts_with(info->env, &info->argv[n][1], '=');
if (node)
{
replace_string(&(info->argv[n]),
_strdup(_strchr(node->str, '=') + 1));
continue;
}
replace_string(&info->argv[n], _strdup(""));
}
return (0);
}

/**
 * replace_string - replaces string
 * @old: address of old string
 * @new: new string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_string(char **old, char *new)
{
free(*old);
*old = new;
return (1);
}
