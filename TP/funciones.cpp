#include <iostream>
#include <string>
#include <cstring>
#include "Direccion.h"
#include "funciones.h"
#include "Sucursal.h"
#include "Cajero.h"
#include "Transacciones.h"
#include "UsuarioLogin.h"
#include <time.h>
#include "Cuenta.h"
#include "funcionesClientes.h"


using namespace std;

///***********  Funciones para Sucursales   ***********///
void mostarSucursales()
{
    Sucursal sucu;
    int pos=0;
    while (sucu.leerDeDisco(pos++))
    {
        sucu.Mostrar();
        cout << "---------------------------------" << endl;
    }
}
bool mostarSucursalesActivas()
{
    Sucursal sucu;
    int pos=0;
    bool flag = false;
    while (sucu.leerDeDisco(pos++))
    {
        if (sucu.getEstadoSucursal()==1)
        {
            sucu.Mostrar();
            flag = true;
            cout << "---------------------------------" << endl;
        }
    }
    return flag;
}
void mostarSucursalesInactivas()
{
    Sucursal sucu;
    int pos=0;
    while (sucu.leerDeDisco(pos++))
    {
        if (sucu.getEstadoSucursal()==0)
        {
            sucu.Mostrar();
            cout << "---------------------------------" << endl;
        }
    }
    return;
}
bool validarSucursalEstado(int sucEditar)///devuelve true si encuentra Sucursal
{
    Sucursal suc;
    int pos=0;
    while(suc.leerDeDisco(pos++))
    {
        if(sucEditar == suc.getNumeroSucursal())
        {
//            cout << "el estado de la sucursal es : " << suc.getEstadoSucursal() << endl;
            return suc.getEstadoSucursal();
        }
    }
    return suc.getEstadoSucursal();
}
bool validarSucursal(int SucEditar)///devuelve true si encuentra Sucursal
{
    Sucursal sucu;
    int pos = 0;
    while(sucu.leerDeDisco(pos++))
    {
        if(SucEditar == sucu.getNumeroSucursal())
        {
            return true;
        }
    }
    return false;
}
void editarSucursal(int sucEditar)
{
    Sucursal sucu;
    int pos=0, posEdit;
    int numSucursal;
    bool flag;
    char nombreSucursal[60];
    Direccion dire;
    while(sucu.leerDeDisco(pos++))
    {
        if(sucEditar == sucu.getNumeroSucursal())
        {
            cout << "\n" << "\n";
            cout << "EDITAR DATOS DE LA SUCURSAL" << endl;
            cout <<"Ingrese numero de Sucursal"<<endl;
            numSucursal = validarNumerosIngresados();
            if(numSucursal != sucu.getNumeroSucursal()) {
                flag = validarSucursal(numSucursal);
                if(flag) {
                    cout<<"Numero de Sucursal esta tomado por otra Sucursal"<<endl;
                    return;
                }
            }
            sucu.setNumeroSucursal(numSucursal);
            cout <<"Ingrese nuevo Nombre de la Sucursal"<<endl;
            cargarCadena(nombreSucursal, 59);
            sucu.setNombreSucursal(nombreSucursal);
            cout<<"Ingrese nueva Direccion Sucursal"<<endl;
            dire.Cargar();
            sucu.setDirecSucursal(dire);
            posEdit=pos-1;
            sucu.editarEnDisco(posEdit);
            return;
        }
    }
}
void listarSucuNumero(int numSucMostar)
{
    Sucursal suc;
    int pos=0;
    while(suc.leerDeDisco(pos++))
    {
        if(numSucMostar == suc.getNumeroSucursal())
        {
            cout << "La sucursal tiene los siguientes datos: " << endl;
            suc.Mostrar();
            return;
        }
    }
    cout << "La sucursal que desea mostrar no esta registrada" << endl;
}
void borrarSucursal(int numBorrarSucu)
{
    Sucursal sucu;
    int pos=0, posEdit;
    while(sucu.leerDeDisco(pos++))
    {
        if(numBorrarSucu == sucu.getNumeroSucursal())
        {
            cout << "\n" << "\n";
            cout << "INFORMACION A BORRAR" << endl;
            sucu.Mostrar();
            sucu.setEstadoSucursal(0);
            posEdit=pos-1;
            sucu.editarEnDisco(posEdit);
            return;
        }
    }
}
void borrarCajerosXSucursal(int numBorrarSucu)
{
    Cajero objcajero;
    int pos=0, posEdit;
    while(objcajero.leerDeDisco(pos++))
    {
        if(numBorrarSucu == objcajero.getNumSucursal())
        {
            cout << "\n" << "\n";
            cout << "Cajero de Sucursal: " << numBorrarSucu << " a sido Borrado." << endl;
            objcajero.Mostrar();
            objcajero.setEstadoCajero(0);
            posEdit=pos-1;
            objcajero.editarEnDisco(posEdit);
        }
    }
}
void darAltaSucursal(int numAltaSucu)
{
    Sucursal sucu;
    int pos=0, posEdit;
    while(sucu.leerDeDisco(pos++))
    {
        if(numAltaSucu == sucu.getNumeroSucursal())
        {
            cout << "\n" << "\n";
            cout << "INFORMACION A Activar" << endl;
            sucu.Mostrar();
            sucu.setEstadoSucursal(1);
            posEdit=pos-1;
            sucu.editarEnDisco(posEdit);
            return;
        }
    }
}

///***********  Funciones para Cajeros   ***********///
bool validarCajeroID(int cajEditar) ///devuleve true si encuentra el ID del Cajero
{
    Cajero objcajero;
    int pos = 0;
    while(objcajero.leerDeDisco(pos++))
    {
        if(cajEditar == objcajero.getIdCajero())
        {
            return true;
        }
    }
    return false;
}
bool validarCajeroNSerie(int cajEditar) ///devuleve true si encuentra el Num Serie del Cajero
{
    Cajero objcajero;
    int pos = 0;
    while(objcajero.leerDeDisco(pos++))
    {
        if(cajEditar == objcajero.getNumeroSerie())
        {
            return true;
        }
    }
    return false;
}
bool validarCajeroEstado(int cajEditar) ///devuleve true si encuentra el Estado del Cajero es True
{
    Cajero objcajero;
    int pos = 0;
    while(objcajero.leerDeDisco(pos++))
    {
        if(cajEditar == objcajero.getIdCajero())
        {
            return objcajero.getEstadoCajero();
        }
    }
}
void mostarCajeros()
{
    Cajero objcajero;
    int pos=0;
    while (objcajero.leerDeDisco(pos++))
    {
        objcajero.Mostrar();
        cout << "---------------------------------" << endl;
    }
}
void mostarCajerosActivos()
{
    Cajero objcajero;
    int pos=0;
    while (objcajero.leerDeDisco(pos++))
    {
        if (objcajero.getEstadoCajero()==1)
        {
            objcajero.Mostrar();
            cout << "---------------------------------" << endl;
        }
    }
}
void mostarCajerosInactivos()
{
    Cajero objcajero;
    int pos=0;
    while (objcajero.leerDeDisco(pos++))
    {
        if (objcajero.getEstadoCajero()==0)
        {
            objcajero.Mostrar();
            cout << "---------------------------------" << endl;
        }
    }
}
void editarCajeroID(int cajEditar)
{
    Cajero objcajero;
    int pos=0, posEdit;
    while(objcajero.leerDeDisco(pos++))
    {
        if(cajEditar == objcajero.getIdCajero())
        {
            cout << "\n" << "\n";
            cout << "INFORMACION A EDITAR" << endl;
            objcajero.Mostrar();
            objcajero.CargarEditar();
            cout << "Nuevos datos: " << endl;
            objcajero.Mostrar();
            posEdit=pos-1;
            objcajero.editarEnDisco(posEdit);
        }
    }
}
void borrarCajero(int numBorrarCajero)
{
    Cajero objcajero;
    int pos=0, posEdit;
    while(objcajero.leerDeDisco(pos++))
    {
        if(numBorrarCajero == objcajero.getIdCajero())
        {
            cout << "\n" << "\n";
            cout << "INFORMACION A Borrar" << endl;
            objcajero.Mostrar();
            objcajero.setEstadoCajero(0);
            posEdit=pos-1;
            objcajero.editarEnDisco(posEdit);
        }
    }
}
void darAltaCajero(int numAltaCajero)
{
    Cajero objcajero;
    int pos=0, posEdit;
    while(objcajero.leerDeDisco(pos++))
    {
        if(numAltaCajero == objcajero.getIdCajero())
        {
            cout << "\n" << "\n";
            cout << "INFORMACION a Activar" << endl;
            objcajero.Mostrar();
            objcajero.setEstadoCajero(1);
            posEdit=pos-1;
            objcajero.editarEnDisco(posEdit);
        }
    }
}
void mostrarCajeroID(int idCajeroMostar)
{
    Cajero objcajero;
    int pos=0;
    while(objcajero.leerDeDisco(pos++))
    {
        if(idCajeroMostar == objcajero.getIdCajero())
        {
            cout << "El Cajero tiene los siguientes datos: " << endl;
            objcajero.Mostrar();
            return;
        }
    }
    cout << "El Cajero que desea mostrar no esta registrado" << endl;
}
void mostarCajeroSucursal(int numSucuMostrar)
{
    Cajero objcajero;
    int pos=0;
    cout << "La sucursal: " << numSucuMostrar  << " tiene los siguiente Cajeros: "<< endl;
    while(objcajero.leerDeDisco(pos++))
    {
        if(numSucuMostrar == objcajero.getNumSucursal())
        {
            objcajero.Mostrar();
        }
    }
}

///***********Balanceo***********///

void editarCargaCajero(int idCajero, int cargaCajero)
{
    Cajero objCajero;
    int pos=0, posEdit, cantBilletesActual;
    while(objCajero.leerDeDisco(pos++))
    {
        if(idCajero == objCajero.getIdCajero())
        {
            cantBilletesActual=objCajero.getCapacidad();
            objCajero.setCapacidad(cargaCajero + cantBilletesActual);
            posEdit=pos-1;
            objCajero.editarEnDisco(posEdit);
        }
    }
}
void mostarCargaCajero(int idCajero)
{
    Cajero objCajero;
    int pos=0;
    while (objCajero.leerDeDisco(pos++))
    {
        if (idCajero == objCajero.getIdCajero())
        {
            objCajero.MostrarBilletes();
        }
    }
}

bool esPosibleCargarCajero(int idCajero, double montoACargar)
{
    Cajero objCajero;
    int cantBilletesCajero, cantBilletesACagar;
    cantBilletesACagar = (montoACargar/BILLETE);
    int pos=0;
    while (objCajero.leerDeDisco(pos++))
    {
        if (idCajero == objCajero.getIdCajero())
        {
            cantBilletesCajero=objCajero.getCapacidad();
            if ((objCajero.getCapcidadMaxima()) >= (cantBilletesCajero + cantBilletesACagar))
            {
                return true;
            }
            else
            {
                cout << "Usted supera el limete de Carga posible para este cajero" << endl;
                return false;
            }
        }
    }
    return false;
}

void ustedPuedeCargar(int idCajero)
{
    Cajero objCajero;
    int cargaMaxPosible;
    int pos=0;
    while (objCajero.leerDeDisco(pos++))
    {
        if (idCajero == objCajero.getIdCajero())
        {
            cargaMaxPosible=objCajero.getCapcidadMaxima() - objCajero.getCapacidad();
            cout << "Usted Puede cargar hasta: " << cargaMaxPosible << " billetes." << endl;
            cout << "El equivalente a: " << cargaMaxPosible * BILLETE << " pesos." << endl;
            return;
        }
    }
}

///***********Transacciones***********///
///me devuelve el ultimo numero de transaccion +1, sino tiene nada me devuelve 1, la 1er transaccion
int generarNumTransaccion()
{
    Transacciones reg;
    int num;
    num=reg.contarRegistros();
    if (num==-1)
    {
        return 1;
    }
    else
    {
        return num+1;
    }
}
///Aca Guarda la transacciones que se hacen
void operacionTransaccion(int id,float monto, int dni, int tipoTransaccion, bool posible) /// en el case pasar el id cajero como paremetro y creo que es mejor pasale el monto,
{
    Transacciones regTransaccion;
    Fecha fechasis;
    int numTran;
    ///seteo la fecha del sistema a fechasis;
    time_t t;
    t = time(NULL);
    struct tm *f;
    f = localtime(&t);
    int _dia = f->tm_mday;
    int _mes = f->tm_mon + 1;
    int _anio = f->tm_year + 1900;
    fechasis.setDia(_dia);
    fechasis.setMes(_mes);
    fechasis.setAnio(_anio);

    numTran=generarNumTransaccion();
    regTransaccion.setFechaTransaccion(fechasis);
    regTransaccion.setMonto(monto);
    regTransaccion.setIdProcedencia(id);
    regTransaccion.setNumTransaccion(numTran);
    regTransaccion.setDniCliente(dni);
    regTransaccion.setConfirmada(posible);
    regTransaccion.setTipoTransaccion(tipoTransaccion);
    regTransaccion.grabarEnDisco();
}

void transaccionConfirmada(bool estaConfirmada)
{
    if (estaConfirmada)
    {
        cout << "Transaccion Confirmada" << endl;
    }
    else
    {
        cout << "Error en Transaccion" << endl;
    }
}

void mostrarTransacciones()
{
    Transacciones regTransaccion;
    int pos=0;
    while (regTransaccion.leerDeDisco(pos++))
    {
        regTransaccion.Mostrar();
        transaccionConfirmada(regTransaccion.getConfirmada());
    }
}

/*************Verifico Si el monto esta disponible en la cuenta y en el Cajero************/
bool verificarSaldoDisplonible(int dni, int monto)
{
    float montoFloat=float(monto);
    Cuenta cuentaCliente;
    int pos=0;
    while (cuentaCliente.leerDeDisco(pos++))
    {
        if ((dni==cuentaCliente.getDniCliente()) && cuentaCliente.getActivo()==true)
        {
            if (cuentaCliente.getSaldo()>=montoFloat)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    return false;
}
bool verificarDineroEnCajero(int idCajero, int monto)
{
    Cajero objCajero;
    int pos=0;
    while (objCajero.leerDeDisco(pos++))
    {
        if (idCajero==objCajero.getIdCajero())
        {
            if ((objCajero.getCapacidad()*BILLETE)>=monto)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    return false;
}

/********** Le resto el dinero a la Cuenta del Cliente y al Cajero de la operacion ************/
void restarSaldoCuentaCliente(int dni, int montoRetirado)
{
    float montoRetidadoF =montoRetirado;
    Cuenta cuentaCliente;
    int pos=0, posEdit;
    while (cuentaCliente.leerDeDisco(pos++))
    {
        if ((dni==cuentaCliente.getDniCliente()) && cuentaCliente.getActivo()==true)
        {
            posEdit=pos-1;
            cuentaCliente.setSaldoDecrementar(montoRetidadoF);
            cuentaCliente.editarEnDisco(posEdit);
        }
    }
}
void restarDineroCajero(int idCajero, float montoExtraido)
{
    static_cast<int>(montoExtraido);
    Cajero objCajero;
    int capacidadActual;
    int cantBilletesExtraida=0;
    int pos=0, posEdit;
    while (objCajero.leerDeDisco(pos++))
    {
        if (idCajero==objCajero.getIdCajero())
        {
            posEdit=pos-1;
            capacidadActual=objCajero.getCapacidad();
            cantBilletesExtraida= (montoExtraido/BILLETE);
            capacidadActual = capacidadActual - cantBilletesExtraida;
            objCajero.setCapacidad(capacidadActual);
            objCajero.editarEnDisco(posEdit);
        }
    }
}

/********** Lo que le Muesto a los Clientes ************/
int pedirleAlClienteNumSucursal()
{
    int numSucusal;
    bool flagSucursal=false;
    bool validSucu = false;
    bool validSucuEstado;

    flagSucursal=false;
    validSucu = false;
    do
    {
        if (flagSucursal==false)
        {
            cout << "Por favor ingrese el numero del sucursal al que desea ingresar:" << endl;
            numSucusal = validarNumerosIngresados(); // ingreso valido numSucusal como numero int
            //cin >> numSucusal;
            flagSucursal=true;
        }
        else
        {
            cout << "El numero de sucursal ingresado no existe o esta temporalmente dada de baja:" << endl;
            cout << "Vuelva a ingresar otra sucursal:" << endl;
            numSucusal = validarNumerosIngresados(); // ingreso valido numSucusal como numero int
            //cin >> numSucusal;
        }
        validSucu=validarSucursal(numSucusal);
        validSucuEstado=validarSucursalEstado(numSucusal);
    }while (validSucu == false);
    if ((validSucu==true) && (validSucuEstado==true))
    {
        return numSucusal;
    } else {
        cout << "La Sucursal No se encuentra disponible"<<endl;
        system("pause");
        return -1;
    }
}

int pedirleAlClienteCajero(int numSucursal)
{
    int idCajero;
    bool flagCajero=false;
    bool existeCajero= false;
    bool estadoCajero, existeCajeros;
    cout << "Ustedes se encuentra en:" << "\n";
    listarSucuNumeroAlCliente(numSucursal);
    cout << "\n" << "Cuenta con los siguiente Cajeros Automaticos:"<< "\n" << endl;
    existeCajeros = mostarCajeroSucursalAlCliente(numSucursal);
    if(!existeCajeros) return -1;
    flagCajero=false;
    existeCajero= false;
    do
    {
        if (flagCajero==false)
        {
            cout << "Por favor ingrese el numero del Cajero:" << endl;
            idCajero = validarNumerosIngresados(); // ingreso valido idCajero como numero int
            //cin >> idCajero;
            flagCajero=true;
        }
        else
        {
            cout << "El ID del Cajero ingresado no existe:" << endl;
            cout << "Vuelva a ingresar el del cajero:" << endl;
            idCajero = validarNumerosIngresados(); // ingreso valido idCajero como numero int
        }
        existeCajero = validarCajeroID(idCajero);
        estadoCajero = validarCajeroEstado(idCajero);
    }while (existeCajero == false);
    if ((existeCajero==true) && (estadoCajero==true))
    {
        return idCajero;
    }
}

void listarSucuNumeroAlCliente(int numSucMostar)
{
    Sucursal suc;
    int pos=0;
    while(suc.leerDeDisco(pos++))
    {
        if(numSucMostar == suc.getNumeroSucursal())
        {
            suc.MostarAlCliente();
            return;
        }
    }
    cout << "La sucursal que desea mostrar no esta registrada" << endl;
}

bool mostarCajeroSucursalAlCliente(int numSucuMostrar)
{
    Cajero objcajero;
    int pos=0;
    bool flag = false;
    cout << "Numero sucursal: " << numSucuMostrar << endl;
    while(objcajero.leerDeDisco(pos++))
    {
        if(numSucuMostrar == objcajero.getNumSucursal())
        {
            objcajero.MostarAlCliente();
            cout << endl;
            flag = true;
        }
    }
    return flag;
}

bool cajeroEsdeSucursal(int sucursal,int idCajero)
{
    Cajero regCajero;
    int pos=0;
    while(regCajero.leerDeDisco(pos++))
    {
        if (idCajero==regCajero.getIdCajero())
        {
            if (sucursal==regCajero.getNumSucursal())
            {
                return true;
            }
            else
            {
                cout << "El Cajero Ingresado no pertenece a esta Sucursal" << "\n";
                return false;
            }
        }
    }
    cout << "El Cajero Ingresado no pertenece a esta Sucursal" << "\n";
    return false;
}
