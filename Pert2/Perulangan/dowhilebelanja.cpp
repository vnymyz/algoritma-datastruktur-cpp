#include <iostream>
using namespace std;

int main() {
    char jawab;

    do {
        cout << "Belanja barang... (anggap 1 item dibeli)" << endl;

        cout << "Mau belanja lagi? (y/n): ";
        cin >> jawab;
    } while (jawab == 'y' || jawab == 'Y');

    cout << "Terima kasih sudah belanja!" << endl;

    return 0;
}
