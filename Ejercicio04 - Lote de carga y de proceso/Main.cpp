/* 
    4. Una empresa que realiza transporte de productos fr�giles cuenta con una 
       flota de 30 camiones. 
       Se gener� un lote de registros con los siguientes datos para cada cami�n:
          - N�mero de cami�n (1 a 30).
          - C�digo de chofer (3 d�gitos, no correlativos).
       Este lote se encuentra ordenado por n�mero de cami�n en forma ascendente 
       (de menor a mayor).
       Cada c�digo de chofer maneja uno y solo un cami�n. Existe un segundo lote
       con la informaci�n de los viajes realizados por los camiones en el mes 
       anterior, cada registro contiene:
          - D�a (1 a 31).
          - C�digo de chofer (3 d�gitos, no correlativos).
          - Cantidad de kil�metros recorridos en ese viaje (entero).
          - Cantidad de piezas rotas en ese viaje (entero).
       Este lote finaliza con un registro con d�a igual a cero. Se gener� un 
       registro por cada viaje realizado, por lo tanto, puede haber m�s de un 
       registro para el mismo d�a y para el mismo c�digo de chofer.
       Se pide determinar e informar:
          a) Para cada d�a del mes informar cu�l fue el c�digo de chofer que 
             haya totalizado menor cantidad de piezas rotas en un solo viaje.
             Tener en cuenta que los choferes que no realizaron viajes ese d�a, 
             no deben ser considerados.
          b) Informar cu�l es el n�mero de cami�n con el que se hayan recorrido 
             mayor cantidad total de kil�metros en todo el mes y qu� c�digo de 
             chofer lo conduce.
          c) Informar para cada c�digo de chofer el promedio de roturas entre 
             todos los viajes realizados en la primera quincena (d�a 1 a 15) y 
             los realizados en la segunda quincena (d�a 16 a 31). 
             El formato ser�:
                C�digo de chofer    Promedio Q1    Promedio Q2
                      999              999            999
*/      

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

    cout << "\n----------------------------------------------------------------";
    cout << "\n----------------------------------------------------------------\n";

    Proceso(vCamiones, vChoferes, vViajeDia, mPRotas, mViajeChofer, vKilometros);

    cout << "\n---------------------------------------------------------------";
    cout << "\n---------------------------------------------------------------\n";

    FPA(vChoferes, vViajeDia, mPRotas, mViajeChofer);
    cout << "\n---------------------------------------------------------------\n";

    FPB(vCamiones, vChoferes, vKilometros);
    cout << "\n---------------------------------------------------------------\n";

    FPC(vChoferes, mPRotas);
    cout << "\n---------------------------------------------------------------";
    cout << "\n---------------------------------------------------------------\n";

    return 0;
}