///Ver si se agrega la camtidad de saldo que tiene en la cuenta
#include <iostream>
#include "MenuAdmin.h"
#include "Transacciones.h"
#include "UsuarioLogin.h"
#include "Cliente.h"
#include <time.h>

using namespace std;
/**
guardar en transacciones.dat
y auxCajero.dat
y cuenta.dat

*/
void menuExtraxion(int dni, int idCajero)
{
    bool dineroCliente;
    bool dineroCajero;
    bool montoPosible;
    bool estadoTransaccion;
    float monto;
    do
    {
        montoPosible=false;
        cout << "Por favor ingrese el monto que desea retirar del cajero: ";
        cin >> monto;
        int intMonto = static_cast<int>(monto);
        if ((intMonto >= BILLETE) && (intMonto % BILLETE == 0))
        {
            montoPosible=true;
        }
        else
        {
            montoPosible=false;
            cout << "Ingrese un numero multiplo de: " << BILLETE << endl;
        }
    }while (montoPosible==false);

    dineroCliente = verificarSaldoDisplonible(dni, monto); // false Saldo insuficiente // true tiene dinero disponible para extarer
    dineroCajero = verificarDineroEnCajero(idCajero, monto);// false Cajero no tiene suficiente efectivo

    if (dineroCliente==true)
    {
        if (dineroCajero==true)
        {
            restarSaldoCuentaCliente(dni, monto);
            restarDineroCajero(idCajero, monto);
            /**
            Hasta aca, ya le reste el dinero a la cuenta y al cajero
            y supuestamente se lo di al cliente
            */
            estadoTransaccion =true;
            operacionTransaccion(idCajero, monto, dni, 1, estadoTransaccion); /// Aca me genera la transaccion y la guarda en transaccion.dat
            cout << "Por favor retire el dinero" << endl;
            system("cls");
        }
        else
        {
            estadoTransaccion=false;
            cout << "El cajero en el que usted esta no cuenta con esa cantidad de efectivo." << endl;
            cout << "Por favor dirijase a otro Cajero, o intene sacar menos dinero" << endl;
            operacionTransaccion(idCajero, monto, dni, 1, estadoTransaccion);
        }
    }
    else
    {
        cout << "Usted no cuenta con saldo suficiente" << endl;
    }
}
