#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include "Direccion.h"
#include "funcionesClientes.h"

using namespace std;

/*Direccion::Direccion()
{
    strcpy(pais,"Argentina");
}
*/
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

//    cin.ignore(0, '\n');
    cout << "Ingrese la calle: ";
//    cin.getline(calle,100);
    cargarCadena(calle, 99);

    cout << "Ingrese numero: ";
    cin >> numero;

    cout << "Ingrese Cod Postal: ";
    cin >> codPostal;

//    cin.ignore();
    cout << "Ingrese la localidad: ";
//    cin.getline(localidad,100);
     cargarCadena(localidad, 99);

    cout << "Ingrese la provincia: ";
//    cin.ignore(0, '\n');
//    cin.getline(provincia,100);
    cargarCadena(provincia, 99);

    cout << "Ingrese la pais: ";
//    cin.ignore(0, '\n');
//    cin.getline(pais,100);
    cargarCadena(pais, 99);

}

void Direccion::Mostrar()
{
    cout << "calle " << calle;
    cout << " " << numero;
    cout << ". ";
    cout << codPostal << " CP." << "\n";
    cout << localidad <<", ";
    cout <<provincia;
    cout << pais <<endl;
}
