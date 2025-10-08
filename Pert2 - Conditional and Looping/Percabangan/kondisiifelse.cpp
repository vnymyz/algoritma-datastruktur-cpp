#include <iostream>
using namespace std;

int main() {
    int nilai;
    cout << "Masukkan nilai: ";
    cin >> nilai;

    if (nilai >= 75) {
        cout << "Lulus!" << endl;
    } else {
        cout << "Tidak lulus." << endl;
    }

    return 0;
}
