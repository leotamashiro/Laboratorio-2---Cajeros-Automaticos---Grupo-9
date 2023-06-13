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
    bool verificarUsuario=false;
    int verificarLogin;
    int dni;
    int Sucusal;
    int idCajero;
    bool flagSucursal=false;
    bool validSucu = false;
    bool validSucuEstado;
    bool flagCajero=false;
    bool existeCajero= false;
    bool estadoCajero;
    char user[30]="";
    char password[7]="";
    cout << "--------------------------------------" << endl;
    cout << "--------------BIENVENIDO--------------" << endl;
    cout << "--------------------------------------" << endl << endl;
    cout << "A continuacion Listaremos todas las sucursales disponibles:"<< endl << endl;
    system ("pause");
    mostarSucursalesActivas();
    Sucusal = pedirleAlClienteNumSucursal();
    system("cls");
    idCajero = pedirleAlClienteCajero(Sucusal);
    system("cls");

    /**
    HASTA ACA YA TENGO EL ID DEL CAJERO DEL QUE VA A REALIZAR LA EXTRAXION   ->   idCajero
    */

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
        menuExtraxion(dni, idCajero);
    default:
        break;
    }
}
