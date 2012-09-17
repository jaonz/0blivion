#ifndef OBJECT_H
#define OBJECT_H

#include <allegro5/allegro.h>

/**
 * Estrutura de controle de objeto 
 **/
typedef struct object {

	int x,y,z;
	int width, height, depth;
	ALLEGRO_BITMAP *bmp;

} tObject;

/**
 * Descrição: Criação de novo objeto.
 * Entrada:
 * 		int widgth: Largura do objeto.
 * 		int heigth: Altura do objeto.
 * 		int depth: Profundidade do objeto.
 * 		int x: Posição do objeto no eixo x.
 * 		int y: Posição do objeto no eixo y.
 * 		int z: Posição do objeto no eixo z.
 * Saída:
 * 		tObject *: Ponteiro para tObject
 **/
extern tObject * bomber_object_new(int width, int heigth, int depth, int x, int y, int z);

/**
 * Descrição: Criação de novo objeto a partir de uma imagem bitmap (.bmp)
 * Entrada:
 * 		const char * filename: nome do arquivo a ser importado.
 * 		int x: Posição do objeto no eixo x.
 * 		int y: Posição do objeto no eixo y.
 * 		int z: Posição do objeto no eixo z.
 * Saída:
 * 		tObject *: Ponteiro para tObject
 **/
extern tObject * bomber_object_new_from_bmp(const char *filename, int x, int y, int z);

#endif
