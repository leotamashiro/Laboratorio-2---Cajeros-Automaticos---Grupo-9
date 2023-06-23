#include <iostream>
#include <string>
#include <cstring>
#include "Direccion.h"
using namespace std;

void menuSucursales ()
{

    int opcion;
    do
    {
        cout << "---------------------------------" << endl;
        cout << "---------MENU SUCURSALES---------" << endl;
        cout << "---------------------------" << endl;
        cout << "1. Cargar" << endl;
        cout << "2. Editar" << endl;
        cout << "3. Borrar" << endl;
        cout << "4. Listar Sucursal por Numero" << endl;
        cout << "5. Listar Sucursal por Nombre" << endl;
        cout << "6. Listar Todas las Sucursales" << endl;
        cout << endl;
        cout << "0. Salir" << endl;
        cout << "---------------------------------" << endl;
        cout << endl;
        cin >> opcion;

        switch(opcion)
        {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        default:
            cout << "Debe ingresar una opcion correcta" << endl;
            break;
        }

    }
    while(opcion != 0);
}
