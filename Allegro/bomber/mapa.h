#ifndef MAPA_H
#define MAPA_H

#define MAPA_LARGURA 640
#define MAPA_ALTURA 480

#include "object.h"
#include "block.h"

/**
 * Matriz de objetos do jogo 
 * 
 **/
extern tObject * mapa[MAPA_LARGURA][MAPA_ALTURA];

/**
 * Inicia o mapa gerando os blocos.
 **/
extern void bomber_mapa_init();

/**
 * Desenha o mapa na superfície.
 **/
extern void bomber_mapa_draw();

/**
 * Destrói o mapa junto de seus elementos. 
 **/
extern void bomber_mapa_destroy();

#endif
