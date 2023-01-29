// 3. Una empresa de transporte de carga por camión posee 20 tarifas distintas de acuerdo al destino de los 
//    envíos que deba realizar. Dispone de un lote de registros con la siguiente información:
//       - Número de Tarifa(Número de 4 cifras, no correlativos).
//       - Importe por KM.
//    Este lote no viene ordenado. A continuación, dispone de un segundo lote de registros con la información 
//    de los envíos que se realizaron durante la semana pasada, conteniendo cada uno de ellos los siguientes campos:
//       - Número de Camión (1 a 100).
//       - Número de Tarifa.
//       - Kilómetros Recorridos.
//    Este lote finaliza con un registro con número de camión negativo.
//    Se nos pide realizar un programa que determine e informe:
//       a) El total recaudado por cada tarifa.
//       b) Un listado como el siguiente:
//             Número de camión    Total recaudado
//                   xxx                 xxx
//          Este listado debe salir ordenado por total recaudado, de mayor a menor.
//       c) Indicar el número de camión que recorrió la menor cantidad de kilómetros entre los que realizaron viajes.
//          Nota: cada camión realizó cero, uno o varios viajes.

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
    cout << "\n------------------------------------------------------------------";
    cout << "\n------------------------------------------------------------------" << endl;

    Proceso(vNumeroTarifa, vImporteKM, vTotalRecaudado, vTotalRecaudadoCamion, vKilometros);

    cout << "\n------------------------------------------------------------------";
    cout << "\n------------------------------------------------------------------" << endl;
    cout << "                           Reporte General" << endl;
    cout << endl;

    FPA(vNumeroTarifa, vTotalRecaudado);
    cout << endl;

    FPB(vCamiones, vTotalRecaudadoCamion);
    cout << endl;

    FPC(vCamiones, vKilometros);
    cout << "\n------------------------------------------------------------------";
    cout << "\n------------------------------------------------------------------" << endl;
    return 0;
}
