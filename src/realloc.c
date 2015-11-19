#include "malloc.h"
/*Realise Realloc is a little like free function, 
 *just collect all the block allocated, and copy it to a new memory
 *by "mumcyp", then split, fusion.
 */
void *realloc(void *ptr, size_t size)
{
	t_block b, newb;
	size_t temp_s = size;
	void *newptr;
	if (!ptr)
		return (malloc(size));

	if (valid_addr(ptr))
	{
		b = get_block(ptr);
		if (b->size >= temp_s)
			{
				if (b->size - temp_s >= (BLOCK_SIZE + 8))
				{
					split_block(b, temp_s);
				}
			}
			else
			{
				
			}
	}
}
