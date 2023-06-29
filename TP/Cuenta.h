#ifndef CUENTA_H
#define CUENTA_H
//#include "Tarjeta.h"

class Cuenta
{
private:
    int numeroCuenta;
    float saldo;
    bool activo;
    int dniCliente;
public:
    Cuenta();
    int getNumeroCuenta();
    float getSaldo();
    int getDniCliente();
    bool getActivo();

    void setNumeroCuenta();
    void setSaldoAumentar(float cantidad);
    int setSaldoDecrementar(float cantidad);
    void setActivo(bool flag);
    void setSaldo(float cantidad);

    void CargarCuenta(int dni);
    void MostrarCuenta();

    bool editarEnDisco(int);
    void grabarEnDisco();
    bool leerDeDisco(int);
    int contarRegistros();
    int buscarCuentaPorDni(int dni);


};

#endif // CUENTA_H
