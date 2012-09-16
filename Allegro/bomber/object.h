#ifndef OBJECT_H
#define OBJECT_H

#include <allegro5/allegro.h>

typedef struct object {

	int x,y,z;
	int width, height, prof;
	ALLEGRO_BITMAP *bmp;

} tObject;

extern tObject * bomber_object_new(int width, int heigth, int prof, int x, int y, int z);

#endif
