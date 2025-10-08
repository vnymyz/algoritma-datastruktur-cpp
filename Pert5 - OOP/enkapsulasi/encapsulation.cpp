#include <iostream>
using namespace std;

class Mahasiswa {
private:
    string nama;      // Tidak bisa diakses langsung dari luar
    int umur;         // Atribut private: hanya bisa diakses lewat method

public:
    // Setter: untuk mengisi data
    void setNama(string n) {
        nama = n;
    }

    void setUmur(int u) {
        if (u >= 0) umur = u; // Validasi umur
        else umur = 0;
    }

    // Getter: untuk mengambil data
    // Dibuat untuk mengakses data yg private
    string getNama() {
        return nama;
    }

    int getUmur() {
        return umur;
    }
};

int main() {
    // membuat objek dari class mahasiswa
    Mahasiswa mhs;

    // Mengisi data melalui setter
    mhs.setNama("Vanya");
    mhs.setUmur(21);

    // Mengambil data melalui getter
    cout << "Nama Mahasiswa: " << mhs.getNama() << endl;
    cout << "Umur: " << mhs.getUmur() << " tahun" << endl;

    return 0;
}
