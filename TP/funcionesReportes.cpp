#include <iostream>
#include <string>
#include <cstring>
#include <time.h>

using namespace std;
#include "Cuenta.h"
#include "funciones.h"
#include "Sucursal.h"
#include "Cajero.h"
#include "Transacciones.h"
#include "UsuarioLogin.h"
#include "Cliente.h"
#include "ArchivoCliente.h"
#include "funcionesClientes.h"

int desplazamientoDerecha(int *vec, int tam)
{
    int tamVector=tam-1;
    for (int t=tamVector; t>0; t--)
    {
        vec[t] = vec[t - 1];
    }
}

void topSucursales()
{
    int rankingSucursal[3];

}

void topCajeros()
{
    int rankingCajeros[5]={};
    int rankingTransac[5]={};
    int contTrans=0, contTranAux;
    Cajero objCajero;
    Transacciones regTransacciones;
    int idCajero, idCajeroAux;
    int posCajero=0, posTransac=0;
    while(objCajero.leerDeDisco(posCajero))
    {
        contTrans=0;
        idCajero=objCajero.getIdCajero();
        while (regTransacciones.leerDeDisco(posTransac))
        {
            if (idCajero==regTransacciones.getIdProcedencia())
            {
                contTrans++;
            }
            posTransac++;
        }
        if (posCajero==0)
        {
            rankingCajeros[0]=idCajero;
            rankingTransac[0]=contTrans;
        }
        else
        {
            for (int i=0; i<5; i++)
            {
                if (contTrans>rankingTransac[i])
                {
                    desplazamientoDerecha (rankingTransac, 5-i);
                    rankingTransac[i]=contTrans;
                }
            }
            //comparar Y/O desplazar
        }
        posCajero++;
    }
}

void transaccionesPeriodoTiempo() {
    Transacciones transacciones;
    Fecha fechaInicial, fechaFinal;
    int totalTransacciones = transacciones.contarRegistros();
    string fechaTransaccion, fechaPeriodoInicial, fechaPeriodoFinal;
    int contador = 0;

    cout<<"INGRESE EL PERIODO DE TIEMPO "<<endl;
    cout<<"Ingrese el comienzo: "<<endl;
    fechaInicial.Cargar();
    cout<<"Ingrese el final: "<<endl;
    fechaFinal.Cargar();

    cout<<"---------------------"<<endl;
    system("cls");

    fechaPeriodoInicial = fechaInicial.toString();
    fechaPeriodoFinal = fechaFinal.toString();

    for(int i = 0; i < totalTransacciones; i++) {
        transacciones.leerDeDisco(i);
        fechaTransaccion = transacciones.getFechaTranssacion().toString();
        if(fechaTransaccion >= fechaPeriodoInicial && fechaTransaccion <= fechaPeriodoFinal) {
            transacciones.Mostrar();
            contador++;
        }
    }
    cout<<"Para el periodo de tiempo desde "<<fechaPeriodoInicial<<" hasta "<<fechaPeriodoFinal;
    cout<<", se obtuvieron "<<contador<<" transacciones."<<endl;
}

void cantidadDineroExtraidoPorDia() {
    Fecha fecha;
    Transacciones transacciones;
    int totalTransacciones = transacciones.contarRegistros();
    string fechaDia;
    float acumulador = 0;
    cout<<"INGRESE LA FECHA DEL DIA QUE DESEA CONSULTAR "<<endl;
    fecha.Cargar();
    fechaDia = fecha.toString();

    for(int i = 0; i < totalTransacciones; i++) {
        transacciones.leerDeDisco(i);
        if(transacciones.getFechaTranssacion().toString() == fechaDia && transacciones.getTipoTransaccion() == 1 && transacciones.getConfirmada()) {
            acumulador += transacciones.getMonto();
        }
    }
    if(acumulador > 0) {
        cout<<"Para el dia "<<fechaDia<<", se extrajeron de todos los cajeros un monto total de "<<acumulador<<endl;
    } else {
        cout<<"Para el dia "<<fechaDia<<", no se extrajo dinero de ningun cajero"<<endl;
    }
}

void cantidadDineroIngresadoClientesPorMes() {
    int mes, anio, contador;
    float acumulado;
    Transacciones transacciones;
    Cliente cliente;
    ArchivoCliente arcCliente("clientes.dat");
    int totalClientes = arcCliente.getCantidadRegistros();
    int totalTransacciones = transacciones.contarRegistros();

    cout<<"Ingrese el mes que desea consultar"<<endl;
    mes = validarNumerosIngresados();
    if(mes <= 0 || mes > 12) {
        cout<<"Ingrese un mes valido"<<endl;
        return;
    }
    cout<<"Ingrese el anio que desea consultar"<<endl;
    anio = validarNumerosIngresados();
    Fecha fechaDeMes(1, mes, anio);

    system("pause");
    system("cls");

    for(int i = 0; i < totalClientes; i++) {
        acumulado = 0;
        contador = 0;
        cliente = arcCliente.leerCliente(i);
        for(int j = 0; j < totalTransacciones; j++){
            transacciones.leerDeDisco(j);
            if(cliente.getDni() == transacciones.getDniCliente() && transacciones.getTipoTransaccion() == 2 && transacciones.getConfirmada() && cliente.getActivo()) {
                acumulado += transacciones.getMonto();
                contador++;
            }
        }
        cout<<"Nombre Cliente: "<<cliente.getNombre()<<endl;
        cout<<"Apellido Cliente: "<<cliente.getApellido()<<endl;
        cout<<"Dni Cliente: "<<cliente.getDni()<<endl;
        cout<<"Email Cliente: "<<cliente.getEmail()<<endl;
        cout<<"Total de Ingresos Mensual: "<<acumulado<<endl;
        cout<<"Cantidad de Transacciones Confirmadas Mensuales: "<<contador<<endl;
        cout<<"-------------------------------------------------"<<endl;
    }

    cout<<"DATOS MENSUALES PARA EL MES "<<mes<<" Y EL ANIO "<<anio<<endl;
}


