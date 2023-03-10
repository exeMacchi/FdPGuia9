/* 
    2. Se dispone de un lote de 300 registros (uno por artículo), cada uno de 
       los cuales tiene la siguiente información:
          - Número de artículo (4 dígitos no correlativos).
          - Cantidad de unidades en stock.
          - Precio Unitario.
       El lote está desordenado. Se dispone de otro lote de registros, cada uno
       de los cuales corresponde a una venta con la siguiente información:
          - Número de cliente (1 a 300).
          - Número de artículo (4 dígitos, no correlativos).
          - Cantidad de unidades vendidas.
       El último registro de este lote tiene número de cliente cero y no debe 
       procesarse.
       Desarrollar el programa que determine e imprima:
          a) Un listado de las ventas realizadas, con el siguiente formato:
                               Listado de ventas
             Nro.Cliente    Nro.Artículo    Cantidad Vendida    Importe Total
                 99              99               999               999.99
          b) Informar cuál es el número de cliente que más compró en total 
             (en pesos).
          c) Informar cada uno de los números de los artículos que no hayan
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