#include "Tarjeta.h"
#include "funcionesClientes.h"

Tarjeta::Tarjeta()
{
    //ctor
}

void Tarjeta::setActivo(bool flag)
{
    _activo = flag;
}

void Tarjeta::setNumeroTarjeta(int numero)
{
    _numeroTarjeta = numero;
}

void Tarjeta::setFechaVencimiento(Fecha fecha)
{
    _fechaVencimiento = fecha;
}

void Tarjeta::cargarTarjeta(int numCuenta)
{
    int numTarjeta, codSeguridad;
    numTarjeta = generarNumeros(1000, 9999);
    _numeroTarjeta = numTarjeta;
    cout<<"Numero de Tarjeta: "<<_numeroTarjeta<<endl;
    codSeguridad = generarNumeros(100, 999);
    _codigoSeguridad = codSeguridad;
    cout<<"Codigo de Seguridad: "<<_codigoSeguridad<<endl;
    _numeroCuenta = numCuenta;
    _fechaVencimiento.fechaVencimiento();
    _activo = true;
}

void Tarjeta::mostrarTarjeta() {
    cout<<"-----------------"<<endl;
    cout<<"DATOS TARJETA:"<<endl;
    cout<<"NUMERO DE TARJETA: "<<_numeroTarjeta<<endl;
    cout<<"CODIGO DE SEGURIDAD: "<<_codigoSeguridad<<endl;
    cout<<"FECHA DE VENCIMIENTO: "<<_fechaVencimiento.toString()<<endl;
}

bool Tarjeta::estaVencido()
{
    Fecha fechaActual;
    fechaActual.actualFecha();

    if(_fechaVencimiento.toString() < fechaActual.toString())
    {
        return true;
    }
    return false;
}
