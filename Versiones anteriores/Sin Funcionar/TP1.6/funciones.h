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
bool validarSucursalEstado(int );
void listarSucuNumero(int numSucMostar);
void borrarSucursal(int);
void borrarCajerosXSucursal(int);
void darAltaSucursal (int);
/// Funciones para Cajeros
bool validarCajeroID(int);
bool validarCajeroNSerie(int);
bool validarCajeroEstado(int);
void mostarCajeros();
void mostarCajerosActivos();
void mostarCajerosInactivos();
void editarCajeroID(int);
void borrarCajero(int);
void darAltaCajero(int);
void mostrarCajeroID(int);
void mostarCajeroSucursal(int);

///Funciones para el Balanceo
void editarCargaCajero(int, int);
void mostarCargaCajero(int);

///Transacciones
double generarNumTransaccion();


#endif // FUNCIONES_H_INCLUDED
