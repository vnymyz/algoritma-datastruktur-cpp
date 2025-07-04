// 3
#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    int umur;
};

int main() {
    Mahasiswa daftar[2];  // Array of struct

    for (int i = 0; i < 2; i++) {
        cout << "Masukkan nama mahasiswa ke-" << i + 1 << ": ";
        cin >> daftar[i].nama;

        cout << "Masukkan umur: ";
        cin >> daftar[i].umur;
    }

    cout << "\nData Mahasiswa:\n";
    for (int i = 0; i < 2; i++) {
        cout << daftar[i].nama << " - " << daftar[i].umur << " tahun\n";
    }

    return 0;
}


// Struct bisa dipakai untuk membuat array of object.

// Cocok untuk menyimpan banyak data bertipe sama.