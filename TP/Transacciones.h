#ifndef TRANSACCIONES_H
#define TRANSACCIONES_H
#include <iostream>
#include "Fecha.h"
#include "funciones.h"
using namespace std;

class Transacciones
{
    private:
        int numTransaccion;
        int id;
        Fecha fechaTransaccion;
        int dniCliente;
        float monto;
        int tipoTransaccion;
        bool confirmada;

    public:

        int getNumTransaccion ();
        int getIdProcedencia();
        Fecha getFechaTranssacion();
        int getDniCliente();
        float getMonto();
        int getTipoTransaccion();
        bool getConfirmada();

        void setNumTransaccion(int _numTransaccion);
        void setIdProcedencia(int _id);
        void setDniCliente(int _dniCliente);
        void setFechaTransaccion(Fecha _fechaTransaccion);
        void setMonto(float _monto);
        void setConfirmada (bool _confirmada);
        void setTipoTransaccion(int _tipoTransaccion);
        void Mostrar();

        void grabarEnDisco();
        bool leerDeDisco(int);
        int contarRegistros();

};

#endif // TRANSACCIONES_H
