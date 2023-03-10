#pragma once
#include <iostream>
#include "FuncionesAuxiliares.h"

using std::cout;
using std::cin;
using std::endl;


void cargarLote(int vNT[20], float vIKM[20]) 
{
    int NT;
    float IKM;

    for (int i = 0; i < 20; i++) 
    {
        if (i == 0) 
        {
            cout << "Numero de tarifa: "; cin >> NT;
            cout << "Importe por kilometro: $"; cin >> IKM;
            vNT[i] = NT;
            vIKM[i] = IKM;
        }
        else 
        {
            cout << "\nNumero de tarifa: "; cin >> NT;
            cout << "Importe por kilometro: $"; cin >> IKM;
            vNT[i] = NT;
            vIKM[i] = IKM;
        }
    }
}

void Proceso(int vNT[20], float vIKM[20], float vTR[20], float vTRC[100],
             int vKilometros[100]) 
{
    int numCamion, numTarifa, KM, I;
    float impTotal = 0;

    cout << "\nNumero de camion (1-100): "; cin >> numCamion;
    cout << "Numero de tarifa (1-20): "; cin >> numTarifa;
    cout << "Kilometros viajados: "; cin >> KM;

    while (numCamion > 0) 
    {
        I = buscarI(numTarifa, vNT);
        impTotal = KM * vIKM[I];
        vTR[I] += impTotal;
        vTRC[numCamion - 1] += impTotal;
        vKilometros[numCamion - 1] += KM;

        cout << "\nNumero de camion (1-100): "; cin >> numCamion;
        if (numCamion > 0) 
        {
            cout << "Numero de tarifa (1-20): "; cin >> numTarifa;
            cout << "Kilometros viajados: "; cin >> KM;
        }
    }
}

void FPA(int vNT[20], float vTR[20]) 
{
    for (int i = 0; i < 20; i++) 
    {
        cout << "La tarifa numero " << vNT[i] << " recaudo en total: $" 
             << vTR[i] << endl;
    }
}

void FPB(int vCamiones[100], float vTRC[100]) 
{
    int vCamionesCopia[100];
    float vTRCCopia[100];

    copiaCamiones(vCamiones, vCamionesCopia);
    copiaTRC(vTRC, vTRCCopia);

    ordenarMayorAMenor(vCamionesCopia, vTRCCopia);
    for (int i = 0; i < 100; i++) {
        cout << "El camion numero " << vCamionesCopia[i] 
             << " recaudo en total: $" << vTRCCopia[i] << endl;
    }
}

void FPC(int vCamiones[100], int vKilometros[100]) 
{
    int I = minimo(vKilometros);
    cout << "El camion numero " << vCamiones[I] 
         << " viajo la menor distancia (" << vKilometros[I] << " km).";
}



void inicializarA(float vTR[20]) 
{
    for (int i = 0; i < 20; i++) 
    {
        vTR[i] = 0;
    }
}

void inicializarB(int vCamiones[100], float vTotalRecaudadoCamion[100], 
                  int vKilometros[100]) 
{
    for (int i = 0; i < 100; i++) 
    {
        vTotalRecaudadoCamion[i] = 0;
        vCamiones[i] = i + 1;
        vKilometros[i] = 0;
    }
}