#ifndef SUCURSAL_H
#define SUCURSAL_H
#include <iostream>
#include <string>
#include <cstring>
#include "Direccion.h"


class Sucursal
{
    private:
        int numSucursal;
        Direccion direcSucursal;
        char nombreSucursal [40];
        bool estadoSucursal;
    public:

        ///gets

        int getNumeroSucursal();
        std::string getNombreSucursal();
        bool getEstadoSucursal();
        Direccion getDirecSucursal();

        ///sets
        void setNumeroSucursal(int _numSucursal);
        void setNombreSucursal(std::string _nombreSucursal);
        void setDirecSucursal(Direccion _direcSucursal);
        void setEstadoSucursal(bool _estadoSucursal);

        void Cargar();
        void Mostrar();

        bool grabarEnDisco(int);
        void grabarEnDisco();
        bool leerDeDisco(int);

};

#endif // SUCURSAL_H
