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
    int sucursal;
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
        cout << "5. Ver Transacciones:" << endl;
        cout << endl;
        cout << "0. Salir" << endl;
        cout << "--------------------------------------" << endl;
        cout << endl;
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            {
                ///FUNCION PARA MOSTRAR LOS DATOS DEL CLIENTE
                system("cls");
                buscarClientePorDni(dni);
                system("pause");
            }
        break;
        case 2:
            {
                ///FUNCION PARA EDITAR LOS DATOS DEL CLIENTE
                system("cls");
                menuEditarClientes(dni);
            }
            break;
        case 3:
            {
                bool perteceASucursal=false;
                system("cls");
                cout << "A continuacion Listaremos todas las sucursales disponibles:"<< endl << endl;
                system ("pause");
                system("cls");
                if (!mostarSucursalesActivas()) {
                    cout<<"No existen sucursales activas en estos momentos"<<endl;
                    system("pause");
                    break;
                };
                sucursal = pedirleAlClienteNumSucursal();
                if(sucursal == -1) break;
                system("cls");
                do
                {
                    idCajero = pedirleAlClienteCajero(sucursal);
                    perteceASucursal=cajeroEsdeSucursal(sucursal,idCajero);

                }while(perteceASucursal==false);
                system("cls");
                ///Ya empizo a extraer el dinero
                menuExtraxion(dni, idCajero);
            }
        break;
        case 4:
            {
               ///FUNCION PARA INGRESAR DINERO EN LA CUENTA DEL CLIENTE
                system("cls");
                ingresarFondosCuenta(dni);
                system("pause");
            }
            break;
        case 5:
            {
                ///FUNCION PARA VER LOS DATOS DE LAS TRANSACCIONES REALIZADAS
                system("cls");
                mostrarTransaccionesCliente(dni);
                system("pause");
            }
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
