#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include "MenuAdmin.h"
#include "funciones.h"
#include "funcionesClientes.h"

using namespace std;

void menuUsuario()
{
    int opcion, dni, permisoCliente;
    do
    {
        system("cls");
        cout << "--------------------------------------" << endl;
        cout << "--------------BIENVENIDO--------------" << endl;
        cout << "--------------------------------------" << endl << endl;
        cout << "1. Logearse:" << endl;
        cout << "2. Registrarse:" << endl;
        cout << endl;
        cout << "0. Salir" << endl;
        cout << "--------------------------------------" << endl;
        cout << endl;
        cin >> opcion;

        switch(opcion)
        {
        case 1:
        {
            system("cls");
            cout<<"INGRESE DNI: "<<endl;
            dni = validarNumerosIngresados();
            permisoCliente = loginUsuario(dni);
            system("pause");
            switch(permisoCliente)
            {
            case 1:
                system("cls");
                menuAdmin();
                system("pause");
                break;

            case 2:
            system("cls");
            menuClienteExterno(dni);
            system("pause");
            default:
                break;
            }
        }
        break;
        case 2:
            system("cls");
            persistirCliente();
            system("pause");
            break;
        default:
            cout << "Por favor ingrese una opcion correcta: ";
            break;
        }
    }
    while(opcion!=0);

}
