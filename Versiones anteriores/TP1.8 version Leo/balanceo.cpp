#include <iostream>
#include <string>
#include <cstring>
#include "MenuAdmin.h"
#include "Cajero.h"
#include "AuxuliarCajero.h"
#include "funciones.h"

using namespace std;
void menuBalanceo()
{

    int opcion, idCajero, cantBilletes;
    bool flag=false;
    bool existeCajero=true;
    bool estadoCajero=true;
    do
    {
        cout << "-----------------------------------" << endl;
        cout << "-----------MENU BALANCEO-----------" << endl;
        cout << "-----------------------------------" << endl;
        cout << "1. Cargar Billetes" << endl;
        cout << "2. Vizualisar Transacciones" << endl;
        cout << "3. Verificar Carga de un Cajero" << endl;
        cout << "0. Salir" << endl;
        cout << "-----------------------------------" << endl;
        cout << endl;
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            {
                AuxuliarCajero auxCajero;
                mostarCajerosActivos();
                Cajero objcajero;
                int capacidad;
                bool flagCash=false;
                flag=false;
                existeCajero=false;
                estadoCajero=true;
                while (existeCajero == false)
                {
                    if (flag==false)
                    {
                        cout << "El ID del Cajero a Cargar:" << endl;
                        cin >> idCajero;
                        flag=true;
                    }
                    else
                    {
                        cout << "El ID del Cajero ingresado no existe:" << endl;
                        cout << "Vuelva a ingresar el ID:" << endl;
                        cin >> idCajero;
                    }
                    existeCajero = validarCajeroID(idCajero);
                    estadoCajero = validarCajeroEstado(idCajero);
                }
                if ((existeCajero==true) && (estadoCajero==true))
                {
                    auxCajero.MostrarBilletes();
                    flagCash=false;

                    while (flagCash==false)
                    {
                        cout << "Ingrese la Cantidad de Billetes que desea cargar: " << endl;
                        cin >> cantBilletes;

                        if ((cantBilletes + auxCajero.getCapacidad()) < objcajero.getCapcidadMaxima())
                        {
                            flagCash=true;
                            capacidad= auxCajero.getCapacidad()+ cantBilletes;
                            editarCargaCajero(idCajero, capacidad);

                        }
                        else
                        {
                            cout << "La cantidad que desea cargar supera el limite maximo de cargar posible para este Cajero: " << endl;
                        }
                    }
                }
                else
                {
                    cout << "El cajero esta Inactivo, por favor dar de Alta para poder Cargarlo:" << endl;
                }
            }
            break;

        /*
        case 2:
        break;
        */
        case 3:
            {
                flag=false;
                existeCajero=false;
                estadoCajero=false;
                mostarCajerosActivos();
                while (existeCajero == false)
                {
                    if (flag==false)
                    {
                        cout << "El ID del Cajero a Mostrar:" << endl;
                        cin >> idCajero;
                        flag=true;
                    }
                    else
                    {
                        cout << "El ID del Cajero ingresado no existe:" << endl;
                        cout << "Vuelva a ingresar el ID:" << endl;
                        cin >> idCajero;
                    }
                    existeCajero = validarCajeroID(idCajero);
                    estadoCajero = validarCajeroEstado(idCajero);
                }
                if ((existeCajero==true) && (estadoCajero==true))
                {
                    mostarCargaCajero(idCajero);
                }
            }
            break;

            default:
            cout << "Debe ingresar una opcion correcta" << endl;
            break;

        }

    }
    while(opcion != 0);
}

