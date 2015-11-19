#include "malloc.h"
void *first_block = NULL;
/*align in 8(1000), and size is size_t = 8bits
 *0x7 is used for check 1xxx, if x is 0, is x is 0
 *align8 is multiple to 8, if not, add correct bits to make it align 
 */
#if 0
size_t align8(size_t align8)
{
	if (align8 & 0x7 == 0)
		return 0;
	return ((align8 >> 3) + 1) << 3;
}
#endif

void *malloc(size_t size)
{
	t_block ptr, last;
	size_t temp_s = size;
	if (first_block)
	{
		/*First find a block*/
		printf("mark first_block is not NULL now.\n");
		last = first_block;
		ptr = find_block(&last, temp_s);

		/*split if yes*/
		if (ptr)
		{
			printf("mark start of split_block");
			if((ptr->size - temp_s) >= BLOCK_SIZE + 1)
				split_block(ptr, temp_s);
			ptr->is_free = FREE_N;
		}
		else
		{
			/*No fitting block, extend it*/	
			printf("====extend block because theres no fit block====\n");
			ptr = extend_block(last, temp_s);
			if(!ptr)
			{
				fprintf(stderr, "extend block failed because of{ %s }\n", strerror(errno));
				return NULL;
			}
		}
	}
	else
	{
		/*first time to allocate memory*/
		ptr = extend_block(NULL, temp_s);
		if(!ptr)
			return NULL;
		first_block = ptr;
	}
	printf("====end of page ====\n");
	return (void*)ptr->data;
}


