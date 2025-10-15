#include <stdio.h>

// Fungsi untuk menukar dua nilai
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi untuk melakukan partisi (memisahkan elemen kecil dan besar)
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // pilih elemen terakhir sebagai pivot
    int i = low - 1;       // penanda posisi elemen lebih kecil dari pivot

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]); // tukar elemen kecil ke kiri
        }
    }

    // Setelah loop, tempatkan pivot di posisi yang benar
    swap(&arr[i + 1], &arr[high]);
    return i + 1; // posisi akhir pivot
}

// Fungsi utama quick sort (rekursif)
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Dapatkan posisi pivot setelah partisi
        int pi = partition(arr, low, high);

        // Urutkan bagian kiri dan kanan dari pivot
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Fungsi untuk menampilkan array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Fungsi utama
int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array sebelum diurutkan:\n");
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    printf("\nArray setelah diurutkan (Quick Sort):\n");
    printArray(arr, size);

    return 0;
}
