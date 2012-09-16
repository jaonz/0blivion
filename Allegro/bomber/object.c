#include "object.h"

tObject * bomber_object_new(int width, int height, int prof, int x, int y, int z)
{

	tObject * obj = malloc(sizeof(tObject));
	obj->x = x;
	obj->y = y;
	obj->z = z;
	//
	obj->width=width;
	obj->height=height;
	obj->prof = prof;
	//
	obj->bmp=NULL;

	return obj;	

}
