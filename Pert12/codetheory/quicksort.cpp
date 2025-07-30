#include <iostream>
using namespace std;

// pivot: elemen acuan (dalam contoh: elemen terakhir)

// partition(): memindahkan elemen kecil ke kiri pivot, besar ke kanan

// quickSort(): memanggil rekursif bagian kiri dan kanan dari pivot

// Fungsi untuk melakukan partisi
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // pilih elemen terakhir sebagai pivot
    int i = low - 1;        // indeks dari elemen lebih kecil

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);  // tempatkan pivot di posisi yang benar
    return i + 1;  // kembalikan posisi pivot
}

// Fungsi quick sort (rekursif)
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // partisi dan dapatkan pivot index

        quickSort(arr, low, pi - 1);  // sort elemen sebelum pivot
        quickSort(arr, pi + 1, high); // sort elemen setelah pivot
    }
}

// Fungsi cetak array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

// Main program
int main() {
    int arr[] = {6, 5, 3, 2, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array sebelum disortir: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Array setelah quick sort: ";
    printArray(arr, n);

    return 0;
}
