#ifndef DIRECCION_H
#define DIRECCION_H
#include <string>
#include <cstring>

using namespace std;

class Direccion
{
    private:
        char calle[100];
        int numero;
        int codPostal;
        char localidad[100];
        char provincia[100];
        char pais[100];

    public:

        ///gets
        char *getCalle();
        int getNumero();
        int getCodPostal();
        char *getLocalidad();
        char *getProvincia();
        char *getPais();

        ///sets
        void setCalle(char *_calle);
        void setNumero(int _numero);
        void setCodPostal(int _codPostal);
        void setLocalidad(char *_localidad);
        void setProvincia(char *_provincia);
        void setPais(char *_pais);

        void Cargar();
        void Mostrar();
};

#endif // DIRECCION_H
