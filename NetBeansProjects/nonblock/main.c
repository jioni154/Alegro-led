#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // usleep
#include "nonblock.h"
#include "termlib.h"
#include "parameters.h"


#define T_MAX 300
#define NUM_INI 99


#ifdef _WIN32
   #error "This program is only targeted at Linux systems"
#endif

int main(void) 
{
	timecount=0;		//creamos un contador que lleve el tiempo
	gsnum=NUM_INI;		//le asignamos un numero de inicializacion al 'guess number' tal que no tenga problemas al ejecutar por primera vez el while
	get_random_num(&rnum);
        printf("elija un numero entre el 1 y el 10\n");
	nonblock(NB_ENABLE);
	
    while(gsnum!=rnum)//asi se comprueba que la respuesta y lo que adivina el usuario sea distinto, para que pueda seguir probando
    {
	printf("Quedan %d segundos\n", T_MAX-timecount);        
	if (kbhit())//si se presiona una tecla, se comprueba que fue, y que sea la correcta
		{
			c=getch();
                        if(c<'9'&&c>'0')
			{gsnum=(c-'0');
			printf("numero elegido=%d\n",gsnum);
			if(gsnum==rnum)
			printf("Ganador!\n");
			else
			printf("incorrecto, intente de nuevo\n");
                        }
                        else
                          printf("input invalido\n");
        }

	timecount++;	//el tiempo avanza
	sleep(1);
	if(timecount==T_MAX)//esto seria la comprobacion del tiempo limite
	{
		printf("Perdiste..\n");	
		break;
	}
    }
    printf("El numero era %d\n", rnum);
    nonblock(NB_DISABLE);

    return 0;
}


