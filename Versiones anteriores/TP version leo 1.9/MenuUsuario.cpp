#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include "MenuAdmin.h"
#include "funciones.h"

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
    cout << "--------------------------------------" << endl;
    cout << "--------------BIENVENIDO--------------" << endl;
    cout << "--------------------------------------" << endl << endl;
    do
    {
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
                    while (verificarUsuario==false)
                    {
                        cout << "Por favor ingrese su numero DNI: ";
                        cin >> dni;
                        cout << "Ingrese su nombre de usuario: ";
                        cin.ignore();
                        cin.getline(user, 30);
                        cout << "Ingrese su contrasena (maximo 6 caracteres): ";
                        cin.getline(password, 7);
                        //leerLogin(dni, *user, *password);
                        /**
                        validar que los datos esten correctos  ->   idCajero
                        */
                        if (verificarLogin==1 || verificarLogin==2)
                        {
                            verificarUsuario=true;
                        }
                    }
                    switch(verificarLogin)
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
                ///Registrar Cliente:
                break;
            default:
                cout << "Por favor ingrese una opcion correcta: ";
                break;
        }
    }while(opcion!=0);

}
