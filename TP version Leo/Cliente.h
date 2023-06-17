#ifndef CLIENTE_H
#define CLIENTE_H
#include "Cuenta.h"
#include "Fecha.h"
#include "Direccion.h"


class Cliente
{
    private:
        int dni;
        char nombre[30];
        char apellido[30];
        char email[30];
        int nroTelefono;
        Fecha fechaCreacion;
        Direccion direccion;
        bool activo;
    public:
        Cliente();
        int getDni();
        const char* getNombre();
        const char* getApellido();
        const char* getEmail();
        int getTelefono();
        bool getActivo();
        Fecha getFechaInicio();
        Direccion getDireccion();

        void setNombre(const char *_nombre);
        void setApellido(const char *_apellido);
        void setEmail(const char *_email);
        void setDni(int _dni);
        void setNumeroTelefono(int _nroTelefono);
        void setActivo(bool flag);

        void CargarCliente();
        void MostrarCliente();
};


#endif // CLIENTE_H
