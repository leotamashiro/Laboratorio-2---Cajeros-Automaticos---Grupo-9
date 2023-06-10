#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include "MenuAdmin.h"

using namespace std;

void menuUsuario()
{
    bool flag=false;
    bool verificarUsuario=false;
    int dni;
    char user[30]="";
    char password[7]="";
    cout << "--------------------------------------" << endl;
    cout << "--------------BIENVENIDO--------------" << endl;
    cout << "--------------------------------------" << endl << endl;
    while (verificarUsuario==false)
    {
        cout << "Por favor ingrese su numero DNI: ";
        cin >> dni;
        cout << "Ingrese su nombre de usuario: ";
        cin.ignore();
        cin.getline(user, 30);
        cout << "Ingrese su contrasena (maximo 6 caracteres): ";
        cin.getline(password, 7);

    }

    cout << "Número de DNI: " << dni << endl;
    cout << "Nombre de usuario: " << user << endl;
    cout << "Contrasena: " << password << endl;
}
