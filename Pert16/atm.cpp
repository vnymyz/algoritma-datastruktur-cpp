#include <iostream>
using namespace std;

// Fungsi untuk login
bool login() {
    int pin, percobaan = 0;
    const int PIN_BENAR = 1234;

    while (percobaan < 3) { // maksimal 3 kali percobaan
        cout << "Masukkan PIN: ";
        cin >> pin;

        if (pin == PIN_BENAR) {
            cout << "Login berhasil!\n";
            return true;
        } else {
            cout << "PIN salah. Coba lagi.\n";
            percobaan++;
        }
    }
    cout << "Akun terblokir. Silakan hubungi bank.\n";
    return false;
}

// Fungsi untuk menampilkan menu
void tampilMenu() {
    cout << "\n=== Menu ATM ===\n";
    cout << "1. Cek Saldo\n";
    cout << "2. Tarik Tunai\n";
    cout << "3. Setor Tunai\n";
    cout << "4. Keluar\n";
    cout << "Pilih menu: ";
}

int main() {
    int saldo = 1000000; // saldo awal
    int pilihan;
    int jumlah;

    if (!login()) return 0; // jika login gagal, keluar program

    do {
        tampilMenu();
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Saldo Anda: Rp" << saldo << endl;
                break;
            case 2:
                cout << "Masukkan jumlah tarik tunai: Rp";
                cin >> jumlah;
                if (jumlah > saldo) {
                    cout << "Saldo tidak cukup.\n";
                } else if (jumlah <= 0) {
                    cout << "Jumlah tidak valid.\n";
                } else {
                    saldo -= jumlah;
                    cout << "Tarik tunai berhasil. Saldo sekarang: Rp" << saldo << endl;
                }
                break;
            case 3:
                cout << "Masukkan jumlah setor tunai: Rp";
                cin >> jumlah;
                if (jumlah <= 0) {
                    cout << "Jumlah tidak valid.\n";
                } else {
                    saldo += jumlah;
                    cout << "Setor tunai berhasil. Saldo sekarang: Rp" << saldo << endl;
                }
                break;
            case 4:
                cout << "Terima kasih telah menggunakan ATM.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 4);

    return 0;
}
