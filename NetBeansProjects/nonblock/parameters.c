#include "parameters.h"
#include <stdlib.h>
#include <time.h>


void get_random_num(int *num)
{
	srand(time(NULL));	//inicializamos 'la semilla' 
	(*num)=rand()%10+1;	//creamos un numero aleatorio entre el 1 y el 10
}