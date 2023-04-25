#include "main.h"

/**
 * conv_c - prints %c
 * @conv: arg
 * @buff: buff[1024]
 * @i: index
 * @f: flag characters for non-custom conversion specifiers
 * Return: length of write
 */

int conv_c(va_list conv, char *buff, int i, __attribute__ ((unused)) char f)
{
	char c = va_arg(conv, int);

	buff[i++] = c;
	return (i);
}
/**
 * conv_s - prints %s
 * @conv: arg
 * @buff: buff[1024]
 * @i: index
 * @f: flag characters for non-custom conversion specifiers
 * Return: length of write
 */

int conv_s(va_list conv, char *buff, int i, __attribute__ ((unused)) char f)
{
	char *p = va_arg(conv, char *), s[] = "(null)";

	if (!p)
	{
		i = _strcpy(buff, s, i);
		return (i);
	}
	i = _strcpy(buff, p, i);
	return (i);
}
