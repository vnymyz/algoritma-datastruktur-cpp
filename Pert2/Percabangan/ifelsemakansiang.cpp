#include <iostream>
using namespace std;

int main() {
    int jam;

    cout << "Sekarang jam berapa? (dalam format 24 jam): ";
    cin >> jam;

    if (jam >= 12 && jam <= 13) {
        cout << "Saatnya makan siang!" << endl;
    } else {
        cout << "Bukan waktu makan siang." << endl;
    }

    return 0;
}
