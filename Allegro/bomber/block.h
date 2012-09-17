#ifndef BLOCK_H
#define BLOCK_H

#include "object.h"

/**
 *	Estrutura de controle de blocos destruíveis. 
 **/
typedef struct block
{
	tObject *obj;
	bool destroyed;
	
} tBlock;

/**
 * Descrição: Cria um novo block destruível.
 * Entrada:
 * 		int x: Posição no eixo x.
 * 		int y: Posição no eixo y.
 * 		int z: Posição no eixo z.
 * Saída:
 * 		Ponteiro para tBlock.
 **/
extern tBlock * bomber_block_new(int x, int y, int z);

#endif
