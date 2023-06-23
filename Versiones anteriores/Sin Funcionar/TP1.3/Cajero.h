#ifndef CAJERO_H
#define CAJERO_H
#include <iostream>
#include "Fecha.h"
#include "Sucursal.h"
#include "funciones.h"

using namespace std;
class Cajero
{
    private:
        int idCajero;
        Fecha fechaInstalacion;
        int numSerie;
        int numSucursal;
        bool estadoCajero;
        Sucursal sucu;

    public:
        ///gets
        int getIdCajero();
        int getNumeroSerie();
        Fecha getFechaInstalacion();
        int getNumSucursal();
        bool getEstadoCajero();

        ///sets
        void setIdCajero(int _idCajero);
        void setNumeroSerie(int _numSerie);
        void setFechaInstalacion(Fecha _fechaInstalacion);
        void setNumSucursal(int _numSucursal);
        void setEstadoCajero(bool _estadoCajero);

        void Cargar();
        void Mostrar();

        bool editarEnDisco(int);
        void grabarEnDisco();
        bool leerDeDisco(int);
        int contarRegistros();
};

#endif // CAJERO_H
