#include <iostream>

using std::cout;
using std::endl;

int buscarI(int AC, int vC[20]) {
    for (int i = 0; i < 20; i++) {
        if (AC == vC[i]) {
            return i;
        }
    }
}

void ordenarMayorAMenor(int vC[20], int vA[20]) {
    int Aux;
    for (int i = 0; i < 20; i++) {
        for (int x = 0; x < 19; x++) {
            if (vA[x] < vA[x + 1]) {
                Aux = vA[x];
                vA[x] = vA[x + 1];
                vA[x + 1] = Aux;
                Aux = vC[x];
                vC[x] = vC[x + 1];
                vC[x + 1] = Aux;
            }
        }
    }
}

void noVentasMes(int i) {
    switch (i) {
        case 0:
            cout << "En enero no se registraron ventas." << endl;
            break;

        case 1:
            cout << "En febrero no se registraron ventas." << endl;
            break;

        case 2:
            cout << "En marzo no se registraron ventas." << endl;
            break;

        case 3:
            cout << "En abril no se registraron ventas." << endl;
            break;

        case 4:
            cout << "En mayo no se registraron ventas." << endl;
            break;

        case 5:
            cout << "En junio no se registraron ventas." << endl;
            break;

        case 6:
            cout << "En julio no se registraron ventas." << endl;
            break;

        case 7:
            cout << "En agosto no se registraron ventas." << endl;
            break;

        case 8:
            cout << "En septiembre no se registraron ventas." << endl;
            break;

        case 9:
            cout << "En octubre no se registraron ventas." << endl;
            break;

        case 10:
            cout << "En noviembre no se registraron ventas." << endl;
            break;

        case 11:
            cout << "En diciembre no se registraron ventas." << endl;
            break;

        default:
            cout << "Error: algo ha sucedido." << endl;
            break;
    }
}

void ventasMes(int i, int vM[12]) {
    switch (i) {
        case 0:
            cout << "En enero, " << vM[i] << " ventas fueron registradas." << endl;
            break;

        case 1:
            cout << "En febrero, " << vM[i] << " ventas fueron registradas." << endl;
            break;

        case 2:
            cout << "En marzo, " << vM[i] << " ventas fueron registradas." << endl;
            break;

        case 3:
            cout << "En abril, " << vM[i] << " ventas fueron registradas." << endl;
            break;

        case 4:
            cout << "En mayo, " << vM[i] << " ventas fueron registradas." << endl;
            break;

        case 5:
            cout << "En junio, " << vM[i] << " ventas fueron registradas." << endl;
            break;

        case 6:
            cout << "En julio, " << vM[i] << " ventas fueron registradas." << endl;
            break;

        case 7:
            cout << "En agosto, " << vM[i] << " ventas fueron registradas." << endl;
            break;

        case 8:
            cout << "En septiembre, " << vM[i] << " ventas fueron registradas." << endl;
            break;

        case 9:
            cout << "En octubre, " << vM[i] << " ventas fueron registradas." << endl;
            break;

        case 10:
            cout << "En noviemrbe, " << vM[i] << " ventas fueron registradas." << endl;
            break;

        case 11:
            cout << "En diciembre, " << vM[i] << " ventas fueron registradas." << endl;
            break;

        default:
            cout << "Error: algo ha sucedido." << endl;
            break;
    }
}

