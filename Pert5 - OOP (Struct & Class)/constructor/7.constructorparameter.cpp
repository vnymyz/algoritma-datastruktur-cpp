#include <iostream>
using namespace std;

class Mahasiswa {
private:
    string nama;
    int umur;

public:
    // Constructor dengan parameter
    Mahasiswa(string n, int u) {
        nama = n;
        umur = u;
    }

    void tampilkan() {
        cout << "Nama: " << nama << ", Umur: " << umur << " tahun" << endl;
    }
};

int main() {
    Mahasiswa mhs("Vanya", 21);
    mhs.tampilkan();
    return 0;
}
