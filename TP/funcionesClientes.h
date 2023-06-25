#ifndef FUNCIONESCLIENTES_H
#define FUNCIONESCLIENTES_H
#include "ArchivoCliente.h"
#include "Cliente.h"
#include "Transacciones.h"


int persistirCliente();
void mostrarClientes();
bool validarDni(int dni);
void cargarCadena(char *pal, int tam);
int generarNumeros(int desde, int hasta);
bool validarUser(const char* user);
int loginUsuario(int dni);
bool buscarClientePorDni();
bool buscarClientePorDni(int dni);
bool eliminadoLogico();
void buscarClientes();
int posCliente(int dni);
bool buscarClienteporApellido();
int validarNumerosIngresados();
int posDniUsarioLogin();
void menuEditarClientes(int dni = -1);
void editarDireccionCliente(int dni = -1);
void editarUserCliente(int dni = -1);
void editarPasswordCliente(int dni = -1);
void editarDatosCliente(int dni = -1);
void ingresarFondosCuenta(int dni);
void mostrarTransaccionesCliente(int dni);



#endif // FUNCIONESCLIENTES_H
