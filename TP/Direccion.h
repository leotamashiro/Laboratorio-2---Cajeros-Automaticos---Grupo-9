#ifndef DIRECCION_H
#define DIRECCION_H
#include <string>
#include <cstring>

using namespace std;

class Direccion
{
    private:
        string calle;
        int numero;
        int codPostal;
        std::string localidad;
        std::string provincia;
        std::string pais;

    public:

        ///gets
        string getCalle();
        int getNumero();
        int getCodPostal();
        std::string getLocalidad();
        std::string getProvincia();
        std::string getPais();

        ///sets
        void setCalle(string _calle);
        void setNumero(int _numero);
        void setCodPostal(int _codPostal);
        void setLocalidad(std::string _localidad);
        void setProvincia(std::string _provincia);
        void setPais(std::string _pais);

        void Cargar();
        void Mostrar();
};

#endif // DIRECCION_H
