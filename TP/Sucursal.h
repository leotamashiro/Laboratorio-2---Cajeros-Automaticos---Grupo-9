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
        char nombreSucursal [60];
        bool estadoSucursal;
    public:

        ///gets

        int getNumeroSucursal();
        char *getNombreSucursal();
        bool getEstadoSucursal();
        Direccion getDirecSucursal();

        ///sets
        void setNumeroSucursal(int _numSucursal);
        void setNombreSucursal(char *_nombreSucursal);
        void setDirecSucursal(Direccion _direcSucursal);
        void setEstadoSucursal(bool _estadoSucursal);

        void Cargar();
        void Mostrar();

        bool grabarEnDisco(int);
        void grabarEnDisco();
        bool leerDeDisco(int);

};

#endif // SUCURSAL_H
