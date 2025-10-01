#include <stdio.h>

// Fungsi untuk cetak array
void printArray(int arr[], int n, int currentIndex, int keyPos) {
    for (int i = 0; i < n; i++) {
        if (i == keyPos)
            printf("[%d] ", arr[i]); // tandai posisi key
        else if (i == currentIndex)
            printf("(%d) ", arr[i]); // tandai elemen yang sedang dibandingkan
        else
            printf("%d ", arr[i]);
    }
    printf("\n");
}

// Insertion Sort dengan visualisasi langkah
void insertionSort(int arr[], int n) {
    int i, j, key;
    int step = 1;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        printf("\n=== Pass %d ===\n", step++);
        printf("Ambil elemen %d sebagai 'key'\n", key);
        printArray(arr, n, j, i);

        // geser elemen lebih besar dari key
        while (j >= 0 && arr[j] > key) {
            printf("Bandingkan key %d dengan %d --> geser\n", key, arr[j]);
            arr[j+1] = arr[j];
            j--;
            printArray(arr, n, j, i);
        }

        // simpan key di posisi yang benar
        arr[j+1] = key;
        printf("Tempatkan key %d di posisi yang tepat\n", key);
        printArray(arr, n, -1, j+1);
    }
}

int main() {
    int arr[] = {5, 3, 4, 6, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Array sebelum sorting:\n");
    printArray(arr, n, -1, -1);

    insertionSort(arr, n);

    printf("\nArray setelah sorting:\n");
    printArray(arr, n, -1, -1);

    return 0;
}
