#include <iostream>
#include <vector>
using namespace std;

int main() {
    int baris, kolom;

    cout << "Masukkan jumlah baris: ";
    cin >> baris;
    cout << "Masukkan jumlah kolom: ";
    cin >> kolom;

    // Membuat vector 2D dengan ukuran baris x kolom
    vector<vector<int>> nilai(baris, vector<int>(kolom));
    
    // Input data
    cout << "\nMasukkan nilai untuk matriks " << baris << "x" << kolom << ":\n";
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << "nilai[" << i << "][" << j << "]: ";
            cin >> nilai[i][j];
        }
    }

    // Output data
    cout << "\nTampilan Matriks:\n";
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << nilai[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
