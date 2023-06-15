#ifndef ARCHIVOCLIENTE_H
#define ARCHIVOCLIENTE_H
#include "Cliente.h"


class ArchivoCliente
{
    private:
        char _nombre[30];
    public:
      ArchivoCliente(const char* nombre);
      int getCantidadRegistros();
      int buscarClientePorId(int ID);
      Cliente leerCliente(int nroRegistro);
      bool guardarCliente(Cliente reg);
//      int getCantidadRegistros();
//      bool guardar(Multa reg);
//      bool guardar(Multa reg, int posicionAReemplazar);
//      bool guardar(Multa *vec, int cantidadRegistrosAEscribir);
//
//      Multa leer(int nroRegistro);
//      void leer(Multa *vec, int cantidadRegistrosALeer);
//      int buscar(int ID);
//      void vaciar();
};

#endif // ARCHIVOCLIENTE_H
