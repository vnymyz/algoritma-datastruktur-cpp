#include <iostream>
#include <string>  // untuk menggunakan getline()
using namespace std;

// Mendefinisikan struct Mahasiswa
struct Mahasiswa {
    string nama;
    int umur;
};

int main() {
    const int JUMLAH = 2;               // Jumlah mahasiswa
    Mahasiswa daftar[JUMLAH];           // Array of struct Mahasiswa

    // Input data mahasiswa
    for (int i = 0; i < JUMLAH; i++) {
        cout << "Masukkan nama mahasiswa ke-" << i + 1 << ": ";
        cin.ignore();                   // Membersihkan buffer sebelum getline
        getline(cin, daftar[i].nama);  // Menggunakan getline agar bisa input nama dengan spasi

        cout << "Masukkan umur mahasiswa ke-" << i + 1 << ": ";
        cin >> daftar[i].umur;
    }

    // Menampilkan data
    cout << "\n Data Mahasiswa:\n";
    for (int i = 0; i < JUMLAH; i++) {
        cout << "- " << daftar[i].nama << " (" << daftar[i].umur << " tahun)" << endl;
    }

    return 0;
}
