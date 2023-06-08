#ifndef TARJETA_H
#define TARJETA_H
#include "Fecha.h"


class Tarjeta
{
    private:
        int _numeroTarjeta;
        int _codigoSeguridad;
        Fecha _fechaVencimiento;
        bool _activo;
        int _numeroCuenta;
    public:
        Tarjeta();
        int getNumeroTarjeta() {return _numeroTarjeta;}
        int getCodigoSeguridad() {return _codigoSeguridad;}
        int getNumeroCuenta() {return _numeroCuenta;}
        Fecha getFechaVencimiento() {return _fechaVencimiento;}

        void setNumeroTarjeta(int numero);
        void setFechaVencimiento(Fecha fecha);
        void setActivo(bool flag);
        bool estaVencido();
        void cargarTarjeta(int numCuenta);
        void mostrarTarjeta();
};

#endif // TARJETA_H
