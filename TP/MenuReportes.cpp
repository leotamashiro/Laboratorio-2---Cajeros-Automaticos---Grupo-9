#include <iostream>
#include <string>
#include <cstring>
#include "MenuAdmin.h"
#include "funcionesReportes.h"

using namespace std;

void reportes()
{
    int opcion;
    do
    {
        cout << "--------------------------" << endl;
        cout << "-------MENU Reportes------" << endl;
        cout << "--------------------------" << endl;
        cout << "1. Top 3 Sucursales" << endl;
        cout << "2. Top 5 Cajeros" << endl;
        cout << "3. Transacciones realizadas en un Perido de Tiempo" << endl;
        cout << "4. Cantidad Total de Extracciones por un dia" << endl;
        cout << "5. Cantidad y Monto Mensual de Ingresos de los Clientes" << endl;
        cout << "6. Porcentaje Mensual de Extracciones en un anio" << endl;
        cout << endl;
        cout << "0. Salir" << endl;
        cout << "--------------------------" << endl;
        cout << endl;
        cin >> opcion;
        system("cls");

        switch(opcion)
        {
        case 1:
            topSucursales();
            system("pause");
            system("cls");
            break;
        case 2:
            topCajeros();
            system("pause");
            system("cls");
            break;
        case 3:
            transaccionesPeriodoTiempo();
            system("pause");
            system("cls");
            break;
        case 4:
            cantidadDineroExtraidoPorDia();
            system("pause");
            system("cls");
            break;
        case 5:
            cantidadDineroIngresadoClientesPorMes();
            system("pause");
            system("cls");
            break;
        case 6:
            porcetajeExtracionesPorAnio();
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
