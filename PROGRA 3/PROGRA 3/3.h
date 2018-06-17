#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include<Windows.h>
#define DERECHA 1
#define IZQUIERDA 0
#define TRUE 1
#define FALSE 0
using namespace std;;
typedef struct nodoavl
{
	int dato;
	int FE;
	struct nodoavl *D;
	struct nodoavl *IZ;
	struct nodoavl *padre;
}*AVL;

void Insertar(AVL *nodoavl, int dato);
void Eliminar_nodoavl(AVL *n, int dato);
int Buscar(AVL n, int dato);
int EsHoja(AVL n);
int Num_nodoavls(AVL n, int* c);
int Altura_Arbol(AVL n, int* altura);
int Nivel_nodoavl(AVL n, int dato);
void InOrden(AVL, void(*func)(int*));
void PreOrden(AVL, void(*func)(int*));
void PostOrden(AVL, void(*func)(int*));
void Equilibrar(AVL *raiz, AVL nodoavl, int, int);
void RSI(AVL *r, AVL nodoavl);
void RSD(AVL *r, AVL nodoavl);
void RDI(AVL *r, AVL nodoavl);
void RDD(AVL *r, AVL nodoavl);
void Eliminar_Arbol(AVL *nodoavl);
void auxContador(AVL n, int*);
void auxAltura(AVL a, int, int*);
void Mostrar(int *n);
void verArbol(AVL arbol, int n);



void menu3() {// ESTE ERA EL MAIN
	AVL Arbol = NULL;

	int i, num, ndatos, opcion;

	do
	{
		system("cls");
		printf("\n");
		printf("\n*********************");
		printf("\n1. Insertar         *");
		printf("\n2. Mostrar          *");
		printf("\n3. Buscar           *");
		printf("\n4. Eliminar nodo    *");
		printf("\n5. Eliminar árbol   *");
		printf("\n6. Salir            *");
		printf("\n*********************");

		printf("\n\n\n");

		printf(" Elija opción    ");

		scanf_s("%d", &opcion);




		switch (opcion)
		{
		case 1:   system("cls");

			printf("\n INGRESE CANTIDAD DE NODOS ->");

			scanf_s("%d", &ndatos);

			system("cls");

			printf("\n Introduzca %d dato ->\n\n", ndatos);

			for (i = 1; i <= ndatos; i++)
			{
				scanf_s("%d", &num);

				Insertar(&Arbol, num);
			}
			system("cls");
			printf("\n Número nodos ----> %d ", Num_nodoavls(Arbol, &num));

			printf("\n\n Altura `árbol ----> %d ", Altura_Arbol(Arbol, &num));

			printf("\n\n InOrden      ----> ");
			InOrden(Arbol, Mostrar);
			printf("\n\n PreOrden     ----> ");
			PreOrden(Arbol, Mostrar);
			printf("\n\n PostOrden    ----> ");
			PostOrden(Arbol, Mostrar);
			printf("\n\n\n\n\n\n\n\n");

			system("pause");

			system("cls");
			break;






		case 2:   system("cls");
			verArbol(Arbol, 0);
			printf("\n\n Introduzca nodo      ");

			scanf_s("%d", &num);

			system("cls");

			printf("\n\n Nivel de %d  ---->  %d\n", num, Nivel_nodoavl(Arbol, num));

			printf("\n\n\n\n\n\n\n\n");

			system("PAUSE");

			system("cls");

			break;


		case 3:   system("cls");

			printf("\n Introduzca dato a buscar      ");

			scanf_s("%d", &num);

			system("cls");

			Buscar(Arbol, num);

			printf("\n\n\n\n\n\n\n\n");

			system("PAUSE");

			system("cls");

			break;


		case 4:  system("cls");

			printf("\n Introduzca dato a eliminar      ");

			scanf_s("%d", &num);

			system("cls");

			Eliminar_nodoavl(&Arbol, num);

			printf("\n\n Eliminado    ----> %d  ", num);

			printf("\n\n InOrden      ----> ");

			InOrden(Arbol, Mostrar);

			printf("\n\n Número nodos ----> %d", Num_nodoavls(Arbol, &num));

			printf("\n\n Altura árbol ----> %d", Altura_Arbol(Arbol, &num));

			printf("\n\n\n\n\n\n\n\n");

			system("PAUSE");

			system("cls");

			break;






		case 5:  system("cls");

			Eliminar_Arbol(&Arbol);

			printf("\n ARBOL ELIMINADO");

			printf("\n\n\n\n\n\n\n\n");

			system("PAUSE");

			system("cls");

			break;

		case 6: 	
			system("cls");
			cout << "\n\n\n\t\tSALIENDO...";
			Sleep(1500);  break;

		default:  system("cls");

			break;
		}
	} while (opcion != 6);

}


void Insertar(AVL *nodoavl, int dato)
{
	AVL padre = NULL;

	AVL actual = *nodoavl;

	while (actual != NULL && dato != actual->dato)
	{
		padre = actual;

		if (dato < actual->dato)

			actual = actual->IZ;

		else if (dato > actual->dato)

			actual = actual->D;
	}
	if (actual != NULL)

		return;

	if (padre == NULL)
	{
		*nodoavl = (AVL)malloc(sizeof(struct nodoavl));

		(*nodoavl)->dato = dato;

		(*nodoavl)->IZ = (*nodoavl)->D = NULL;

		(*nodoavl)->padre = NULL;

		(*nodoavl)->FE = 0;
	}

	else if (dato < padre->dato)
	{
		actual = (AVL)malloc(sizeof(struct nodoavl));

		padre->IZ = actual;

		actual->dato = dato;

		actual->IZ = actual->D = NULL;

		actual->padre = padre;

		actual->FE = 0;

		Equilibrar(nodoavl, padre, IZQUIERDA, TRUE);
	}
	else if (dato > padre->dato)
	{
		actual = (AVL)malloc(sizeof(struct nodoavl));

		padre->D = actual;

		actual->dato = dato;

		actual->IZ = actual->D = NULL;

		actual->padre = padre;

		actual->FE = 0;

		Equilibrar(nodoavl, padre, DERECHA, TRUE);
	}
}

void Equilibrar(AVL *r, AVL nodoavl, int rama, int dato)
{
	int salir = FALSE;

	while (nodoavl && !salir)
	{
		if (dato)

			if (rama == IZQUIERDA)

				nodoavl->FE--;

			else

				nodoavl->FE++;

		else

			if (rama == IZQUIERDA)

				nodoavl->FE++;

			else

				nodoavl->FE--;

		if (nodoavl->FE == 0)

			salir = TRUE;

		else if (nodoavl->FE == -2)
		{
			if (nodoavl->IZ->FE == 1)

				RDD(r, nodoavl);

			else

				RSD(r, nodoavl);

			salir = TRUE;

		}
		else if (nodoavl->FE == 2) {

			if (nodoavl->D->FE == -1)

				RDI(r, nodoavl);

			else

				RSI(r, nodoavl);

			salir = TRUE;
		}
		if (nodoavl->padre)

			if (nodoavl->padre->D == nodoavl)

				rama = DERECHA;

			else

				rama = IZQUIERDA;

		nodoavl = nodoavl->padre;
	}
}

int EsHoja(AVL nodoavl)
{
	return !nodoavl->D && !nodoavl->IZ;
}


void RDD(AVL *r, AVL nodoavl)
{
	AVL Padre = nodoavl->padre;
	AVL A = nodoavl;
	AVL B = A->IZ;
	AVL C = B->D;
	AVL CI = C->IZ;
	AVL CD = C->D;
	if (Padre)
		if (Padre->D == A)
			Padre->D = C;
		else
			Padre->IZ = C;
	else
		*r = C;
	B->D = CI;
	A->IZ = CD;
	C->IZ = B;
	C->D = A;
	C->padre = Padre;
	A->padre = B->padre = C;
	if (CI)
		CI->padre = B;
	if (CD)
		CD->padre = A;

	switch (C->FE)
	{
	case -1: B->FE = 0;

		A->FE = 1;

		break;

	case 0:  B->FE = 0;

		A->FE = 0;

		break;

	case 1:  B->FE = -1;

		A->FE = 0;

		break;
	}
	C->FE = 0;
}


void RDI(AVL *r, AVL nodoavl)
{
	AVL Padre = nodoavl->padre;
	AVL A = nodoavl;
	AVL B = A->D;
	AVL C = B->IZ;
	AVL CI = C->IZ;
	AVL CD = C->D;
	if (Padre)
		if (Padre->D == A)
			Padre->D = C;
		else
			Padre->IZ = C;
	else
		*r = C;

	A->D = CI;
	B->IZ = CD;
	C->IZ = A;
	C->D = B;
	C->padre = Padre;
	A->padre = B->padre = C;
	if (CI)
		CI->padre = A;
	if (CD)
		CD->padre = B;

	switch (C->FE)
	{
	case -1: A->FE = 0;

		B->FE = 1;

		break;

	case 0:  A->FE = 0;

		B->FE = 0;

		break;

	case 1:  A->FE = -1;

		B->FE = 0;

		break;
	}
	C->FE = 0;
}

void RSD(AVL *r, AVL nodoavl)
{
	AVL Padre = nodoavl->padre;
	AVL A = nodoavl;
	AVL B = A->IZ;
	AVL C = B->D;
	if (Padre)
		if (Padre->D == A)
			Padre->D = B;
		else
			Padre->IZ = B;
	else
		*r = B;

	A->IZ = C;

	B->D = A;

	A->padre = B;

	if (C)

		C->padre = A;

	B->padre = Padre;

	A->FE = 0;

	B->FE = 0;
}

void RSI(AVL *r, AVL nodoavl)
{
	AVL Padre = nodoavl->padre;
	AVL A = nodoavl;
	AVL B = A->D;
	AVL C = B->IZ;
	if (Padre)
		if (Padre->D == A)
			Padre->D = B;
		else
			Padre->IZ = B;
	else
		*r = B;

	A->D = C;

	B->IZ = A;

	A->padre = B;

	if (C)

		C->padre = A;

	B->padre = Padre;

	A->FE = 0;

	B->FE = 0;
}

void Eliminar_nodoavl(AVL *n, int dato)
{
	AVL padre = NULL;

	AVL actual;

	AVL nodoavl;

	int aux;

	actual = *n;

	while (actual != NULL)
	{
		if (dato == actual->dato)
		{
			if (EsHoja(actual))
			{
				if (padre)

					if (padre->D == actual)

						padre->D = NULL;

					else if (padre->IZ == actual)

						padre->IZ = NULL;

				free(actual);

				actual = NULL;

				if ((padre->D == actual && padre->FE == 1) || (padre->IZ == actual && padre->FE == -1))
				{
					padre->FE = 0;

					actual = padre;

					padre = actual->padre;
				}
				if (padre)

					if (padre->D == actual)

						Equilibrar(n, padre, DERECHA, FALSE);

					else

						Equilibrar(n, padre, IZQUIERDA, FALSE);

				return;

			}
			else {

				padre = actual;

				if (actual->D)
				{
					nodoavl = actual->D;

					while (nodoavl->IZ)
					{
						padre = nodoavl;

						nodoavl = nodoavl->IZ;
					}
				}

				else {

					nodoavl = actual->IZ;

					while (nodoavl->D)
					{
						padre = nodoavl;

						nodoavl = nodoavl->D;
					}
				}

				aux = actual->dato;

				actual->dato = nodoavl->dato;

				nodoavl->dato = aux;

				actual = nodoavl;
			}

		}
		else {

			padre = actual;

			if (dato > actual->dato)

				actual = actual->D;

			else if (dato < actual->dato)

				actual = actual->IZ;
		}
	}
}


void InOrden(AVL nodoavl, void(*func)(int*))
{
	if (nodoavl->IZ)

		InOrden(nodoavl->IZ, func);

	func(&(nodoavl->dato));

	if (nodoavl->D)

		InOrden(nodoavl->D, func);
}
void PreOrden(AVL nodoavl, void(*func)(int*))
{
	func(&nodoavl->dato);

	if (nodoavl->IZ)

		PreOrden(nodoavl->IZ, func);

	if (nodoavl->D)

		PreOrden(nodoavl->D, func);
}
void PostOrden(AVL nodoavl, void(*func)(int*))
{
	if (nodoavl->IZ)

		PostOrden(nodoavl->IZ, func);

	if (nodoavl->D)

		PostOrden(nodoavl->D, func);

	func(&nodoavl->dato);
}


int Buscar(AVL nodoavl, int dato)
{
	AVL actual = nodoavl;
	while (actual != NULL)
	{
		if (dato == actual->dato)
		{
			printf("\n %d  EXISTE", dato);
			return TRUE;
		}
		else if (dato < actual->dato)
			actual = actual->IZ;
		else if (dato > actual->dato)
			actual = actual->D;
	}
	printf("\n %d  NO EXISTE", dato);
	return FALSE;
}

int Nivel_nodoavl(AVL nodoavl, int dato)
{
	int altura = 0;
	AVL actual = nodoavl;
	while (actual != NULL)
	{
		if (dato == actual->dato)
			return altura;
		else {
			altura++;
			if (dato < actual->dato)
				actual = actual->IZ;
			else if (dato > actual->dato)
				actual = actual->D;
		}
	}
	return -1;
}

void auxContador(AVL nodoavl, int *c)
{
	(*c)++;
	if (nodoavl->IZ)
		auxContador(nodoavl->IZ, c);
	if (nodoavl->D)
		auxContador(nodoavl->D, c);
}

int Num_nodoavls(AVL nodoavl, int *cont)
{
	*cont = 0;
	auxContador(nodoavl, cont);
	return *cont;
}

void auxAltura(AVL nodoavl, int a, int *altura)
{
	if (nodoavl->IZ)
		auxAltura(nodoavl->IZ, a + 1, altura);
	if (nodoavl->D)
		auxAltura(nodoavl->D, a + 1, altura);
	if (EsHoja(nodoavl) && a > *altura)
		*altura = a;
}

int Altura_Arbol(AVL nodoavl, int *altura)
{
	*altura = 0;
	auxAltura(nodoavl, 0, altura);
	return *altura;
}

void Mostrar(int *n)
{
	printf("%d, ", *n);
}

void Eliminar_Arbol(AVL *nodoavl)
{
	if (*nodoavl)
	{
		Eliminar_Arbol(&(*nodoavl)->IZ);
		Eliminar_Arbol(&(*nodoavl)->D);
		free(*nodoavl);
		*nodoavl = NULL;
	}
}
void verArbol(AVL arbol, int n)
{
	if (arbol == NULL)
		return;
	verArbol(arbol->D, n + 1);
	cout << "\t\t\t\t";
	for (int i = 0; i<n; i++)
		cout << "  ";

	cout << arbol->dato << endl;

	verArbol(arbol->IZ, n + 1);
}
