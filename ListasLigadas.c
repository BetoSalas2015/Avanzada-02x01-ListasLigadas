#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>			//  Para usar la memoria dinámica

struct Nodo 
{ 
	char info; 
	struct Nodo *sig;
};

typedef struct Nodo nodo;


int main()
{
	int a;
	nodo caja;
	caja.info = 'c';
	printf("el tamaño del struct Nodo es: %d bytes\n", sizeof( struct Nodo ) );
	system("pause");
	return 0;
}