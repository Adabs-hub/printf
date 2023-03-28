#include "main.h"

/**
 * _printf - printf function
 * @format: const char pointer
 * Desc: prints strings in related formats
 * Return: b_len
 */
int _printf(const char *format, ...)
{
	int (*pfunc)(va_list, flags_t *);
	int i = 0;
	va_list arg_list;
	flags_t flags = {0, 0, 0};
	register int count = 0;

	va_start(arg_list, format);
	/*check % format specifier*/
	if (format == 0)
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
			{
				count += _putchar('%');
				i++;
				continue;
			}
			while (get_flag(format[i], &flags))
				i++;
			pfunc = get_print(format[i]);
			count += (pfunc)
				? pfunc(arg_list, &flags)
				: _printf("%%%c", format[i]);
		} else
			count += _putchar(format[i]);
		i++;
	}
	_putchar(-1);
	va_end(arg_list);
	return (count);
}
