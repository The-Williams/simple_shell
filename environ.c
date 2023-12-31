#include "shell.h"

/**
 * _myownenv - the intent environ is printed
 * @info: for the requisite arguments structure. For maintaining
 * a prototype of a constant function.
 * Return: 0
 */
int _myownenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getmyenv - environ of the var value is got here
 * @info: The structure containing the potential arguments
 * @name: the name of the environ variable present
 *
 * Return: value
 */
char *_getmyenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _myputenv - environ variable is initialized,
 * or an already existing one modified
 * @info: Struct that have arguments with potential. For maintaining
 * prototype with a constant function.
 * Return: 0
 */
int _myputenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect arguements number\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunputenv - Environ variable is removed
 * @info: Struct that has arguments with potential. For maintaining
 * function with a constant prototype.
 * Return: 0
 */
int _myunputenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * create_env_list - environ list that is linked is populated
 * @info: Struct arguments with potential. For maintaining
 * function with a constant prototype.
 * Return: 0
 */
int create_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
