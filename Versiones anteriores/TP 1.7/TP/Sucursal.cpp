#include "Sucursal.h"
#include <iostream>
#include <string>
#include <cstring>
#include "Direccion.h"
#include "funciones.h"

using namespace std;

/*Sucursal::Sucursal()
{
    estadoSucursal=1;
}*/

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
    bool flag=false;
    bool validSucu=true;
    while (validSucu==true)
    {
        if (flag==false)
        {
            cout << "Ingrese numero de Sucursal: ";
            cin >> numSucursal;
            flag=true;
        }
        else
        {
            cout << "Sucursal repetida, por favor ingrese otro numero de Sucursal: ";
            cin >> numSucursal;
        }
        validSucu = validarSucursal(numSucursal);
    }

    cin.ignore();
    cout << "Ingrese el Nombre de la Sucursal: ";

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
    cout << endl;
    cout << "Estado Sucursal: " << estadoSucursal << endl;
}

void Sucursal::MostarAlCliente()
{
    cout << "Numero sucursal: " << numSucursal << endl;
    cout << "Nombre de la Sucursal: ";
    std::cout << nombreSucursal;
    direcSucursal.Mostrar();
    cout << endl;
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
