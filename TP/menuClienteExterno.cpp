#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include "MenuAdmin.h"
#include "funciones.h"
#include "funcionesClientes.h"

using namespace std;

void menuClienteExterno(int dni)
{
    int opcion;
    int verificarLogin;
    int Sucusal;
    int idCajero;
    do
    {
        system("cls");
        cout << "--------------------------------------" << endl;
        cout << "--------------BIENVENIDO--------------" << endl;
        cout << "--------------------------------------" << endl << endl;
        cout << "1. Mostrar Datos Cliente:" << endl;
        cout << "2. Editar Datos Cliente:" << endl;
        cout << "3. Extraer Dinero:" << endl;
        cout << "4. Ingresar Dinero:" << endl;
        cout << endl;
        cout << "0. Salir" << endl;
        cout << "--------------------------------------" << endl;
        cout << endl;
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            ///FUNCION PARA MOSTRAR LOS DATOS DEL CLIENTE
            system("cls");
            buscarClientePorDni(dni);
            system("pause");
        break;
        case 2:
            ///FUNCION PARA EDITAR LOS DATOS DEL CLIENTE
            system("cls");
            menuEditarClientes(dni);
            break;
        case 3:
            cout << "A continuacion Listaremos todas las sucursales disponibles:"<< endl << endl;
            system ("pause");
            mostarSucursalesActivas();
            Sucusal = pedirleAlClienteNumSucursal();
            system("cls");
            idCajero = pedirleAlClienteCajero(Sucusal);
            system("cls");
            ///Ya empizo a extraer el dinero
            menuExtraxion(dni, idCajero);
        break;
        case 4:
            ///FUNCION PARA INGRESAR DINERO EN LA CUENTA DEL CLIENTE
            system("cls");
            ingresarFondosCuenta(dni);
            system("pause");
            break;
        case 0:
            system("cls");
            break;
        default:
            cout << "Por favor ingrese una opcion correcta: ";
            break;
        }
    }
    while(opcion!=0);

}
