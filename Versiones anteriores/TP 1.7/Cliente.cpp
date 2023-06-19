#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include "Cliente.h"
#include "Fecha.h"
#include "funcionesClientes.h"

using namespace std;

Cliente::Cliente()
{
    //ctor
}

void Cliente::setNombre(const char *nombre)
{
    strcpy(_nombre,nombre);
}
void Cliente::setApellido(const char *apellido)
{
    strcpy(_apellido, apellido);
}
void Cliente::setEmail(const char *email)
{
    strcpy(_email, email);
}
void Cliente::setPassword(const char *password)
{
    strcpy(_password, password);
}
void Cliente::setUser(const char* user)
{
    strcpy(_user, user);
}
void Cliente::setDni(int dni)
{
    _dni = dni;
}
void Cliente::setActivo(bool flag)
{
    _activo = flag;
}
void Cliente::setNumeroTelefono(int nroTelefono)
{
    _nroTelefono = nroTelefono;
}

void Cliente::CargarCliente() {
    int dni, nroTelefonico;
    bool existeDni;
    Fecha fecha;
    fecha.actualFecha();
    cout << "INGRESE DNI: " <<endl;
    cin>>dni;
    existeDni = validarDni(dni);
    if(existeDni) {
        cout<<"DNI INGRESADO YA EXISTENTE, POR FAVOR INGRESE UN DNI NO EXISTENTE"<<endl;
        return;
    }
    _dni = dni;
    cout << "INGRESE NOMBRE: " <<endl;
    cargarCadena(_nombre, 29);
    cout << "INGRESE APELLIDO: " <<endl;
    cargarCadena(_apellido, 29);
    cout << "INGRESE EMAIL: " <<endl;
    cargarCadena(_email, 29);
    cout << "INGRESE USER: " <<endl;
    cargarCadena(_user, 29);
    cout << "INGRESE PASSWORD: " <<endl;
    cargarCadena(_password, 29);

    cout << "INGRESE NUMERO TELEFONICO: " <<endl;
    cin>>nroTelefonico;
    _nroTelefono = nroTelefonico;
    _fechaCreacion = fecha;
    _cuenta.CargarCuenta(_dni);
    _direccion.Cargar();

    _activo = true;
}

void Cliente::MostrarCliente() {
    cout<<"-----------------"<<endl;
    cout<<"DATOS CLIENTE:"<<endl;
    cout<<"NOMBRE: "<<_nombre<<endl;
    cout<<"APELLIDO: "<<_apellido<<endl;
    cout<<"DNI: "<<_dni<<endl;
    cout<<"USER: "<<_user<<endl;
    cout<<"PASSWORD: "<<_password<<endl;
    cout<<"NUMERO DE TELEFONO: "<<_nroTelefono<<endl;
    _cuenta.MostrarCuenta();
    _direccion.Mostrar();
}
