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

int Cajero::getCapcidadMaxima()
{
    return capacidadMaxima;
}

int Cajero::getCapacidad(){
    return capacidad;
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

void Cajero::setCapacidadMaxima (int _capidadMax)
{
    capacidadMaxima=_capidadMax;
}

void Cajero::setCapacidad(int _capacidad)
{
    capacidad=_capacidad;
}

void Cajero::setEstadoCajero(bool _estadoCajero)
{
    estadoCajero=_estadoCajero;
}

void Cajero::Cargar()
{
    bool flag=false;
    bool validSucu=false;
    bool validCajeroID=true;
    bool validCajeroNSerie=true;
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

    flag=false;
    while (validCajeroID==true)
    {
        if (flag==false)
        {
            cout << "Ingrese el ID del Cajero: ";
            cin >> idCajero;
            flag=true;
        }
        else
        {
            cout << "ID del Cajero ya ingresa, por favor ingrese otro: ";
            cin >> idCajero;
        }
        validCajeroID = validarCajeroID(idCajero);
    }

    flag=false;
    while (validCajeroNSerie==true)
    {
        if (flag==false)
        {
            cout << "Ingrese el N de Serie del Cajero: ";
            cin >> numSerie;
            flag=true;
        }
        else
        {
            cout << "N de Serie del Cajero ya ingresado, por favor ingrese otro: ";
            cin >> numSerie;
        }
        validCajeroNSerie = validarCajeroNSerie(numSerie);
    }

    cout << "Ingrese la fecha de Instalacion: ";
    fechaInstalacion.Cargar();

    cout << "Ingrese el Estado del Cajero: ";
    cin >> estadoCajero;

}

void Cajero::CargarEditar()
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

    cout << "Ingrese la fecha de Instalacion: ";
    fechaInstalacion.Cargar();
    cout << endl;
    cout << "Ingrese el Estado del Cajero: ";
    cin >> estadoCajero;
}

void Cajero::Mostrar()
{
    cout << "ID del Cajero: " << idCajero << endl;
    cout << "Numero sucursal: " << numSucursal << endl;
    cout << "Numero de Serie: " << numSerie << endl;
    fechaInstalacion.Mostrar();
    cout << endl;
    cout << "Estado Cajero: " << estadoCajero << endl;
}

void Cajero::MostarAlCliente()
{
    cout << "ID del Cajero: " << idCajero << "  ";
    cout << "Serie: " << numSerie << endl;
}


void Cajero::MostrarBilletes()
{
    int cantDinero; // es la cantidad de plata que tiene el cajero (capacidad x denominacion de billete, en este caso de 100)
    cantDinero = capacidad*BILLETE;
    cout << "ID del Cajero: " << idCajero << endl;
    cout << "Cuenta con: " << capacidad << " cantidad de billetes" << endl;
    cout << "Es decir con: " << cantDinero << " pesos" << endl;
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

int Cajero::contarRegistros()
{
        FILE *p;
        p=fopen("cajeros.dat", "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Cajero);
}
