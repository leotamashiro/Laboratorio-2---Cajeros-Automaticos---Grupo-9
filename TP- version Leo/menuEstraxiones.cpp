///Ver si se agrega la camtidad de saldo que tiene en la cuenta

#include <iostream>
#include "MenuAdmin.h"
#include "AuxuliarCajero.h"
#include "Transacciones.h"
#include "UsuarioLogin.h"
#include "Cliente.h"
#include <time.h>

using namespace std;
/**
Verificar que user tenga saldo mayor al monto
Verificar que cajero tenga dinero mayor al monto
generar un numero de transaccion
restar la plata de la cuenta del cliente
restar la plata del cajero
guardar en transacciones.dat
y auxCajero.dat
y Cliente.dat

*/
void menuExtraxion(int dni, int idCajero)
{
    bool primerIngreso;
    bool dineroCliente;
    bool dineroCajero;
    int monto;
    float saldoCuenta;
    primerIngreso=true;
    do
    {
        if (primerIngreso==true)
        {
            cout << "Por fsvor ingrese la cantidad de dinero que desea retirar: ";
            cin >> monto;
            primerIngreso=false;
        }
        else
        {
            cout << "Ingrese un numero multiplo de 100: ";
            cin >> monto;
        }

    }while ((monto%100==0) && (monto>=100));

    dineroCliente = verificarSaldoDisplonible(dni, monto); // false Saldo insuficiente // true tiene dinero disponible para extarer
    dineroCajero = verificarDineroEnCajero(idCajero, monto);// false Cajero no tiene suficiente efectivo

    if (dineroCliente==true)
    {
        if (dineroCajero==true)
        {
            /**
            Aca va la parte de sacar plata
            */
        }
        else
        {
            cout << "El cajero en el que usted esta no cuenta con esa cantidad de efectivo." << endl;
            cout << "Por favor dirijase a otro Cajero, o intene sacar menos dinero" << endl;
        }
    }
    else
    {
        cout << "Usted no cuenta con saldo suficiente" << endl;
    }

    //saldoCuenta = traerMontoCuenta();
}
