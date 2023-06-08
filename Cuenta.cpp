#include <cstdio>
#include "Cuenta.h"
#include "funcionesClientes.h"

Cuenta::Cuenta()
{
    //ctor
}

void Cuenta::setSaldoAumentar(float cantidad)
{
    _saldo += cantidad;
}

int Cuenta::setSaldoDecrementar(float cantidad)
{
    if(cantidad > _saldo)
    {
        return 1;
    }
    _saldo -= cantidad;
    return 0;
}

void Cuenta::setActivo(bool flag)
{
    _activo = flag;
}

void Cuenta::CargarCuenta(int dni)
{
    int opt;
    string cuentaCorriente = "CUENTA CORRIENTE";
    string cuentaAhorro = "CUENTA AHORRO";
    bool flag = false;
    _numeroCuenta = generarNumeros(10000, 99999);
    _saldo = 0;
    while(!flag)
    {
        cout<<"INGRESE QUE TIPO DE CUENTA DESEA: "<<endl<<"1. Cuenta Corriente"<<endl<<"2. Cuenta Ahorro"<<endl;
        cin>>opt;
        if(opt == 1)
        {
            strcpy(_tipoCuenta, cuentaCorriente.c_str());
            flag = true;
        }
        else if (opt == 2)
        {
            strcpy(_tipoCuenta, cuentaAhorro.c_str());
            flag = true;
        }
        else
        {
            cout<<"OPCION NO VALIDA. INGRESE UNA DE LAS OPCIONES POSIBLES"<<endl;
            flag = false;
        }
    }
    _dniCliente = dni;
    _tarjeta.cargarTarjeta(_numeroCuenta);
}

void Cuenta::MostrarCuenta() {
    cout<<"-----------------"<<endl;
    cout<<"DATOS CUENTA:"<<endl;
    cout<<"NUMERO DE CUENTA: "<<_numeroCuenta<<endl;
    cout<<"SALDO: "<<_saldo<<endl;
    cout<<"TIPO DE CUENTA: "<<_tipoCuenta<<endl;
    _tarjeta.mostrarTarjeta();
}


