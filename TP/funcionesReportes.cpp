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
#include <time.h>
#include "Cuenta.h"

using namespace std;

void topSucursales()
{

    Cajero objCajero;
    Transacciones regTransacciones;
    Sucursal sucu;
    int tamCajero, tamSucursal;
    tamCajero=objCajero.contarRegistros();
    tamSucursal = sucu.contarRegistros();

    if(tamCajero == -1 || tamSucursal == -1)
    {
        cout<<"No es encontraron registros"<<endl;
        return;
    }

    int *cantTranSucu;// me guardo la cantidad de transacciones por Sucursal
    cantTranSucu=new int[tamSucursal];

    int *posicionArchivoSucursal; // el vector donde me guardo la poscion de (las 3 mayores) del vector dinamico que voy ornando
    posicionArchivoSucursal= new int [tamSucursal];


    if((cantTranSucu==NULL)||(posicionArchivoSucursal==NULL))
    {
        cout<<"ERROR DE ASIGANCION DE MEMORIA"<<endl;
        return;
    }

    //pongo en 0 todo el vector dinamico de cantidad de Transacion por Cajero, y Pos del Cajero en ArchivoCajero
    for (int a=0; a<tamSucursal; a++)
    {
        cantTranSucu[a]=0;
        posicionArchivoSucursal[a]=0;
    }


    int idCajero, numSucursal;
    int posCajero=0, posTransac=0, posSucu=0;
    //Busco la cantidad de transacciones por Cajero
    while (sucu.leerDeDisco(posSucu))
    {
        numSucursal=sucu.getNumeroSucursal();
        posCajero=0;
        while (objCajero.leerDeDisco(posCajero))
        {
            idCajero=objCajero.getIdCajero();
            posTransac=0;
            if (numSucursal==objCajero.getNumSucursal())
            {
                while(regTransacciones.leerDeDisco(posTransac))
                {
                    if (idCajero==regTransacciones.getIdProcedencia())
                    {
                        cantTranSucu[posSucu]++;
                    }
                    posTransac++;
                }
            }
            posCajero++;
        }
        posicionArchivoSucursal[posSucu]=posSucu;
        posSucu++;
    }

    // Se ordena el vector de mayor a menor por metodo burbuja
    int auxTran, auxPosSucu;
    for(int i=0; i<tamSucursal ; i++)
    {
        for(int j=0; j<tamSucursal ; j++)
        {
            if(cantTranSucu[j]<cantTranSucu[j+1])
            {
                //Ordeno de mayor a menor la cantidad de Transacciones por Sucursal,
                auxTran=cantTranSucu[j];
                cantTranSucu[j]=cantTranSucu[j+1];
                cantTranSucu[j+1]=auxTran;
                //Ordeno de mayor a menor (por cantidad de Transacciones) la posicion de la Sucursal en Archivo Sucursal
                auxPosSucu=posicionArchivoSucursal[j];
                posicionArchivoSucursal[j]=posicionArchivoSucursal[j+1];
                posicionArchivoSucursal[j+1]=auxPosSucu;
            }
        }
    }

    // Se muestra top 3 sucursal con mas visitas
    cout << "Top 3 Sucursales con mas visitas" << endl;
    cout << "-------------------------------------" << endl;
    for (int t=0; t<3; t++)
    {
        if (cantTranSucu[t]!=0)
        {
            cout << "Puesto " << ":" << t+1 << "    ";
            sucu.leerDeDisco(posicionArchivoSucursal[t]);
            cout << "Sucursal numero: " << sucu.getNumeroSucursal() << "  ";
            cout << "con: " << cantTranSucu[t] << " Visitas" << "\n";
        }
        else
        {
            cout << "El registro Sucursales no tiene 3 registros" << "\n";
        }
    }
    delete cantTranSucu;
    delete posicionArchivoSucursal;
}

void topCajeros()
{
    Cajero objCajero;
    Transacciones regTransacciones;
    int tamCajero;
    tamCajero=objCajero.contarRegistros();

    if(tamCajero == -1)
    {
        cout<<"No es encontraron registros"<<endl;
        return;
    }

    int *cantTran;    // me guardo la cantidad de transacciones por Cajero
    cantTran=new int[tamCajero];

    int *posicionArchivoCajero; // es el vector donde me guardo cada poscion (las 5 mayores) del vector dinamico cuando los voy ordenando
    posicionArchivoCajero= new int [tamCajero];

    if((cantTran==NULL)||(posicionArchivoCajero==NULL))
    {
        cout<<"ERROR DE ASIGANCION DE MEMORIA"<<endl;
        return;
    }

    //pongo en 0 todo el vector dinamico
    for (int a=0; a<tamCajero; a++)
    {
        cantTran[a]=0;
        posicionArchivoCajero[a]=0;
    }

    int idCajero;
    int posCajero=0, posTransac=0;
    //Busco la cantidad de transacciones por Cajero
    while(objCajero.leerDeDisco(posCajero))
    {
        posTransac=0;
        idCajero=objCajero.getIdCajero();
        while (regTransacciones.leerDeDisco(posTransac))
        {
            if (idCajero==regTransacciones.getIdProcedencia())
            {
                cantTran[posCajero]++;
            }
            posicionArchivoCajero[posCajero]=posCajero;
            posTransac++;
        }

        posCajero++;
    }
    //hasta aca tengo el vector din lleno
    // Se ordena el vector de mayor a menor por metodo burbuja
    int auxTran, auxPosCajero;
    for(int i=0; i<tamCajero ; i++)
    {
        for(int j=0; j<tamCajero ; j++)
        {
            if(cantTran[j]<cantTran[j+1])
            {
                //Ordeno de mayor a menor la cantidad de Transacciones por Cajero,
                auxTran=cantTran[j];
                cantTran[j]=cantTran[j+1];
                cantTran[j+1]=auxTran;
                //Ordeno de mayor a menor (por cantidad de Transacciones) la posicion del Cajero en Archivo cajero
                auxPosCajero=posicionArchivoCajero[j];
                posicionArchivoCajero[j]=posicionArchivoCajero[j+1];
                posicionArchivoCajero[j+1]=auxPosCajero;
            }
        }
    }

    // Se muestra los primeros 5 cajeros con mas transaccciones
    cout << "Top 5 Cajeros con mas transacciones" << endl;
    cout << "-------------------------------------" << endl;
    for (int t=0; t<5; t++)
    {
        if (cantTran[t]!=0)
        {
            cout << "Puesto " << ":" << t+1 << "    ";
            objCajero.leerDeDisco(posicionArchivoCajero[t]);
            cout << "ID Cajero: " << objCajero.getIdCajero() << "  ";
            cout << "con: " << cantTran[t] << " Tranacciones" << "\n";
        }
        else
        {
            cout << "El registro Cajeros no tiene 5 registros" << "\n";
        }

    }
    delete cantTran;
    delete posicionArchivoCajero;
}

void transaccionesPeriodoTiempo()
{
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

    for(int i = 0; i < totalTransacciones; i++)
    {
        transacciones.leerDeDisco(i);
        fechaTransaccion = transacciones.getFechaTranssacion().toString();
        if(fechaTransaccion >= fechaPeriodoInicial && fechaTransaccion <= fechaPeriodoFinal)
        {
            transacciones.Mostrar();
            contador++;
        }
    }
    cout<<"Para el periodo de tiempo desde "<<fechaPeriodoInicial<<" hasta "<<fechaPeriodoFinal;
    cout<<", se obtuvieron "<<contador<<" transacciones."<<endl;
}

void cantidadDineroExtraidoPorDia()
{
    Fecha fecha;
    Transacciones transacciones;
    int totalTransacciones = transacciones.contarRegistros();
    string fechaDia;
    float acumulador = 0;
    cout<<"INGRESE LA FECHA DEL DIA QUE DESEA CONSULTAR "<<endl;
    fecha.Cargar();
    fechaDia = fecha.toString();

    for(int i = 0; i < totalTransacciones; i++)
    {
        transacciones.leerDeDisco(i);
        if(transacciones.getFechaTranssacion().toString() == fechaDia && transacciones.getTipoTransaccion() == 1 && transacciones.getConfirmada())
        {
            acumulador += transacciones.getMonto();
        }
    }
    if(acumulador > 0)
    {
        cout<<"Para el dia "<<fechaDia<<", se extrajeron de todos los cajeros un monto total de "<<acumulador<<endl;
    }
    else
    {
        cout<<"Para el dia "<<fechaDia<<", no se extrajo dinero de ningun cajero"<<endl;
    }
}

void cantidadDineroIngresadoClientesPorMes()
{
    int mes, anio, contador;
    float acumulado;
    Transacciones transacciones;
    Cliente cliente;
    ArchivoCliente arcCliente("clientes.dat");
    int totalClientes = arcCliente.getCantidadRegistros();
    int totalTransacciones = transacciones.contarRegistros();

    cout<<"Ingrese el MES que desea consultar"<<endl;
    mes = validarNumerosIngresados();
    if(mes <= 0 || mes > 12)
    {
        cout<<"Ingrese un mes valido"<<endl;
        return;
    }
    cout<<"Ingrese el ANIO que desea consultar"<<endl;
    anio = validarNumerosIngresados();
    Fecha fechaDeMes(1, mes, anio);

    system("pause");
    system("cls");

    for(int i = 0; i < totalClientes; i++)
    {
        acumulado = 0;
        contador = 0;
        cliente = arcCliente.leerCliente(i);
        for(int j = 0; j < totalTransacciones; j++)
        {
            transacciones.leerDeDisco(j);
            if(cliente.getDni() == transacciones.getDniCliente() && transacciones.getTipoTransaccion() == 2 && transacciones.getConfirmada() && cliente.getActivo())
            {
                acumulado += transacciones.getMonto();
                contador++;
            }
        }
        if(cliente.getActivo())
        {
            cout<<"Nombre Cliente: "<<cliente.getNombre()<<endl;
            cout<<"Apellido Cliente: "<<cliente.getApellido()<<endl;
            cout<<"Dni Cliente: "<<cliente.getDni()<<endl;
            cout<<"Email Cliente: "<<cliente.getEmail()<<endl;
            cout<<"Cliente Activo: "<<cliente.getActivo()<<endl;
            cout<<"Total de Ingresos Mensual: "<<acumulado<<endl;
            cout<<"Cantidad de Transacciones Confirmadas Mensuales: "<<contador<<endl;
            cout<<"-------------------------------------------------"<<endl;

        }
    }

    cout<<"DATOS MENSUALES PARA EL MES "<<mes<<" Y EL ANIO "<<anio<<endl;
}


void porcetajeExtracionesPorAnio()
{
    int anioBuscado;
    int vecMes[12]={0};
    int contTrans=0;
    float porcentajeMes[12]={0};
    Transacciones regTrasacciones;
    int tamTrans = regTrasacciones.contarRegistros();
    cout<<"INGRESE EL ANIO "<<endl;
    anioBuscado = validarNumerosIngresados(); // ingreso anioBuscado

    for (int i=0; i<tamTrans; i++)
    {
        regTrasacciones.leerDeDisco(i);
        if (anioBuscado==regTrasacciones.getFechaTranssacion().getAnio())
        {
            vecMes[regTrasacciones.getFechaTranssacion().getMes()-1]++;
            contTrans++;
        }
    }
    for (int t=0; t<12; t++)
    {
        porcentajeMes[t]=(vecMes[t]*100)/contTrans;
    }
    cout << "El porcentaje de extracion mensual del anio: " << anioBuscado << " es:\n";
    for (int a=1; a<=12; a++)
    {
        cout << "Mes: " << a << "  " << porcentajeMes[a-1] << "%" << endl;
    }

}

