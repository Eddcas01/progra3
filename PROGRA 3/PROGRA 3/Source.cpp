#include<iostream>
<<<<<<< HEAD
#include"1.h"
#include"2.h"
#include"3.h"
#include"5.h"
=======

#include"1.h"
#include"2.h"
#include"3.h"
>>>>>>> 498d6bd03cff3b36ff2e961e5b24f6844ce1cd4c

using namespace std;

int main() 
{
	int opmain = 0;
	do
	{
		system("cls");
		cout << "\n\t\t################# - MENU - ################\n";
		cout << "\t\t# 1. ALFABETO                               #\n";
		cout << "\t\t# 2. ARBOL BINARIO                          #\n";
<<<<<<< HEAD
		cout << "\t\t# 3. ARBOLES AVL                            #\n";
=======
		cout << "\t\t# 3. Arboles AVL                            #\n";
>>>>>>> 498d6bd03cff3b36ff2e961e5b24f6844ce1cd4c
		cout << "\t\t# 4.                                        #\n";
		cout << "\t\t# 5.                                        #\n";
		cout << "\t\t# 6.                                        #\n";
		cout << "\t\t# 7.                                        #\n";
		cout << "\t\t# 8.                                        #\n";
		cout << "\t\t# 9.                                        #\n";
		cout << "\t\t# 10.                                       #\n";
		cout << "\t\t#############################################\n";
		cout << "\t\tseleccione una opcion -> ";
		cin >> opmain;

		switch (opmain)
		{
<<<<<<< HEAD
		case 1: menu1(); break;
		case 2: menu2(); break;
		case 3: menu3(); break;
		case 4: menu4(); break;
		case 5: menu5(); break;
		case 6: break;
=======
		case 1: menu1();break;
		case 2: menu2();break;
		case 3: menu3(); break;
		case 4: break;
		case 5: break;
		case 6: menu6();break;
>>>>>>> 498d6bd03cff3b36ff2e961e5b24f6844ce1cd4c
		case 7: break;
		case 8: break;
		case 9: break;
		case 10: break;

		default:
			break;
		}
	} while (opmain!=0);
	
	
	system("pause>nul");

}