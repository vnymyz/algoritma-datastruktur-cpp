// 2. Pointer dan Array
// Memahami bagaimana pointer bisa digunakan untuk mengakses elemen array.
#include <stdio.h>

int main() {
    int angka[5] = {10, 20, 30, 40, 50};
    int *p;

    p = angka;  // pointer menunjuk ke elemen pertama array

    printf("Isi array menggunakan pointer:\n");
    for (int i = 0; i < 5; i++) {
        printf("Elemen ke-%d = %d (alamat: %p)\n", i, *(p + i), (p + i));
    }

    return 0;
}

// p = angka; sama artinya dengan p = &angka[0];

// *(p + i) mengambil nilai pada indeks ke-i.

// (p + i) menunjukkan alamat tiap elemen array.

// Jadi pointer bisa digunakan seperti indeks array!