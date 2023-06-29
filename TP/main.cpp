#include <iostream>
#include <string>
#include <cstring>
#include "MenuAdmin.h"
#include "funciones.h"
#include "funcionesClientes.h"

using namespace std;


int main()
{
    Transacciones obj;
    Fecha fec;
    int id=10;
    int dni=10;
    float monto;
    for (int i=26; i<30; i++)
    {
        cout << "fecha: ";
        fec.Cargar();
        cout << "\n" << "monto" << "\n";
        cin >> monto;
        cout << "\n";
        obj.setNumTransaccion(i);
        obj.setIdProcedencia(id);
        obj.setDniCliente(10);
        obj.setFechaTransaccion(fec);
        obj.setMonto(monto);
        obj.setConfirmada (true);
        obj.setTipoTransaccion(1);
        obj.grabarEnDisco();
        cout << i <<"\n";
    }

    menuUsuario();

    return 0;
}


