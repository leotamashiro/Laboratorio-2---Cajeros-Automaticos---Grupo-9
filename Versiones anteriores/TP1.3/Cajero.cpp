#include "Cajero.h"

int Cajero::getIdCajero()
{
    return idCajero;
}

int Cajero::getNumeroSerie()
{
    return numSerie;
}

Fecha Cajero::getFechaInstalacion()
{
    return fechaInstalacion;
}

int Cajero::getNumSucursal()
{
    return numSucursal;
}

bool Cajero::getEstadoCajero()
{
    return estadoCajero;
}

void Cajero::setIdCajero(int _idCajero)
{
    idCajero = _idCajero;
}
void Cajero::setNumeroSerie(int _numSerie)
{
    numSerie=_numSerie;
}

void Cajero::setFechaInstalacion(Fecha _fechaInstalacion)
{
    fechaInstalacion=_fechaInstalacion;
}

void Cajero::setNumSucursal(int _numSucursal)
{
    numSucursal=_numSucursal;
}

void Cajero::setEstadoCajero(bool _estadoCajero)
{
    estadoCajero=_estadoCajero;
}

void Cajero::Cargar()
{
    bool flag=false;
    bool validSucu=false;
    while (validSucu==false)
    {
        if (flag==false)
        {
            cout << "Ingrese numero de Sucursal: ";
            cin >> numSucursal;
            flag=true;
        }
        else
        {
            cout << "Sucursal no Cargada, por favor ingrese una sucursal valida: ";
            cin >> numSucursal;
        }
        validSucu = validarSucursal(numSucursal);
    }

    cout << "Ingrese el ID del Cajero: ";
    cin >> idCajero;

    cout << "Ingrese la fecha de Instalacion: ";
    fechaInstalacion.Cargar();

    cout << "Ingrese el Estado delCajero: ";
    cin >> estadoCajero;

}
void Cajero::Mostrar()
{
    cout << "Numero sucursal: " << numSucursal << endl;
    cout << "ID del Cajero: " << idCajero << endl;
    cout << "Numero de Serie: " << numSerie << endl;
    fechaInstalacion.Mostrar();
    cout << endl;
    cout << "Estado Cajero: " << estadoCajero << endl;
}

bool Cajero::editarEnDisco(int pos)
{
    bool guardo;
    FILE *p;
    p = fopen("cajeros.dat", "rb+");
    if( p == NULL ){
        return false;
    }
    fseek(p, sizeof(Cajero)*pos, SEEK_SET);
    guardo = fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return guardo;
}

void Cajero::grabarEnDisco()
{
    FILE *p;
    p = fopen("cajeros.dat", "ab");
    if( p == NULL ){
        return;
    }
    fwrite(this, sizeof *this, 1, p);
    fclose(p);
}
bool Cajero::leerDeDisco(int pos)
{
    bool lectura;
    FILE *p;
    p = fopen("cajeros.dat", "rb");
    if( p == NULL ){
        return false;
    }
    fseek(p, sizeof(Cajero)*pos, SEEK_SET);
    lectura = fread(this, sizeof *this, 1, p);
    fclose(p);
    return lectura;
}
