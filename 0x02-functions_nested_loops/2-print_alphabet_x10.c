#include "main.h"

/**
  * print_alphabet_x10 - Make alphabet x10 times
  *
  * Return: void
  */
void print_alphabet_x10(void)
{
	char g;
	int i = 0;

	while (i <= 9)
	{
		for (g = 'a'; g <= 'z'; g++)
		{
			_putchar(g);
		}

		_putchar('\n');

		i++;
	}
}
