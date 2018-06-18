#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void Push();
void Pop();
void Recorrer();

int Pila[6];
int Inicio, Final, Tope, opcion = 0;

void Push()
{
	system("cls");
	if (Tope == Final)
	{
		cout << "La pila se encuentra llena, ocasionara Desbordamiento";
	}
	else
	{
		cout << "Valor a Ingresar en la Pila : "; cin >> Inicio;
		Final++;
		Pila[Final] = Inicio;
		cout << "Valor agregado en la Pila en la Posicion: " << Final << endl;
	}
	system("pause>nul");
}
void Pop()
{
	if (Final == 0)
	{
		cout << "La pila se encuentra vacia, no procede";
	}
	else
	{
		cout << "Eliminando de la Pila el valor : " << Pila[Final] << " -- De la posicion en la Pila: " << Final << endl;
		Pila[Final] = 0;
		Final--;
	}
	system("pause>nul");
}

void Recorrer()
{
	system("cls");
	if (Final == 0)
	{
		cout << "La pila se encuentra acia, no procede";
	}
	else
	{
		for (int r = 1; r <= Final; r++)
		{
			cout << "Posicion en Pila: " << r << " -- Valor en Posicion: " << Pila[r] << endl;
		}
	}
	system("pause>nul");
}

void menu9()
{
	Tope = 6;
	Final = 0;
	do
	{
		system("cls");
		cout << "\tPROGRAMA PARA CONTROL DE PILA ESTATICA\n";
		cout << "1.Ingresar Valores a la pila (Push) \n";
		cout << "2.Mostrar Datos de la Pila (Recorrido) \n";
		cout << "3.Eliminar Valores de la Pila (Pop) \n";
		cout << "4.Regresar\n\n";
		cout << "Que opcion desea realizar : "; cin >> opcion;
		switch (opcion)
		{
		case 1:
			system("cls");
			Push(); break;
		case 2:
			system("cls");
			Recorrer(); break;
		case 3:
			system("cls");
			Pop(); break;
		}
	} while (opcion != 4);
}