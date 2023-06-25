#include <iostream>
#include <string>
#include <cstring>
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
    	for(int j=0;j<tamSucursal ;j++)
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
        cout << "Puesto " << ":" << t+1 << "    ";
        sucu.leerDeDisco(posicionArchivoSucursal[t]);
        cout << "Sucursal numero: " << sucu.getNumeroSucursal() << "  ";
        cout << "con: " << cantTranSucu[t] << " Visitas" << "\n";
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
    	for(int j=0;j<tamCajero ;j++)
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
        cout << "Puesto " << ":" << t+1 << "    ";
        objCajero.leerDeDisco(posicionArchivoCajero[t]);
        cout << "ID Cajero: " << objCajero.getIdCajero() << "  ";
        cout << "con: " << cantTran[t] << " Tranacciones" << "\n";
    }
    delete cantTran;
    delete posicionArchivoCajero;
}



