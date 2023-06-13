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
int generarNumTransaccion();

///
void extracciones(int, int, int);

/// Extracciones
bool verificarSaldoDisplonible(int, int);
bool verificarDineroEnCajero(int, int);


///Login, diferencia admin de cliente,
int leerLogin (int, char, char);

///lo que Ven los Clientes

int pedirleAlClienteNumSucursal();
void listarSucuNumeroAlCliente(int);
int pedirleAlClienteCajero(int);
void mostarCajeroSucursalAlCliente(int);

float traerMontoCuenta(int);
#endif // FUNCIONES_H_INCLUDED
