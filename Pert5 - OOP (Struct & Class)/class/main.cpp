#include <iostream>
using namespace std;

// ===============================
// | Bagian        | Penjelasan |
// ===============================
// | class         | Template/class yang berisi data (atribut) dan fungsi (method)
// | public        | Modifier akses, berarti bisa diakses dari luar class
// | string nama   | Atribut untuk menyimpan nama mahasiswa
// | int umur      | Atribut untuk menyimpan umur mahasiswa
// | Constructor   | Fungsi khusus yang otomatis dipanggil saat objek dibuat
// | Method        | Fungsi dalam class yang bisa dipanggil lewat objek
// | Object        | Variabel hasil instansiasi dari class
// ===============================

// Definisi class Mahasiswa
class Mahasiswa {
public:
    string nama;   // Atribut: menyimpan nama
    int umur;      // Atribut: menyimpan umur

    // Constructor: otomatis dipanggil saat objek dibuat
    Mahasiswa(string n, int u) {
        nama = n;
        umur = u;
    }

    // Method: Fungsi anggota dari class
    // void adalah fungsi yang tidak mengembalikan apapun saat selesai jalan.
    void perkenalan() {
        cout << "Halo, nama saya " << nama << " dan saya berumur " << umur << " tahun." << endl;
    }
};

int main() {
    // Membuat objek dari class Mahasiswa
    Mahasiswa mhs1("Vanya", 21); // Object: mhs1

    // Memanggil method dari objek
    mhs1.perkenalan();

    return 0;
}

// Gunakan class saat:

// Kamu bekerja dengan data kompleks (misal data pegawai, transaksi, kendaraan)

// Kamu ingin struktur kode yang bersih, mudah dimengerti, dan terpisah

// Kamu membangun program besar yang butuh banyak bagian (modularitas)
