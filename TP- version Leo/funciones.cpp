#include <iostream>
#include <string>
#include <cstring>
#include "Direccion.h"
#include "funciones.h"
#include "Sucursal.h"
#include "Cajero.h"
#include "AuxuliarCajero.h"
#include "Transacciones.h"
#include <time.h>

using namespace std;

/// Funciones para Sucursales

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

void mostarSucursalesActivas()
{
    Sucursal sucu;
    int pos=0;
    while (sucu.leerDeDisco(pos++))
    {
        if (sucu.getEstadoSucursal()==1)
        {
            sucu.Mostrar();
            cout << "---------------------------------" << endl;
        }
    }
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
}

bool validarSucursalEstado(int sucEditar)///devuelve true si encuentra Sucursal
{
    Sucursal suc;
    int pos=0;
    while(suc.leerDeDisco(pos++))
    {
        if(sucEditar == suc.getNumeroSucursal())
        {
            cout << "el estado de la sucursal es: " << suc.getEstadoSucursal() << endl;
            return suc.getEstadoSucursal();
            break;
        }
    }
    cout << "sucursal no encontrada : " << suc.getEstadoSucursal() << endl;
    return suc.getEstadoSucursal();
}

bool validarSucursal(int SucEditar)///devuelve true si encuentra Sucursal
{
    Sucursal sucu;
    int pos = 0;
    while(sucu.leerDeDisco(pos++)){
        if(SucEditar == sucu.getNumeroSucursal()){
            return true;
        }
    }
    return false;
}


void editarSucursal(int sucEditar)
{
    Sucursal sucu;
    int pos=0, posEdit;
    while(sucu.leerDeDisco(pos++)){
        if(sucEditar == sucu.getNumeroSucursal()){
            cout << "\n" << "\n";
            cout << "INFORMACION A EDITAR" << endl;
            sucu.Mostrar();
            sucu.Cargar();
            posEdit=pos-1;
            sucu.editarEnDisco(posEdit);
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
            break;
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
            cout << "INFORMACION A Borrar" << endl;
            sucu.Mostrar();
            sucu.setEstadoSucursal(0);
            posEdit=pos-1;
            sucu.editarEnDisco(posEdit);
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
        }
    }
}

/// Funciones para Cajeros

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
    while(objcajero.leerDeDisco(pos++)){
        if(cajEditar == objcajero.getIdCajero()){
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
            break;
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
        else
        {
            cout << "La Sucursal " << endl;
            break;
        }
    }
}


///***********Balanceo***********///

void editarCargaCajero(int idCajero, int cargaCajero)
{
    AuxuliarCajero auxCajero;
    int pos=0, posEdit;
    while(auxCajero.leerDeDisco(pos++)){
        if(idCajero == auxCajero.getIdCajero())
        {
            auxCajero.setCapacidad(cargaCajero);
            posEdit=pos-1;
            auxCajero.editarEnDisco(pos);
        }
    }
}

void mostarCargaCajero(int id)
{
    AuxuliarCajero auxCajero;
    int pos=0;
    while (auxCajero.leerDeDisco(pos++))
    {
        if (id == auxCajero.getIdCajero())
        {
            auxCajero.MostrarBilletes();
        }
    }
}

///***********Transacciones***********///
/*double generarNumTransaccion()
{
    Transacciones reg;
    double num;
    FILE *p;
    p = fopen("transacciones.dat", "rb");
    if(p==NULL) return -1;
    fseek(p, -sizeof(Transacciones), SEEK_END);
    if(fread(&reg, sizeof(Transacciones), 1, p) == 0){
        num = 0;
    }
    else{
        num = reg.getNumTransaccion();
    }
    fclose(p);
    return num;
}*/

void extracciones(int idCajero) /// en el case pasar el id cajero como paremetro y creo que es mejor pasale el monto,
{
    int monto;
    Transacciones regTransaccion;
    Fecha fechasis;
    double numTran;
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
   /** do
    {
        cout << "Ingrese el monto a Extraer: ";
        cin >> monto;
    }while ((monto&100==0) && (monto>=100));*/   ///Creo que no VA!!!!!!!!

    ///numTran=generarNumTransaccion();
    regTransaccion.setFechaTransaccion(fechasis);
    regTransaccion.setMonto(monto);
    regTransaccion.setIdCajero(idCajero);
    ///regTransaccion.getNumTransaccion(numTran);
    ///regTransaccion.grabarEnDisco();/// Falta HAcerla en CPP

}

