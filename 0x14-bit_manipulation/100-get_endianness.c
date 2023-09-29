#include "main.h"
/**
 *get_endianness - this function checks foe endianness
 *Return: 0 if big endian and 1 if little endian
 */
int get_endianness(void)
{
	unsigned int n = 1;
	char *m = (char *)&n;

	if (*m)
		return (1);
	else
		return (0);
}
