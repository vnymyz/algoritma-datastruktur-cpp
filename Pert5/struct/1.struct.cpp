// 1
// struct ini mirip dengan array bedanya dia bisa menyimpan data yang banyak
// dengan tipe data yang berbeda dan dapat diakses dengan class.
#include <iostream>
using namespace std;

// Definisi struct
struct Mahasiswa {
    string nama;
    int umur;
};

int main() {
    Mahasiswa m1;  // Buat objek dari struct

    m1.nama = "Vanya";
    m1.umur = 21;

    cout << "Nama: " << m1.nama << endl;
    cout << "Umur: " << m1.umur << " tahun" << endl;

    return 0;
}

// Struct Mahasiswa menyimpan dua data: nama dan umur.

// Kita membuat objek m1, lalu isi datanya.

// Akses data dengan . (dot operator).
