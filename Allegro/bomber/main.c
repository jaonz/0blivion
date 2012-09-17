
#include <stdio.h>
#include <allegro5/allegro.h>

#include "mapa.h"
#include "settings.h"
#include "object.h"

enum MYKEYS {
	KEY_W, KEY_S, KEY_UP, KEY_DOWN, KEY_ENTER, KEY_P
};

int main(int argc, char **argv)
{

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;

	bool redraw = true;
	bool doexit = false;

	if(!al_init()) { //iniciando o allegro
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}

	if(!al_install_keyboard()) { //instalando o teclado
		fprintf(stderr, "failed to initialize the keyboard!\n");
		return -1;
	}

	timer = al_create_timer(1.0 / FPS); //criando temporizador (FPS)

	display = al_create_display(MAPA_LARGURA, MAPA_ALTURA); //criando o display


	al_set_target_bitmap(al_get_backbuffer(display)); //setando o target pro display


	event_queue = al_create_event_queue(); //iniciando o leitor de eventos

	al_register_event_source(event_queue, al_get_display_event_source(display)); //registrando os eventos do display

	al_register_event_source(event_queue, al_get_timer_event_source(timer)); //registrando os eventos do temporizador

	al_register_event_source(event_queue, al_get_keyboard_event_source()); //registrando os eventos do teclado

	al_clear_to_color(al_map_rgb(0,0,0)); 

	al_flip_display();

	al_start_timer(timer);
	 
	//inicia o mapa
	bomber_mapa_init();
	 
	while(!doexit) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if(ev.type == ALLEGRO_EVENT_TIMER) {
			if(redraw == true){
				//TODO update objects
			}
		}
		else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			doexit=true; //redundante?
			break;
		}
		
		else if(ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch(ev.keyboard.keycode) {	
				case ALLEGRO_KEY_ESCAPE:
					doexit = true;
					break;
			}	
		}

		if(redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;
			
			bomber_mapa_draw(); //desenha o mapa
			
			al_flip_display();
		}

	}
	
	bomber_mapa_destroy(); //destrói o mapa junto de seus objetos.
	
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

return 0;
}
