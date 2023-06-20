#include "UsuarioLogin.h"
#include "funcionesClientes.h"
#include "UsuarioLogin.h"
///gets
int UsuarioLogin::getDNI()
{
    return dni;
}

int UsuarioLogin::getPermiso()
{
    return permiso;
}

char *UsuarioLogin::getUser()
{
    return user;
}

char *UsuarioLogin::getPassword()
{
    return password;
}

bool UsuarioLogin::getEstado()
{
    return estado;
}

///set
void UsuarioLogin::setDNI(int _dni)
{
    dni = _dni;
}

void UsuarioLogin::setUser(char *_user)
{
    strcpy(user, _user);
}

void UsuarioLogin::setPermiso(int _permiso)
{
    permiso = _permiso;
}

void UsuarioLogin::setPassword(char *_password)
{
    strcpy(password, _password);
}

void UsuarioLogin::setEstado(bool _estado)
{
    estado=_estado;
}

bool UsuarioLogin::cargarLogin(int _dni)
{
    bool existeUser = true;

    while(existeUser)
    {
        cout<<"INGRESE USER: "<<endl;
        cargarCadena(user, 29);
        existeUser = validarUser(user);
        if(existeUser)
        {
            cout<<"USER INGRESADO YA EXISTENTE, POR FAVOR INGRESE UN USER NO EXISTENTE"<<endl;
        }
    }


    cout<<"INGRESE PASSWORD: "<<endl;
    cargarCadena(password, 6);

    dni = _dni;
    estado = true;
    permiso = 2;

    this->grabarEnDisco();
    return true;
}

void UsuarioLogin::mostrarLogin()
{
    cout<<"USER: "<<user<<endl;
    cout<<"PASSWORD: "<<password<<endl;
    cout<<"PERMISO: "<<permiso<<endl;
}

///
bool UsuarioLogin::editarEnDisco(int pos)
{
    bool guardo;
    FILE *p;
    p = fopen("usuarioLogin.dat", "rb+");
    if( p == NULL )
    {
        return false;
    }
    fseek(p, sizeof(UsuarioLogin)*pos, SEEK_SET);
    guardo = fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return guardo;
}
bool UsuarioLogin::leerDeDisco(int pos)
{
    bool lectura;
    FILE *p;
    p = fopen("usuarioLogin.dat", "rb");
    if( p == NULL )
    {
        return false;
    }
    fseek(p, sizeof(UsuarioLogin)*pos, SEEK_SET);
    lectura = fread(this, sizeof *this, 1, p);
    fclose(p);
    return lectura;
}
void UsuarioLogin::grabarEnDisco()
{
    FILE *p;
    p = fopen("usuarioLogin.dat", "ab");
    if( p == NULL )
    {
        return;
    }
    fwrite(this, sizeof *this, 1, p);
    fclose(p);
}

int UsuarioLogin::buscarClientePorUser(const char* user)
{
    int i, encontroUser;
    int cantidadRegistros = this->getCantidadRegistros();


    for(i=0; i<cantidadRegistros; i++)
    {
        this->leerDeDisco(i);
        encontroUser = strcmp(this->getUser(), user);
        if(encontroUser == 0)
        {
            return i;
        }
    }
    return -1;
}

int UsuarioLogin::getCantidadRegistros()
{
    FILE *p = fopen("usuarioLogin.dat", "rb");

    if (p == NULL)
    {
        return 0;
    }

    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(*this);
}
