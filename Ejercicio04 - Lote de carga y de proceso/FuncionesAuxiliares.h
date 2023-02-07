
int buscarICho(int Chofer, int vChoferes[30]) {
    for (int i = 0; i < 30; i++) {
        if (Chofer == vChoferes[i]) {
            return i;
        }
    }
}

int buscarIMinPRotas(int D, bool mViajeChofer[31][30], int mPRotas[31][30], int& minPRotas) {
    int iCho;
    bool banMin = false;

    for (int x = 0; x < 30; x++) {
        if (mViajeChofer[D][x]) {
            if (!banMin) {
                minPRotas = mPRotas[D][x];
                iCho = x;
                banMin = true;
            }
            else if (mPRotas[D][x] < minPRotas) {
                minPRotas = mPRotas[D][x];
                iCho = x;
            }
        }
    }
    return iCho;
}

int buscarMaxKM(int vKilometros[30], int& maxKM) {
    int I;
    for (int i = 0; i < 30; i++) {
        if (i == 0) {
            maxKM = vKilometros[i];
            I = i;
        }
        else if (vKilometros[i] > maxKM) {
            maxKM = vKilometros[i];
            I = i;
        }
    }
    return I;
}

void totalPiezasRotasQuincena(float& totalPiezasRotasQ1, float& totalPiezasRotasQ2, int mPRotas[31][30]) {
    for (int i = 0; i < 15; i++) {
        for (int x = 0; x < 30; x++) {
            totalPiezasRotasQ1 += mPRotas[i][x];
        }
    }

    for (int i = 15; i < 31; i++) {
        for (int x = 0; x < 30; x++) {
            totalPiezasRotasQ2 += mPRotas[i][x];
        }
    }
}

void inicializarC(float vTPRotasChoferQ1[30], float vTPRotasChoferQ2[30], float vPromedioPROtasQ1[30], 
                  float vPromedioPRotasQ2[30]) {
    for (int i = 0; i < 30; i++) {
        vTPRotasChoferQ1[i] = 0;
        vTPRotasChoferQ2[i] = 0;
        vPromedioPROtasQ1[i] = 0;
        vPromedioPRotasQ2[i] = 0;
    }
}

void totalPiezasRotasChoferes(float vTPRotasChoferQ1[30], float vTPRotasChoferQ2[30], int mPRotas[31][30]) {
    for (int x = 0; x < 30; x++) {
        for (int i = 0; i < 15; i++) {
            vTPRotasChoferQ1[x] += mPRotas[i][x];
        }
    }

    for (int x = 0; x < 30; x++) {
        for (int i = 15; i < 31; i++) {
            vTPRotasChoferQ2[x] += mPRotas[i][x];
        }
    }
}

void Promedios(float totalPiezasRotasQ1, float totalPiezasRotasQ2, float vTPRotasChoferQ1[30], 
               float vTPRotasChoferQ2[30], float vPromedioPRotasQ1[30], float vPromedioPRotasQ2[30]) {
    for (int x = 0; x < 30; x++) {
        vPromedioPRotasQ1[x] = vTPRotasChoferQ1[x] / totalPiezasRotasQ1;
    }

    for (int x = 0; x < 30; x++) {
        vPromedioPRotasQ2[x] = vTPRotasChoferQ2[x] / totalPiezasRotasQ2;
    }
}
