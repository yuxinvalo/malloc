#include "malloc.h"
void split_block(t_block ptr, size_t size);
extern void* first_block;

/*---find the block and use first fit---*/
t_block find_block(t_block *last, size_t size)
{
	t_block ptr;
	ptr = first_block;
	while (ptr && !(ptr->is_free && ptr->size >= size))
	{
		*last = ptr;
		ptr = ptr->nextblock;
	}	
	return ptr;
}

/*if block is full or first time use malloc, extend a new space*/
t_block extend_block(t_block last, size_t s)
{
//-----------init a new block----------------------------
	printf("extend_block,here\n");
	t_block ptr_extend;
	ptr_extend = mmap(NULL, PAGE_SIZE, PROT_READ | PROT_WRITE, 
										MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
	//total size used = s_block + s
	ptr_extend->ptr_next = ptr_extend->data;
	ptr_extend->size_used = s;
	ptr_extend->size = PAGE_SIZE - BLOCK_SIZE;
	ptr_extend->nextblock = NULL;
 	ptr_extend->prevblock = last;

	split_block(ptr_extend, s);
	
	if (last)
	{
		ptr_extend->prevblock = last;
		last->nextblock = ptr_extend;
	}
	return ptr_extend;
}

void split_block(t_block ptr, size_t size)
{
  printf("split_bloc\n");
  t_block newb;
  newb = (t_block)(ptr->data + size);
  //new block size(mapped) = block_size(4096) - size - s_block 
  newb->size = ptr->size - size - BLOCK_SIZE;
  newb->nextblock = ptr->nextblock;
  newb->prevblock = ptr;
  newb->is_free = FREE_Y;
  //point to next header
  newb->ptr_next = newb->data;

  ptr->size = size;
  ptr->nextblock = newb;

  if (newb->nextblock)
    newb->nextblock->prevblock = newb;
}

