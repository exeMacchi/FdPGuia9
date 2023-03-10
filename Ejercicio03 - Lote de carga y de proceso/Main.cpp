/*
    3. Una empresa de transporte de carga por cami�n posee 20 tarifas distintas 
       de acuerdo al destino de los env�os que deba realizar. Dispone de un lote
       de registros con la siguiente informaci�n:
          - N�mero de Tarifa(N�mero de 4 cifras, no correlativos).
          - Importe por KM.
       Este lote no viene ordenado. A continuaci�n, dispone de un segundo lote 
       de registros con la informaci�n de los env�os que se realizaron durante 
       la semana pasada, conteniendo cada uno de ellos los siguientes campos:
         - N�mero de Cami�n (1 a 100).
         - N�mero de Tarifa.
         - Kil�metros Recorridos.
       Este lote finaliza con un registro con n�mero de cami�n negativo.
       Se nos pide realizar un programa que determine e informe:
          a) El total recaudado por cada tarifa.
          b) Un listado como el siguiente:
                N�mero de cami�n    Total recaudado
                      xxx                 xxx
             Este listado debe salir ordenado por total recaudado, 
             de mayor a menor.
          c) Indicar el n�mero de cami�n que recorri� la menor cantidad de 
             kil�metros entre los que realizaron viajes.
          Nota: cada cami�n realiz� cero, uno o varios viajes.
*/ 
#include <iostream>
#include "FuncionesPrincipales.h"

using std::cout;
using std::endl;

int main()
{
    int vNumeroTarifa[20], vCamiones[100], vKilometros[100];
    float vImporteKM[20], vTotalRecaudado[10], vTotalRecaudadoCamion[100];

    cargarLote(vNumeroTarifa, vImporteKM);

    inicializarA(vTotalRecaudado);

    inicializarB(vCamiones, vTotalRecaudadoCamion, vKilometros);
    cout << "\n---------------------------------------------------------------";
    cout << "\n---------------------------------------------------------------\n";

    Proceso(vNumeroTarifa, vImporteKM, vTotalRecaudado, vTotalRecaudadoCamion,
            vKilometros);

    cout << "\n---------------------------------------------------------------";
    cout << "\n---------------------------------------------------------------\n";
    cout << "                         Reporte General" << endl;
    cout << endl;

    FPA(vNumeroTarifa, vTotalRecaudado);
    cout << endl;

    FPB(vCamiones, vTotalRecaudadoCamion);
    cout << endl;

    FPC(vCamiones, vKilometros);
    cout << "\n---------------------------------------------------------------";
    cout << "\n---------------------------------------------------------------\n";

    return 0;
}