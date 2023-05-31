#include <iostream>
#include <string>
#include <cstring>
#include "Direccion.h"
#include "Sucursal.h"
#include "funciones.h"

using namespace std;

void menuSucursales ()
{
    int opcion, numSucEditar, numSucMostar;

    do
    {
        cout << "---------------------------------" << endl;
        cout << "---------MENU SUCURSALES---------" << endl;
        cout << "---------------------------------" << endl;
        cout << "1. Cargar" << endl;
        cout << "2. Editar" << endl;
        cout << "3. Borrar" << endl;
        cout << "4. Ordenar Sucursales de Menor a Mayor" << endl;
        cout << "5. Listar Sucursal por Numero" << endl;
        cout << "6. Listar Todas las Sucursales" << endl;
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

            bool validSucu;
            mostarSucursales();
            bool flag;
            flag=false;
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

        case 5:
            cout << "El numero de sucursal que de desea mostar:" << endl;
            cin >> numSucMostar;
            listarSucuNumero(numSucMostar);
            break;

        case 6:
            mostarSucursales();
            break;

        /*default:
            cout << "Debe ingresar una opcion correcta" << endl;
            break;*/

        }

    }
    while(opcion != 0);
}
