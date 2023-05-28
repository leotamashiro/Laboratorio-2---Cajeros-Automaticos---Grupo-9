#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include "Direccion.h"

using namespace std;

///get

string Direccion::getCalle()
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

std::string Direccion::getLocalidad()
{
   return localidad;
}

std::string Direccion::getProvincia()
{
   return provincia;
}

std::string Direccion::getPais()
{
   return pais;
}

///set

void Direccion::setCalle(string _calle){
   calle=_calle;
}

void Direccion::setNumero(int _numero){
   numero = _numero;
}

void Direccion::setCodPostal(int _codPostal)
{
   codPostal = _codPostal;
}

void Direccion::setLocalidad(std::string _localidad)
{
   localidad=_localidad;
}

void Direccion::setProvincia(std::string _provincia)
{
    provincia=_provincia;
}

void Direccion::setPais(std::string _pais)
{
    pais=_pais;
}

void Direccion::Cargar()
{

    cout << "Ingrese la calle: ";
    getline(cin, calle);
    cin.ignore();

    cout << "Ingrese numero: ";
    cin >> numero;

    cout << "Ingrese Cod Postal: ";
    cin >> codPostal;

    cout << "Ingrese la localidad: ";
    getline(cin, localidad);
    cin.ignore();

    cout << "Ingrese la provincia: ";
    getline(cin, provincia);
    cin.ignore();

    cout << "Ingrese la pais: ";
    getline(cin, pais);
    cin.ignore();

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
