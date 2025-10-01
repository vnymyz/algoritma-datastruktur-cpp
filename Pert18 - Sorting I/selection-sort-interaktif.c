#include <stdio.h>

// Fungsi untuk cetak array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Selection Sort dengan visualisasi langkah
void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    int step = 1;

    for (i = 0; i < n-1; i++) {
        minIndex = i;
        printf("\n=== Pass %d ===\n", step++);
        
        for (j = i+1; j < n; j++) {
            printf("Bandingkan %d dengan %d", arr[minIndex], arr[j]);
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
                printf(" --> %d jadi elemen terkecil baru!\n", arr[minIndex]);
            } else {
                printf(" --> tetap.\n");
            }
            printArray(arr, n);
        }

        // Tukar elemen terkecil dengan posisi i
        if (minIndex != i) {
            printf("Tukar %d dengan %d\n", arr[i], arr[minIndex]);
            temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
            printArray(arr, n);
        } else {
            printf("Tidak ada pertukaran.\n");
        }
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Array sebelum sorting:\n");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("\nArray setelah sorting:\n");
    printArray(arr, n);

    return 0;
}
