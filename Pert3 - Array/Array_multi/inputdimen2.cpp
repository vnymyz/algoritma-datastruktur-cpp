#include <iostream>
using namespace std;

int main() {
    int nilai[3][4];
    // baris dan kolom

    cout << "Masukkan nilai 3x4:\n";
    for (int i = 0; i < 3; i++) { // baris
        for (int j = 0; j < 4; j++) { // kolom
            cout << "nilai[" << i << "][" << j << "]: ";
            cin >> nilai[i][j];
        }
    }

    cout << "\nTampilan Matriks:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << nilai[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
