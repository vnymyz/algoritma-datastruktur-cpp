#include <iostream>
using namespace std;

int main() {
    int pilihan;

    // Menampilkan menu ke user
    cout << "=== Menu Makanan ===" << endl;
    cout << "1. Nasi Goreng" << endl;
    cout << "2. Mie Ayam" << endl;
    cout << "3. Bakso" << endl;
    cout << "4. Sate Ayam" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilih menu (1-5): ";
    cin >> pilihan;

    // Menggunakan switch untuk menentukan pilihan
    switch (pilihan) {
        case 1:
            cout << "Anda memilih Nasi Goreng." << endl;
            break;
        case 2:
            cout << "Anda memilih Mie Ayam." << endl;
            break;
        case 3:
            cout << "Anda memilih Bakso." << endl;
            break;
        case 4:
            cout << "Anda memilih Sate Ayam." << endl;
            break;
        case 5:
            cout << "Terima kasih, sampai jumpa!" << endl;
            break;
        default:
            cout << "Pilihan tidak tersedia." << endl;
            break;
    }

    return 0;
}
