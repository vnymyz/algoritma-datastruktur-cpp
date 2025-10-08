#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    int umur;

    // Constructor
    Mahasiswa(string n, int u) {
        nama = n;
        umur = u;
    }

    void print() {
        cout << "Nama: " << nama << ", Umur: " << umur << endl;
    }
};

int main() {
    Mahasiswa m("Fajar", 23);  // Panggil constructor
    m.print();

    return 0;
}

// Struct bisa punya constructor untuk inisialisasi otomatis.

// Sudah mirip dengan penggunaan class.