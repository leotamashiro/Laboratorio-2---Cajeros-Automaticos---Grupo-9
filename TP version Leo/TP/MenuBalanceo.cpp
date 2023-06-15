#include <iostream>
#include <string>
#include "MenuAdmin.h"
#include "funciones.h"

using namespace std;

void balanceoMenu()
{
    int opcion;
    int idCajero, numSucural;
    bool primerIngreso;
    bool dineroCajero;
    bool montoPosible;// multiplo de 100
    int montoACargar;
    do
    {
        cout << "--------------------------" << endl;
        cout << "----MENU Balanceo----" << endl;
        cout << "--------------------------" << endl;
        cout << "1. Mostar Carga de los Cajeros" << endl;
        cout << "2. Balancear Equipos" << endl;
        cout << endl;
        cout << "0. Salir" << endl;
        cout << "--------------------------" << endl;
        cout << endl;
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            numSucural = pedirleAlClienteNumSucursal();
            idCajero = pedirleAlClienteCajero(numSucural);
            mostarCargaCajero(idCajero);
            break;
        case 2:
            {
                numSucural = pedirleAlClienteNumSucursal();
                idCajero = pedirleAlClienteCajero(numSucural);
                mostarCargaCajero(idCajero);
                ustedesPuedeCargar(idCajero);
                dineroCajero=false;
                primerIngreso=true;
                montoPosible=false;
                do
                {
                    if ((primerIngreso==true)&&(montoPosible==false))
                    {
                        cout << "Por fsvor ingrese la cantidad de dinero que desea cargar en el cajero: ";
                        cin >> montoACargar;
                        primerIngreso=false;
                        if ((montoACargar%100==0) && (montoACargar>=100))
                        {
                            montoPosible=true;
                        }
                    }
                    else
                    {
                        cout << "Ingrese un numero multiplo de 100: ";
                        cin >> montoACargar;
                        if ((montoACargar%100==0) && (montoACargar>=100))
                        {
                            montoPosible=true;
                        }
                    }
                    dineroCajero = esPosibleCargarCajero(idCajero, montoACargar);

                }while ((montoPosible==true) && (dineroCajero==true));
            }

            break;
        default:
            cout << "Debe ingresar una opcion correcta" << endl;
            break;
        }

    }
    while(opcion != 0);
}
