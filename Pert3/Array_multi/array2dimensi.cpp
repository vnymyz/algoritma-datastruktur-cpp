#include <iostream>
using namespace std;

int main() {
    // Array 2D: 2 baris (i) dan 3 kolom (j)
    int angka[2][3] = {
        {1, 2, 3},   // Baris ke-0
        {4, 5, 6}    // Baris ke-1
    };

    // Menampilkan isi array dengan indeks
    for (int i = 0; i < 2; i++) {       // Baris
        for (int j = 0; j < 3; j++) {   // Kolom
            cout << "angka[" << i << "][" << j << "] = " << angka[i][j] << endl;
        }
    }

    return 0;
}
