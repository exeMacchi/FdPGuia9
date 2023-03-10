#pragma once
int buscarI(int NT, int vNT[20]) 
{
    for (int i = 0; i < 20; i++) 
    {
        if (NT == vNT[i]) 
        {
            return i;
        }
    }

}

void ordenarMayorAMenor(int vCamiones[100], float vTRC[100]) 
{
    int AuxC;
    float AuxI;

    for (int i = 0; i < 100; i++) 
    {
        for (int x = 0; x < 99; x++) 
        {
            if (vTRC[x] < vTRC[x + 1]) 
            {
                AuxI = vTRC[x];
                vTRC[x] = vTRC[x + 1];
                vTRC[x + 1] = AuxI;

                AuxC = vCamiones[x];
                vCamiones[x] = vCamiones[x + 1];
                vCamiones[x + 1] = AuxC;
            }
        }
    }
}

int minimo(int vKilometros[100]) 
{
    int I, Min;
    for (int i = 0; i < 100; i++) 
    {
        if (i == 0) 
        {
            I = i;
            Min = vKilometros[i];
        }
        else if (vKilometros[i] < Min) 
        {
            I = i;
            Min = vKilometros[i];
        }
    }
    return I;
}

void copiaCamiones(int vCamiones[100], int vCamionesCopia[100]) 
{
    for (int i = 0; i < 100; i++) 
    {
        vCamionesCopia[i] = vCamiones[i];
    }
}

void copiaTRC(float vTRC[100], float vTRCCopia[100]) 
{
    for (int i = 0; i < 100; i++) 
    {
        vTRCCopia[i] = vTRC[i];
    }
}