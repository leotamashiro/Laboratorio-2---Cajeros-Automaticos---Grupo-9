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

///
bool UsuarioLogin::editarEnDisco(int pos){
    bool guardo;
    FILE *p;
    p = fopen("usuarioLogin.dat", "rb+");
    if( p == NULL ){
        return false;
    }
    fseek(p, sizeof(UsuarioLogin)*pos, SEEK_SET);
    guardo = fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return guardo;
}
bool UsuarioLogin::leerDeDisco(int pos){
    bool lectura;
    FILE *p;
    p = fopen("usuarioLogin.dat", "rb");
    if( p == NULL ){
        return false;
    }
    fseek(p, sizeof(UsuarioLogin)*pos, SEEK_SET);
    lectura = fread(this, sizeof *this, 1, p);
    fclose(p);
    return lectura;
}
void UsuarioLogin::grabarEnDisco(){
    FILE *p;
    p = fopen("usuarioLogin.dat", "ab");
    if( p == NULL ){
        return;
    }
    fwrite(this, sizeof *this, 1, p);
    fclose(p);
}
