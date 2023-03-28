#include "main.h"

/**
 * get_print - selects the right printing function
 * depending on the conversion specifier passed to _printf
 * @s: character that holds the conversion specifier
 * Description: the function loops through the structs array
 * func_arr[] to find a match between the specifier passed to _printf
 * and the first element of the struct, and then the approriate
 * printing function
 * Return: a pointer to the matching printing function
 */
int (*get_print(char s))(va_list, flags_t *)
{
	ph func_arr[] = {
		{'i', print_int},
		{'s', print_string},
		{'c', print_char},
		{'d', print_int},
		{'u', print_unsigned},
		{'x', print_hex},
		{'X', print_hex_big},
		{'b', print_binary},
		{'o', print_octal},
		{'R', print_rot13},
		{'r', print_rev},
		{'S', print_bigS},
		{'p', print_address},
		{'%', print_percent}
		};
	int flags = 14;

	register int i;

	for (i = 0; i < flags; i++)
		if (func_arr[i].c == s)
			return (func_arr[i].f);
	return (NULL);
}

/**
 * get_flag - turns on flags if _printf finds
 * @s: character that holds the flag specifier
 * @f: pointer to the struct flags in which we turn the flags on
 *
 * Return: 1 if a flag has been turned on, 0 otherwise
 */
int get_flag(char s, flags_t *f)
{
	int i = 0;
	switch (s)
	{
		case '+':
			f->plus = 1;
			i = 1;
			break;
		case ' ':
			f->space = 1;
			i = 1;
			break;
		case '#':
			f->hash = 1;
			i = 1;
			break;
	}
	return (i);
}
