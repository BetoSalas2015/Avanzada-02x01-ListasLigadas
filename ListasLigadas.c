#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>			//  Para usar la memoria din�mica

int main()
{
	int *ptra, *ptrb, *ptrc;

	ptra = (int *) malloc( sizeof(int) );			
	ptrb = (int *) malloc( sizeof(int) );
	ptrc = (int *) malloc( sizeof(int) );

	//printf("La direcci�n de memoria de a es: %p \n", &a);
	//printf("La direcci�n de memoria de b es: %p \n", &b);
	//printf("La direcci�n de memoria de c es: %p \n\n", &c);

	//printf("La direcci�n de memoria de ptra es: %p \n", &ptra);
	//printf("La direcci�n de memoria de ptrb es: %p \n", &ptrb);
	//printf("La direcci�n de memoria de ptrc es: %p \n\n", &ptrc);

	//printf("La direcci�n de memoria guardada en ptra es: %p \n", ptra);
	//printf("La direcci�n de memoria guardada en ptra es: %p \n", ptrb);
	//printf("La direcci�n de memoria guardada en ptra es: %p \n\n", ptrc);

	printf("Dame el valor de a: ");
	scanf("%d", ptra);
	printf("Dame el valor de b: ");
	scanf("%d", ptrb);

	*ptrc = *ptra + *ptrb;

	printf("El valor de c es : %d\n", *ptrc);

	system("pause");
	return 0;
}