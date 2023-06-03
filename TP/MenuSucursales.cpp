/**
Al cambiar el estado de la sucursal los cajeros de la sucursales hay que cambiar el estado
*/
#include <iostream>
#include <string>
#include <cstring>
#include "Direccion.h"
#include "Sucursal.h"
#include "funciones.h"

using namespace std;

void menuSucursales ()
{
    int opcion, numSucEditar, numSucMostar, numSucuEstado;
    bool validSucu;
    bool flag;
    do
    {
        cout << "---------------------------------" << endl;
        cout << "---------MENU SUCURSALES---------" << endl;
        cout << "---------------------------------" << endl;
        cout << "1. Cargar" << endl;
        cout << "2. Editar" << endl;
        cout << "3. Borrar" << endl;
        cout << "4. Dar de Alta Sucursal" << endl;
        cout << "5. Listar Sucursal por Numero" << endl;
        cout << "6. Listar Todas las Sucursales Activas" << endl;
        cout << "7. Listar Todas las Sucursales Inactivas" << endl;
        cout << "8. Listar Todas las Sucursales" << endl;
        cout << endl;
        cout << "0. Salir" << endl;
        cout << "---------------------------------" << endl;
        cout << endl;
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            Sucursal sucu;
            sucu.Cargar();
            sucu.grabarEnDisco();
            break;

        case 2:
            mostarSucursalesActivas();
            flag=false;
            validSucu == false;
            while (validSucu == false)
            {
                if (flag==false)
                {
                    cout << "El numero de sucursal a editar:" << endl;
                    cin >> numSucEditar;
                    flag=true;
                }
                else
                {
                    cout << "El numero de sucursal ingresado no existe:" << endl;
                    cout << "Vuelva a ingresar el numero:" << endl;
                    cin >> numSucEditar;
                }

                validSucu=validarSucursal(numSucEditar);
            }
            if (validSucu==true)
            {
                editarSucursal(numSucEditar);
            }

            break;

        case 3:
            mostarSucursalesActivas();
            flag=false;
            validSucu == false;
            while (validSucu == false)
            {
                if (flag==false)
                {
                    cout << "Ingrese el numero de Sucursal que desea Borrar:" << endl;
                    cin >> numSucuEstado;
                    flag=true;
                }
                else
                {
                    cout << "El numero de sucursal ingresado no existe:" << endl;
                    cout << "Vuelva a ingresar el numero:" << endl;
                    cin >> numSucuEstado;
                }

                validSucu=validarSucursal(numSucuEstado);
            }
            if (validSucu==true)
            {
                borrarSucursal(numSucuEstado);
            }
            break;

        case 4:
            mostarSucursalesInactivas();
            flag=false;
            validSucu == false;
            while (validSucu == false)
            {
                if (flag==false)
                {
                    cout << "Ingrese el numero de Sucursal que desea dar de Alta:" << endl;
                    cin >> numSucuEstado;
                    flag=true;
                }
                else
                {
                    cout << "El numero de sucursal ingresado no existe:" << endl;
                    cout << "Vuelva a ingresar el numero:" << endl;
                    cin >> numSucuEstado;
                }

                validSucu=validarSucursal(numSucuEstado);
            }
            if (validSucu==true)
            {
                darAltaSucursal(numSucuEstado);
            }
            break;

        case 5:
            cout << "El numero de sucursal que de desea mostar:" << endl;
            cin >> numSucMostar;
            listarSucuNumero(numSucMostar);
            break;

        case 6:
            mostarSucursalesActivas();
            break;

        case 7:
            mostarSucursalesInactivas();
            break;

        case 8:
            mostarSucursales();
            break;

        /*default:
            cout << "Debe ingresar una opcion correcta" << endl;
            break;*/

        }

    }
    while(opcion != 0);
}
