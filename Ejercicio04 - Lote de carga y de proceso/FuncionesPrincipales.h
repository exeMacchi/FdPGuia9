#pragma once
#include <iostream>
#include "FuncionesAuxiliares.h"

using std::cout;
using std::cin;
using std::endl;


void cargarLote(int vCamiones[30], int vChoferes[30]) 
{
    int Chofer;
    for (int i = 0; i < 30; i++) 
    {
        cout << "Codigo de chofer (" << i + 1 << "): "; cin >> Chofer;
        vChoferes[i] = Chofer;
        vCamiones[i] = i + 1;
    }
}

void inicializarAB(bool vViajeDia[31], int mPRotas[31][30], 
                   bool mViajeChofer[31][30], int vKilometros[30]) 
{
    for (int i = 0; i < 31; i++) 
    {
        vViajeDia[i] = false;
        for (int x = 0; x < 30; x++) 
        {
            mPRotas[i][x] = 0;
            mViajeChofer[i][x] = false;
            vKilometros[x] = 0;
        }
    }
}


void Proceso(int vCamiones[30], int vChoferes[30], bool vViajeDia[30],
             int mPRotas[31][30], bool mViajeChofer[31][30], int vKilometros[30])
{
    int D, Chofer, KM, piezasRotas;
    int iCho;

    cout << "\nDia (1-31): "; cin >> D;
    if (D != 0) 
    {
        cout << "Codigo chofer: "; cin >> Chofer;
        cout << "Cantidad kilometros viajados: "; cin >> KM;
        cout << "Cantidad de piezas rotas: "; cin >> piezasRotas;
    }

    while (D != 0) 
    {
        iCho = buscarICho(Chofer, vChoferes);
        vViajeDia[D - 1] = true;
        mPRotas[D - 1][iCho] += piezasRotas;
        mViajeChofer[D - 1][iCho] = true;
        vKilometros[iCho] += KM;

        cout << "\nDia (1-31): "; cin >> D;
        if (D != 0) 
        {
            cout << "Codigo chofer: "; cin >> Chofer;
            cout << "Cantidad kilometros viajados: "; cin >> KM;
            cout << "Cantidad de piezas rotas: "; cin >> piezasRotas;
        }
    }
}

void FPA(int vChoferes[30], bool vViajeDia[31], int mPRotas[31][30], 
         bool mViajeChofer[31][30]) 
{
    int iCho, minPRotas;

    for (int i = 0; i < 31; i++) 
    {
        if (vViajeDia[i]) 
        {
            iCho = buscarIMinPRotas(i, mViajeChofer, mPRotas, minPRotas);
            cout << "El dia " << i + 1 << ", el chofer " << vChoferes[iCho] 
                 << " rompio el menor numero de piezas (" << minPRotas 
                 << " piezas)." << endl;
        }
        else 
        {
            cout << "El dia " << i + 1 << ", no se realizaron viajes." << endl;
        }
    }
}

void FPB(int vCamiones[30], int vChoferes[30], int vKilometros[30]) 
{
    int I, maxKM = 0;
    I = buscarMaxKM(vKilometros, maxKM);
    if (maxKM != 0) 
    {
        cout << "\nEl camion numero " << vCamiones[I] 
             << " realizo la mayor cantidad de kilometros (" << maxKM 
             << " kilometros), y fue conducido por el chofer numero "
             << vChoferes[I] << "." << endl;
    }
    else 
    {
        cout << "\nNingun camion viajo." << endl;
    }
}

void FPC(int vChoferes[30], int mPRotas[31][30]) 
{
    float totalPiezasRotasQ1 = 0, totalPiezasRotasQ2 = 0;
    float vTPRotasChoferQ1[30], vTPRotasChoferQ2[30];
    float vPromedioPRotasQ1[30], vPromedioPRotasQ2[30];

    totalPiezasRotasQuincena(totalPiezasRotasQ1, totalPiezasRotasQ2, mPRotas);

    inicializarC(vTPRotasChoferQ1, vTPRotasChoferQ2, vPromedioPRotasQ1, 
                 vPromedioPRotasQ2);

    totalPiezasRotasChoferes(vTPRotasChoferQ1, vTPRotasChoferQ2, mPRotas);

    Promedios(totalPiezasRotasQ1, totalPiezasRotasQ2, vTPRotasChoferQ1, 
              vTPRotasChoferQ2, vPromedioPRotasQ1, vPromedioPRotasQ2);

    for (int i = 0; i < 30; i++) 
    {
        if (i < 9) 
        {
            cout.precision(2);
            cout << vChoferes[i] << "  ||  " << vPromedioPRotasQ1[i] 
                 << "         ||  " << vPromedioPRotasQ2[i] << endl;
        }
        else 
        {
            cout.precision(2);
            cout << vChoferes[i] << " ||  " << vPromedioPRotasQ1[i] 
                 << "         ||  " << vPromedioPRotasQ2[i] << endl;
        }
    }
}
