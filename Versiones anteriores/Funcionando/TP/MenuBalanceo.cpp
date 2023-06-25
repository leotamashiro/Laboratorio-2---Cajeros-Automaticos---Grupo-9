#include <iostream>
#include <string>
#include "MenuAdmin.h"
#include "funciones.h"
#include "funcionesClientes.h"

using namespace std;

void balanceoMenu()
{
    int opcion;
    int idCajero, numSucural;
    bool sePuedeCargarCajero;
    bool montoPosible;
    int montoACargar;
    do
    {
        cout << "---------------------------------" << endl;
        cout << "----------MENU Balanceo----------" << endl;
        cout << "---------------------------------" << endl;
        cout << "1. Mostar Carga de los Cajeros" << endl;
        cout << "2. Balancear Equipos" << endl;
        cout << "3. Visualizar Transacciones" << endl;
        cout << endl;
        cout << "0. Salir" << endl;
        cout << "---------------------------------" << endl;
        cout << endl;
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            system("cls");
            numSucural = pedirleAlClienteNumSucursal();
            idCajero = pedirleAlClienteCajero(numSucural);
            mostarCargaCajero(idCajero);//Muestro la cantidad de plata que tiene el cajero
            system("pause");
            system("cls");
            break;
        case 2:
            {
                system("cls");
                numSucural = pedirleAlClienteNumSucursal();
                idCajero = pedirleAlClienteCajero(numSucural);
                mostarCargaCajero(idCajero);
                ustedPuedeCargar(idCajero);
                sePuedeCargarCajero=false;
                do
                {
                    montoPosible=false;
                    cout << "Por favor ingrese la cantidad de pesos que desea cargar en el cajero: ";
                    montoACargar = validarNumerosIngresados(); // ingreso valido montoACargar como numero enteo
                    //cin >> montoACargar;
                    if ((montoACargar >= BILLETE) && (montoACargar % BILLETE == 0))
                    {
                        montoPosible=true;
                    }
                    else
                    {
                        montoPosible=false;
                        cout << "Ingrese un numero multiplo de: " << BILLETE << endl;
                    }
                    sePuedeCargarCajero = esPosibleCargarCajero(idCajero, montoACargar);
                }while ((montoPosible==false)&&(sePuedeCargarCajero==false));
                editarCargaCajero(idCajero, (montoACargar/BILLETE)); //edito el .dat de auxCajero
            }
            system("pause");
            system("cls");
            break;

        case 3:
            system("cls");
            mostrarTransacciones();
            ///Transacciones
            system("pause");
            system("cls");
            break;
            case 0:
                system("cls");
            break;
        default:
            cout << "Debe ingresar una opcion correcta" << endl;
            break;
        }

    }
    while(opcion != 0);
}
