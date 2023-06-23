#ifndef CAJERO_H
#define CAJERO_H
#include <iostream>
#include "Fecha.h"
#include "Sucursal.h"
#include "funciones.h"

///Ver el tema de la capacidad de Carga de los Cajeros


using namespace std;
class Cajero
{
    private:
        int idCajero;
        Fecha fechaInstalacion;
        int numSerie;
        int numSucursal;
        bool estadoCajero;
        int capacidadMaxima=CAP_MAX;
        int capacidad;
        //Sucursal sucu;

    public:
        const int CAP_MAX = 40000;
        ///gets
        int getIdCajero();
        int getNumeroSerie();
        Fecha getFechaInstalacion();
        int getNumSucursal();
        int getCapcidadMaxima();
        int getCapacidad();
        bool getEstadoCajero();

        ///sets
        void setIdCajero(int _idCajero);
        void setNumeroSerie(int _numSerie);
        void setFechaInstalacion(Fecha _fechaInstalacion);
        void setNumSucursal(int _numSucursal);
        void setCapacidadMaxima (int _capidadMax);
        void setCapacidad(int _capacidad);
        void setEstadoCajero(bool _estadoCajero);

        void Cargar();
        void CargarEditar();
        void Mostrar();
        void MostarAlCliente();
        void MostrarBilletes();

        bool editarEnDisco(int);
        void grabarEnDisco();
        bool leerDeDisco(int);
        int contarRegistros();
};

#endif // CAJERO_H
