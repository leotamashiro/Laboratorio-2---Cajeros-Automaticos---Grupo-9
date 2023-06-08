#ifndef TRANSACCIONES_H
#define TRANSACCIONES_H
#include <iostream>
#include "Fecha.h"
#include "funciones.h"

class Transacciones
{
    private:
        double numTransaccion;
        int idCajero;
        Fecha fechaTransaccion;
        int dniCliente;
        int monto;

    public:

        double getNumTransaccion ();
        int getIdCajero();
        Fecha getFechaTranssacion();
        int getDniCliente();
        int getMonto();

        void setNumTransaccion(double _numTransaccion);
        void setIdCajero(int _idCajero);
        void setFechaTransaccion(Fecha _fechaTransaccion);
        void setMonto(int _monto);


};

#endif // TRANSACCIONES_H
