#include <iostream>
using namespace std;

int main() {
    int suhu;

    cout << "Masukkan suhu sekarang (°C): ";
    cin >> suhu;

    if (suhu >= 30) {
        cout << "Suhu panas! Minum es teh atau air dingin ya!" << endl;
    } else if (suhu >= 20) {
        cout << "Suhu sedang, minum air putih biasa cukup." << endl;
    } else {
        cout << "Dingin banget! Cocoknya minum teh atau kopi hangat." << endl;
    }

    return 0;
}
