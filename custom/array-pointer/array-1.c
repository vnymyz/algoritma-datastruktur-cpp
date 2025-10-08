// 1. Menampilkan Elemen Array
// Memahami cara membuat dan mengakses elemen array.
#include <stdio.h>

int main() {
    int angka[5] = {10, 20, 30, 40, 50};

    printf("Isi array:\n");
    for (int i = 0; i < 5; i++) {
        printf("angka[%d] = %d\n", i, angka[i]);
    }

    return 0;
}
// Compile with: gcc -o array-1 array-1.c -std=c17
// Run with: ./array-1