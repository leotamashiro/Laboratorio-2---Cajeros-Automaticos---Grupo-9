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
    bool sePuedeCargarCajero;
    bool montoPosible;
    int montoACargar;
    bool existeArchivoAuxCajero;
    do
    {
        cout << "---------------------------------" << endl;
        cout << "----------MENU Balanceo----------" << endl;
        cout << "---------------------------------" << endl;
        cout << "1. Mostar Carga de los Cajeros" << endl;
        cout << "2. Balancear Equipos" << endl;
        cout << "3. Vizualisar Transacciones" << endl;
        cout << endl;
        cout << "0. Salir" << endl;
        cout << "---------------------------------" << endl;
        cout << endl;
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            numSucural = pedirleAlClienteNumSucursal();
            idCajero = pedirleAlClienteCajero(numSucural);
            mostarCargaCajero(idCajero);//Muestro la cantidad de plata que tiene el cajero
            system("pause");
            system("cls");
            break;
        case 2:
            {
                numSucural = pedirleAlClienteNumSucursal();
                idCajero = pedirleAlClienteCajero(numSucural);
                mostarCargaCajero(idCajero);
                ustedesPuedeCargar(idCajero);
                sePuedeCargarCajero=false;
                primerIngreso=true;
                montoPosible=false;
                do
                {
                    if ((primerIngreso==true)&&(montoPosible==false))
                    {
                        cout << "Por favor ingrese la cantidad de pesos que desea cargar en el cajero: ";
                        cin >> montoACargar;
                        primerIngreso=false;
                        if ((montoACargar%BILLETE==0) && (montoACargar>=BILLETE))
                        {
                            montoPosible=true;
                        }
                    }
                    else
                    {
                        cout << "Ingrese un numero multiplo de: " << BILLETE ;
                        cin >> montoACargar;
                        if ((montoACargar%BILLETE==0) && (montoACargar>=BILLETE))
                        {
                            montoPosible=true;
                        }
                    }
                    existeArchivoAuxCajero=archivoAuxCajeroExiste();
                    if (existeArchivoAuxCajero==false)
                    {
                        seGeneraArchivoAuxCajero(idCajero, (montoACargar/BILLETE));
                    }
                    else
                    {
                        sePuedeCargarCajero = esPosibleCargarCajero(idCajero, montoACargar);
                    }
                }while ((montoPosible==true) && (sePuedeCargarCajero==true));
                if (sePuedeCargarCajero==true)
                {
                    editarCargaCajero(idCajero, (montoACargar/BILLETE)); //edito el .dat de auxCajero
                }
            }
            system("pause");
            system("cls");
            break;

        case 3:
            ///Transacciones
            break;
        default:
            cout << "Debe ingresar una opcion correcta" << endl;
            break;
        }

    }
    while(opcion != 0);
}
