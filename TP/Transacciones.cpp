#include "Transacciones.h"

///gets
int Transacciones::getNumTransaccion()
{
    return numTransaccion;
}

int Transacciones::getIdProcedencia()
{
    return id;
}

Fecha Transacciones::getFechaTranssacion()
{
    return fechaTransaccion;
}

int Transacciones::getDniCliente()
{
    return dniCliente;
}

float Transacciones::getMonto()
{
    return monto;
}

bool Transacciones::getConfirmada()
{
    return confirmada;
}

int Transacciones::getTipoTransaccion() {
    return tipoTransaccion;
}
///sets
void Transacciones::setNumTransaccion(int _numTransaccion)
{
    numTransaccion=_numTransaccion;
}

void Transacciones::setIdProcedencia(int _id)
{
    id =_id;
}

void Transacciones::setDniCliente(int _dniCliente)
{
    dniCliente=_dniCliente;
}

void Transacciones::setFechaTransaccion(Fecha _fechaTransaccion)
{
    fechaTransaccion=_fechaTransaccion;
}

void Transacciones::setMonto(float _monto)
{
    monto=_monto;
}

void Transacciones::setConfirmada(bool _confirmada)
{
    confirmada=_confirmada;
}

void Transacciones::setTipoTransaccion(int _tipoTransaccion) {
    tipoTransaccion = _tipoTransaccion;
}

void Transacciones::Mostrar()
{
    cout << "---------------------------------" << endl;
    cout << "Numero de Transaccion: " << numTransaccion << endl;
    if(tipoTransaccion == 1) {
        cout << "ID Cajero: " << id << endl;
    } else {
        cout << "Numero Cuenta: "<< id <<endl;
    }
    cout << "Importe: " << monto << endl;
    cout << "DNI del Cliente: " << dniCliente << endl;
    cout << "Tipo de Transaccion " <<tipoTransaccion<<endl;
    cout << "Fecha: ";
    fechaTransaccion.Mostrar();
    cout << endl;
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

int Transacciones::contarRegistros()
{
        FILE *p;
        p=fopen("transacciones.dat", "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Transacciones);
}

