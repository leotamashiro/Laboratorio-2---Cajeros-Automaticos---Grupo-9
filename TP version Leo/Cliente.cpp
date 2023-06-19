#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include "Cliente.h"
#include "Fecha.h"
#include "UsuarioLogin.h"
#include "funcionesClientes.h"

using namespace std;

Cliente::Cliente()
{
    //ctor
}

int Cliente::getDni()
{
    return dni;
}
const char* Cliente::getNombre()
{
    return nombre;
}
const char* Cliente::getApellido()
{
    return apellido;
}
const char* Cliente::getEmail()
{
    return email;
}
int Cliente::getTelefono()
{
    return nroTelefono;
}
bool Cliente::getActivo()
{
    return activo;
}
Fecha Cliente::getFechaInicio()
{
    return fechaCreacion;
}
Direccion Cliente::getDireccion()
{
    return direccion;
}

void Cliente::setNombre(const char *_nombre)
{
    strcpy(nombre,_nombre);
}
void Cliente::setApellido(const char *_apellido)
{
    strcpy(apellido, _apellido);
}
void Cliente::setEmail(const char *_email)
{
    strcpy(email, _email);
}
void Cliente::setDni(int _dni)
{
    dni = _dni;
}
void Cliente::setActivo(bool flag)
{
    activo = flag;
}
void Cliente::setNumeroTelefono(int _nroTelefono)
{
    nroTelefono = _nroTelefono;
}

void Cliente::CargarCliente()
{
    Cuenta cuenta;
    UsuarioLogin userLogin;
    int _dni, _nroTelefonico;
    bool existeDni;
    Fecha fecha;
    fecha.actualFecha();
    cout << "INGRESE DNI: " <<endl;
    _dni = validarNumerosIngresados();
    existeDni = validarDni(_dni);
    if(existeDni)
    {
        cout<<"DNI INGRESADO YA EXISTENTE, POR FAVOR INGRESE UN DNI NO EXISTENTE"<<endl;
        return;
    }
    dni = _dni;
    cout << "INGRESE NOMBRE: " <<endl;
    cargarCadena(nombre, 29);
    cout << "INGRESE APELLIDO: " <<endl;
    cargarCadena(apellido, 29);
    cout << "INGRESE EMAIL: " <<endl;
    cargarCadena(email, 29);

    cout << "INGRESE NUMERO TELEFONICO: " <<endl;
    nroTelefono = validarNumerosIngresados();
    fechaCreacion = fecha;
    cuenta.CargarCuenta(dni);
    userLogin.cargarLogin(dni);

    direccion.Cargar();

    activo = true;
}

void Cliente::MostrarCliente()
{
    Cuenta cuenta;
    UsuarioLogin userLogin;
    cout<<"-----------------"<<endl;
    cout<<"DATOS CLIENTE:"<<endl;
    cout<<"NOMBRE: "<<nombre<<endl;
    cout<<"APELLIDO: "<<apellido<<endl;
    cout<<"DNI: "<<dni<<endl;
    cout<<"NUMERO DE TELEFONO: "<<nroTelefono<<endl;
    cout<<"ACTIVO: "<<activo<<endl;
    direccion.Mostrar();
}
