#ifndef TRANSACCIONES_H
#define TRANSACCIONES_H
#include <iostream>
#include "Fecha.h"
#include "funciones.h"

class Transacciones
{
    private:
        int numTransaccion;
        int idCajero;
        Fecha fechaTransaccion;
        int dniCliente;
        int monto;
        bool confirmada;

    public:

        int getNumTransaccion ();
        int getIdCajero();
        Fecha getFechaTranssacion();
        int getDniCliente();
        int getMonto();
        bool getConfirmada();

        void setNumTransaccion(int _numTransaccion);
        void setIdCajero(int _idCajero);
        void setDniCliente(int _dniCliente);
        void setFechaTransaccion(Fecha _fechaTransaccion);
        void setMonto(int _monto);
        void setConfirmada (bool _confirmada);

        void grabarEnDisco();
        bool leerDeDisco(int);
        int contarRegistros();

};

#endif // TRANSACCIONES_H
