#include "mapa.h"

#include <stdio.h>

/**
 * Matriz de objetos do jogo 
 * 
 **/
tObject * mapa[MAPA_LARGURA][MAPA_ALTURA];

void bomber_mapa_init()
{

}

void bomber_mapa_draw()
{
	int x,y;
	for(x=0;x<MAPA_LARGURA;x++)
	{
		for(y=0;y<MAPA_ALTURA;y++)
		{
			if(mapa[x][y]) //verifica se não é nulo.
			; //TODO função de desenho genérico -> jaonz
		}
	}
	
}

void bomber_mapa_destroy()
{
	int x,y;
	for(x=0;x<MAPA_LARGURA;x++)
	{
		for(y=0;y<MAPA_ALTURA;y++)
		{
			if(mapa[x][y]) //verifica se não é nulo.
			{
				if(mapa[x][y]->bmp)
					al_destroy_bitmap(mapa[x][y]->bmp);
				free(mapa[x][y]);
			}
		}
	}
}
