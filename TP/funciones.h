#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void menuSucursales();
void menuCajeros();

/// Funciones para Sucursales
void mostarSucursales();
void mostarSucursalesActivas();
void mostarSucursalesInactivas();
bool validarSucursal(int);
void editarSucursal(int);
bool buscarSuc(int );
void listarSucuNumero(int numSucMostar);
void borrarSucursal(int);
void darAltaSucursal (int);
/// Funciones para Cajeros
bool validarCajeroID(int);
bool validarCajeroNSerie(int);
void mostarCajeros();
void mostarCajerosActivos();
void mostarCajerosInactivos();


#endif // FUNCIONES_H_INCLUDED
