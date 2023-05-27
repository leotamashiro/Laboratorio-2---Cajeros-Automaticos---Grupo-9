#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include "Direccion.h"

using namespace std;

Direccion::Direccion()
{
    strcpy(calle, "");
    numero = 0;
    codPostal = 0;
    strcpy(localidad, "");
    strcpy(provincia, "");
    strcpy(pais, "");
}

Direccion::Direccion(std::string _calle, int _numero, int _codPostal, std::string _localidad, std::string _provincia, std::string _pais)
{
    strcpy(calle, _calle.c_str());
    numero = _numero;
    codPostal = _codPostal;
    strcpy(localidad, _localidad.c_str());
    strcpy(provincia, _provincia.c_str());
    strcpy(pais, _pais.c_str());
}

///get

std::string Direccion::getCalle()
{
   std::string _calle;
   _calle = calle;
   return _calle;
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
   std::string _localidad;
   _localidad = localidad;
   return _localidad;
}

std::string Direccion::getProvincia()
{
   std::string _provincia;
   _provincia = provincia;
   return _provincia;
}

std::string Direccion::getPais()
{
   std::string _pais;
   _pais = pais;
   return _pais;
}

///set

void Direccion::setCalle(std::string _calle){
   strcpy(calle, _calle.c_str());
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
   strcpy(localidad, _localidad.c_str());
}

void Direccion::setProvincia(std::string _provincia)
{
   strcpy(provincia, _provincia.c_str());
}

void Direccion::setPais(std::string _pais)
{
   strcpy(pais, _pais.c_str());
}

void Direccion::Cargar()
{
    string _calle;
    string _localidad;
    string _provincia;
    string _pais;
    //int _numero, _codPostal;

    cout << "Ingrese la calle: ";
    getline(cin, _calle);
    //cin << _calle;
    //std::cin >>_calle;

    cout << "Ingrese numero: ";
    cin >> numero;

    cout << "Ingrese Cod Postal: ";
    cin >> codPostal;

    cout << "Ingrese la localidad: ";
    cin.ignore();
    getline(cin, _localidad);
    //cin >> _localidad;
    //std::cin >>_localidad;

    cout << "Ingrese la provincia: ";
    getline(cin, _provincia);
    //cin >> _provincia;
    //std::cin >>_provincia;

    cout << "Ingrese la pais: ";
    getline(cin, _pais);
    //cin >> pais;
    //std::cin >>_pais;

    setCalle(_calle);
    setLocalidad(_localidad);
    setProvincia(_provincia);
    setPais(_pais);

}

void Direccion::Mostrar()
{
    cout << "calle ";
    std::cout << calle;
    cout << " " << numero;
    cout << ". ";
    std::cout << codPostal;
    cout << " CP." << "\n";
    std::cout << localidad;
    cout << ", ";
    std::cout <<provincia;
    cout << ", ";
    std::cout << pais;
}
