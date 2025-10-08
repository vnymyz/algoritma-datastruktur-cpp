// 3. Pointer dan Input User
// Melatih penggunaan pointer untuk input dan output data dari user.
#include <stdio.h>

int main() {
    int data[5];
    int *ptr;
    ptr = data;

    printf("Masukkan 5 angka:\n");
    for (int i = 0; i < 5; i++) {
        printf("Angka ke-%d: ", i + 1);
        scanf("%d", ptr + i);  // input langsung ke alamat (ptr + i)
    }

    printf("\nData yang dimasukkan:\n");
    for (int i = 0; i < 5; i++) {
        printf("Data ke-%d = %d\n", i + 1, *(ptr + i));
    }

    return 0;
}

// scanf("%d", ptr + i) mengisi elemen array lewat alamat memori.

// *(ptr + i) menampilkan nilai dari alamat tersebut.

// Konsep ini penting untuk memahami bagaimana fungsi menerima array sebagai parameter.