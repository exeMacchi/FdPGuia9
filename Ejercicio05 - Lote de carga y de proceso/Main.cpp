/*
    5. Una empresa de alquiler de autos cuenta con distintas agencias desde 
       donde efect�a sus operaciones. 
       Para ello cuenta con varios lotes de registros. Un primer lote contiene
       los datos de los autos, cada registro est� compuesto por:
          - C�digo de auto (4 d�gitos no correlativos).
          - Categor�a del auto (1 a 10).
          - Importe del alquiler por km.
          - N�mero de agencia (1 a 20).
       Este lote se encuentra ordenado por c�digo de auto y contiene 400 
       registros. Existe un segundo lote con la informaci�n de los alquileres 
       que se realizaron durante el mes pasado. Cada registro contiene:
          - C�digo de auto (4 d�gitos no correlativos).
          - N�mero de cliente que efect�o el alquiler (1 a 200).
          - Total de d�as del alquiler.
          - Kms Recorridos.
       Este lote finaliza con un registro con n�mero de cliente igual a cero. 
       Puede haber m�s de un registro para el mismo auto y para el mismo cliente.
       Por �ltimo, un tercer lote contiene los datos de las agencias de esta 
       empresa:
          - N�mero de agencia (1 a 20).
          - Ubicaci�n de la agencia (1 = Aeropuerto Ezeiza, 2 = Aeroparque, 
                                     3 = Centro Ciudad).
       A partir de estos lotes se pide determinar e informar:
          a) Un listado con el siguiente formato:
              N�mero de Cliente    Total de pesos abonados en alquiler
                    999                              999
          b) La recaudaci�n total acumulada para cada una de las tres ubicaciones.
          c) La cantidad total de autos para cada una de las veinte agencias.
          d) La categor�a de auto m�s veces alquilada por los clientes.
          e) Los n�meros de las agencias, si las hubiera, que hayan efectuado en 
             el mes menos de diez alquileres en total. Para calcular el importe 
             del alquiler de un auto se debe multiplicar el importe en pesos por
             kil�metro por la cantidad de kil�metros recorridos.
*/          

#include <iostream>
#include "FuncionesPrincipales.h"

using std::cout;
using std::endl;

int main()
{
    cargarLoteAgencias(vAgencias, cantAgencias);
    cout << "\n-----------------------------------------------------------" << endl;
    cout << endl;
    cargarLoteAutos(vAutos, vAgencias, cantAutos, cantAgencias);

    inicializarvUbicaciones(vUbicaciones);
    inicializarvCategorias(vCategorias);
    inicializarvAgenciasMensual(vAgenciasMensual, cantAgencias);

    cout << "\n-----------------------------------------------------------";
    cout << "\n-----------------------------------------------------------" << endl;

    Proceso(vAutos, vClientes, cantAutos, vUbicaciones, vCategorias, 
            vAgenciasMensual, alquiler);

    cout << "\n-----------------------------------------------------------";
    cout << "\n-----------------------------------------------------------" << endl;
    cout << "                        Reporte mensual";
    cout << "\n-----------------------------------------------------------";
    cout << "\n-----------------------------------------------------------" << endl;

    FPA(vClientes, cantClientes);
    cout << "-----------------------------------------------------------";

    FPB(vUbicaciones);
    cout << "-----------------------------------------------------------";

    FPC(cantAutos, cantAgencias);
    cout << "-----------------------------------------------------------";

    FPD(vCategorias, alquiler);
    cout << "-----------------------------------------------------------" << endl;

    FPE(vAgenciasMensual, cantAgencias);
    cout << "-----------------------------------------------------------" << endl;

    return 0;
}