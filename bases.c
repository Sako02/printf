#include "main.h"

/**
 * print_binary - prints a binary representation of an unsigned int
 * @list: va_list of integers to be printed
 * @field_width: parameter with the field_width
 * Return: number of characters printed
 */
int print_binary(va_list list, int field_width)
{
	char buffer[50];
	unsigned int num = va_arg(list, unsigned int);
	(void)(field_width);

	return (to_base_n(num, 2, buffer));
}

/**
 * print_octal - prints a octal representation of an unsigned int
 * @list: va_list of integers to be printed
 * @field_width: parameter with the field_width
 * Return: number of characters printed
 */
int print_octal(va_list list, int field_width)
{
	char buffer[50];
	unsigned int num = va_arg(list, unsigned int);
	(void)(field_width);

	return (to_base_n(num, 8, buffer));
}

/**
 * print_hex - prints a hexadecimal representation of an unsigned int
 * @list: va_list of integers to be printed
 * @field_width: parameter with the field_width
 * Return: number of characters printed
 */
int print_hex(va_list list, int field_width)
{
	char buffer[50];
	unsigned int num = va_arg(list, unsigned int);
	int len = _strlen(buffer);
	int i;
	int count = 0;
	(void)(field_width);

	if (field_width > len)
	{
		for (i = 0; i < field_width - len; i++)
			count += _putchar(' ');
	}
	count += to_base_n(num, 16, buffer);
	return (count);
}

/**
 * print_HEX - as print_hex() func but in uppercase
 * @list: va_list of integers to be printed
 * @field_width: parameter with the field_width
 * Return: number of characters printed
 */
int print_HEX(va_list list, int field_width)
{
	char buffer[50];
	unsigned int num = va_arg(list, unsigned int);
	(void)(field_width);

	buffer[0] = 'A';
	return (to_base_n(num, 16, buffer));
}

/**
 * print_addrs - prints the address of a given pointer
 * @list: va_list list of arguments
 * @field_width: parameter with the field_width
 * Return: number of characters printed (including "0x")
 */
int print_addrs(va_list list, int field_width)
{
	char buffer[50];
	void *ptr = va_arg(list, void *);
	unsigned long address = (unsigned long)ptr;
	(void)(field_width);

	if (!ptr)
		return (_puts("(nil)"));

	return (_puts("0x") + to_base_n(address, 16, buffer));
}
