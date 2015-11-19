#include "malloc.h"

int main(void)
{
	void *test = malloc(sizeof(int) * 20);
	printf("addr of test is : %p", (void*)&test);
	printf("\n\n");
	void *test1 = malloc(564);
	printf("addr of test1 is : %p\n", (void*)&test1);
	printf("\n\n");
	void *test3 = malloc(8);
	printf("addr of test3 is : %p", (void*)&test3);
	printf("\n\n");
	void *test5 = malloc(1200);
	printf("addr of test5 is : %p", (void*)&test5);
	printf("\n\n");

	return 0;
}
