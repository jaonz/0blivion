#include <stdio.h>
#include <allegro5/allegro.h>
 
const float FPS = 60;
const int SCREEN_W = 640;
const int SCREEN_H = 480;
const int TAP_HEIGHT = 150;
const int TAP_WIDTH = 10;
const int BOUNCE_SIZE = 30;

enum MYKEYS {
	KEY_W, KEY_S, KEY_UP, KEY_DOWN, KEY_ENTER, KEY_P
};
 
int main(int argc, char **argv)
{
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *tapl = NULL;
	ALLEGRO_BITMAP *tapr = NULL;
	ALLEGRO_BITMAP *bounce = NULL;
	float tapl_x = 0.0;
	float tapl_y = SCREEN_H / 2.0 - TAP_HEIGHT / 2.0;
	float tapr_x = SCREEN_W - TAP_WIDTH - 1.0;
	float tapr_y = SCREEN_H / 2.0 - TAP_HEIGHT / 2.0;
	float bounce_x = SCREEN_W / 2.0 - BOUNCE_SIZE / 2.0;
	float bounce_y = SCREEN_H / 2.0 - BOUNCE_SIZE / 2.0;
	float bounce_dx = -4.0, bounce_dy = 4.0;  
	bool key[6] = { false, false, false, false, false, false };
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

	display = al_create_display(SCREEN_W, SCREEN_H); //criando o display

	tapl = al_create_bitmap(TAP_WIDTH, TAP_HEIGHT); //criando o rebatedor esquerdo (vermelho)

	tapr = al_create_bitmap(TAP_WIDTH, TAP_HEIGHT); //criando o rebatedor direito (azul)

	bounce = al_create_bitmap(BOUNCE_SIZE, BOUNCE_SIZE); //criando a bounce (branco)

	//setando cores dos bitmaps
	al_set_target_bitmap(tapl); //setando o target pro rebatedor esquerdo

	al_clear_to_color(al_map_rgb(255, 0, 0)); //setando a cor do target (rebatedor esquerdo)

	al_set_target_bitmap(tapr); //setando o target pro rebatedor direito

	al_clear_to_color(al_map_rgb(0, 0, 255)); //setando a cor do target (rebatedor direito)

	al_set_target_bitmap(bounce); //setando o target pra bounce

	al_clear_to_color(al_map_rgb(255, 255, 255)); //setando a cor do target

	al_set_target_bitmap(al_get_backbuffer(display)); //setando o target pro display


	event_queue = al_create_event_queue(); //iniciando o leitor de eventos

	al_register_event_source(event_queue, al_get_display_event_source(display)); //registrando os eventos do display

	al_register_event_source(event_queue, al_get_timer_event_source(timer)); //registrando os eventos do temporizador

	al_register_event_source(event_queue, al_get_keyboard_event_source()); //registrando os eventos do teclado

	al_clear_to_color(al_map_rgb(0,0,0)); 

	al_flip_display();

	al_start_timer(timer);
	 
	while(!doexit) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);		
		
		if(key[KEY_ENTER]) {
			redraw = true;
		}
		
		if(key[KEY_P]) {
			redraw = false;
		}
		
		if(ev.type == ALLEGRO_EVENT_TIMER) {
			if(redraw == true){
				if(
					bounce_x - bounce_dx < tapl_x + (TAP_WIDTH + 14.0)&&
					bounce_x + bounce_dx > tapl_x - TAP_WIDTH &&
					bounce_y - bounce_dy < tapl_y + TAP_HEIGHT &&
					bounce_y + bounce_dy > tapl_y - TAP_HEIGHT 
					) 
				{

					bounce_dx = bounce_dx + 1;

				}
			
				if(
					bounce_x - bounce_dx < tapr_x + (TAP_WIDTH + 0.0)&&
					bounce_x + bounce_dx > tapr_x - (TAP_WIDTH + 15.0)&&
					bounce_y - bounce_dy < tapr_y + TAP_HEIGHT &&
					bounce_y + bounce_dy > tapr_y - TAP_HEIGHT 
					)
				{

					bounce_dx -= 11;

				}
			
				if(bounce_x < 0) { 
					al_destroy_timer(timer);

				}
			
				if(bounce_x > SCREEN_W - BOUNCE_SIZE) {
					al_destroy_timer(timer);      	 

				}
			
				if(bounce_y < 0 || bounce_y > SCREEN_H - BOUNCE_SIZE) { //aqui rebate normal no eixo da altura
					bounce_dy = -bounce_dy;
				}

				bounce_x += bounce_dx;
				bounce_y += bounce_dy;
			
				if(key[KEY_W] && tapl_y >= 4.0) {
					tapl_y -= 4.0;
				}

				if(key[KEY_S] && tapl_y <= SCREEN_H - TAP_HEIGHT - 4.0) {
					tapl_y += 4.0;
				}

				if(key[KEY_UP] && tapr_y >= 4.0) {
					tapr_y -= 4.0;
				}
			
				if(key[KEY_DOWN] && tapr_y <= SCREEN_H - TAP_HEIGHT - 4.0) {
					tapr_y += 4.0;
				}
			

			}
		
		}
		
		else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		
		else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch(ev.keyboard.keycode) {
			case ALLEGRO_KEY_W:
			key[KEY_W] = true;
			break;

			case ALLEGRO_KEY_S:
			key[KEY_S] = true;
			break;

			case ALLEGRO_KEY_UP:
			key[KEY_UP] = true;
			break;

			case ALLEGRO_KEY_DOWN:
			key[KEY_DOWN] = true;
			break;
			
			case ALLEGRO_KEY_P:
			key[KEY_ENTER] = false;
			key[KEY_P] = true;
			break;
			
			case ALLEGRO_KEY_ENTER:
			key[KEY_P] = false;
			key[KEY_ENTER] = true;
			break;
			
			}			
		}
		
		else if(ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch(ev.keyboard.keycode) {
			case ALLEGRO_KEY_W:
			key[KEY_W] = false;
			break;

			case ALLEGRO_KEY_S:
			key[KEY_S] = false;
			break;

			case ALLEGRO_KEY_UP: 
			key[KEY_UP] = false;
			break;

			case ALLEGRO_KEY_DOWN:
			key[KEY_DOWN] = false;
			break;
			
			case ALLEGRO_KEY_ESCAPE:
			doexit = true;
			break;

			}	
		}		
		
		if(redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			al_clear_to_color(al_map_rgb(0,0,0));

			al_draw_bitmap(tapl, tapl_x, tapl_y, 0);
		 
			al_draw_bitmap(tapr, tapr_x, tapr_y, 0);
		 
			al_draw_bitmap(bounce, bounce_x, bounce_y, 0);
		  
			al_flip_display();
		}

   }
 
   
   al_destroy_bitmap(tapl);
   al_destroy_bitmap(tapr);
   al_destroy_bitmap(bounce);
   al_destroy_timer(timer);
   al_destroy_display(display);
   al_destroy_event_queue(event_queue);
   
   return 0;
}
