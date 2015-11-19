#include "malloc.h"

void *calloc(size_t number, size_t size)
{
	printf("calloc function, number is %i, size is %i \n\n", number, size);
	size_t *new_mem;
	size_t	s,i;
	new_mem = malloc(number * size);
	for (i = 0; i < size; i++)
	{
		new_mem[i] = 0;
	}
	return (new_mem);
}
