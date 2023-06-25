#include <iostream>
#include <string>
#include <cstring>
#include "MenuAdmin.h"
#include "funcionesReportes.h"

using namespace std;

void reportes()
{
    int opcion;
    do
    {
        cout << "--------------------------" << endl;
        cout << "----MENU Reportes----" << endl;
        cout << "--------------------------" << endl;
        cout << "1. Top 3 Sucursales" << endl;
        cout << "2. Top 5 Cajeros" << endl;
        cout << "3. " << endl;
        cout << "4. " << endl;
        cout << "5. " << endl;
        cout << endl;
        cout << "0. Salir" << endl;
        cout << "--------------------------" << endl;
        cout << endl;
        cin >> opcion;
        system("cls");

        switch(opcion)
        {
        case 1:
            topSucursales();
            break;
        case 2:
            topCajeros();
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 0:
            system("cls");
            break;
        default:
            cout << "Debe ingresar una opcion correcta" << endl;
            break;
        }

    }
    while(opcion != 0);
}
