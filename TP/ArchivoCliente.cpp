#include <string>
#include <cstring>
#include "ArchivoCliente.h"

ArchivoCliente::ArchivoCliente(const char* nombre)
{
    strcpy(_nombre, nombre);
}

int ArchivoCliente::getCantidadRegistros()
{
    FILE *p = fopen(_nombre, "rb");

    if (p == NULL)
    {
        return 0;
    }

    fseek(p, 0, 2);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(Cliente);
}

bool ArchivoCliente::guardarCliente(Cliente reg)
{
  FILE *p = fopen(_nombre, "ab");

  if (p == NULL)
  {
    return false;
  }

  bool pudoEscribir = fwrite(&reg, sizeof(Cliente), 1, p);
  fclose(p);
  return pudoEscribir;
}


Cliente ArchivoCliente::leerCliente(int nroRegistro)
{
    Cliente aux;
    FILE *p = fopen(_nombre, "rb");
    if (p == NULL)
    {
        return aux;
    }

    fseek(p, nroRegistro * sizeof(Cliente), SEEK_SET);
    fread(&aux, sizeof(Cliente), 1, p);
    fclose(p);
    return aux;
}

int ArchivoCliente::buscarClientePorId(int ID)
{
    int i, cantidadRegistros = this->getCantidadRegistros();
    Cliente aux;

    for(i=0; i<cantidadRegistros; i++)
    {
        aux = this->leerCliente(i);
        if (aux.getDni() == ID && aux.getActivo())
        {
            return i;
        }
    }
    return -1;
}

int ArchivoCliente::buscarClientePorApellido(const char *_apellido)
{
    int i, cantidadRegistros = this->getCantidadRegistros();
    Cliente aux;

    for(i=0; i<cantidadRegistros; i++)
    {
        aux = this->leerCliente(i);
        if (strcmp(aux.getApellido(), _apellido) == 0 && aux.getActivo())
        {
            return i;
        }
    }
    return -1;
}

bool ArchivoCliente::sobreescribirCliente(Cliente reg, int posicionAReemplazar)
{
  FILE *p = fopen(_nombre, "rb+");

  if (p == NULL)
  {
    return false;
  }

  fseek(p, posicionAReemplazar * sizeof(Cliente), SEEK_SET);
  bool pudoEscribir = fwrite(&reg, sizeof(Cliente), 1, p);
  fclose(p);
  return pudoEscribir;
}
