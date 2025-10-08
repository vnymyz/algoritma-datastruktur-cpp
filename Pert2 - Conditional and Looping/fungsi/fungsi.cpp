#include <iostream>
using namespace std;

// Fungsi untuk menjumlahkan dua angka
int tambah(int a, int b) {
    return a + b;
}

int main() {
    int hasil = tambah(10, 5); // Memanggil fungsi tambah
    cout << "Hasil: " << hasil << endl;
    return 0;
}
