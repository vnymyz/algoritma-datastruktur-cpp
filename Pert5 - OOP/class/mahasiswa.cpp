#include <iostream>  // Library untuk input-output
using namespace std;

// Membuat class bernama Mahasiswa
class Mahasiswa {
public:
    // Atribut (data) milik Mahasiswa
    string nama;
    int umur;

    // Method (fungsi) untuk memperkenalkan diri
    void perkenalan() {
        cout << "Halo, nama saya " << nama << " dan saya berumur " << umur << " tahun." << endl;
    }
};

int main() {
    // Membuat objek dari class Mahasiswa
    Mahasiswa mhs1;

    // Mengisi nilai atribut pada objek mhs1
    mhs1.nama = "Vanya";
    mhs1.umur = 21;

    // Memanggil method perkenalan pada objek mhs1
    mhs1.perkenalan();

    return 0;
}

// class Mahasiswa: mendefinisikan blueprint untuk objek mahasiswa

// string nama, int umur: atribut yang menyimpan data tiap objek

// void perkenalan(): fungsi yang bisa dijalankan oleh objek

// mhs1: objek dari class Mahasiswa

// mhs1.perkenalan(): memanggil method milik objek mhs1