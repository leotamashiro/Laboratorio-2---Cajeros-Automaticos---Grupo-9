#include <cstdlib>
#include <time.h>
#include "funcionesClientes.h"
#include "UsuarioLogin.h"

int posCliente(int dni)
{
    ArchivoCliente aux("clientes.dat");
    int encontroCliente;
    encontroCliente = aux.buscarClientePorId(dni);
    encontroCliente;
}

bool validarDni(int dni)
{
    int encontroCliente = posCliente(dni);
    if(encontroCliente < 0)
    {
        return false;
    }
    return true;
}

void cargarCadena(char *pal, int tam)
{
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

int generarNumeros(int desde, int hasta)
{
    Cuenta cuenta;
    int num;
    int totalCuenta = cuenta.contarRegistros();
    int contador;

    do
    {
        srand(time(NULL));
        num=desde+rand()%(hasta-desde);
        contador = 0;
        for(int i = 0; i < totalCuenta; i++)
        {
            cuenta.leerDeDisco(i);
            if(cuenta.getNumeroCuenta() == num)
            {
                contador++;
            }
        }

    }
    while(contador!=0);

    return num;
}

int persistirCliente()
{
    ArchivoCliente arcCli("clientes.dat");
    Cliente cliente;

    cliente.CargarCliente();
    arcCli.guardarCliente(cliente);
    cout<<"-------------------------------"<<endl;
}

void mostrarClientes(int pos, Cliente &cliente)
{
    UsuarioLogin login;
    Cuenta cuenta;
    int totalCuenta = cuenta.contarRegistros();
    int totalLogin = login.getCantidadRegistros();

    for(int j = 0; j<totalCuenta; j++)
    {
        cuenta.leerDeDisco(j);
        if(cuenta.getDniCliente() == cliente.getDni() && cliente.getActivo())
        {
            for(int x = 0; x < totalLogin; x++)
            {
                login.leerDeDisco(x);
                if(login.getDNI() == cuenta.getDniCliente() && cuenta.getActivo() && login.getEstado())
                {
                    cliente.MostrarCliente();
                    cuenta.MostrarCuenta();
                    login.mostrarLogin();

                }
            }
        }
    }
}

void buscarClientes()
{
    ArchivoCliente arcCli("clientes.dat");
    Cliente cliente;
    int totalClientes = arcCli.getCantidadRegistros();
    for(int i = 0; i < totalClientes; i++)
    {
        cliente = arcCli.leerCliente(i);
        mostrarClientes(i, cliente);
    }
}

bool validarUser(const char* user)
{
    UsuarioLogin userLogin;
    int encontroCliente;
    encontroCliente = userLogin.buscarClientePorUser(user);
    if(encontroCliente < 0)
    {
        return false;
    }
    return true;
}

int posDniEncontrado()
{
    int dni, encontroCliente;
    cout<<"INGRESE DNI A BUSCAR: "<<endl;
    cin>>dni;
    encontroCliente = posCliente(dni);
    if(encontroCliente < 0)
    {
        cout<<"NO SE ENCONTRO NINGUN CLIENTE POR EL DNI: "<<dni<<endl;
        return -1;
    }
    return encontroCliente;
}
int posDniEncontrado(int dni)
{
    int encontroCliente;
    encontroCliente = posCliente(dni);
    if(encontroCliente < 0)
    {
        cout<<"NO SE ENCONTRO NINGUN CLIENTE POR EL DNI: "<<dni<<endl;
        return -1;
    }
    return encontroCliente;

}

bool buscarClientePorDni()
{
    ArchivoCliente arcCli("clientes.dat");
    Cliente cliente;
    int pos = posDniEncontrado();
    if (pos == -1) return false;

    cliente = arcCli.leerCliente(pos);
    mostrarClientes(pos, cliente);
}

bool eliminadoLogico()
{
    ArchivoCliente arcCli("clientes.dat");
    Cliente cliente;
    Cuenta cuenta;
    UsuarioLogin login;
    int totalCuenta = cuenta.contarRegistros();
    int totalLogin = login.getCantidadRegistros();
    int dni;
    cout<<"INGRESE DNI A BUSCAR: "<<endl;
    cin>>dni;

    int pos = posDniEncontrado(dni);
    if (pos == -1) return false;

    cliente = arcCli.leerCliente(pos);
    cliente.setActivo(false);

    for(int i = 0; i < totalCuenta; i++)
    {
        cuenta.leerDeDisco(i);
        if(cuenta.getDniCliente() == dni)
        {
            cuenta.setActivo(false);
            cuenta.editarEnDisco(i);
        }
    }
    for(int i = 0; i < totalLogin; i++)
    {
        login.leerDeDisco(i);
        if(login.getDNI() == dni)
        {
            login.setEstado(false);
            login.editarEnDisco(i);
        }
    }
    return arcCli.sobreescribirCliente(cliente, pos);
}

int validarCin() {
    int num;
    cin>>num;
    if(cin.fail()) {
        cout<<"Por favor ingrese un numero entero"<<endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return -1;
    }
    return num;
}

int validarNumerosIngresados()
{
    int num;
    bool flag = false;
    cout<<"Ingrese un numero entero"<<endl;
    while(!flag) {
        num = validarCin();
        if(num != -1) {
            flag = true;
        }
    }
    return num;
}

int loginUsuario(int dni) {
    UsuarioLogin login;
    int pos;
    char password[7];
    char user[30];
    bool puedeIngresar;

    cout<<"INGRESE USER: "<<endl;
    cargarCadena(user, 29);
    cout<<"INGRESE PASSWORD: "<<endl;
    cargarCadena(password, 6);

    pos = login.buscarClientePorUser(user);

    if(pos == -1) {
        cout<<"NO SE ENCONTRO NINGUN CLIENTE CON EL USER: "<<user<<endl;
        return 0;
    }

    puedeIngresar = login.validarLogin(dni, password, pos);
    if(puedeIngresar) {
        cout<<"LOGIN OK"<<endl;
        login.leerDeDisco(pos);
        return login.getPermiso();
    } else {
        cout<<"NO PUEDE INGRESAR"<<endl;
        return 0;
    }
}

