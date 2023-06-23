#include <iostream>
#include <string>
#include <cstring>

using namespace std;
#include "Direccion.h"
#include "funcionesClientes.h"
void menuClientes ()
{

    int opcion;
    do
    {
        cout << "---------------------------------" << endl;
        cout << "----------MENU CLIENTES----------" << endl;
        cout << "---------------------------------" << endl;
        cout << "1. Cargar" << endl;
        cout << "2. Editar" << endl;
        cout << "3. Borrar" << endl;
        cout << "4. Listar Cliente por DNI" << endl;
        cout << "5. Listar Todos lss Clientes" << endl;
        cout << endl;
        cout << "0. Salir" << endl;
        cout << "---------------------------------" << endl;
        cout << endl;
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            persistirCliente();
            break;
        case 2:
            system("cls");
            menuEditarClientes();
            break;
        case 3:
            eliminadoLogico();
            break;
        case 4:
            buscarClientePorDni();
            break;
        case 5:
            buscarClientes();
            break;
        default:
            cout << "Debe ingresar una opcion correcta" << endl;
            break;
        }

    }
    while(opcion != 0);
}
