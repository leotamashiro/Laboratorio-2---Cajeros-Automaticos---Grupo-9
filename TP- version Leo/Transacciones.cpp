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


bool Transacciones::editarEnDisco(int pos)
{
    bool guardo;
    FILE *p;
    p = fopen("transacciones.dat", "rb+");
    if( p == NULL ){
        return false;
    }
    fseek(p, sizeof(Transacciones)*pos, SEEK_SET);
    guardo = fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return guardo;
}

void Transacciones::grabarEnDisco()
{
    FILE *p;
    p = fopen("transacciones.dat", "ab");
    if( p == NULL ){
        return;
    }
    fwrite(this, sizeof *this, 1, p);
    fclose(p);
}
bool Transacciones::leerDeDisco(int pos)
{
    bool lectura;
    FILE *p;
    p = fopen("transacciones.dat", "rb");
    if( p == NULL ){
        return false;
    }
    fseek(p, sizeof(Transacciones)*pos, SEEK_SET);
    lectura = fread(this, sizeof *this, 1, p);
    fclose(p);
    return lectura;
}
