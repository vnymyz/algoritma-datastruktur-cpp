#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Berapa banyak nilai yang ingin dimasukkan? ";
    cin >> n;  // Input jumlah elemen

    // Alokasi array dinamis
    int* nilai = new int[n];
    int total = 0;

    // Input nilai dan hitung total
    for (int i = 0; i < n; i++) {
        cout << "Nilai ke-" << i + 1 << ": ";
        cin >> nilai[i];
        total += nilai[i];
    }

    // Hitung rata-rata (gunakan cast untuk hasil desimal)
    double rata_rata = static_cast<double>(total) / n;

    // Tampilkan hasil rata-rata
    cout << "Rata-rata: " << rata_rata << endl;

    // Hapus array dari heap
    delete[] nilai;
    return 0;
}

