#ifndef FUNCIONESCLIENTES_H
#define FUNCIONESCLIENTES_H
#include "ArchivoCliente.h"
#include "Cliente.h"

int persistirCliente();
void mostrarClientes();
bool validarDni(int dni);
void cargarCadena(char *pal, int tam);
int generarNumeros(int desde, int hasta);
bool validarUser(const char* user);
bool buscarClientePorDni();
bool eliminadoLogico();
void buscarClientes();
int posCliente(int dni);
bool buscarClienteporApellido();



#endif // FUNCIONESCLIENTES_H
