#include <stdio.h>

// Fungsi untuk cetak array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Bubble Sort dengan visualisasi
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int step = 1; // buat nunjukin langkah ke berapa

    for (i = 0; i < n - 1; i++) {
        printf("\n=== Pass %d ===\n", step++);
        for (j = 0; j < n - i - 1; j++) {
            printf("Bandingkan %d dan %d", arr[j], arr[j+1]);
            if (arr[j] > arr[j+1]) {
                printf(" --> tukar!\n");
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            } else {
                printf(" --> tidak perlu tukar.\n");
            }
            printArray(arr, n);
        }
    }
}

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array sebelum sorting:\n");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("\nArray setelah sorting:\n");
    printArray(arr, n);

    return 0;
}
