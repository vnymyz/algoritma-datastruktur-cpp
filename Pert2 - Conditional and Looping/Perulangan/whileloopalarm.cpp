#include <iostream>
using namespace std;

int main() {
    int hitung = 1;
    char bangun;

    // Selama belum bangun, alarm terus bunyi
    while (true) {
        cout << "Alarm berbunyi ke-" << hitung << endl;
        cout << "Sudah bangun? (y/n): ";
        cin >> bangun;

        if (bangun == 'y' || bangun == 'Y') {
            break; // keluar dari loop
        }
        hitung++;
    }

    cout << "Selamat pagi!" << endl;

    return 0;
}
