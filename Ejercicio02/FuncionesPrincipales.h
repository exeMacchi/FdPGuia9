#include <iostream>
#include "FuncionesAuxiliares.h"

using std::cout;
using std::cin;
using std::endl;

void cargarLote(int vAN[300], int vStock[300], float vPrecio[300]) {
    int AN, S;
    float P;

    for (int i = 0; i < 300; i++) {
        if (i == 0) {
            cout << "Numero de articulo (" << i + 1 <<"): "; cin >> AN;
            cout << "Cantidad de unidades en stock: "; cin >> S;
            cout << "Precio unitario: $"; cin >> P;

            vAN[i] = AN;
            vStock[i] = S;
            vPrecio[i] = P;
        }
        else {
            cout << "\nNumero de articulo (" << i + 1 << "): "; cin >> AN;
            cout << "Cantidad de unidades en stock: "; cin >> S;
            cout << "Precio unitario: $"; cin >> P;

            vAN[i] = AN;
            vStock[i] = S;
            vPrecio[i] = P;
        }
    }
}

void Proceso(int vNumeroArticulo[300], int vStock[300], float vPrecio[300], float vCompra[300], bool vArticulo[300]) {
    int clienteNumero, articuloNumero, cantidadVendida, I;


    cout << "\nNumero de cliente (1 a 300): "; cin >> clienteNumero;
    cout << "Numero de articulo: "; cin >> articuloNumero;
    cout << "Cantidad de unidades vendidas: "; cin >> cantidadVendida;

    while (clienteNumero != 0) {
        float importeTotal = 0;

        I = buscarI(articuloNumero, vNumeroArticulo);
        
        importeTotal = cantidadVendida * vPrecio[I];

        vCompra[clienteNumero - 1] += importeTotal;

        vArticulo[I] = true;

        cout << "\n-------------------------------------------------------------------";
        cout << "\n\t                      Detalles de la venta";
        cout << "\nNumero de cliente: " << clienteNumero;
        cout << "\nNumero de articulo: " << articuloNumero;
        cout << "\nCantidad de unidades vendidas: " << cantidadVendida;
        cout << "\nImporte total : $" << importeTotal;
        cout << "\n-------------------------------------------------------------------" << endl;

        cout << "\nNumero de cliente (1 a 300): "; cin >> clienteNumero;
        if (clienteNumero != 0) {
            cout << "Numero de articulo: "; cin >> articuloNumero;
            cout << "Cantidad de unidades vendidas: "; cin >> cantidadVendida;
        }
    }
}


void FPB(float vCompras[300]) {
    int CN = 1;
    float maxCN = vCompras[0];

    for (int i = 0; i < 300; i++) {
        if (vCompras[i] > maxCN) {
            maxCN = vCompras[i];
            CN = i + 1;
        }
    }
    cout << "El numero de cliente " << CN << " fue el mayor comprador en total: $" << maxCN << endl;
}

void FPC(int vAN[300], bool vArticulo[300]) {
    for (int i = 0; i < 300; i++) {
        if (!vArticulo[i]) {
            cout << "\nEl numero de articulo " << vAN[i] << " no registro ninguna venta.";
        }
    }
}


void inicializar(float vCompras[300]) {
    for (int i = 0; i < 300; i++) {
        vCompras[i] = 0;
    }
}

void falsear(bool vArticle[300]) {
    for (int i = 0; i < 300; i++) {
        vArticle[i] = false;
    }
}
