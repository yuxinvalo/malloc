#include "malloc.h"

int main(void)
{
	void *test = calloc(12, 55);
	printf("addr of calloc test is : %p\n", (void*)&test);	
	void *test2 = calloc(122, 20);
	printf("addr of calloc test2 is : %p\n", (void*)&test2);	
}
