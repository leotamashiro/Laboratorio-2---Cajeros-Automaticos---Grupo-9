#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include "Direccion.h"

using namespace std;

///get

char *Direccion::getCalle()
{
   return calle;
}

int Direccion::getNumero()
{
    return numero;
}

int Direccion::getCodPostal()
{
    return codPostal;
}

char *Direccion::getLocalidad()
{
   return localidad;
}

char *Direccion::getProvincia()
{
   return provincia;
}

char *Direccion::getPais()
{
   return pais;
}

///set

void Direccion::setCalle(char *_calle)
{
    strcpy(calle, _calle);
}

void Direccion::setNumero(int _numero){
   numero = _numero;
}

void Direccion::setCodPostal(int _codPostal)
{
   codPostal = _codPostal;
}

void Direccion::setLocalidad(char *_localidad)
{
    strcpy(localidad, _localidad);
}

void Direccion::setProvincia(char *_provincia)
{
    strcpy(provincia, _provincia);
}

void Direccion::setPais(char *_pais)
{
    strcpy(pais, _pais);
}

void Direccion::Cargar()
{

    cout << "Ingrese la calle: ";
    cin.ignore();
    cin.getline(calle,100);

    cout << "Ingrese numero: ";
    cin >> numero;

    cout << "Ingrese Cod Postal: ";
    cin >> codPostal;

    cout << "Ingrese la localidad: ";
    cin.ignore();
    cin.getline(localidad,100);


    cout << "Ingrese la provincia: ";
    cin.ignore();
    cin.getline(provincia,100);

    cout << "Ingrese la pais: ";
    cin.ignore();
    cin.getline(pais,100);

}

void Direccion::Mostrar()
{
    cout << "calle " << calle;
    cout << " " << numero;
    cout << ". ";
    cout << codPostal << " CP." << "\n";
    cout << localidad <<", ";
    cout <<provincia << ", ";
    cout << pais;
}
