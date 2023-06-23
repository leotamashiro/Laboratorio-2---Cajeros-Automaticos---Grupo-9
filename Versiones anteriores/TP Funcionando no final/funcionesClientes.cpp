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

int validarCin()
{
    int num;
    cin>>num;
    if(cin.fail())
    {
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
    while(!flag)
    {
        num = validarCin();
        if(num != -1)
        {
            flag = true;
        }
    }
    return num;
}

void ingresarFondosCuenta(int dni) {
    Cuenta cuenta;
    int pos;
    float fondos;
    bool editoEnDisco;
    pos = cuenta.buscarCuentaPorDni(dni);
    cuenta.leerDeDisco(pos);
    cout<<"INGRESE LA CANTIDAD DE FONDOS A INGRESAR A SU CUENTA: "<<cuenta.getNumeroCuenta()<<endl;
    cin>>fondos;
    cuenta.setSaldoAumentar(fondos);
    editoEnDisco = cuenta.editarEnDisco(pos);
    if(editoEnDisco) {
        cout<<"SE AGREGO LA CANTIDAD DE FONDOS: "<<cuenta.getSaldo()<<" A SU CUENTA: "<<cuenta.getNumeroCuenta()<<endl;
    } else {
        cout<<"HA OCURRIDO UN ERROR, POR FAVOR INTENTE DE NUEVO"<<endl;
    }
}

int posDniUsarioLogin() {
    UsuarioLogin login;
    int totalLogin = login.getCantidadRegistros();
    int pos, dni;

    cout<<"INGRESE DNI"<<endl;
    dni = validarNumerosIngresados();

    pos = login.buscarClientePorDni(dni);
    if(pos < 0)
    {
        cout<<"NO SE ENCONTRO NINGUN CLIENTE CON DNI: "<<dni<<endl;
        return -1;
    } else {
        return pos;
    }
}

int loginUsuario(int dni)
{
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

    if(pos == -1)
    {
        cout<<"NO SE ENCONTRO NINGUN CLIENTE CON EL USER: "<<user<<endl;
        return 0;
    }

    puedeIngresar = login.validarLogin(dni, password, pos);
    if(puedeIngresar)
    {
        cout<<"LOGIN OK"<<endl;
        login.leerDeDisco(pos);
        if(login.getPermiso() == 2) {
            ingresarFondosCuenta(dni);
        }
        return login.getPermiso();
    }
    else
    {
        cout<<"NO PUEDE INGRESAR"<<endl;
        return 0;
    }
}

void editarDireccionCliente()
{
    Cliente cliente;
    ArchivoCliente arcCli("clientes.dat");
    int pos;
    bool clienteEditado;

    pos = posDniEncontrado();

    cliente = arcCli.leerCliente(pos);
    cliente.setDireccion();
    clienteEditado = arcCli.sobreescribirCliente(cliente, pos);
    if(clienteEditado)
    {
        cout<<"CLIENTE MODIFICADO CORRECTAMENTE"<<endl;
    }
    else
    {
        cout<<"NO SE LOGRO MODIFICAR EL CLIENTE"<<endl;
    }
}

void editarUserCliente()
{
    UsuarioLogin login;
    int pos;
    bool clienteEditado;
    char user[30];
    char nuevoUser[30];

    pos = posDniUsarioLogin();
    if(pos == -1) return;

    login.leerDeDisco(pos);
    cout<<"INGRESE ANTIGUO USER"<<endl;
    cargarCadena(user, 29);
    if(strcmp(login.getUser(), user))
    {
        cout<<"EL USER INGRESADO NO COINCIDE CON ANTIGUO USER"<<endl;
    }
    else
    {
        cout<<"INGRESE EL NUEVO NOMBRE DE USER"<<endl;
        cargarCadena(nuevoUser, 29);
        login.setUser(nuevoUser);
        clienteEditado = login.editarEnDisco(pos);

        if(clienteEditado)
        {
            cout<<"CLIENTE MODIFICADO CORRECTAMENTE"<<endl;
        }
        else
        {
            cout<<"NO SE LOGRO MODIFICAR EL CLIENTE"<<endl;
        }
    }
}

void editarPasswordCliente() {
    UsuarioLogin login;
    int pos;
    bool clienteEditado;
    char pass[7];
    char nuevoPass[7];

    pos = posDniUsarioLogin();
    if(pos == -1) return;

    login.leerDeDisco(pos);
    cout<<"INGRESE ANTIGUA PASSWORD"<<endl;
    cargarCadena(pass, 6);
    if(strcmp(login.getPassword(), pass))
    {
        cout<<"LA PASSWORD INGRESADA NO COINCIDE CON LA ANTIGUA PASSWORD"<<endl;
    }
    else
    {
        cout<<"INGRESE LA NUEVA PASSWORD (MAXIMO 6 DIGITOS)"<<endl;
        cargarCadena(nuevoPass, 6);
        login.setPassword(nuevoPass);
        clienteEditado = login.editarEnDisco(pos);

        if(clienteEditado)
        {
            cout<<"CLIENTE MODIFICADO CORRECTAMENTE"<<endl;
        }
        else
        {
            cout<<"NO SE LOGRO MODIFICAR EL CLIENTE"<<endl;
        }
    }

}

void editarDatosCliente() {
    Cliente cliente;
    ArchivoCliente arcCli("clientes.dat");
    int pos, nroTelefono;
    bool clienteEditado;
    char nombre[30], apellido[30], email[30];

    pos = posDniEncontrado();

    cliente = arcCli.leerCliente(pos);
    cout<<"INGRESE NOMBRE: "<<endl;
    cargarCadena(nombre, 29);
    cout<<"INGRESE APELLIDO: "<<endl;
    cargarCadena(apellido, 29);
    cout<<"INGRESE EMAIL: "<<endl;
    cargarCadena(email, 29);
    cout<<"INGRESE NUEVO NUMERO TELEFONICO"<<endl;
    nroTelefono = validarNumerosIngresados();
    cliente.setNombre(nombre);
    cliente.setApellido(apellido);
    cliente.setEmail(email);
    cliente.setNumeroTelefono(nroTelefono);

    clienteEditado = arcCli.sobreescribirCliente(cliente, pos);
    if(clienteEditado)
    {
        cout<<"CLIENTE MODIFICADO CORRECTAMENTE"<<endl;
    }
    else
    {
        cout<<"NO SE LOGRO MODIFICAR EL CLIENTE"<<endl;
    }
}

void editarPermisosCliente() {
    UsuarioLogin login;
    int pos, permiso;
    bool clienteEditado;

    pos = posDniUsarioLogin();
    if(pos == -1) return;
    login.leerDeDisco(pos);
    cout<<"ELIJA EL PERMISO PARA EL CLIENTE. 1. ADMINSTRADOR - 2. CLIENTE"<<endl;
    cin>>permiso;
    if(permiso == 1 || permiso == 2) {
        login.setPermiso(permiso);
        login.editarEnDisco(pos);
        cout<<"PERMISOS DE CLIENTE ACTUALIZADOS CORRECTAMENTE"<<endl;
    } else {
        cout<<"INGRESE UN PERMISO VALIDO"<<endl;
    }
}

void menuEditarClientes()
{
    int opcion;
    do
    {
        cout << "---------------------------------" << endl;
        cout << "1. Editar Direccion" << endl;
        cout << "2. Editar User" << endl;
        cout << "3. Editar Password" << endl;
        cout << "4. Editar Datos Personales" << endl;
        cout << "5. Editar Permisos Clientes" << endl;
        cout << endl;
        cout << "0. Salir" << endl;
        cout << "---------------------------------" << endl;
        cout << endl;
        cin >> opcion;

        switch(opcion)
        {
        case 1:
            editarDireccionCliente();
            break;
        case 2:
            editarUserCliente();
            break;
        case 3:
            editarPasswordCliente();
            break;
        case 4:
            editarDatosCliente();
            break;
        case 5:
            editarPermisosCliente();
            break;
        default:
            cout << "Debe ingresar una opcion correcta" << endl;
            break;
        }

    }
    while(opcion != 0);
}

