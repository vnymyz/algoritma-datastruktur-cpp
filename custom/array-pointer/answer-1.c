// 1. Menampilkan Isi Array dan Alamat Memori Menggunakan Pointer
// Tulislah program yang menampilkan isi array dan alamat memorinya menggunakan pointer.
#include <stdio.h>

int main() {
    int nilai[5] = {10, 20, 30, 40, 50};
    int *ptr;

    ptr = nilai;

    printf("Menampilkan isi array dan alamat memori:\n");
    for (int i = 0; i < 5; i++) {
        printf("Elemen ke-%d: %d\tAlamat: %p\n", i, *(ptr + i), (ptr + i));
    }

    return 0;
}
// Compile with: gcc -o answer-1 answer-1.c -std=c17
// Run with: ./answer-1