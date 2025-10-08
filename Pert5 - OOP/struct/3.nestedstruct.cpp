#include <iostream>
using namespace std;

struct Alamat {
    string jalan;
    string kota;
};

struct Mahasiswa {
    string nama;
    int umur;
    Alamat alamat;  // Nested struct
};

int main() {
    Mahasiswa mhs;

    mhs.nama = "Dina";
    mhs.umur = 20;
    mhs.alamat.jalan = "Jl. Mawar";
    mhs.alamat.kota = "Depok";

    cout << "Nama: " << mhs.nama << endl;
    cout << "Umur: " << mhs.umur << endl;
    cout << "Alamat: " << mhs.alamat.jalan << ", " << mhs.alamat.kota << endl;

    return 0;
}

// Struct Alamat disisipkan ke dalam struct Mahasiswa.

// Cocok untuk data yang kompleks dan berelasi.