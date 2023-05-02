#include "main.h"

/**
 * parse_flags - parses flags in a format string
 * @format: the format string
 * @flags: pointer to a flags_t struct
 *
 * @i: pointer to the index of the format string
 * This function parses flags in a format string
 */
void parse_flags(const char *format, flags_t *flags, int *i)
{


	for (flags->j = *i; format[flags->j]; flags->j++)
	{
		if (format[flags->j] == '+')
			flags->plus = 1;
		else if (format[flags->j] == '#')
			flags->hash = 1;
		else if (format[flags->j] == ' ')
		{
			/* if after % more than one space, return */
			if (format[flags->j + 1] == ' ')
				return;
			flags->space = 1;
		}
		else
			break;
	}
	*i = flags->j;

	if (flags->plus && flags->space)
		flags->space = 0;

}
