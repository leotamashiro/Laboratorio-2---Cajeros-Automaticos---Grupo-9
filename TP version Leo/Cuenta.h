#ifndef CUENTA_H
#define CUENTA_H
//#include "Tarjeta.h"

class Cuenta
{
private:
    int numeroCuenta;
    float saldo;
//        char _tipoCuenta[30];

    bool activo;
    int dniCliente;
public:
    Cuenta();
    int getNumeroCuenta();
    float getSaldo();
//        const char* getTipoCuenta();
    int getDniCliente();
    bool getActivo();

    void setNumeroCuenta();
    void setSaldoAumentar(float cantidad);
    int setSaldoDecrementar(float cantidad);
//        void setTipoCuenta(char* tipoCuenta);
    void setActivo(bool flag);

    void CargarCuenta(int dni);
    void MostrarCuenta();

    bool editarEnDisco(int);
    void grabarEnDisco();
    bool leerDeDisco(int);
    int contarRegistros();


};

#endif // CUENTA_H
