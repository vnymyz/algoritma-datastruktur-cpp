#include <iostream> // Mengimpor library standar untuk input dan output
using namespace std; // Menggunakan namespace std agar tidak perlu menulis std:: sebelum cout, endl, dll

// Mendefinisikan struct bernama 'Alamat' untuk menyimpan data alamat
struct Alamat {
    string jalan; // Variabel untuk menyimpan nama jalan
    string kota;  // Variabel untuk menyimpan nama kota
};

// Mendefinisikan struct bernama 'Siswa' yang memiliki anggota berupa struct 'Alamat'
struct Siswa {
    string nama;    // Variabel untuk menyimpan nama siswa
    Alamat alamat;  // Variabel bertipe struct Alamat (nested struct)
};

int main() {
    // Membuat objek bernama 'siswa1' dari struct Siswa
    Siswa siswa1;

    // Mengisi data pada objek siswa1
    siswa1.nama = "Vanya";                     // Memberi nilai pada variabel 'nama'
    siswa1.alamat.jalan = "Jl. Melati";        // Memberi nilai pada variabel 'jalan' dalam nested struct 'alamat'
    siswa1.alamat.kota = "Depok";              // Memberi nilai pada variabel 'kota' dalam nested struct 'alamat'

    // Menampilkan data ke layar
    cout << "Nama: " << siswa1.nama << endl;                       // Menampilkan nama siswa
    cout << "Alamat: " << siswa1.alamat.jalan << ", "              // Menampilkan jalan dari nested struct alamat
         << siswa1.alamat.kota << endl;                            // Menampilkan kota dari nested struct alamat

    return 0; // Mengakhiri program
}
