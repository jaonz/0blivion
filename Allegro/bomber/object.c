#include "object.h"

#include <stdio.h>

tObject * bomber_object_new(int width, int height, int depth, int x, int y, int z)
{

	tObject * obj = malloc(sizeof(tObject));
	obj->x = x;
	obj->y = y;
	obj->z = z;
	//
	obj->width=width;
	obj->height=height;
	obj->depth = depth;
	//
	obj->bmp=NULL;

	return obj;	

}

tObject * bomber_object_new_from_bmp(const char *filename, int x, int y, int z)
{
	tObject * obj = malloc(sizeof(tObject));
	obj->x = x;
	obj->y = y;
	obj->z = z;
	//
	obj->bmp = al_load_bitmap(filename);
	if (!obj->bmp)
	{
		printf("Error: Não foi possível carregar a imagem \"%s\"",filename);
	}
	return obj;
}
