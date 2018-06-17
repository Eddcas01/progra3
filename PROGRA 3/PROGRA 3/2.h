#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

struct nodo1 {
	int nro;
	struct nodo1 *izq, *der, *padre;
};

typedef struct nodo1 *ABB;
/* es un puntero de tipo nodo1 que hemos llamado ABB, que ulitizaremos
para mayor facilidad de creacion de variables */


//protos
bool Busqueda(ABB &arbol, int n);
void Eliminarnodo1(nodo1 *);
nodo1 *minimo(nodo1 *);
void reemplazar(nodo1*, nodo1 *);
void destruirnodo1(nodo1 *);
void Eliminarnodo1Der(nodo1 *);
void EliminarIZQ(nodo1 *);
nodo1 *minimoDer(nodo1 *);
void reemplazarDer(nodo1*, nodo1 *);
void destruirnodo1Der(nodo1 *);

ABB crearnodo1(int x, nodo1 *padre)
{
	ABB nuevonodo1 = new nodo1;
	nuevonodo1->nro = x;
	nuevonodo1->izq = NULL;
	nuevonodo1->der = NULL;
	nuevonodo1->padre = padre;


	return nuevonodo1;
}
void insertar(ABB &arbol, int x, nodo1 *padre)
{
	if (arbol == NULL)
	{
		arbol = crearnodo1(x, padre);

	}
	else if (x < arbol->nro)
		insertar(arbol->izq, x, arbol);
	else if (x > arbol->nro)
		insertar(arbol->der, x, arbol);
}

void preOrden(ABB arbol)
{
	if (arbol != NULL)
	{
		cout << arbol->nro << " ";
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}

void enOrden(ABB arbol)
{
	if (arbol != NULL)
	{
		enOrden(arbol->izq);
		cout << arbol->nro << " ";
		enOrden(arbol->der);
	}
}

void postOrden(ABB arbol)
{
	if (arbol != NULL)
	{
		postOrden(arbol->izq);
		postOrden(arbol->der);
		cout << arbol->nro << " ";
	}
}

void verArbol(ABB arbol, int n)
{
	if (arbol == NULL)
		return;
	verArbol(arbol->der, n + 1);

	for (int i = 0; i<n; i++)
		cout << "   ";

	cout << arbol->nro << endl;

	verArbol(arbol->izq, n + 1);
}

bool Busqueda(ABB &arbol, int n) {
	if (arbol == NULL) {
		return false;
	}
	else if (arbol->nro == n) {
		return true;
	}
	else if (n< arbol->nro)
	{
		return Busqueda(arbol->izq, n);
	}
	else {
		return Busqueda(arbol->der, n);
	}

}
void Eliminar(nodo1 *arbol, int n) {
	if (arbol == NULL) {
		return;
	}
	else if (n<arbol->nro) {
		Eliminar(arbol->izq, n);//si el valor es menor busca por la izquierda

	}
	else if (n>arbol->nro) {
		Eliminar(arbol->der, n);//si es mayor vamos a buscar por la derecha
	}
	else// si noo es mayor ni menor y el arbol no esta vacio "lo encontramos"
	{

		Eliminarnodo1(arbol);
	}



}

//funcion para determinar el nodo1 mas izquierdo posible

nodo1 *minimo(nodo1 *arbol) {
	if (arbol == NULL) {
		return NULL;
	}
	if (arbol->izq) {//si tiene hijo izq
		return minimo(arbol->izq);
	}
	else
	{
		return arbol; //si no tinen hijo izq le regresamos el misno nodo1

	}


}
void Eliminarnodo1(nodo1 *nodo1Eliminar) {

	//puede ser hoja 0 hijos
	//hijo izquierdo o derecho

	//eliminacion con 2 subarboles hijos
	if (nodo1Eliminar->izq && nodo1Eliminar->der) {
		nodo1 *menor = minimo(nodo1Eliminar->der);
		nodo1Eliminar->nro = menor->nro;
		Eliminarnodo1(menor);
	}
	else if (nodo1Eliminar->izq) {//si tiene hijo izq
		reemplazar(nodo1Eliminar, nodo1Eliminar->izq);
		destruirnodo1(nodo1Eliminar);
	}
	else if (nodo1Eliminar->der) {//si tiene hijo der
		reemplazar(nodo1Eliminar, nodo1Eliminar->der);
		destruirnodo1(nodo1Eliminar);
	}
	else {//nodo1 terminal
		reemplazar(nodo1Eliminar, NULL);
		destruirnodo1(nodo1Eliminar);

	}


}
void reemplazar(nodo1 *arbol, nodo1 *nuevonodo1) {
	if (arbol->padre) {
		//arbol->padre hay que asignarle el nuevo hijo
		if (arbol->nro == arbol->padre->izq->nro) {
			arbol->padre->izq = nuevonodo1;
		}
		else if (arbol->nro == arbol->padre->der->nro) {
			arbol->padre->der = nuevonodo1;
		}
	}
	if (nuevonodo1) {
		//asignarle su nuevo padre
		nuevonodo1->padre = arbol->padre;


	}



}
void destruirnodo1(nodo1 *nodo1) {
	nodo1->izq = NULL;
	nodo1->der = NULL;

	delete nodo1;

}
//eliminacion por la izquierda-todo derecha
void EliminarIZQ(nodo1 *arbol, int n) {
	if (arbol == NULL) {
		return;
	}
	else if (n<arbol->nro) {
		EliminarIZQ(arbol->izq, n);//si el valor es menor busca por la izquierda

	}
	else if (n>arbol->nro) {
		EliminarIZQ(arbol->der, n);//si es mayor vamos a buscar por la derecha
	}
	else// si noo es mayor ni menor y el arbol no esta vacio "lo encontramos"
	{

		Eliminarnodo1Der(arbol);
	}



}

//funcion para determinar el nodo1 mas derecho posible

nodo1 *minimoDer(nodo1 *arbol) {
	if (arbol == NULL) {
		return NULL;
	}
	if (arbol->der) {//si tiene hijo izq
		return minimoDer(arbol->der);
	}
	else
	{
		return arbol; //si no tinen hijo izq le regresamos el misno nodo1

	}


}
void Eliminarnodo1Der(nodo1 *nodo1Eliminar) {

	//puede ser hoja 0 hijos
	//hijo izquierdo o derecho

	//eliminacion con 2 subarboles hijos
	if (nodo1Eliminar->izq && nodo1Eliminar->der) {
		nodo1 *menor = minimoDer(nodo1Eliminar->izq);
		nodo1Eliminar->nro = menor->nro;
		Eliminarnodo1Der(menor);
	}
	else if (nodo1Eliminar->izq) {//si tiene hijo izq
		reemplazarDer(nodo1Eliminar, nodo1Eliminar->izq);
		destruirnodo1Der(nodo1Eliminar);
	}
	else if (nodo1Eliminar->der) {//si tiene hijo der
		reemplazarDer(nodo1Eliminar, nodo1Eliminar->der);
		destruirnodo1Der(nodo1Eliminar);
	}
	else {//nodo1 terminal
		reemplazarDer(nodo1Eliminar, NULL);
		destruirnodo1Der(nodo1Eliminar);

	}


}
void reemplazarDer(nodo1 *arbol, nodo1 *nuevonodo1) {
	if (arbol->padre) {
		//arbol->padre hay que asignarle el nuevo hijo
		if (arbol->nro == arbol->padre->izq->nro) {
			arbol->padre->izq = nuevonodo1;
		}
		else if (arbol->nro == arbol->padre->der->nro) {
			arbol->padre->der = nuevonodo1;
		}
	}
	if (nuevonodo1) {
		//asignarle su nuevo padre
		nuevonodo1->padre = arbol->padre;
	}



}
void destruirnodo1Der(nodo1 *nodo1) {
	nodo1->izq = NULL;
	nodo1->der = NULL;

	delete nodo1;

}


void menu2()
{

	int op;
	int dato;
	ABB arbol = NULL;   // creado Arbol

	int n;  // numero de nodo1s del arbol
	int x; // elemento a insertar en cada nodo1
menu:
	system("cls");
	cout << "***** MENU ******\n";
	cout << "1.ingresar arbol\n";
	cout << "2.ver arbol\n ";
	cout << "3.morstrar ordenamientos\n";
	cout << "4.Buscar en arbol\n";
	cout << "5.Eliminar un nodo1 del arbol\n";
	cout << "6.Eliminar por la izquierda\n";
	cout << "7.salir\n ";
	cin >> op;
	do {
		switch (op)
		{
		case 1:cout << "\n\t\t  ..[ ARBOL BINARIO DE BUSQUEDA ]..  \n\n";

			cout << " Numero de nodo1s del arbol:  ";
			cin >> n;
			cout << endl;

			for (int i = 0; i < n; i++)
			{
				cout << " Numero del nodo1 " << i + 1 << ": ";
				cin >> x;
				insertar(arbol, x, NULL);
			}
			system("pause");
			goto menu;
			break;
		case 2:
			system("cls");

			cout << "\n Mostrando ABB \n\n";
			verArbol(arbol, 0);


			system("pause");
			goto menu;
			break;

		case 3:
			system("cls");
			cout << "\n Recorridos del ABB";

			cout << "\n\n En orden   :  ";   enOrden(arbol);
			cout << "\n\n Pre Orden  :  ";   preOrden(arbol);
			cout << "\n\n Post Orden :  ";   postOrden(arbol);

			cout << endl << endl;

			system("pause");
			goto menu;
			break;


		case 4:
			system("cls");
			cout << "ingrese el elemento a buscar\n";
			cin >> dato;

			if (Busqueda(arbol, dato) == true) {
				cout << "elemento" << dato << "Ha sido encontrado " << endl;
			}
			else {
				cout << "elemento no encontrado\n";
			}

			system("pause");
			goto menu;

		case 5:
			system("cls");
			cout << "Digite el numero a eliminar\n";
			cin >> dato;
			Eliminar(arbol, dato);
			system("pause");
			goto menu;
			break;
		case 6:
			system("cls");
			cout << "Digite el numero a eliminar\n";
			cin >> dato;
			EliminarIZQ(arbol, dato);
			system("pause");
			goto menu;
			break;
		}

	} while (op != 7);

}
