int buscarI(int AN, int vAN[300]) {
    for (int i = 0; i < 300; i++) {
        if (AN == vAN[i]) {
            return i;
        }
    }
}
