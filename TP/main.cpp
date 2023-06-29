#include <iostream>
#include <string>
#include <cstring>
#include "MenuAdmin.h"
#include "funciones.h"
#include "funcionesClientes.h"

using namespace std;


int main()
{
//    Transacciones obj;
//    Fecha fec;
//    Cuenta cuenta;
//    int dni=96;
//    cuenta.buscarCuentaPorDni(dni);
////    int id=10;
//    float monto;
//    for (int i=39; i<45; i++)
//    {
//        cout << "fecha: ";
//        fec.Cargar();
//        cout << "\n" << "monto" << "\n";
//        cin >> monto;
//        cout << "\n";
//        obj.setNumTransaccion(i);
//        obj.setIdProcedencia(cuenta.getNumeroCuenta());
//        obj.setDniCliente(dni);
//        obj.setFechaTransaccion(fec);
//        obj.setMonto(monto);
//        obj.setConfirmada (true);
//        obj.setTipoTransaccion(2);
//        obj.grabarEnDisco();
//        cout << i <<"\n";
//    }

//    ArchivoCliente arc("clientes.dat");
//    Cliente cliente;
//    int total = arc.getCantidadRegistros();
//    for(int i = 0; i < total; i++) {
//        cliente = arc.leerCliente(i);
//        if(cliente.getActivo()) {
//            cliente.MostrarCliente();
//        }
//        if(cliente.getTelefono() == 104 && cliente.getActivo()) {
//            cliente.MostrarCliente();
//            cliente.setActivo(false);
//            arc.sobreescribirCliente(cliente, i);
//
//        }
//    }
//    Cuenta cuenta;
//    int total = cuenta.contarRegistros();
//    for(int i = 0; i < total; i++) {
//        cuenta.leerDeDisco(i);
//        if(cuenta.getDniCliente() == 10) {
//            cuenta.setSaldo(0);
//            cuenta.editarEnDisco(i);
//        }
//    }

    reportes();
//    menuUsuario();

    return 0;
}


