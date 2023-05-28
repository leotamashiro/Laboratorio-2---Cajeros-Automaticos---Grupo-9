#ifndef DIRECCION_H
#define DIRECCION_H


class Direccion
{
    private:
        char calle[40];
        int numero;
        int codPostal;
        char localidad[40];
        char provincia[40];
        char pais[40];

    public:
        Direccion();
        Direccion(std::string _calle, int _numero, int _codPostal, std::string _localidad, std::string _provincia, std::string _pais);

        ///gets
        std::string getCalle();
        int getNumero();
        int getCodPostal();
        std::string getLocalidad();
        std::string getProvincia();
        std::string getPais();

        ///sets
        void setCalle(std::string _calle);
        void setNumero(int _numero);
        void setCodPostal(int _codPostal);
        void setLocalidad(std::string _localidad);
        void setProvincia(std::string _provincia);
        void setPais(std::string _pais);

        void Cargar();
        void Mostrar();
};

#endif // DIRECCION_H
