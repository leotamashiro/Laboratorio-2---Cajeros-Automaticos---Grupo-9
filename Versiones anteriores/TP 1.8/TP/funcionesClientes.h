#ifndef FUNCIONESCLIENTES_H
#define FUNCIONESCLIENTES_H
#include "ArchivoCliente.h"
#include "Cliente.h"

int persistirCliente();
void mostrarCliente();
bool validarDni(int dni);
void cargarCadena(char *pal, int tam);
int generarNumeros(int desde, int hasta);


#endif // FUNCIONESCLIENTES_H
