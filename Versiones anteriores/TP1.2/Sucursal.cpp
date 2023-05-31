#include "Sucursal.h"
#include <iostream>
#include <string>
#include <cstring>
#include "Direccion.h"

using namespace std;

int Sucursal::getNumeroSucursal()
{
    return numSucursal;
}

char *Sucursal::getNombreSucursal()
{
    return nombreSucursal;
}

bool Sucursal::getEstadoSucursal()
{
    return estadoSucursal;
}

Direccion Sucursal::getDirecSucursal()
{
    return direcSucursal;
}

void Sucursal::setNumeroSucursal(int _numSucursal)
{
    numSucursal = _numSucursal;
}

void Sucursal::setNombreSucursal(char *_nombreSucursal)
{
   strcpy(nombreSucursal, _nombreSucursal);
}

void Sucursal::setEstadoSucursal(bool _estadoSucursal)
{
    estadoSucursal=_estadoSucursal;
}

void Sucursal::setDirecSucursal(Direccion _direcSucursal)
{
    direcSucursal=_direcSucursal;
}

void Sucursal::Cargar()
{

    cout << "Ingrese numero de Sucursal: ";
    cin >> numSucursal;

    cout << "Ingrese el Nombre de la Sucursal: ";
    cin.ignore();
    cin.getline(nombreSucursal,60);


    direcSucursal.Cargar();

    cout << "Ingrese el Estado de la Sucursal: ";
    cin >> estadoSucursal;

}

void Sucursal::Mostrar()
{
    cout << "Numero sucursal: " << numSucursal << endl;
    cout << "Nombre de la Sucursal: ";
    std::cout << nombreSucursal;
    cout << endl;
    direcSucursal.Mostrar();
    cout << "Estado Sucursal: " << estadoSucursal << endl;
}

bool Sucursal::editarEnDisco(int pos){
    bool guardo;
    FILE *p;
    p = fopen("sucursales.dat", "rb+");
    if( p == NULL ){
        return false;
    }
    fseek(p, sizeof(Sucursal)*pos, SEEK_SET);
    guardo = fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return guardo;
}
bool Sucursal::leerDeDisco(int pos){
    bool lectura;
    FILE *p;
    p = fopen("sucursales.dat", "rb");
    if( p == NULL ){
        return false;
    }
    fseek(p, sizeof(Sucursal)*pos, SEEK_SET);
    lectura = fread(this, sizeof *this, 1, p);
    fclose(p);
    return lectura;
}
void Sucursal::grabarEnDisco(){
    FILE *p;
    p = fopen("sucursales.dat", "ab");
    if( p == NULL ){
        return;
    }
    fwrite(this, sizeof *this, 1, p);
    fclose(p);
}

int Sucursal::contarRegistros()
{
        FILE *p;
        p=fopen("sucursales.dat", "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Sucursal);
}
