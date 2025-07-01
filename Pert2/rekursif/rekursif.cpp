#include <iostream>
using namespace std;

// Fungsi rekursif untuk menghitung faktorial
int faktorial(int n) {
    // Menampilkan proses saat fungsi dipanggil
    cout << "Memanggil faktorial(" << n << ")" << endl;

    // Base case: jika n <= 1, berhenti dan kembalikan 1
    if (n <= 1) {
        cout << "Kembali 1 (karena n <= 1)" << endl;
        return 1;
    } else {
        // Hitung faktorial dengan rekursi
        int hasil = n * faktorial(n - 1);

        // Tampilkan hasil dari pemanggilan fungsi ini
        cout << "Hasil faktorial(" << n << ") = " << hasil << endl;
        return hasil;
    }
}

int main() {
    int angka;

    cout << "Masukkan angka untuk dihitung faktorialnya: ";
    cin >> angka;

    int hasil = faktorial(angka);

    cout << "\nFaktorial dari " << angka << " adalah: " << hasil << endl;

    return 0;
}
