#include "AuxuliarCajero.h"

AuxuliarCajero::AuxuliarCajero()
{
    capacidad=0;
}

int AuxuliarCajero::getIdCajero()
{
    return idCajero;
}

int AuxuliarCajero::getCapacidad()
{
    return capacidad;
}

void AuxuliarCajero::setIdCajero(int _idCajero)
{
    idCajero = _idCajero;
}
void AuxuliarCajero::setCapacidad(int _capacidad)
{
    capacidad=_capacidad;
}

void AuxuliarCajero::MostrarBilletes()
{
    int cantDinero; // es la cantidad de plata que tiene el cajero (capacidad x denominacion de billete, en este caso de 100)
    cantDinero = capacidad*BILLETE;
    cout << "ID del Cajero: " << idCajero << endl;
    cout << "Cuenta con: " << capacidad << " cantidad de billetes" << endl;
    cout << "Es decir con: " << cantDinero << " de pesos" << endl;
}

bool AuxuliarCajero::editarEnDisco(int pos)
{
    bool guardo;
    FILE *p;
    p = fopen("auxiliarCajeros.dat", "rb+");
    if( p == NULL )
    {
        return false;
    }
    fseek(p, sizeof(AuxuliarCajero)*pos, SEEK_SET);
    guardo = fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return guardo;
}

void AuxuliarCajero::grabarEnDisco()
{
    FILE *p;
    p = fopen("auxiliarCajeros.dat", "ab");
    if( p == NULL )
    {
        return;
    }
    fwrite(this, sizeof *this, 1, p);
    fclose(p);
}
bool AuxuliarCajero::leerDeDisco(int pos)
{
    bool lectura;
    FILE *p;
    p = fopen("auxiliarCajeros.dat", "rb");
    if( p == NULL )
    {
        return false;
    }
    fseek(p, sizeof(AuxuliarCajero)*pos, SEEK_SET);
    lectura = fread(this, sizeof *this, 1, p);
    fclose(p);
    return lectura;
}
