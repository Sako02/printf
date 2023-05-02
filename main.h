#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct fmt - Struct for formatting data.
 * @sym: *sym: Pointer to a character string.
 * @fn: list of pointers that takes a va_list as an arg.
 */
typedef struct fmt
{
	char *sym;
	int (*fn)(va_list, int);
} fmt_t;

/**
 * struct flags - Struct for flagging data.
 * @space: space of a character string.
 * @plus: parameter for adding
 * @hash: parameter for the hash sign
 * @j: iteration parameter.
 */
typedef struct flags
{
	int j;
	int plus;
	int space;
	int hash;
} flags_t;

/* main */
int _printf(const char *format, ...);

/* handlers */
int (*get_print(const char *format))(va_list, int);
void parse_flags(const char *format, flags_t *flags, int *);

/* chars */
int print_char(va_list list, int field_width);
int print_str(va_list list, int field_width);
int print_perc(va_list list, int field_width);

/* numbers */
int print_int(va_list list, int field_width);
int print_unsigned(va_list list, int field_width);

/* bases */
int print_binary(va_list list, int field_width);
int print_octal(va_list list, int field_width);
int print_hex(va_list list, int field_width);
int print_HEX(va_list list, int field_width);
int print_addrs(va_list list, int field_width);

/* str_rev */
int print_STR(va_list list, int field_width);
int print_rev(va_list list, int field_width);

/* utilities */
unsigned int _strlen(char *s);
void reverse_str(char s[]);
void _itoa(long n, char s[]);
int to_base_n(unsigned long num, int base, char s[]);
int _isdigit(int c);

/* writer */
int _putchar(char c);
int _puts(char *str);

#endif
