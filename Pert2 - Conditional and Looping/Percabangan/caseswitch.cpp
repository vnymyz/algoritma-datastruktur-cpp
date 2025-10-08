#include <iostream>
using namespace std;

int main() {
    int hari;
    cout << "Masukkan angka 1–7: ";
    cin >> hari;

    // Switch untuk memilih nama hari berdasarkan angka
    switch (hari) {
        case 1: cout << "Minggu"; break;
        case 2: cout << "Senin"; break;
        case 3: cout << "Selasa"; break;
        case 4: cout << "Rabu"; break;
        case 5: cout << "Kamis"; break;
        case 6: cout << "Jumat"; break;
        case 7: cout << "Sabtu"; break;
        default: cout << "Hari tidak valid"; break;
    }

    return 0;
}
