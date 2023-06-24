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



