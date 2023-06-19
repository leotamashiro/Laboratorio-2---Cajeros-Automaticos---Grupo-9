#include <iostream>
#include <string>
#include <cstring>
#include "MenuAdmin.h"

/**
En la parte del Balanceo tengo que poner la plata que tiene cada auxCajero
*/
/**
La opcion 3 seria Agregar el dinero que tiene cada cuenta y su numero de DNI.
*/
using namespace std;

void menuAdmin()
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
        cout << "4. Balanceo" << endl;
        cout << endl;
        cout << "0. Salir" << endl;
        cout << "--------------------------" << endl;
        cout << endl;
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            menuSucursales();
            break;
        case 2:
            menuCajeros();
            break;
        case 3:
            ///Clientes();
            break;
        case 4:
            balanceoMenu();
            break;
        default:
            cout << "Debe ingresar una opcion correcta" << endl;
            break;
        }

    }
    while(opcion != 0);
}
