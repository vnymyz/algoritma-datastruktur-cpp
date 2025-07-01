#include <iostream>
using namespace std;

int main() {
    int umur;

    cout << "Masukkan umur: ";
    cin >> umur;

    // Cetak lilin sebanyak umur
    for (int i = 1; i <= umur; i++) {
        cout << " Lilin ke-" << i << endl;
    }

    cout << "Selamat ulang tahun!" << endl;
    return 0;
}
