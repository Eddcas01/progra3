#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct NODOSIMPLE
{
	int dato;
	NODOSIMPLE * sig;
};

int valorSimple, opption = 0;
NODOSIMPLE *cabeza = NULL;

void Insertar(NODOSIMPLE **cabs, int vals)
{
	NODOSIMPLE * n = NULL;
	n = new NODOSIMPLE();
	if (n != NULL)
	{
		n->dato = vals;
		n->sig = *cabs;
		*cabs = n;
	}
}

void mostrar(NODOSIMPLE *cabs)
{
	NODOSIMPLE*aux = cabs;
	while (aux != NULL)
	{
		cout << "\t" << aux->dato << "\n";
		aux = aux->sig;
	}
}

void menu7()
{
	int opption = 0;
	do
	{
		system("cls");
		cout << "\n\n\t- -MENU- -" << endl;
		cout << "\t1.Ingreso" << endl;
		cout << "\t2.Mostrar" << endl;
		cout << "\t3.Regresar" << endl;
		cout << "\tSeleccione una opcion: "; cin >> opption;
		switch (opption)
		{
		case 1:
			system("cls");
			cout << "Ingrese un dato: ";
			cin >> valorSimple;
			Insertar(&cabeza, valorSimple);
			break;
		case 2:
			system("cls");
			mostrar(cabeza);
			system("pause>nul");
			break;
		}
	} while (opption != 3);
}