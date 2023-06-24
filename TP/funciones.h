#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

const int BILLETE = 1000; //Es el monto minimo para extraer de los cajeros.

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
bool archivoAuxCajeroExiste();
void seGeneraArchivoAuxCajero(int, int);
void editarCargaCajero(int, int);
void mostarCargaCajero(int);
bool esPosibleCargarCajero(int, double);
void ustedPuedeCargar(int);

///Transacciones
int generarNumTransaccion();
void operacionTransaccion(int, float, int, int, bool); ///Aca Guarda la transacciones que se hacen
void mostrarTransacciones();
void transaccionConfirmada(bool estaConfirmada);

/// Extracciones
bool verificarSaldoDisplonible(int, int);
bool verificarDineroEnCajero(int, int);

///Le saco dinero a la cuenta del Cliente
void restarSaldoCuentaCliente(int, int);
///Le saco dinero al Cajero
void restarDineroCajero(int, float);


///Login, diferencia admin de cliente,
int leerLogin (int, char, char);

///lo que Ven los Clientes

int pedirleAlClienteNumSucursal();
void listarSucuNumeroAlCliente(int);
int pedirleAlClienteCajero(int);
void mostarCajeroSucursalAlCliente(int);

float traerMontoCuenta(int);
#endif // FUNCIONES_H_INCLUDED
