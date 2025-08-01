#include <iostream>
using namespace std;

void tampilMundur(int arr[], int i) {
    if (i < 0) return;      // base case
    cout << arr[i] << " ";
    tampilMundur(arr, i - 1);   // recursive case
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    int* data = new int[n]; // alokasi array dinamis

    cout << "Masukkan elemen array:\n";
    for (int i = 0; i < n; i++) {
        cout << "data[" << i << "] = ";
        cin >> data[i];
    }

    cout << "Isi array secara mundur: ";
    tampilMundur(data, n - 1);

    delete[] data; // jangan lupa hapus array dinamis
    return 0;
}
