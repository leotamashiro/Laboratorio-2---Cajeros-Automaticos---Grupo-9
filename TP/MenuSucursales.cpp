/**
Creo que funciona todo
*/
#include <iostream>
#include <string>
#include <cstring>
#include "Direccion.h"
#include "Sucursal.h"
#include "funciones.h"
#include "funcionesClientes.h"

using namespace std;

void menuSucursales()
{
    int opcion, numSucEditar=0, numSucMostar=0, numSucuEstado=0;
    bool validSucu;
    bool validSucuEstado;
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
        system("cls");

        switch(opcion)
        {
            case 1:
                Sucursal sucu;
                sucu.Cargar();
                sucu.grabarEnDisco();
                system("cls");
                break;

            case 2:
                {
                    mostarSucursalesActivas();
                    flag=false;
                    validSucu == false;
                    do
                    {
                        if (flag==false)
                        {
                            cout << "El numero de sucursal a editar:" << endl;
                            numSucEditar = validarNumerosIngresados(); // ingreso numSucEditar
                            //cin >> numSucEditar;
                            flag=true;
                        }
                        else
                        {
                            cout << "El numero de sucursal ingresado no existe:" << endl;
                            cout << "Vuelva a ingresar el numero:" << endl;
                            numSucEditar = validarNumerosIngresados(); // ingreso numSucEditar
                            //cin >> numSucEditar;
                        }

                        validSucu=validarSucursal(numSucEditar);
                        validSucuEstado=validarSucursalEstado(numSucEditar);
                    }while(validSucu == false);

                    if (validSucuEstado==true)
                    {
                        editarSucursal(numSucEditar);
                    }
                    else
                    {
                        cout << "Sucursal no puede ser Editada, esta dada de Baja:" << endl;
                    }
                }
                system("pause");
                system("cls");
                break;

            case 3:
                {
                    mostarSucursalesActivas();
                    flag=false;
                    validSucu == false;
                    do
                    {
                        if (flag==false)
                        {
                            cout << "Ingrese el numero de Sucursal que desea Borrar:" << endl;
                            numSucuEstado = validarNumerosIngresados(); // ingreso numSucuEstado
                            //cin >> numSucuEstado;
                            flag=true;
                        }
                        else
                        {
                            cout << "El numero de sucursal ingresado no existe:" << endl;
                            cout << "Vuelva a ingresar el numero:" << endl;
                            numSucuEstado = validarNumerosIngresados(); // ingreso numSucuEstado
                            //cin >> numSucuEstado;
                        }

                        validSucu=validarSucursal(numSucuEstado);
                        validSucuEstado=validarSucursalEstado(numSucEditar);
                    }while (validSucu == false);
                    if (validSucuEstado==true)
                    {
                        borrarSucursal(numSucuEstado);
                        borrarCajerosXSucursal(numSucuEstado);
                    }
                    else
                    {
                        cout << "Sucursal esta dada de Baja:" << endl;
                    }
                }
                system("pause");
                system("cls");
                break;

            case 4:
                {
                    mostarSucursalesInactivas();
                    flag=false;
                    validSucu == false;
                    do
                    {
                        if (flag==false)
                        {
                            cout << "Ingrese el numero de Sucursal que desea dar de Alta:" << endl;
                            numSucuEstado = validarNumerosIngresados(); // ingreso numSucuEstado
                            //cin >> numSucuEstado;
                            flag=true;
                        }
                        else
                        {
                            cout << "El numero de sucursal ingresado no existe:" << endl;
                            cout << "Vuelva a ingresar el numero:" << endl;
                            numSucuEstado = validarNumerosIngresados(); // ingreso numSucuEstado
                            //cin >> numSucuEstado;
                        }

                        validSucu=validarSucursal(numSucuEstado);
                        validSucuEstado=validarSucursalEstado(numSucuEstado);
                    }while (validSucu == false);
                    if (validSucuEstado==false)
                    {
                        darAltaSucursal(numSucuEstado);
                    }
                    else
                    {
                        cout << "La Sucursal esta Activa:" << endl;
                    }
                }
                system("pause");
                system("cls");
                break;

            case 5:
                cout << "El numero de sucursal que de desea mostar:" << endl;
                numSucMostar = validarNumerosIngresados(); // ingreso valido numSucMostar como numero int
                //cin >> numSucMostar;
                listarSucuNumero(numSucMostar);
                system("pause");
                system("cls");
                break;

            case 6:
                mostarSucursalesActivas();
                system("pause");
                system("cls");
                break;

            case 7:
                mostarSucursalesInactivas();
                system("pause");
                system("cls");
                break;

            case 8:
                mostarSucursales();
                system("pause");
                system("cls");
                break;

            default:
                //cout << "Debe ingresar una opcion correcta" << endl;
                break;
    }

    }
    while(opcion != 0);
}
