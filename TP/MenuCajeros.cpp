/**
Funciona el cargar cajero,
mostrar cajero
pero no todo junto, ver el de tema de los case
*/
#include <iostream>
#include <string>
#include <cstring>
#include "Cajero.h"
#include "funciones.h"

using namespace std;

void menuCajeros ()
{
    int opcion, idCajeroEditar;
    // idCajeroMostar, numCajeroEstado;
    bool existeCajero=false;
    bool flag=false;
    do
    {
        cout << "----------------------------------" << endl;
        cout << "-----------MENU CAJEROS-----------" << endl;
        cout << "----------------------------------" << endl;
        cout << "1. Cargar" << endl;
        cout << "2. Editar" << endl;
        cout << "3. Borrar Cajero" << endl;
        cout << "4. Activar Cajero" << endl;
        cout << "5. Listar Cajero por ID" << endl;
        cout << "6. Listar Cajero por Sucursal" << endl;
        cout << "7. Listar Cajero Inactivos" << endl;
        cout << "8. Listar Todos los Cajero" << endl;
        cout << endl;
        cout << "0. Salir" << endl;
        cout << "----------------------------------" << endl;
        cout << endl;
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            Cajero objcajero;
            objcajero.Cargar();
            objcajero.grabarEnDisco();
            break;
/*
        case 2:
            mostarCajerosActivos();
            flag=false;
            existeCajero= false;
            while (existeCajero == false)
            {
                if (flag==false)
                {
                    cout << "El ID del Cajero a editar:" << endl;
                    cin >> idCajeroEditar;
                    flag=true;
                }
                else
                {
                    cout << "El ID del Cajero ingresado no existe:" << endl;
                    cout << "Vuelva a ingresar el ID:" << endl;
                    cin >> idCajeroEditar;
                }
                existeCajero = validarCajeroID(idCajeroEditar);
            }
            if (existeCajero==true)
            {
                editarCajeroID(idCajeroEditar);
                ///Aca va la parte de editar Cajero por ID
            }
            break;

        /*
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

            break;
            */
        /*case 8:
            mostarCajeros();
            break;
       /*
        default:
            cout << "Debe ingresar una opcion correcta" << endl;
            break;*/
        }

    }
    while(opcion != 0);
}
