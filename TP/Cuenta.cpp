#include <cstdio>
#include "Cuenta.h"
#include "funcionesClientes.h"

Cuenta::Cuenta()
{
    //ctor
}

int Cuenta::getNumeroCuenta()
{
    return numeroCuenta;
}
float Cuenta::getSaldo()
{
    return saldo;
}
//const char* getTipoCuenta() {return _tipoCuenta;}

int Cuenta::getDniCliente()
{
    return dniCliente;
}
bool Cuenta::getActivo()
{
    return activo;
}

void Cuenta::setSaldoAumentar(float cantidad)
{
    saldo += cantidad;
}

int Cuenta::setSaldoDecrementar(float cantidad)
{
    saldo -= cantidad;
    return 0;
}

void Cuenta::setActivo(bool flag)
{
    activo = flag;
}

void Cuenta::CargarCuenta(int dni)
{
    numeroCuenta = generarNumeros(10000, 99999);
    saldo = 0;
    dniCliente = dni;
    activo = true;
    this->grabarEnDisco();
}

void Cuenta::MostrarCuenta()
{
    cout<<"DATOS CUENTA:"<<endl;
    cout<<"NUMERO DE CUENTA: "<<numeroCuenta<<endl;
    cout<<"SALDO: "<<saldo<<endl;
}

bool Cuenta::editarEnDisco(int pos)
{
    bool guardo;
    FILE *p;
    p = fopen("cuenta.dat", "rb+");
    if( p == NULL )
    {
        return false;
    }
    fseek(p, sizeof(Cuenta)*pos, SEEK_SET);
    guardo = fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return guardo;
}
bool Cuenta::leerDeDisco(int pos)
{
    bool lectura;
    FILE *p;
    p = fopen("cuenta.dat", "rb");
    if( p == NULL )
    {
        return false;
    }
    fseek(p, sizeof(Cuenta)*pos, SEEK_SET);
    lectura = fread(this, sizeof *this, 1, p);
    fclose(p);
    return lectura;
}
void Cuenta::grabarEnDisco()
{
    FILE *p;
    p = fopen("cuenta.dat", "ab");
    if( p == NULL )
    {
        return;
    }
    fwrite(this, sizeof *this, 1, p);
    fclose(p);
}

int Cuenta::contarRegistros()
{
    FILE *p;
    p=fopen("cuenta.dat", "rb");
    if(p==NULL) return -1;
    fseek(p, 0,2);
    int tam=ftell(p);
    fclose(p);
    return tam/sizeof(Cuenta);
}

int Cuenta::buscarCuentaPorDni(int dni){
    int i, cantidadRegistros = this->contarRegistros();

    for(i=0; i<cantidadRegistros; i++)
    {
        this->leerDeDisco(i);
        if (this->getDniCliente() == dni)
        {
            return i;
        }
    }
    return -1;
}



