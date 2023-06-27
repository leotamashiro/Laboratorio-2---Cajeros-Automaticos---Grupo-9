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
      int buscarClientePorApellido(const char *_apellido);
      bool sobreescribirCliente(Cliente reg, int posicionAReemplazar);

};

#endif // ARCHIVOCLIENTE_H
