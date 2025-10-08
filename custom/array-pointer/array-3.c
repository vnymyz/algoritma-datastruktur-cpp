// 3. Mencari Nilai Terbesar dan Terkecil
// Memahami perbandingan antar elemen dalam array.
#include <stdio.h>

int main() {
    int data[5];
    int max, min;

    printf("Masukkan 5 angka:\n");
    for (int i = 0; i < 5; i++) {
        printf("Angka ke-%d: ", i + 1);
        scanf("%d", &data[i]);
    }

    max = data[0];
    min = data[0];

    for (int i = 1; i < 5; i++) {
        if (data[i] > max)
            max = data[i];
        if (data[i] < min)
            min = data[i];
    }

    printf("\nNilai terbesar = %d\n", max);
    printf("Nilai terkecil = %d\n", min);

    return 0;
}
