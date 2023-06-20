#ifndef CLIENTE_H
#define CLIENTE_H
#include "Cuenta.h"
#include "Fecha.h"
#include "Direccion.h"


class Cliente
{
    private:
        int _dni;
        char _nombre[30];
        char _apellido[30];
        char _email[30];
        int _nroTelefono;
        char _user[30];
        char _password[30];
        Cuenta _cuenta;
        Fecha _fechaCreacion;
        Direccion _direccion;
        bool _activo;
    public:
        Cliente();
        int getDni() {return _dni;}
        const char* getNombre() {return _nombre;}
        const char* getApellido() {return _apellido;}
        const char* getEmail() {return _email;}
        const char* getUser() {return _user;}
        const char* getPassword() {return _password;}
        int getTelefono() {return _nroTelefono;}
        bool getActivo() {return _activo;}
        Cuenta getCuenta() {return _cuenta;}
        Fecha getFechaInicio() {return _fechaCreacion;}
        Direccion getDireccion() {return _direccion;}

        void setNombre(const char *nombre);
        void setApellido(const char *apellido);
        void setEmail(const char *email);
        void setUser(const char *user);
        void setPassword(const char *password);
        void setDni(int dni);
        void setNumeroTelefono(int nroTelefono);
        void setActivo(bool flag);

        void CargarCliente();
        void MostrarCliente();
};


#endif // CLIENTE_H
