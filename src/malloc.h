#ifndef MALLOC_H
# define MALLOC_H
#include <sys/mman.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
# define BLOCK_SIZE 28
# define PAGE_SIZE 4096
# define FREE_Y 1;
# define FREE_N 0;

//void *first_block = NULL;
struct s_block
{
	size_t size; //size of block
	int is_free; //if the block is free
	size_t size_used; //the busy size in a page
	struct s_block* nextblock;//next block
	struct s_block* prevblock;//prev block
	void *ptr_next; // point to next head data
	char data[1];
};
typedef struct s_block *t_block;


void free(void *ptr);
t_block fusion(t_block ptr);
t_block get_block(void *p);
int valid_addr(void *p);


void *malloc(size_t size);
t_block find_block(t_block *last, size_t size);
t_block extend_block(t_block last, size_t s);

void *calloc(size_t number, size_t size);
void *realloc(void *ptr, size_t size);
#endif /*MALLOC_H*/
