// 2. Array char Nama dan Pointer
// Buatlah array char berisi nama kamu, lalu tampilkan huruf demi huruf menggunakan pointer.
#include <stdio.h>

int main() {
    char nama[] = "Vanya";
    char *p;

    p = nama;

    printf("Huruf demi huruf dari nama kamu:\n");

    while (*p != '\0') {
        printf("%c ", *p);
        p++;
    }

    return 0;
}
