#include <iostream>
#include <string>
#include <cstring>
#include "Direccion.h"
using namespace std;

void menuAdmin ()
{

    int opcion;
    do
    {
        cout << "--------------------------" << endl;
        cout << "----MENU ADMINISTRADOR----" << endl;
        cout << "--------------------------" << endl;
        cout << "1. Sucursales" << endl;
        cout << "2. Cajeros" << endl;
        cout << "3. Clientes" << endl;
        cout << endl;
        cout << "0. Salir" << endl;
        cout << "--------------------------" << endl;
        cout << endl;
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            ///Sucursales();
            break;
        case 2:
            ///Cajeros();
            break;
        case 3:
            ///Clientes();
            break;
        default:
            cout << "Debe ingresar una opcion correcta" << endl;
            break;
        }

    }
    while(opcion != 0);
}
