// 1. Dasar Pointer: Menampilkan Nilai dan Alamat Memori
// Memahami konsep dasar pointer — bagaimana variabel menyimpan 
// alamat memori, dan bagaimana pointer menunjuk ke alamat itu.
#include <stdio.h>

int main() {
    int x = 10;
    int *ptr;  // pointer bertipe integer

    ptr = &x;  // pointer menyimpan alamat variabel x

    printf("Nilai x: %d\n", x);
    printf("Alamat x: %p\n", &x);
    printf("Nilai ptr (alamat yang ditunjuk): %p\n", ptr);
    printf("Nilai yang ditunjuk oleh ptr: %d\n", *ptr);

    return 0;
}

// &x berarti “alamat dari x”.

// *ptr berarti “nilai yang disimpan di alamat yang ditunjuk ptr”.

// Jadi pointer berfungsi seperti “jembatan” antara alamat dan nilai.