#ifndef AUXULIARCAJERO_H
#define AUXULIARCAJERO_H
#include "funciones.h"
#include "Cajero.h"

using namespace std;

class AuxuliarCajero
{
    private:
        int idCajero;
        int capacidad;

    public:
        AuxuliarCajero();
        ///gets
        int getIdCajero();
        int getCapacidad();

        ///sets
        void setIdCajero(int _idCajero);
        void setCapacidad(int _capacidad);

        void MostrarBilletes();

        bool editarEnDisco(int);
        void grabarEnDisco();
        bool leerDeDisco(int);
};

#endif // AUXULIARCAJERO_H
