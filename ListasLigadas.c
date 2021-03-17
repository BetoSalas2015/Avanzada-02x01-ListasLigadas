#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>			//  Para usar la memoria din�mica

struct Nodo 
{ 
	char info; 
	struct Nodo *sig;
};

typedef struct Nodo nodo;

nodo *raiz = NULL;					// creamos una lista vac�a

void insert(char dato)
{
	nodo *nuevo = NULL;				// creamos un apuntador auxiliar para la nueva area de memoria
	nuevo = (nodo *) malloc( sizeof( nodo ) );		// creamos un nodo nuevo
	if(nuevo == NULL)				// Error: no hay memoria disponible
	{
		printf("No hay memeoria disponible. \n");
		return;						//  Se acab�!!
	}
	nuevo->info = dato;				// Preservamos la informaci�n
	if(raiz == NULL)				// Es el primer nodo de la lista
	{
		raiz = nuevo;				// apuntamos raiz al nuevo nodo creado
		nuevo->sig = NULL;			// Lo volvemos el ultimo nodo de la lista
	}
	else
	{								// No es el primer nodo.

	}
}

int main()
{

	system("pause");
	return 0;
}