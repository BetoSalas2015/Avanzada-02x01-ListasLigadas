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
		nodo *ultimo = raiz;		// apuntamos ultimo al primer nodo
		while( ultimo->sig != NULL )	// Repetir MIENTRAS no sea el ultimo nodo
		{
			ultimo = ultimo->sig;
		}
		nuevo -> sig = NULL;		// Volvemos el apuntador nuevo el ultimo nodo
		ultimo->sig = nuevo;

	}
}

void insertn(char dato, int pos)
{
	int cont;
	nodo *nuevo = NULL;				// creamos un apuntador auxiliar para la nueva area de memoria
	nuevo = (nodo *) malloc( sizeof( nodo ) );		// creamos un nodo nuevo
	if(nuevo == NULL)				// Error: no hay memoria disponible
	{
		printf("No hay memeoria disponible. \n");
		return;						//  Se acab�!!
	}
	nuevo->info = dato;				// Preservamos la informaci�n
	if(raiz == NULL)				// Si la lista est� vac�a entonces tendre que insertar en la primera posici�n
	{
		raiz = nuevo;				// apuntamos raiz al nuevo nodo creado
		nuevo->sig = NULL;			// Lo volvemos el ultimo nodo de la lista
		return;						// Se acab�!
	}
	if(pos == 1)				// Lo quiero insertar en la primera posici�n?
	{
		nuevo->sig = raiz;				//  el primero se vuelve el segundo lugar de la lista
		raiz = nuevo;					//  raiz ahora apunta al nuenvo primer nodo
		return;							//  se acab�!
	}
	else							// PAra el resto de los casos...
	{								// No es el primer nodo.
		
		nodo *anterior = raiz;		// apuntamos ultimo al primer nodo
		cont = 1;					// Contamos el primer nodo de la lista
		while( (cont < pos - 1) && (anterior->sig != NULL) )  	// Repetir MIENTRAS no sea el ultimo nodo
		{
			anterior = anterior->sig;
			cont++;
		}
		nuevo -> sig = anterior->sig;		// Volvemos el apuntador nuevo el ultimo nodo
		anterior->sig = nuevo;
		return;							// Se acab�!
	}
}
void insert1(char dato)
{
	nodo *nuevo = NULL;				// creamos un apuntador auxiliar para la nueva area de memoria
	nuevo = (nodo *) malloc( sizeof( nodo ) );		// creamos un nodo nuevo
	if(nuevo == NULL)				// Error: no hay memoria disponible
	{
		printf("No hay memeoria disponible. \n");
		return;						//  Se acab�!!
	}
	nuevo->info = dato;				// Preservamos la informaci�n
	nuevo->sig = raiz;				//  nuevo se coloca en el primer lugar de la lista
	raiz = nuevo;				// apuntamos raiz al nuevo nodo creado
}

char remueve1() {}

char remueve() 
{
	nodo *anterior, *elimina;
	char dato;
	anterior = elimina = raiz;
	if(raiz == NULL)		// No hay nodos en la lista
	{
		printf("No hay nada que elliminar");
		return;				//  Se acab�!
	}
	if(elimina->sig == NULL)
	{
		dato = elimina->info;	//  Preservo el dato del nodo a eliminar
		raiz = NULL;			//  Se vuelve lista vac�a
		free(elimina);			// Liberamos memoria
		return dato;
	}
	elimina = elimina->sig;
	while( elimina->sig != NULL )
	{
		elimina = elimina->sig;		//  avanzo elimina al siguiente nodo
		anterior = anterior->sig;	//  avanzo anterior al siguiente nodo
	}
	dato = elimina->info;	//  Preservo el dato del nodo a eliminar
	anterior->sig = NULL;			//  Se vuelve el ultimo nodo
	free(elimina);			// Liberamos memoria
	return dato;
}

char remueven(int pos) {}

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
	insert('a');
	insert('b');
	remueve();
	insert('c');
	insert('d');
	insert('e');
	imprimeLista();

	remueve();

	imprimeLista();

	system("pause");
	return 0;
}