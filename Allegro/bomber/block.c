#include "block.h"

tBlock * bomber_block_new(int x, int y, int z)
{
	tBlock *b1 = malloc(sizeof(tBlock));
	b1->obj = bomber_object_new_from_bmp("images/block.bmp",x,y,z);
	return b1;
}
