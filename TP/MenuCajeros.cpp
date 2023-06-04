/**
Arreglar el cargar cajero, funciona solo,

Funciona el editar cajero, solo se puede editar la sucursal y la fecha.
        El ID y el N° de Serie lo mantiene

Despues creo que funciona todo
*/
#include <iostream>
#include <string>
#include <cstring>
#include "Cajero.h"
#include "funciones.h"

using namespace std;

void menuCajeros ()
{
    int opcion, idCajeroEditar, numCajeroEstado, idCajeroMostar, numSucuMostrar;
    bool existeCajero=false;
    bool estadoCajero=false;
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

        /*case 1:
            Cajero objcajero;
            objcajero.Cargar();
            objcajero.grabarEnDisco();
            break;
        */

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
                estadoCajero = validarCajeroEstado(numCajeroEstado);
            }
            if ((existeCajero==true) && (estadoCajero==true))
            {
                editarCajeroID(idCajeroEditar);
            }
            else
            {
                cout << "El cajero esta Inactivo, por favor dar de Alta para Editarlo:" << endl;
            }
            break;

        case 3:
            mostarCajerosActivos();
            flag=false;
            existeCajero= false;
            while (existeCajero == false)
            {
                if (flag==false)
                {
                    cout << "El ID del Cajero a borrar:" << endl;
                    cin >> numCajeroEstado;
                    flag=true;
                }
                else
                {
                    cout << "El ID del Cajero ingresado no existe:" << endl;
                    cout << "Vuelva a ingresar el ID:" << endl;
                    cin >> numCajeroEstado;
                }
                existeCajero = validarCajeroID(numCajeroEstado);
                estadoCajero = validarCajeroEstado(numCajeroEstado);
            }
            if ((existeCajero==true) && (estadoCajero==true))
            {
                borrarCajero(numCajeroEstado);
            }
            else
            {
                cout << "El Cajero ya fue borrado:" << endl;
            }

            break;

        case 4:
            mostarCajerosInactivos();
            flag=false;
            existeCajero= false;
            while (existeCajero == false)
            {
                if (flag==false)
                {
                    cout << "El ID del Cajero a borrar:" << endl;
                    cin >> numCajeroEstado;
                    flag=true;
                }
                else
                {
                    cout << "El ID del Cajero ingresado no existe:" << endl;
                    cout << "Vuelva a ingresar el ID:" << endl;
                    cin >> numCajeroEstado;
                }
                existeCajero = validarCajeroID(numCajeroEstado);
                estadoCajero = validarCajeroEstado(numCajeroEstado);

            }
            if ((existeCajero==true) && (estadoCajero==false))
            {
                darAltaCajero(numCajeroEstado);
            }
            else
            {
                cout << "El Cajero ya esta Activado:" << endl;
            }
            break;
        ///Listar por ID
        case 5:
            cout << "Ingrese el ID del Cajero a Mostar:" << endl;
            cin >> idCajeroMostar;
            mostrarCajeroID(idCajeroMostar);
            break;

        ///Listar Cajero por Sucursal
        case 6:
            cout << "Ingrese el Numero de Sucursal de la que desee mostrar todos los Cajeros:" << endl;
            cin >> numSucuMostrar;
            mostarCajeroSucursal(numSucuMostrar);
            break;

        case 7:
            mostarCajerosInactivos();
            break;

        case 8:
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
