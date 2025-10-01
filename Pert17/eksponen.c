#include <stdio.h>
#include <math.h>

int main() {
    double hasil;

    hasil = pow(2, 3);   // 2 pangkat 3 = 8
    printf("2^3 = %lf\n", hasil);

    hasil = pow(9, 0.5); // 9 pangkat 0.5 = akar kuadrat dari 9 = 3
    printf("sqrt(9) = %lf\n", hasil);

    hasil = pow(5, -2);  // 5 pangkat -2 = 1 / (5^2) = 0.04
    printf("5^-2 = %lf\n", hasil);

    return 0;
}
