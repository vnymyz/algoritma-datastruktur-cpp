#include <stdio.h>

// Fungsi untuk menggabungkan dua bagian array yang sudah terurut
void merge(int arr[], int left, int mid, int right) {
    int i = left;      // indeks awal bagian kiri
    int j = mid + 1;   // indeks awal bagian kanan
    int k = 0;         // indeks untuk array sementara
    int temp[100];     // array sementara untuk menampung hasil penggabungan

    // Bandingkan elemen dari kedua bagian dan masukkan ke temp[]
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    // Masukkan sisa elemen dari bagian kiri (jika ada)
    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // Masukkan sisa elemen dari bagian kanan (jika ada)
    while (j <= right) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Salin hasil penggabungan dari temp[] kembali ke arr[]
    for (i = left, k = 0; i <= right; i++, k++) {
        arr[i] = temp[k];
    }
}

// Fungsi utama merge sort (rekursif)
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        // Bagi dua bagian kiri dan kanan
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Gabungkan dua bagian yang sudah diurutkan
        merge(arr, left, mid, right);
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

    mergeSort(arr, 0, size - 1);

    printf("\nArray setelah diurutkan (Merge Sort):\n");
    printArray(arr, size);

    return 0;
}
