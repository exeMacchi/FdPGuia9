// 4. Una empresa que realiza transporte de productos frágiles cuenta con una flota de 30 camiones. 
//    Se generó un lote de registros con los siguientes datos para cada camión:
//       - Número de camión (1 a 30).
//       - Código de chofer (3 dígitos, no correlativos).
//    Este lote se encuentra ordenado por número de camión en forma ascendente (de menor a mayor).
//    Cada código de chofer maneja uno y solo un camión. Existe un segundo lote con la información de los viajes
//    realizados por los camiones en el mes anterior, cada registro contiene:
//       - Día (1 a 31).
//       - Código de chofer (3 dígitos, no correlativos).
//       - Cantidad de kilómetros recorridos en ese viaje (entero).
//       - Cantidad de piezas rotas en ese viaje (entero).
//    Este lote finaliza con un registro con día igual a cero. Se generó un registro por cada viaje realizado, 
//    por lo tanto, puede haber más de un registro para el mismo día y para el mismo código de chofer.
//    Se pide determinar e informar:
//       a) Para cada día del mes informar cuál fue el código de chofer que haya totalizado menor cantidad de 
//          piezas rotas en un solo viaje.Tener en cuenta que los choferes que no realizaron viajes ese día, 
//          no deben ser considerados.
//       b) Informar cuál es el número de camión con el que se hayan recorrido mayor cantidad total de kilómetros 
//          en todo el mes y qué código de chofer lo conduce.
//       c) Informar para cada código de chofer el promedio de roturas entre todos los viajes realizados en la 
//          primera quincena (día 1 a 15) y los realizados en la segunda quincena (día 16 a 31). El formato será:
//             Código de chofer    Promedio Q1    Promedio Q2
//                   999              999            999

#include <iostream>
#include "FuncionesPrincipales.h"

using std::cout;
using std::endl;

int main()
{
    int vCamiones[30], vChoferes[30], vKilometros[30];
    bool vViajeDia[31], mViajeChofer[31][30];
    int mPRotas[31][30];

    cargarLote(vCamiones, vChoferes);

    inicializarAB(vViajeDia, mPRotas, mViajeChofer, vKilometros);

    cout << "\n--------------------------------------------------------------------";
    cout << "\n--------------------------------------------------------------------" << endl;

    Proceso(vCamiones, vChoferes, vViajeDia, mPRotas, mViajeChofer, vKilometros);

    cout << "\n--------------------------------------------------------------------";
    cout << "\n--------------------------------------------------------------------" << endl;

    FPA(vChoferes, vViajeDia, mPRotas, mViajeChofer);
    cout << "\n--------------------------------------------------------------------" << endl;

    FPB(vCamiones, vChoferes, vKilometros);
    cout << "\n--------------------------------------------------------------------" << endl;

    FPC(vChoferes, mPRotas);
    cout << "\n--------------------------------------------------------------------";
    cout << "\n--------------------------------------------------------------------" << endl;

    return 0;
}
