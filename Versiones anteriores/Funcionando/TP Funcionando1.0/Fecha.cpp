#include <iostream>
#include <string>
#include <ctime>
#include "Fecha.h"
using namespace std;

bool Fecha::esBiciesto()
{
    if ((anio % 4 == 0 && anio %100 !=0) || (anio%400==0))
    {
        return true;
    }
    return false;
}


void Fecha::Cargar()
{
    int dias[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    bool flag=true;
    cout << "Anio: ";
    flag=true;
    while (flag==true)
    {
        cin >> anio;
        if (anio > 0)
        {
            if (esBiciesto())
            {
                dias[1]++;
            }
            flag=false;
        }
        else
        {
            cout << "Ingrese un Anio correcto: ";
            flag=true;
        }
    }

    cout << "Mes: ";
    flag=true;
    while (flag==true)
    {
        cin >> mes;
        if (mes > 0 && mes <13)
        {
            flag=false;
        }
        else
        {
            cout << "Ingrese un Mes correcto: ";
            flag=true;
        }
    }

    flag=true;
    cout << "Dia: ";
    while (flag==true)
    {
        cin >> dia;
        if (dia > 0 && dia <=dias[mes-1])
        {
            flag=false;
        }
        else
        {
            cout << "Ingrese un Dia correcto: ";
            flag=true;
        }
    }

}

void Fecha::Mostrar()
{
    cout << dia << "/" << mes << "/" << anio << "\n";
}

///gets
void Fecha::setDia(int _dia)
{
    if (_dia >0 && _dia <32)
    {
        dia=_dia;
    }
}
void Fecha::setMes(int _mes)
{
    if (_mes >0 && _mes <13)
    {
        mes=_mes;
    }
}
void Fecha::setAnio(int _anio)
{
    if (_anio >0)
    {
        anio=_anio;
    }
}

///set
int Fecha::getDia()
{
    return dia;
}
int Fecha::getMes()
{
    return mes;
}
int Fecha::getAnio()
{
    return anio;
}

///
std::string Fecha::toString(std::string formatoFecha){
   std::string fechaFormateada = "";

   std::string DD = std::to_string(dia);
   std::string MM = std::to_string(mes);
   std::string YYYY = std::to_string(anio);
   // DD/MM/YYYY
   if (dia < 10){
      DD = "0" + std::to_string(dia);
   }
   if (mes < 10){
      MM = "0" + std::to_string(mes);
   }

   if (formatoFecha == "DD/MM/YYYY"){
      fechaFormateada = DD + "/" + MM + "/" + YYYY;
   }
   else if (formatoFecha == "YYYY/MM/DD"){
      fechaFormateada = YYYY + "/" + MM + "/" + DD;
   }
   else{
      fechaFormateada = DD + "/" + MM + "/" + YYYY;
   }

   return fechaFormateada;
}

void Fecha::actualFecha() {
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    anio = (now->tm_year +1900);
    dia = now->tm_mday;
    mes = (now->tm_mon+1);

//    cout << "Current Date: " << now->tm_mday << '/' << (now->tm_mon + 1) << '/'
//            << (now->tm_year + 1900) << endl;
}

void Fecha::fechaVencimiento() {
    int anioVencimiento;
    Fecha fecha;
    fecha.actualFecha();
    anioVencimiento = (fecha.getAnio() + 8);
    anio = anioVencimiento;
    mes = fecha.getMes();
    dia = fecha.getDia();
}
