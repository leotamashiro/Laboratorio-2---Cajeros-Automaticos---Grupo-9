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
    int opcion;
    bool verificarUsuario=false;
    int verificarLogin;
    int dni;
    int Sucusal;
    int idCajero;
    char user[30]="";
    char password[7]="";
    int permisoCliente;
    do
    {
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
            cout<<"INGRESE DNI: "<<endl;
            dni = validarNumerosIngresados();
            permisoCliente = loginUsuario(dni);
            switch(permisoCliente)
            {
            case 1:
                menuAdmin();
                break;

            case 2:
                cout << "A continuacion Listaremos todas las sucursales disponibles:"<< endl << endl;
                system ("pause");
                mostarSucursalesActivas();
                Sucusal = pedirleAlClienteNumSucursal();
                system("cls");
                idCajero = pedirleAlClienteCajero(Sucusal);
                system("cls");
                ///Ya empizo a estraer el dinero
                menuExtraxion(dni, idCajero);
            default:
                break;
            }
        }
        break;
        case 2:
            persistirCliente();
            break;
        default:
            cout << "Por favor ingrese una opcion correcta: ";
            break;
        }
    }
    while(opcion!=0);

}
