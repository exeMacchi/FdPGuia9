#include <iostream>
#include "FuncionesAuxiliares.h"

using std::cout;
using std::cin;
using std::endl;


void cargarL1(int vC[20], float vP[20]) {
    int C;
    float P;
    for (int i = 0; i < 20; i++) {
        if (i == 0) {
            cout << "Ingrese el codigo de articulo (" << i + 1 << "): "; cin >> C;
            cout << "Ingrese su precio: $"; cin >> P;
            vC[i] = C;
            vP[i] = P;
        }
        else if (i < 19) {
            cout << "\nIngrese el codigo de articulo (" << i + 1 << "): "; cin >> C;
            cout << "Ingrese su precio: $"; cin >> P;
            vC[i] = C;
            vP[i] = P;
        }
        else {
            cout << "\nIngrese el codigo de articulo (" << i + 1 << "): "; cin >> C;
            cout << "Ingrese su precio: $"; cin >> P;
            vC[i] = C;
            vP[i] = P;
            cout << "\n--------------------------------------------------" << endl;
        }
    }
}

void Proceso(int vCodigo[20], float vPrecio[20], int vAcu[20], int vMes[12], bool& procesoCorrecto) {
    int clienteNumero, articuloCodigo, mes, dia, cantidadVendida, I;

    cout << "\nNumero de cliente (1 a 300): "; cin >> clienteNumero;

    if (clienteNumero > 0 && clienteNumero <= 300) {
        cout << "Codigo de articulo: "; cin >> articuloCodigo;
        cout << "Mes (1-12): "; cin >> mes;
        cout << "Dia: "; cin >> dia;
        cout << "Cantidad vendida: "; cin >> cantidadVendida;
    }
    else {
        cout << "Error en el ingreso de datos." << endl;
        procesoCorrecto = false;
        return;
    }

    while (clienteNumero != 0 && clienteNumero <= 300) {
        I = buscarI(articuloCodigo, vCodigo);
        vAcu[I] += cantidadVendida;
        vMes[mes - 1] += cantidadVendida;

        cout << "\nNumero de cliente (1 a 300): "; cin >> clienteNumero;
        if (clienteNumero > 0 && clienteNumero <= 300) {
            cout << "Codigo de articulo: "; cin >> articuloCodigo;
            cout << "Mes (1-12): "; cin >> mes;
            cout << "Dia: "; cin >> dia;
            cout << "Cantidad vendida: "; cin >> cantidadVendida;
        }
    }

}


void FPA(int vCodigo[20], int vAcu[20]) {
    ordenarMayorAMenor(vCodigo, vAcu);

    for (int i = 0; i < 20; i++) {
        cout << "Codigo de articulo: " << vCodigo[i] << " || Cantidad total de ventas: " << vAcu[i] << endl;
    }

    cout << "\n--------------------------------------------------" << endl;
    cout << endl;
}

void FPB(int vMes[12]) {
    for (int i = 0; i < 12; i++) {
        if (vMes[i] == 0) {
            noVentasMes(i);
        }
        else {
            ventasMes(i, vMes);
        }
    }
}

void FPC(int vCodigo[20], int vAcu[20]) {
    int AcuTotal = 0;
    float Promedio = 0;

    for (int i = 0; i < 20; i++) {
        AcuTotal += vAcu[i];
    }

    Promedio = AcuTotal / 20;

    for (int i = 0; i < 20; i++) {
        if (vAcu[i] > Promedio) {
            cout << "Las ventas del articulo con codigo " << vCodigo[i] << " (" << vAcu[i] 
                 << " ventas) son mayores que el promedio calculado (" << Promedio << ")." << endl;
        }
    }
}


void inicializar(int T, int v[]) {
    for (int i = 0; i < T; i++) {
        v[i] = 0;
    }
}
