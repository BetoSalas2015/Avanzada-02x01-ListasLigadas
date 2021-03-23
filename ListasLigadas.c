#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>			//  Para usar la memoria dinámica

struct Nodo 
{ 
	char info; 
	struct Nodo *sig;
};

typedef struct Nodo nodo;

nodo *raiz = NULL;					// creamos una lista vacía

void insert(char dato)
{
	nodo *nuevo = NULL;				// creamos un apuntador auxiliar para la nueva area de memoria
	nuevo = (nodo *) malloc( sizeof( nodo ) );		// creamos un nodo nuevo
	if(nuevo == NULL)				// Error: no hay memoria disponible
	{
		printf("No hay memeoria disponible. \n");
		return;						//  Se acabó!!
	}
	nuevo->info = dato;				// Preservamos la información
	if(raiz == NULL)				// Es el primer nodo de la lista
	{
		raiz = nuevo;				// apuntamos raiz al nuevo nodo creado
		nuevo->sig = NULL;			// Lo volvemos el ultimo nodo de la lista
	}
	else
	{								// No es el primer nodo.
		nodo *ultimo = raiz;		// apuntamos ultimo al primer nodo
		while( ultimo->sig != NULL )	// Repetir MIENTRAS no sea el ultimo nodo
		{
			ultimo = ultimo->sig;
		}
		nuevo -> sig = NULL;		// Volvemos el apuntador nuevo el ultimo nodo
		ultimo->sig = nuevo;

	}
}

void insertn(char dato, int posicion)
{
	nodo *nuevo = NULL;				// creamos un apuntador auxiliar para la nueva area de memoria
	nuevo = (nodo *) malloc( sizeof( nodo ) );		// creamos un nodo nuevo
	if(nuevo == NULL)				// Error: no hay memoria disponible
	{
		printf("No hay memeoria disponible. \n");
		return;						//  Se acabó!!
	}
	nuevo->info = dato;				// Preservamos la información
	if(raiz == NULL)				// Es el primer nodo de la lista
	{
		raiz = nuevo;				// apuntamos raiz al nuevo nodo creado
		nuevo->sig = NULL;			// Lo volvemos el ultimo nodo de la lista
	}
	else
	{								// No es el primer nodo.
		nodo *ultimo = raiz;		// apuntamos ultimo al primer nodo
		while( ultimo->sig != NULL )	// Repetir MIENTRAS no sea el ultimo nodo
		{
			ultimo = ultimo->sig;
		}
		nuevo -> sig = NULL;		// Volvemos el apuntador nuevo el ultimo nodo
		ultimo->sig = nuevo;

	}
}
void insert1(char dato)
{
	nodo *nuevo = NULL;				// creamos un apuntador auxiliar para la nueva area de memoria
	nuevo = (nodo *) malloc( sizeof( nodo ) );		// creamos un nodo nuevo
	if(nuevo == NULL)				// Error: no hay memoria disponible
	{
		printf("No hay memeoria disponible. \n");
		return;						//  Se acabó!!
	}
	nuevo->info = dato;				// Preservamos la información
	nuevo->sig = raiz;				//  nuevo se coloca en el primer lugar de la lista
	raiz = nuevo;				// apuntamos raiz al nuevo nodo creado
}

void imprimeLista()
{
	nodo *recorre = raiz;		// apuntamos ultimo al primer nodo
	while( !recorre == NULL )	// Repetir MIENTRAS no sea null
	{
		printf("%c, ", recorre->info);
		recorre = recorre->sig;
	}
	printf("\n");
}


int main()
{
	insert1('a');
	insert1('b');
	insert1('c');
	insert1('d');
	insert1('e');

	imprimeLista();

	system("pause");
	return 0;
}