#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>			//  Para usar la memoria dinámica

struct Nodo 
{ 
	int info[100]; 
	struct Nodo *sig;
};




int main()
{
	int a;
	struct Nodo caja;
	//caja.info = 'c';
	printf("el tamaño del struct Nodo es: %d bytes\n", sizeof( struct Nodo ) );
	system("pause");
	return 0;
}