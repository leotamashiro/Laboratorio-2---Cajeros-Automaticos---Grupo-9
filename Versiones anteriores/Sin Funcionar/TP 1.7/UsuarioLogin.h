#ifndef USUARIOLOGIN_H
#define USUARIOLOGIN_H
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class UsuarioLogin
{
    private:
        int dni;
        char user[30];
        char password[7];
        int permiso;
        bool estado;

    public:
        int getDNI();
        int getPermiso();
        char *getUser();
        char *getPassword();
        bool getEstado();

        void setDNI(int _dni);
        void setPermiso (int _permiso);
        void setUser(char *_user);
        void setPassword(char *_password);
        void setEstado(bool _estado);

        bool editarEnDisco(int);
        void grabarEnDisco();
        bool leerDeDisco(int);

};

#endif // USUARIOLOGIN_H
