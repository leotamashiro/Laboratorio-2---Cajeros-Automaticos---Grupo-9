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
int loginUsuario(int dni);
bool buscarClientePorDni();
bool eliminadoLogico();
void buscarClientes();
int posCliente(int dni);
bool buscarClienteporApellido();
int validarNumerosIngresados();
int posDniUsarioLogin();
void menuEditarClientes();
void editarDireccionCliente();
void editarUserCliente();
void editarPasswordCliente();
void editarDatosCliente();
void ingresarFondosCuenta(int dni);



#endif // FUNCIONESCLIENTES_H
