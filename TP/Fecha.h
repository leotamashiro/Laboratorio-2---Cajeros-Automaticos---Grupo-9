#ifndef FECHA_H
#define FECHA_H

class Fecha
{
    private:
        int dia, mes, anio;
        bool esBiciesto();

    public:
        Fecha(int _dia=0, int _mes=0, int _anio=0)
        {
            dia=_dia;
            mes=_mes;
            anio=_anio;
        }

        void Cargar();
        void Mostrar();

        void setDia(int _dia);
        void setMes(int _mes);
        void setAnio(int _anio);

        int getDia();
        int getMes();
        int getAnio();

        std::string toString(std::string formatoFecha = "DD/MM/YYYY");


};

#endif // FECHA_H
