#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Jumlah data: ";
    cin >> n;

    // Alokasi array secara dinamis
    int* data = new int[n];

    // Input data ke dalam array
    for (int i = 0; i < n; i++) {
        cout << "Data ke-" << i + 1 << ": ";
        cin >> data[i];
    }

    // Inisialisasi nilai maksimum dari elemen pertama
    int maks = data[0];

    // Cari nilai maksimum di array
    for (int i = 1; i < n; i++) {
        if (data[i] > maks) {
            maks = data[i];
        }
    }

    // Tampilkan nilai maksimum
    cout << "Nilai maksimum adalah: " << maks << endl;

    // Bebaskan memori array
    delete[] data;
    cout << data;
    
    return 0;
}
