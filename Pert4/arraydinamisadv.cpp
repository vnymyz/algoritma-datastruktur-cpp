#include <iostream>
using namespace std;

// Fungsi untuk input elemen ke dalam array
void inputArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Masukkan elemen ke-" << i + 1 << ": ";
        cin >> arr[i];
    }
}

// Fungsi untuk mencetak elemen array
void printArray(int* arr, int n) {
    cout << "Isi array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;

    // Alokasi array dinamis
    int* array = new int[n];

    // Panggil fungsi input dan output
    inputArray(array, n);
    printArray(array, n);

    // Hapus array dari heap
    delete[] array;
    return 0;
}
