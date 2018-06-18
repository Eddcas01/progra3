#pragma once
#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void PushP();
void PopP();
void RecorrerP();

struct pila
{
	int valor;
	pila *ant;
};

pila *pilao, *pilaaux;

void PushP()
{
	if (pilao == NULL)
	{
		pilao = new pila;
		cout << "Ingrese primer dato: "; cin >> pilao->valor;
		cout << "\nDato ingresado correctamente!!!" << endl;
		pilao->ant = NULL;
		system("pause>nul");
		return;
	}
	pilaaux = new pila;
	cout << "Ingrese dato: "; cin >> pilaaux->valor;
	cout << "\nDato ingresado correctamente!!!" << endl;
	pilaaux->ant = pilao;
	pilao = pilaaux;
	system("pause>nul");
}
void PopP()
{
	if (pilao == NULL)
	{
		cout << "No hay datos en la pila " << endl;
	}
	else
	{
		pilaaux = new pila;
		pilaaux = pilao;
		cout << "Valor a eliminar : " << pilaaux->valor << endl;
		pilao = pilaaux->ant;
		delete(pilaaux);
	}
	system("pause>nul");
}

void RecorrerP()
{
	if (pilao == NULL)
	{
		cout << "No existen datos en la pila " << endl;
	}
	else
	{
		cout << "Los datos son: " << endl;
		pilaaux = pilao;
		while (pilaaux != NULL)
		{
			cout << pilaaux->valor << endl;
			pilaaux = pilaaux->ant;
		}
		cout << "FIN" << endl;
	}
	system("pause>nul");
}

void menu10()
{
	int opcion = 0;
	do
	{
		system("cls");
		cout << "\tPROGRAMA PARA CONTROL DE PILA DINAMICA\n";
		cout << "1.Ingresar Valores a la pila (Push) \n";
		cout << "2.Mostrar Datos de la Pila (Recorrido) \n";
		cout << "3.Eliminar Valores de la Pila (Pop) \n";
		cout << "4.Regresar\n\n";
		cout << "Que opcion desea realizar : "; cin >> opcion;
		switch (opcion)
		{
		case 1:
			system("cls");
			PushP(); break;
		case 2:
			system("cls");
			RecorrerP(); break;
		case 3:
			system("cls");
			PopP(); break;
		}
	} while (opcion != 4);
}