#include <iostream>
using namespace std;

int main(){
    int jml_arr;
    cout << "Jumlah Index : ";
    cin >> jml_arr;

    int angka[jml_arr];

    // Input elemen array
    for(int a = 0; a < jml_arr; a++){
        cout << "Masukkan nilai indeks ke - " << a << " : ";
        cin >> angka[a];
    }

    // Menampilkan hasil input
    cout << "\nHasil input adalah:\n";
    for(int a = 0; a < jml_arr; a++){
        cout << "Indeks ke-" << a << " = " << angka[a] << endl;
    }

    return 0;
}
