#include <iostream> // Mengimpor library untuk input/output standar
using namespace std; // Menghindari keharusan menulis std:: di setiap fungsi C++

int main() {
    // Mendeklarasikan array bertipe string dengan 5 elemen
    string mobil[5];

    // Mengisi elemen array satu per satu
    mobil[0] = "Lahkokgini";  // Elemen pertama (indeks ke-0)
    mobil[1] = "Tokoma";      // Elemen kedua (indeks ke-1)
    mobil[2] = "Willy";       // Elemen ketiga (indeks ke-2)
    mobil[3] = "BVMW";        // Elemen keempat (indeks ke-3)
    mobil[4] = "Suzoku";      // Elemen kelima (indeks ke-4)

    // Menampilkan judul output ke layar
    cout << "Isi array mobil:" << endl;

    // Melakukan perulangan dari 0 sampai 4 untuk menampilkan isi array
    for (int i = 0; i < 5; i++) {
        // Menampilkan setiap elemen array
        cout << "- " << mobil[i] << endl;
    }

    return 0; // Menandakan bahwa program selesai dengan sukses
}
