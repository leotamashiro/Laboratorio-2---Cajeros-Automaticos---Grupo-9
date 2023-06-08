#include <iostream>
#include <string>
#include <cstring>
#include "Direccion.h"
using namespace std;

void menuClientes ()
{

    int opcion;
    do
    {
        cout << "---------------------------------" << endl;
        cout << "---------MENU CLIENTES---------" << endl;
        cout << "---------------------------" << endl;
        cout << "1. Cargar" << endl;
        cout << "2. Editar" << endl;
        cout << "3. Borrar" << endl;
        cout << "4. Listar Cliente por DNI" << endl;
        cout << "5. Listar Cliente por Apellido" << endl;
        cout << "6. Listar Todos lss Clientes" << endl;
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
