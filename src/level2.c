#include "./malloc.h"

int main(void)
{
  void *test = malloc(sizeof(int) * 20);
	int i =  valid_addr(test);
	printf("now free time, i is %i: ----------\n",i);
	free(test);
  printf("\n\n");
  void *test1 = malloc(564);
  printf("\n\n");
  void *test3 = malloc(8);
  printf("\n\n");
	printf("now free time test3: ----------\n");
	free(test3);
  void *test5 = malloc(1200);
  printf("\n\n");
	printf("now free time test3 and test 5: ----------\n");
	free(test1);	
	free(test5);

  return 0;
}

