#include <iostream>
#include <string>
#include <cstring>
#include "Direccion.h"
#include "funciones.h"
#include "Sucursal.h"

using namespace std;

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

bool buscarSuc(int sucEditar){
    Sucursal suc;
    int pos=0;
    while(suc.leerDeDisco(pos++))
    {
        if(sucEditar == suc.getNumeroSucursal())
        {
        return true;
        }
    }
}

bool validarSucursal(int SucEditar)
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

void editarSucursal(int SucEditar)
{
    Sucursal sucu;
    int pos=0, posEdit;
    while(sucu.leerDeDisco(pos++)){
        if(SucEditar == sucu.getNumeroSucursal()){
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
        else
        {
            cout << "La sucursal que desea mostrar no esta registrada" << endl;
            break;
        }
    }
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

void darAltaSucursal(int numAltaSucu)
{
    Sucursal sucu;
    int pos=0, posEdit;
    while(sucu.leerDeDisco(pos++))
    {
        if(numAltaSucu == sucu.getNumeroSucursal())
        {
            cout << "\n" << "\n";
            cout << "INFORMACION A Borrar" << endl;
            sucu.Mostrar();
            sucu.setEstadoSucursal(1);
            posEdit=pos-1;
            sucu.editarEnDisco(posEdit);
        }
    }
}
