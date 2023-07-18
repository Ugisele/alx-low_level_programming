#include "main.h"
/**
 * main - Entry point
 * Return: Always 0 (success)
 */
int main(void)
{
	char *g = "_putchar";

	while (*g)
	{
		_putchar(*g);
		g++;
	}
	_putchar('\n');

	return (0);
}

