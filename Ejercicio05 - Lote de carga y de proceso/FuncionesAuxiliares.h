#pragma once
int const cantAgencias = 20, cantAutos = 10, cantClientes = 200;
float vUbicaciones[3];
int vCategorias[10];
int vAgenciasMensual[cantAgencias];
bool alquiler = false;

struct datosAgencias
{
    int numAgencia;
    int ubiAgencia;
}vAgencias[cantAgencias];

struct datosAutos
{
    int codAuto;
    int catAuto;
    float impKM;
    struct datosAgencias agencia;
}vAutos[cantAutos];

struct datosClientes
{
    float totalAlquier = 0;
}vClientes[cantClientes];


// Funciones

int buscariAuto(struct datosAutos vAutos[], int codigoAuto, int const cantAutos)
{
    for (int i = 0; i < cantAutos; i++)
    {
        if (codigoAuto == vAutos[i].codAuto)
        {
            return i;
        }
    }
}

void inicializarvUbicaciones(float vUbicaciones[])
{
    for (int i = 0; i < 3; i++)
    {
        vUbicaciones[i] = 0;
    }
}

void inicializarvCategorias(int vCategorias[])
{
    for (int i = 0; i < 10; i++)
    {
        vCategorias[i] = 0;
    }
}

void inicializarvAgenciasMensual(int vAgenciasMensual[], int const cantAgencias)
{
    for (int i = 0; i < cantAgencias; i++)
    {
        vAgenciasMensual[i] = 0;
    }
}

void recaudacionUbicaciones(struct datosAutos vAutos[], int iAuto, 
                            float vUbicaciones[], int kmRecorridos)
{
    switch (vAutos[iAuto].agencia.ubiAgencia)
    {
        case 1: vUbicaciones[0] += (kmRecorridos * vAutos[iAuto].impKM); break;
        case 2: vUbicaciones[1] += (kmRecorridos * vAutos[iAuto].impKM); break;
        case 3: vUbicaciones[2] += (kmRecorridos * vAutos[iAuto].impKM); break;
    }
}

void maxCategoria(int vCategorias[], int& maxCat)
{
    int maximo;

    for (int i = 0; i < 10; i++)
    {
        if (i == 0)
        {
            maximo = vCategorias[i];
            maxCat = i + 1;
        }
        else if (vCategorias[i] > maximo)
        {
            maximo = vCategorias[i];
            maxCat = i + 1;
        }
    }
}