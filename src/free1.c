#include "malloc.h"

extern void*first_block;
/*free the chunks*/
//-------fusion the two blocks--------------------
t_block fusion(t_block ptr)
{
  if (ptr->nextblock && ptr->nextblock->is_free)
  {
    /* sum the sizes of the current chunk and the next one, 
     * plus the meta-data siz
     */ printf("mark fusion block\n");
    ptr->size += ptr->nextblock->size + BLOCK_SIZE;
    ptr->nextblock = ptr->nextblock->nextblock;
      if (ptr->nextblock)
        ptr->nextblock->prevblock = ptr;
  }
  return ptr;
}

/*check if its a right chunk by data pointer*/
t_block get_block(void *p) 
{
  char *temp;
  temp = p;
  return (p = temp -= sizeof(struct s_block));
}

int valid_addr(void *p)
{
	while (first_block)
	{
    if (p == ((t_block)first_block)->data)
    {
      return 1;
    }
		first_block = ((t_block)first_block)->nextblock;
  }
	//printf("print addr of valid addr first_block: %p\n", &first_block);
  return 0;
}

void free(void *ptr)
{
  t_block b;
  int i = valid_addr(ptr);
  printf("ptr valid addr return to %i\n",i);
  if (i)
  {
    b = get_block(ptr);
    b->is_free = FREE_Y;

      if (b->prevblock && b->prevblock->is_free)
        b = fusion(b->prevblock);
			/*If b has next block, continue to fusion*/
      if (b->nextblock)
        fusion(b);
      else
      {
        printf("position is free'else\n");
        if (b->prevblock)
 					b->prevblock->prevblock = NULL;
      	else
          	first_block = NULL;
        	
        	int ret = munmap(b, PAGE_SIZE);
        	if (ret != 0)
          fprintf(stderr, "failed to free malloc: %s\n", strerror(errno));
       }
			
 		}
  int ret = munmap(ptr, PAGE_SIZE);
  if(ret !=0)
    fprintf(stderr, "failed to free malloc :{%s}\n", strerror(errno));
}

