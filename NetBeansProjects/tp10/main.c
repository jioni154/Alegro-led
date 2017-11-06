

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h> //manejo de fonts
#include <allegro5/allegro_ttf.h> //Manejo de ttfs
#include <allegro5/allegro_primitives.h>

#define D_WIDTH		1280
#define D_HEIGHT	960


int main(void)
{
   ALLEGRO_DISPLAY * display = NULL;
   ALLEGRO_FONT * font = NULL;
   
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
 
   display = al_create_display(D_WIDTH,D_HEIGHT);
 
   if (!display){
      fprintf(stderr, "Failed to create display.\n");
      return -1;
   }
 
   font = al_load_ttf_font("arial.ttf",36,0 ); //HAY CREAR UN FONT PARA CADA TAMAÑO DE LETRA :( 
 
   if (!font){
      fprintf(stderr, "Could not load 'disney.ttf'.\n");
      return -1;
   }
 
   al_clear_to_color(al_map_rgb(0,0,0));
   al_draw_text(font, al_map_rgb(255,255,255), D_WIDTH*1/17, (D_HEIGHT*3/5),ALLEGRO_ALIGN_CENTER, "Led 7");
   al_draw_text(font, al_map_rgb(255,255,255), D_WIDTH*3/17, (D_HEIGHT*3/5),ALLEGRO_ALIGN_CENTER, "Led 6");
   al_draw_text(font, al_map_rgb(255,255,255), D_WIDTH*5/17, (D_HEIGHT*3/5),ALLEGRO_ALIGN_CENTER, "Led 5");
   al_draw_text(font, al_map_rgb(255,255,255), D_WIDTH*7/17, (D_HEIGHT*3/5),ALLEGRO_ALIGN_CENTER, "Led 4");
   al_draw_text(font, al_map_rgb(255,255,255), D_WIDTH*9/17, (D_HEIGHT*3/5),ALLEGRO_ALIGN_CENTER, "Led 3");
   al_draw_text(font, al_map_rgb(255,255,255), D_WIDTH*11/17, (D_HEIGHT*3/5),ALLEGRO_ALIGN_CENTER, "Led 2");
   al_draw_text(font, al_map_rgb(255,255,255), D_WIDTH*13/17, (D_HEIGHT*3/5),ALLEGRO_ALIGN_CENTER, "Led 1");
   al_draw_text(font, al_map_rgb(255,255,255), D_WIDTH*15/17, (D_HEIGHT*3/5),ALLEGRO_ALIGN_CENTER, "Led 0");
   al_draw_circle(D_WIDTH*1/17, D_HEIGHT*2/5, 50.0, al_map_rgb(255,255,255) , 5.0 );
   al_draw_circle(D_WIDTH*3/17, D_HEIGHT*2/5, 50.0, al_map_rgb(255,255,255) , 5.0 );
   al_draw_circle(D_WIDTH*5/17, D_HEIGHT*2/5, 50.0, al_map_rgb(255,255,255) , 5.0 );
   al_draw_circle(D_WIDTH*7/17, D_HEIGHT*2/5, 50.0, al_map_rgb(255,255,255) , 5.0 );
   al_draw_circle(D_WIDTH*9/17, D_HEIGHT*2/5, 50.0, al_map_rgb(255,255,255) , 5.0 );
   al_draw_circle(D_WIDTH*11/17, D_HEIGHT*2/5, 50.0, al_map_rgb(255,255,255) , 5.0 );
   al_draw_circle(D_WIDTH*13/17, D_HEIGHT*2/5, 50.0, al_map_rgb(255,255,255) , 5.0 );
   al_draw_circle(D_WIDTH*15/17, D_HEIGHT*2/5, 50.0, al_map_rgb(255,255,255) , 5.0 );
   
   
   al_draw_filled_circle(D_WIDTH*1/17, D_HEIGHT*2/5, 47.5, al_map_rgb(255,255,0));
   
   
   al_flip_display();
   al_rest(5.0);
   al_draw_filled_circle(D_WIDTH*1/17, D_HEIGHT*2/5, 47.5, al_map_rgb(0,0,0));
   
   al_flip_display();
   al_rest(5.0);
 
   al_destroy_display(display);
   
   return 0;
}


