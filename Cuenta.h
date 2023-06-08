#ifndef CUENTA_H
#define CUENTA_H
#include "Tarjeta.h"

class Cuenta
{
    private:
        int _numeroCuenta;
        float _saldo;
        char _tipoCuenta[30];
        Tarjeta _tarjeta;
        bool _activo;
        int _dniCliente;
    public:
        Cuenta();
        int getNumeroCuenta() {return _numeroCuenta;}
        float getSaldo() {return _saldo;}
        const char* getTipoCuenta() {return _tipoCuenta;}
        Tarjeta getTarjeta() {return _tarjeta;}
        int getDniCliente() {return _dniCliente;}

//        void setNumeroCuenta();
        void setSaldoAumentar(float cantidad);
        int setSaldoDecrementar(float cantidad);
        void setTipoCuenta(char* tipoCuenta);
        void setActivo(bool flag);

        void CargarCuenta(int dni);
        void MostrarCuenta();

};

#endif // CUENTA_H
