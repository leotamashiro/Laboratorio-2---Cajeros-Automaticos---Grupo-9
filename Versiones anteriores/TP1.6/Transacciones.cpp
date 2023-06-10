#include "Transacciones.h"

///gets
double Transacciones::getNumTransaccion()
{
    return numTransaccion;
}

int Transacciones::getIdCajero()
{
    return idCajero;
}

Fecha Transacciones::getFechaTranssacion()
{
    return fechaTransaccion;
}

int Transacciones::getDniCliente()
{
    return dniCliente;
}

int Transacciones::getMonto()
{
    return monto;
}
///sets
void Transacciones::setNumTransaccion(double _numTransaccion)
{
    numTransaccion=_numTransaccion;
}

void Transacciones::setIdCajero(int _idCajero)
{
    idCajero=_idCajero;
}

void Transacciones::setFechaTransaccion(Fecha _fechaTransaccion)
{
    fechaTransaccion=_fechaTransaccion;
}

void Transacciones::setMonto(int _monto)
{
    monto=_monto;
}
