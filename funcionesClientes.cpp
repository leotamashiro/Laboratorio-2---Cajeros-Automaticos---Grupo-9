#include <cstdlib>
#include <time.h>
#include "funcionesClientes.h"

bool validarDni(int dni) {
    ArchivoCliente aux("clientes.dat");
    int encontroCliente;
    encontroCliente = aux.buscarClientePorId(dni);
    if(encontroCliente < 0) {
        return false;
    }
    return true;
}

void cargarCadena(char *pal, int tam){
    int i;
    fflush(stdin);
    for(i=0; i<tam; i++)
    {
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}

int generarNumeros(int desde, int hasta) {
    int num;
    srand(time(NULL));
    num=desde+rand()%(hasta-desde);
//    cout<<"NUM 2: "<<num<<endl;
    return num;
}

int persistirCliente() {
    ArchivoCliente arcCli("clientes.dat");
    Cliente cliente;

    cliente.CargarCliente();
    cout<<"-------------------------------"<<endl;
    cliente.MostrarCliente();
}

void mostrarCliente() {

}
