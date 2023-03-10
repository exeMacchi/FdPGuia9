/* 
    2. Se dispone de un lote de 300 registros (uno por art�culo), cada uno de 
       los cuales tiene la siguiente informaci�n:
          - N�mero de art�culo (4 d�gitos no correlativos).
          - Cantidad de unidades en stock.
          - Precio Unitario.
       El lote est� desordenado. Se dispone de otro lote de registros, cada uno
       de los cuales corresponde a una venta con la siguiente informaci�n:
          - N�mero de cliente (1 a 300).
          - N�mero de art�culo (4 d�gitos, no correlativos).
          - Cantidad de unidades vendidas.
       El �ltimo registro de este lote tiene n�mero de cliente cero y no debe 
       procesarse.
       Desarrollar el programa que determine e imprima:
          a) Un listado de las ventas realizadas, con el siguiente formato:
                               Listado de ventas
             Nro.Cliente    Nro.Art�culo    Cantidad Vendida    Importe Total
                 99              99               999               999.99
          b) Informar cu�l es el n�mero de cliente que m�s compr� en total 
             (en pesos).
          c) Informar cada uno de los n�meros de los art�culos que no hayan
             registrado ventas.
*/       

#include <iostream>
#include "FuncionesPrincipales.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int vNumeroArticulo[300], vStock[300];
    float vPrecio[300], vCompra[300];
    bool vArticulo[300];

    inicializar(vCompra);
    falsear(vArticulo);
    cargarLote(vNumeroArticulo, vStock, vPrecio);
    cout << "\n---------------------------------------------------------------";
    cout << "\n---------------------------------------------------------------\n"; 


    Proceso(vNumeroArticulo, vStock, vPrecio, vCompra, vArticulo);
    cout << "\n---------------------------------------------------------------";
    cout << "\n---------------------------------------------------------------\n";

    FPB(vCompra);

    FPC(vNumeroArticulo, vArticulo);
    cout << "\n---------------------------------------------------------------";
    cout << "\n---------------------------------------------------------------\n";

    return 0;
}