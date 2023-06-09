#include "main.h"

/**
 * print_STR - prints non printable characters.
 * @list: the va_list containing the string to be printed.
 * @field_width: parameter with the field_width
 * Return: count of characters printed.
 */
int print_STR(va_list list, int field_width)
{
	int i = 0, non_printable = 1, count = 0;
	char *str;
	char buffer[3];
	(void)(field_width);

	str = va_arg(list, char *);
	if (!str)
		str = "(null)";

	for (; str[i]; i++)
	{
		non_printable = (str[i] > 0 && str[i] < 32) || (str[i] >= 127);

		if (non_printable)
		{
			(str[i] < 16) ? (count += _puts("\\x0")) : (count += _puts("\\x"));
			/* pass 'A' to to_base_n to get hex in uppercase  */
			buffer[0] = 'A';
			count += to_base_n(str[i], 16, buffer);
		}
		else
			count += _putchar(str[i]);
	}
	return (count);
}

/**
 * print_rev - prints a string in reverse order
 * @list: the arguments list passed to va_start()
 * @field_width: parameter with the field_width
 * Return: the number of characters printed to the stdout stream
 */
int print_rev(va_list list, int field_width)
{
	char *str, buffer[50];
	int i;
	(void)(field_width);

	str = va_arg(list, char *);

	if (str == NULL)
		return (_puts("(null)"));

	for (i = 0; str[i]; i++)
		buffer[i] = str[i];

	buffer[i] = '\0';

	reverse_str(buffer);

	return (_puts(buffer));
}
