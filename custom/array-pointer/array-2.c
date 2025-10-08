// 2. Input, Total, dan Rata-rata Array
// Melatih penggunaan array dengan input dari user dan perhitungan dasar.
#include <stdio.h>

int main() {
    int nilai[5];
    int total = 0;
    float rata;

    printf("Masukkan 5 nilai:\n");
    for (int i = 0; i < 5; i++) {
        printf("Nilai ke-%d: ", i + 1);
        scanf("%d", &nilai[i]);
        total += nilai[i];
    }

    rata = (float) total / 5;

    printf("\nTotal nilai = %d\n", total);
    printf("Rata-rata = %.2f\n", rata);

    return 0;
}
