// 3. Input dari User & Tampilkan dengan Pointer
// Buat program yang meminta user untuk mengisi beberapa nilai 
// integer ke dalam array, lalu tampilkan hasilnya menggunakan pointer.
#include <stdio.h>

int main() {
    int data[5];
    int *ptr;
    ptr = data;

    printf("Masukkan 5 nilai integer:\n");
    for (int i = 0; i < 5; i++) {
        printf("Data ke-%d: ", i + 1);
        scanf("%d", &data[i]);
    }

    printf("\nMenampilkan data menggunakan pointer:\n");
    for (int i = 0; i < 5; i++) {
        printf("Data ke-%d: %d\n", i + 1, *(ptr + i));
    }

    return 0;
}
// Compile with: gcc -o answer-3 answer-3.c -std=c17
// Run with: ./answer-3