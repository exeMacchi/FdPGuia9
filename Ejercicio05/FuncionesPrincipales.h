#include <iostream>
#include "FuncionesAuxiliares.h"

using std::cout;
using std::cin;
using std::endl;


// Lotes de carga

void cargarLoteAgencias(struct datosAgencias vAgencias[], int const cantAgencias)
{
    for (int i = 0; i < cantAgencias; i++)
    {
        cout << "Introduzca la ubicacion de la agencia numero " << i + 1 << " (1-3): "; cin >> vAgencias[i].ubiAgencia;
        vAgencias[i].numAgencia = i + 1;
    }
}

void cargarLoteAutos(struct datosAutos vAutos[], struct datosAgencias vAgencias[], int const cantAutos, 
                     int const cantAgencias)
{
    for (int i = 0; i < cantAutos; i++)
    {
        if (i == 0)
        {
            cout << "Codigo de auto: "; cin >> vAutos[i].codAuto;
            cout << "Categoria del auto: "; cin >> vAutos[i].catAuto;
            cout << "Importe por kilometro: $"; cin >> vAutos[i].impKM;
            cout << "Numero de agencia (1-20): "; cin >> vAutos[i].agencia.numAgencia;
        }
        else
        {
            cout << "\nCodigo de auto: "; cin >> vAutos[i].codAuto;
            cout << "Categoria del auto: "; cin >> vAutos[i].catAuto;
            cout << "Importe por kilometro: $"; cin >> vAutos[i].impKM;
            cout << "Numero de agencia (1-10): "; cin >> vAutos[i].agencia.numAgencia;
        }
    }

    for (int i = 0; i < cantAutos; i++) //Autos
    {
        for (int x = 0; x < cantAgencias; x++) // Agencias
        {
            if (vAgencias[x].numAgencia == vAutos[i].agencia.numAgencia)
            {
                vAutos[i].agencia.ubiAgencia = vAgencias[x].ubiAgencia;
            }
        }

    }
}


// Lote de proceso

void Proceso(struct datosAutos vAutos[], struct datosClientes vClientes[], int const cantAutos,
             float vUbicaciones[], int vCategorias[], int vAgenciasMensual[], bool& alquiler)
{
    int codigoAuto, cliente, diasAlquier, kmRecorridos;
    int iAuto;

    cout << "Numero de cliente (1-20): "; cin >> cliente;
    cout << "Codigo de auto: "; cin >> codigoAuto;
    cout << "Dias de renta totales: "; cin >> diasAlquier;
    cout << "Kilometros viajados en total: "; cin >> kmRecorridos;


    while (cliente > 0)
    {
        iAuto = buscariAuto(vAutos, codigoAuto, cantAutos);

        vClientes[cliente - 1].totalAlquier += (kmRecorridos * vAutos[iAuto].impKM);
        recaudacionUbicaciones(vAutos, iAuto, vUbicaciones, kmRecorridos);
        vCategorias[(vAutos[iAuto].catAuto - 1)]++;
        vAgenciasMensual[(vAutos[iAuto].agencia.numAgencia - 1)]++;
        alquiler = true;

        cout << "\nNumero de cliente (1-20): "; cin >> cliente;
        if (cliente != 0) {
            cout << "Codigo de auto: "; cin >> codigoAuto;
            cout << "Dias de renta totales: "; cin >> diasAlquier;
            cout << "Kilometros viajados en total: "; cin >> kmRecorridos;
        }
    }
}

// Resultados

void FPA(struct datosClientes vClientes[], int const cantClientes)
{
    for (int i = 0; i < cantClientes; i++)
    {
        if (i < 9)
        {
            cout << "Cliente numero " << i + 1 << "  || " 
                 << "Alquiler total pagado: $" << vClientes[i].totalAlquier << endl;
        }
        else
        {
            cout << "Cliente numero " << i + 1 << " || " 
                 << "Alquier total pagado: $" << vClientes[i].totalAlquier << endl;
        }
    }
}

void FPB(float vUbicaciones[])
{
    for (int i = 0; i < 3; i++)
    {
        switch (i)
        {
            case 0: cout << "\nTotal de ingresos acumulados en el Aeropuerto de Ezeiza: $" << vUbicaciones[i] << endl; 
                break;
            case 1: cout << "Total de ingresos acumulados en Aeroparque: $" << vUbicaciones[i] << endl; 
                break;
            case 2: cout << "Total de ingresos acumulados en Centro Ciudad: $" << vUbicaciones[i] << endl; 
                break;
            default: cout << "\nError: algo ha sucedido." << endl; 
                break;
        }
    }
}

void FPC(int const cantAutos, int const cantAgencias)
{
    int reparto = 0;

    reparto = cantAutos / cantAgencias;

    cout << "\nA cada agencia se le asinga un total de " << reparto << " vehiculos." << endl;
}

void FPD(int vCategorias[], bool alquiler)
{
    int maxCat;
    maxCategoria(vCategorias, maxCat);
    if (alquiler)
    {
        cout << "\nLa categoria de auto que mas alquilan los clientes es la numero " << maxCat << "." << endl;
    }
    else
    {
        cout << "\nLos clientes no alquilaron ninguna categoria." << endl;
    }
}

void FPE(int vAgenciasMensual[], int const cantAgencias)
{
    for (int i = 0; i < 10; i++)
    {
        if (vAgenciasMensual[i] < 10)
        {
            cout << "La agencia numero " << i + 1 << " realizo menos de diez alquileres en total." << endl;
        }
    }
}
