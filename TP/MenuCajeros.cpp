#include <iostream>
#include <string>
#include <cstring>
#include "Cajero.h"
#include "funciones.h"
#include "funcionesClientes.h"

using namespace std;

void menuCajeros()
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
        system("cls");

        switch(opcion)
        {
        case 1:
        {
            Cajero objcajero;
            objcajero.Cargar();
            objcajero.grabarEnDisco();
            system("cls");
        }
            break;

        case 2:
        {
            mostarCajerosActivos();
            flag=false;
            existeCajero= false;
            do
            {
                if (flag==false)
                {
                    cout << "El ID del Cajero a editar:" << endl;
                    idCajeroEditar = validarNumerosIngresados(); // ingreso idCajeroEditar
                    //cin >> idCajeroEditar;
                    flag=true;
                }
                else
                {
                    cout << "El ID del Cajero ingresado no existe:" << endl;
                    cout << "Vuelva a ingresar el ID:" << endl;
                    idCajeroEditar = validarNumerosIngresados(); // ingreso idCajeroEditar
                    //cin >> idCajeroEditar;
                }
                existeCajero = validarCajeroID(idCajeroEditar);
                estadoCajero = validarCajeroEstado(numCajeroEstado);
            }while (existeCajero == false);

            if ((existeCajero==true) && (estadoCajero==true))
            {
                editarCajeroID(idCajeroEditar);
            }
            else
            {
                cout << "El cajero esta Inactivo, por favor dar de Alta para Editarlo:" << endl;
            }
        }
        system("pause");
        system("cls");
        break;

        case 3:
        {
            mostarCajerosActivos();
            flag=false;
            existeCajero= false;
            do
            {
                if (flag==false)
                {
                    cout << "El ID del Cajero a borrar:" << endl;
                    numCajeroEstado = validarNumerosIngresados(); // ingreso numCajeroEstado
                    //cin >> numCajeroEstado;
                    flag=true;
                }
                else
                {
                    cout << "El ID del Cajero ingresado no existe:" << endl;
                    cout << "Vuelva a ingresar el ID:" << endl;
                    numCajeroEstado = validarNumerosIngresados(); // ingreso numCajeroEstado
                    //cin >> numCajeroEstado;
                }
                existeCajero = validarCajeroID(numCajeroEstado);
                estadoCajero = validarCajeroEstado(numCajeroEstado);
            }while (existeCajero == false);
            if ((existeCajero==true) && (estadoCajero==true))
            {
                borrarCajero(numCajeroEstado);
            }
            else
            {
                cout << "El Cajero ya fue borrado:" << endl;
            }
        }
        system("pause");
        system("cls");
        break;

        case 4:
        {
            mostarCajerosInactivos();
            flag=false;
            existeCajero= false;
            do
            {
                if (flag==false)
                {
                    cout << "El ID del Cajero a borrar:" << endl;
                    numCajeroEstado = validarNumerosIngresados(); // ingreso numCajeroEstado
                    //cin >> numCajeroEstado;
                    flag=true;
                }
                else
                {
                    cout << "El ID del Cajero ingresado no existe:" << endl;
                    cout << "Vuelva a ingresar el ID:" << endl;
                    numCajeroEstado = validarNumerosIngresados(); // ingreso numCajeroEstado
                    //cin >> numCajeroEstado;
                }
                existeCajero = validarCajeroID(numCajeroEstado);
                estadoCajero = validarCajeroEstado(numCajeroEstado);

            }while (existeCajero == false);
            if ((existeCajero==true) && (estadoCajero==false))
            {
                darAltaCajero(numCajeroEstado);
            }
            else
            {
                cout << "El Cajero ya esta Activado:" << endl;
            }
        }
        system("pause");
        system("cls");
        break;

        ///Listar por ID
        case 5:
            cout << "Ingrese el ID del Cajero a Mostar:" << endl;
            idCajeroMostar = validarNumerosIngresados(); // ingreso valido idCajeroMostar como numero int
            //cin >> idCajeroMostar;
            mostrarCajeroID(idCajeroMostar);
            system("pause");
            system("cls");
            break;

        ///Listar Cajero por Sucursal
        case 6:
            cout << "Ingrese el Numero de Sucursal de la que desee mostrar todos los Cajeros:" << endl;
            numSucuMostrar = validarNumerosIngresados(); // ingreso valido numSucuMostrar como numero int
            //cin >> numSucuMostrar;
            mostarCajeroSucursal(numSucuMostrar);
            system("pause");
            system("cls");
            break;

        case 7:
            mostarCajerosInactivos();
            system("pause");
            system("cls");
            break;

        case 8:
            mostarCajeros();
            system("pause");
            system("cls");
            break;

        default:
            cout << "Debe ingresar una opcion correcta" << endl;
            break;
        }

    }
    while(opcion != 0);
}
