#include "main.h"

/**
 * strtok_arr_len - Takes a string as input and returns the array lenght.
 * @str: Input string.
 * Return: The number of the lenght of the array to allocate.
 */
size_t strtok_arr_len(char *str)
{
	char *str_cpy, *token;
	size_t arr_len;

	str_cpy = strdup(str);
	if (!str_cpy)
	{
		free(str);
		exit(1);
	}
	token = strtok(str_cpy, "\n ");
	arr_len = 1;
	while (token)
	{
		token = strtok(NULL, "\n ");
		arr_len++;
	}
	free(str_cpy);
	return (arr_len);
}
