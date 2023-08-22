#include "shell.h"

/**
 * bfree - pointer is freed and NULLs the address
 * @ptr: pointer to free address
 *
 * Return: 1 if has been freed, else 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

