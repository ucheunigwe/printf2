#include "main.h"

static int printnum(int);
static int printChar(char item);
static int printString(char *str);

/**
 * _printf - a custom implementation of printf
 * @format: input string
 *
 * Return: number of characters to be printed
 */
int _printf(const char *format, ...)
{

	int noPrintedChar = 0;
	int i = 0;
	char s;

	va_list args;

	va_start(args, format);

	if (format == NULL)
		return (-1);

	while (format[i] != '\0')
	{
		s = format[i];

		if (s == '%')
		{
			++i;

			s = format[i];

			if (s == 'c')
			{
				char ch = va_arg(args, int);

				noPrintedChar += printChar(ch);
			}
			else if (s == 's')
			{
				char *str = va_arg(args, char*);

				noPrintedChar += printString(str);
			}
			else if (s == '%')
			{
				noPrintedChar += printChar('%');
			}
			else if ((s == 'd') || (s == 'i'))
			{
				int num = va_arg(args, int);
				noPrintedChar += printnum(num);

			}
			else
			{
				noPrintedChar += printChar('%');
				noPrintedChar += printChar(format[i]);
			}
		}
		else
		{
			noPrintedChar += printChar(format[i]);
		}
		i++;
	}
	va_end(args);
	return (noPrintedChar);
}

/**
 * printChar - sub-function to print characters
 * @item : item or character to print
 * Return: 1 else 0
 */

static int printChar(char item)
{
	return (write(1, &item, 1));
}

int func (int a, int *b)
{
	if (a == 0)
		return(1);
	else
	{
		int rem = a % 10;
		char digit = rem + '0';
		a = a/10;
		*b += func (a, b);
		write(1, &digit, 1);
	}
	return (0);
}

/**
 * printnum - sub-function to print characters
 * @num : item or character to print
 * Return: 1 else 0
 */

static int printnum(int num)
{
	int size = 0;

	if (num < 0)
	{
		char c = '-';
		size += write(1, &c, 1);
		num = -num;
	}

	if (num > 0)
	{
		int *p = &size;
		func (num, p);
	}
	else if (num == 0)
	{
		char c = num + '0';
		write(1, &c, 1);
		size ++;
	}

        return (size);
}


/**
 * printString - sub-function to print string
 * @str : string to be printed
 * Return: the number of char printed
 */

static int printString(char *str)
{
	int noOfCharPrinted = 0;

	if (str == NULL)
	{
		return (0);
	}
	else
	{
		do {
			noOfCharPrinted += printChar(*str);
			str++;
		} while (*str);
	}

	return (noOfCharPrinted);
}
