#include <stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    // 5, 3, 8, 4, 2
    // 3, 5, 8, 4, 2
    // 3, 8, 5, 4, 2
    // 3, 4, 5, 8, 2
    // 2, 3, 4, 5, 8
    int n = sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr, n);

    printf("Hasil sorting (Bubble Sort): ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
