

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h> //manejo de fonts
#include <allegro5/allegro_ttf.h> //Manejo de ttfs
#include <allegro5/allegro_primitives.h>
#include <unistd.h>

#define FPS		60.0
#define D_WIDTH		1280
#define D_HEIGHT	960

enum MYKEYS {
	KEY_0, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_S, KEY_C, KEY_B //las teclas que nos interesan
};

int main(void)
{
   ALLEGRO_DISPLAY * display = NULL;
   ALLEGRO_FONT * font = NULL;
   ALLEGRO_TIMER *timer = NULL;
   ALLEGRO_EVENT_QUEUE *event_queue = NULL;
   
   bool key_pressed[11] = { false, false, false, false, false, false, false, false, false, false, false }; //Estado de teclas, true cuando esta apretada
   bool do_exit = false; 
   bool redraw = false;
   bool indicador = true;
        
   if(!al_init()){
      fprintf(stderr, "Failed to initialize Allegro.\n");
      return -1;
   }
   
   if(!al_init_primitives_addon()){
	  fprintf(stderr, "failed to initialize primitives!\n");
	  return -1;
   }
   
   al_init_font_addon(); // initialize the font addon
   al_init_ttf_addon();// initialize the ttf (True Type Font) addon
 
   font = al_load_ttf_font("arial.ttf",36,0 ); //HAY CREAR UN FONT PARA CADA TAMAÑO DE LETRA :( 
 
   if (!font){
      fprintf(stderr, "Could not load 'disney.ttf'.\n");
      return -1;
   }
   
   if(!al_install_keyboard()) {
	fprintf(stderr, "failed to initialize the keyboard!\n");
	return -1;
    }
 
    timer = al_create_timer(1.0 / FPS);
    if(!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
    }
    
    event_queue = al_create_event_queue();
    if(!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
                al_destroy_timer(timer);
		return -1;
    }
    
    display = al_create_display(D_WIDTH,D_HEIGHT);
 
    if (!display){
      fprintf(stderr, "Failed to create display.\n");
      al_destroy_timer(timer);
      al_destroy_event_queue(event_queue);
      return -1;
    }
    
    
   al_register_event_source(event_queue, al_get_timer_event_source(timer));
   al_register_event_source(event_queue, al_get_display_event_source(display));
   al_register_event_source(event_queue, al_get_keyboard_event_source()); //REGISTRAMOS EL TECLADO
 
   al_clear_to_color(al_map_rgb(0,0,0));//cargo el buffer de la pantalla con negro
   al_draw_text(font, al_map_rgb(255,255,255), D_WIDTH*1/17, (D_HEIGHT*3/5),ALLEGRO_ALIGN_CENTER, "Led 7");
   al_draw_text(font, al_map_rgb(255,255,255), D_WIDTH*3/17, (D_HEIGHT*3/5),ALLEGRO_ALIGN_CENTER, "Led 6");
   al_draw_text(font, al_map_rgb(255,255,255), D_WIDTH*5/17, (D_HEIGHT*3/5),ALLEGRO_ALIGN_CENTER, "Led 5");
   al_draw_text(font, al_map_rgb(255,255,255), D_WIDTH*7/17, (D_HEIGHT*3/5),ALLEGRO_ALIGN_CENTER, "Led 4");
   al_draw_text(font, al_map_rgb(255,255,255), D_WIDTH*9/17, (D_HEIGHT*3/5),ALLEGRO_ALIGN_CENTER, "Led 3");
   al_draw_text(font, al_map_rgb(255,255,255), D_WIDTH*11/17, (D_HEIGHT*3/5),ALLEGRO_ALIGN_CENTER, "Led 2");
   al_draw_text(font, al_map_rgb(255,255,255), D_WIDTH*13/17, (D_HEIGHT*3/5),ALLEGRO_ALIGN_CENTER, "Led 1");
   al_draw_text(font, al_map_rgb(255,255,255), D_WIDTH*15/17, (D_HEIGHT*3/5),ALLEGRO_ALIGN_CENTER, "Led 0");//escribo todos los nombres de los leds
   al_draw_circle(D_WIDTH*1/17, D_HEIGHT*2/5, 50.0, al_map_rgb(255,255,255) , 5.0 );
   al_draw_circle(D_WIDTH*3/17, D_HEIGHT*2/5, 50.0, al_map_rgb(255,255,255) , 5.0 );
   al_draw_circle(D_WIDTH*5/17, D_HEIGHT*2/5, 50.0, al_map_rgb(255,255,255) , 5.0 );
   al_draw_circle(D_WIDTH*7/17, D_HEIGHT*2/5, 50.0, al_map_rgb(255,255,255) , 5.0 );
   al_draw_circle(D_WIDTH*9/17, D_HEIGHT*2/5, 50.0, al_map_rgb(255,255,255) , 5.0 );
   al_draw_circle(D_WIDTH*11/17, D_HEIGHT*2/5, 50.0, al_map_rgb(255,255,255) , 5.0 );
   al_draw_circle(D_WIDTH*13/17, D_HEIGHT*2/5, 50.0, al_map_rgb(255,255,255) , 5.0 );
   al_draw_circle(D_WIDTH*15/17, D_HEIGHT*2/5, 50.0, al_map_rgb(255,255,255) , 5.0 );//creo el contorno de los leds
   al_flip_display();
   
   al_start_timer(timer);
   
   while(!do_exit)
	{
		ALLEGRO_EVENT ev;
		if( al_get_next_event(event_queue, &ev) ) //Toma un evento de la cola.
		{ 
                    
                    	if(ev.type == ALLEGRO_EVENT_TIMER) 
			{
				if(key_pressed[KEY_0])      //vemos si la tecla esta presionada (viendo si esta en true)
                                    al_draw_filled_circle(D_WIDTH*15/17, D_HEIGHT*2/5, 47.5, al_map_rgb(255,255,0));//los numeros llenan de amarillo en caso de estar presionados, y de negro en caso de no estarlo
                                else
                                    al_draw_filled_circle(D_WIDTH*15/17, D_HEIGHT*2/5, 47.5, al_map_rgb(0,0,0));
                                
				if(key_pressed[KEY_1]) 
                                    al_draw_filled_circle(D_WIDTH*13/17, D_HEIGHT*2/5, 47.5, al_map_rgb(255,255,0));
                                else
                                    al_draw_filled_circle(D_WIDTH*13/17, D_HEIGHT*2/5, 47.5, al_map_rgb(0,0,0));
                                
				if(key_pressed[KEY_2]) 
                                    al_draw_filled_circle(D_WIDTH*11/17, D_HEIGHT*2/5, 47.5, al_map_rgb(255,255,0));
                                else
                                    al_draw_filled_circle(D_WIDTH*11/17, D_HEIGHT*2/5, 47.5, al_map_rgb(0,0,0));
                                
				if(key_pressed[KEY_3]) 
                                    al_draw_filled_circle(D_WIDTH*9/17, D_HEIGHT*2/5, 47.5, al_map_rgb(255,255,0));
                                else
                                    al_draw_filled_circle(D_WIDTH*9/17, D_HEIGHT*2/5, 47.5, al_map_rgb(0,0,0));
                                
                                if(key_pressed[KEY_4])     
                                    al_draw_filled_circle(D_WIDTH*7/17, D_HEIGHT*2/5, 47.5, al_map_rgb(255,255,0));
                                else
                                    al_draw_filled_circle(D_WIDTH*7/17, D_HEIGHT*2/5, 47.5, al_map_rgb(0,0,0));
                                
				if(key_pressed[KEY_5]) 
                                    al_draw_filled_circle(D_WIDTH*5/17, D_HEIGHT*2/5, 47.5, al_map_rgb(255,255,0));
                                else
                                    al_draw_filled_circle(D_WIDTH*5/17, D_HEIGHT*2/5, 47.5, al_map_rgb(0,0,0));
                                
				if(key_pressed[KEY_6]) 
                                    al_draw_filled_circle(D_WIDTH*3/17, D_HEIGHT*2/5, 47.5, al_map_rgb(255,255,0));
                                else
                                    al_draw_filled_circle(D_WIDTH*3/17, D_HEIGHT*2/5, 47.5, al_map_rgb(0,0,0));
                                
				if(key_pressed[KEY_7]) 
                                    al_draw_filled_circle(D_WIDTH*1/17, D_HEIGHT*2/5, 47.5, al_map_rgb(255,255,0));
                                else
                                    al_draw_filled_circle(D_WIDTH*1/17, D_HEIGHT*2/5, 47.5, al_map_rgb(0,0,0));
                                
                                if(key_pressed[KEY_C])//tocar la tecla c es equivalente a haber tocado todas las teclas
                                {
                                    key_pressed[KEY_0] = true;
                                    key_pressed[KEY_1] = true;
                                    key_pressed[KEY_2] = true;
                                    key_pressed[KEY_3] = true;
                                    key_pressed[KEY_4] = true;
                                    key_pressed[KEY_5] = true;
                                    key_pressed[KEY_6] = true;
                                    key_pressed[KEY_7] = true;
                                    key_pressed[KEY_C] = false;
                                }
                                
                                if(key_pressed[KEY_S])//El casp de s es como el de c, solo que suelta todas las teclas, las "des-presiona"
                                {
                                    key_pressed[KEY_0] = false;
                                    key_pressed[KEY_1] = false;
                                    key_pressed[KEY_2] = false;
                                    key_pressed[KEY_3] = false;
                                    key_pressed[KEY_4] = false;
                                    key_pressed[KEY_5] = false;
                                    key_pressed[KEY_6] = false;
                                    key_pressed[KEY_7] = false;
                                    key_pressed[KEY_S] = false;
                                }
                                
                                if(key_pressed[KEY_B])
                                {
                                     al_flip_display();
                                     sleep(0.9);
                                     al_draw_filled_circle(D_WIDTH*1/17, D_HEIGHT*2/5, 47.5, al_map_rgb(0,0,0));
                                     al_draw_filled_circle(D_WIDTH*3/17, D_HEIGHT*2/5, 47.5, al_map_rgb(0,0,0));
                                     al_draw_filled_circle(D_WIDTH*5/17, D_HEIGHT*2/5, 47.5, al_map_rgb(0,0,0));
                                     al_draw_filled_circle(D_WIDTH*7/17, D_HEIGHT*2/5, 47.5, al_map_rgb(0,0,0));
                                     al_draw_filled_circle(D_WIDTH*9/17, D_HEIGHT*2/5, 47.5, al_map_rgb(0,0,0));
                                     al_draw_filled_circle(D_WIDTH*11/17, D_HEIGHT*2/5, 47.5, al_map_rgb(0,0,0));
                                     al_draw_filled_circle(D_WIDTH*13/17, D_HEIGHT*2/5, 47.5, al_map_rgb(0,0,0));
                                     al_draw_filled_circle(D_WIDTH*15/17, D_HEIGHT*2/5, 47.5, al_map_rgb(0,0,0));
                                     al_flip_display();//primero muestro el display prendido de acuerdo a los flags, luego cargo en el buffer la imagen de todos los leds apagados
                                     sleep(0.9);//asi el usuario ve el cambio a negro del parpadeo, pero en la parte legica del programa no se cambio nada,tecnicamente sigue como antes
                                     
                                }
                                
				redraw = true;
			}
			
			else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) 
				do_exit = true;

			else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) //cuando tenemos presionada una tecla
			{      
				switch(ev.keyboard.keycode){
					case ALLEGRO_KEY_0:         //tiene presionado del 0 al 7, con el c, el s y el b, en cada una de las ALLEGRO KEYS  
                                                key_pressed[KEY_0] = (indicador!=key_pressed[KEY_0]);//presionar un numero hace una comparacion donde prueba que es diferente a verdadero su estado, asi se prende y apaga
                                                key_pressed[KEY_B] = false;//todas las teclas apagan b,asi es como se sale del loop del blink
						break;

					case ALLEGRO_KEY_1:
						key_pressed[KEY_1] = (indicador!=key_pressed[KEY_1]);
                                                key_pressed[KEY_B] = false;
						break;

					case ALLEGRO_KEY_2:         
						key_pressed[KEY_2] = (indicador!=key_pressed[KEY_2]);
                                                key_pressed[KEY_B] = false;
						break;

					case ALLEGRO_KEY_3:
						key_pressed[KEY_3] = (indicador!=key_pressed[KEY_3]);
                                                key_pressed[KEY_B] = false;
						break;
                                        case ALLEGRO_KEY_4:         
						key_pressed[KEY_4] = (indicador!=key_pressed[KEY_4]);
                                                key_pressed[KEY_B] = false;
						break;

					case ALLEGRO_KEY_5:
						key_pressed[KEY_5] = (indicador!=key_pressed[KEY_5]);
                                                key_pressed[KEY_B] = false;
						break;

					case ALLEGRO_KEY_6:         
						key_pressed[KEY_6] = (indicador!=key_pressed[KEY_6]);
                                                key_pressed[KEY_B] = false;
						break;

					case ALLEGRO_KEY_7:
						key_pressed[KEY_7] = (indicador!=key_pressed[KEY_7]);
                                                key_pressed[KEY_B] = false;
						break;                      //hasta aca modificamos  el estado de las teclas segun esten presionadas
                                                
                                        case ALLEGRO_KEY_S:         
                                                key_pressed[KEY_S] = true;//las teclas s, c y b no hacen la misma comparacion porque se apagan de otra manera
                                                key_pressed[KEY_B] = false;
                                                break;
                                                
                                        case ALLEGRO_KEY_C:         
                                                key_pressed[KEY_C] = true;
                                                key_pressed[KEY_B] = false;
                                                break;
                                                
                                        case ALLEGRO_KEY_B:         
                                                key_pressed[KEY_B] = true;
                                                break;
				}
			}


			
		}
 
		if(redraw && al_is_event_queue_empty(event_queue)) //con esto damos la directiva de que muestre lo que dibujo el biffer despues de comprobar el estado de las letras
		{  
			redraw = false;
			
                        al_flip_display();
		}
	}
   
   
   al_destroy_display(display);
   
   return 0;
}


