/*
	1. Una empresa que fabrica 20 art�culos tiene la siguiente informaci�n para 
       cada uno de ellos:
         - C�digo de Art�culo(4 d�gitos, no correlativos).
         - Precio Unitario.
      Este primer lote no se encuentra ordenado. Cuenta por otro lado con un 
      lote de registros con las ventas del a�o anterior.Cada registro contiene 
      la siguiente informaci�n :
         - N�mero de Cliente(1 a 300).
         - C�digo de Art�culo(4 d�gitos no correlativos).
         - Mes (1 a 12).
         - D�a (1 a 31).
         - Cantidad vendida.
      Puede haber m�s de un registro para el mismo art�culo. El lote finaliza 
      con un registro con n�mero de cliente igual a cero. Se pide:
         a) Un listado con el siguiente formato: 
               C�digo de Art�culo    Cantidad Total Vendida 
                      999                     999 
            Este listado debe salir ordenado de mayor a menor por cantidad 
            total vendida.
         b) Informar, si los hubiera, los nombres de los meses en que no hubo 
            ventas.
         c) Informar los c�digos de los art�culos cuyas ventas en cantidad son 
            mayores al promedio.
*/ 

#include <iostream>
#include "FuncionesPrincipales.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int vCodigo[20], vAcu[20], vMes[12];
    float vPrecio[20];
    bool procesoCorrecto = true;

    cargarL1(vCodigo, vPrecio);
    inicializar(20, vAcu);
    inicializar(12, vMes);

    Proceso(vCodigo, vPrecio, vAcu, vMes, procesoCorrecto);

    if (procesoCorrecto) {
        cout << "\n--------------------------------------------------";
        cout << "\n--------------------------------------------------" << endl;
        cout << endl;

        FPA(vCodigo, vAcu);

        FPB(vMes);

        cout << endl;
        cout << "\n--------------------------------------------------" << endl;

        FPC(vCodigo, vAcu);

        cout << "\n--------------------------------------------------";
        cout << "\n--------------------------------------------------" << endl;
    }
    else 
    {
        cout << "Ocurrio algun error durante el proceso." << endl;
    }
    return 0;
}