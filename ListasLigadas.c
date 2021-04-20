#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>			//  Para usar la memoria dinámica

struct Nodo 
{ 
	char info; // 1b
	struct Nodo *sig;  // 4b
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
void insertn(char dato, int pos)
{
	int cont;
	nodo *nuevo = NULL;				// creamos un apuntador auxiliar para la nueva area de memoria
	nuevo = (nodo *) malloc( sizeof( nodo ) );		// creamos un nodo nuevo
	if(nuevo == NULL)				// Error: no hay memoria disponible
	{
		printf("No hay memeoria disponible. \n");
		return;						//  Se acabó!!
	}
	nuevo->info = dato;				// Preservamos la información
	if(raiz == NULL)				// Si la lista está vacía entonces tendre que insertar en la primera posición
	{
		raiz = nuevo;				// apuntamos raiz al nuevo nodo creado
		nuevo->sig = NULL;			// Lo volvemos el ultimo nodo de la lista
		return;						// Se acabó!
	}
	if(pos == 1)				// Lo quiero insertar en la primera posición?
	{
		nuevo->sig = raiz;				//  el primero se vuelve el segundo lugar de la lista
		raiz = nuevo;					//  raiz ahora apunta al nuenvo primer nodo
		return;							//  se acabó!
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
		return;							// Se acabó!
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

char remueve1() 
{
	nodo *elimina;
	char dato;
	elimina = raiz;
	if(raiz == NULL)		// No hay nodos en la lista
	{
		printf("No hay nada que elliminar");
		return dato;				//  Se acabó!
	}
	dato = elimina->info;	//  Preservo el dato del nodo a eliminar
	raiz = raiz->sig;		//  Se saca de la lista el nodo a liminar
	free(elimina);			// Liberamos memoria
	return dato;
}

char remueve() 
{
	nodo *anterior, *elimina;
	char dato = '\0';
	anterior = elimina = raiz;
	if(raiz == NULL)		// No hay nodos en la lista
	{
		printf("No hay nada que elliminar");
		return dato;				//  Se acabó!
	}
	if(elimina->sig == NULL)
	{
		dato = elimina->info;	//  Preservo el dato del nodo a eliminar
		raiz = raiz->sig;			//  Se vuelve lista vacía
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

char remueven(int pos) 
{
	nodo *anterior, *elimina;
	int cont;
	char dato = '\0';
	anterior = elimina = raiz;
	if(raiz == NULL)		// No hay nodos en la lista
	{
		printf("No hay nada que elliminar");
		return dato;				//  Se acabó!
	}
	if(pos == 1)
	{
		dato = elimina->info;	//  Preservo el dato del nodo a eliminar
		raiz = raiz->sig;			//  Se vuelve lista vacía
		free(elimina);			// Liberamos memoria
		return dato;
	}
	elimina = elimina->sig;		//  Posiciono elimina en el segundo nodo 
	cont = 2;
	while( elimina->sig != NULL && cont != pos )
	{
		elimina = elimina->sig;		//  avanzo elimina al siguiente nodo
		anterior = anterior->sig;	//  avanzo anterior al siguiente nodo
		cont++;
	}
	dato = elimina->info;	//  Preservo el dato del nodo a eliminar
	anterior->sig = elimina->sig;			//  Se vuelve el ultimo nodo
	free(elimina);			// Liberamos memoria
	return dato;
}

void imprimeLista(nodo *raiz)
{
	nodo *recorre = raiz;		// apuntamos ultimo al primer nodo
	while( !recorre == NULL )	// Repetir MIENTRAS no sea null
	{
		printf("%c, ", recorre->info);
		recorre = recorre->sig;
	}
	printf("\n");
}

void invierte(nodo *raiz) 
{
	nodo *raiz2 = NULL;
	// 1. recorre la lista 1
	nodo *recorre = raiz;		// apuntamos ultimo al primer nodo
	while( !recorre == NULL )	// Repetir MIENTRAS no sea null
	{
		nodo *nuevo = NULL;				// creamos un apuntador auxiliar para la nueva area de memoria
		nuevo = (nodo *) malloc( sizeof( nodo ) );		// creamos un nodo nuevo
		nuevo->info = recorre->info;				// 3. Copia el contenido.
		// 2. Creamos el nodo en la lista2 delante de raiz
		nuevo->sig = raiz2;				//  nuevo se coloca en el primer lugar de la lista
		raiz2 = nuevo;				// apuntamos raiz al nuevo nodo creado
		recorre = recorre->sig;
	}
	imprimeLista(raiz2);
}

void concat(nodo *raiz1, nodo *raiz2) 
{
	nodo *raiz3 = NULL;			// Necesitamos una tercera lista donde guardar la concatenación
	nodo *nuevo;				//  Apuntador para sostener el nuevo nodo
	nodo *ultimo = raiz3;		// Nos posicionamos en el ultimo nodo de la lista3 (no existe ahorita)
	//  1 Ciclo que recorre la lista 1
	nodo *recorre = raiz1;		// apuntamos ultimo al primer nodo de lista 1		
	while( !recorre == NULL )	// Repetir MIENTRAS no sea null en la lista 1
	{
		if(raiz1 == NULL)				// Hay nodo que copiar?
		{
			break;						//  No. continua al sigueite ciclo
		}
		//agregar el if aqui
		nuevo = (nodo *) malloc( sizeof( nodo ) );		// creamos un nodo nuevo
		nuevo -> sig = NULL;		// Volvemos el apuntador nuevo el ultimo nodo
		ultimo->sig = nuevo;		// El ultimo nodo se vuelve el penultimo
		ultimo = ultimo->sig;		// Ultimo se dirige al ultimo nodo
		recorre = recorre->sig;		// avanzamos al siguiente nodo a copiar
	}	
	// 2. Ciclo que recorre la lista2
	recorre = raiz2;		// apuntamos ultimo al primer nodo
	while( !recorre == NULL )	// Repetir MIENTRAS no sea null
	{
		if(raiz1 == NULL)				// Hay nodo que copiar
		{
			return;						//  No, se acabó!
		}
		nuevo = (nodo *) malloc( sizeof( nodo ) );		// creamos un nodo nuevo
		nuevo -> sig = NULL;		// Volvemos el apuntador nuevo el ultimo nodo
		ultimo->sig = nuevo;		// El ultimo nodo se vuelve el penultimo
		ultimo = ultimo->sig;		// Ultimo se dirige al ultimo nodo
		recorre = recorre->sig;		// avanzamos al siguiente nodo a copiar
		recorre = recorre->sig;
	}
	imprimeLista(raiz3);
}

void copy(nodo *raiz) 
{
	nodo *raiz2 = NULL;
	//  copiar  la lista en raiz2
	imprimeLista(raiz2);
}

int main()
{
	nodo *raiz2 = NULL;
	insert('a');
	insert('b');
	insert('c');
	insert('d');
	insert('e');
	concat(raiz,raiz2);

	system("pause");
	return 0;
}