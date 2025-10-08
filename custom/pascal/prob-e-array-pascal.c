#include <stdio.h>
#include <stdbool.h>

int main() {
    int T;
    scanf("%d", &T); // jumlah test case

    for (int t = 1; t <= T; t++) {
        int N;
        scanf("%d", &N); // jumlah elemen array

        int A[205]; // sesuai constraint N ≤ 200
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }

        int cool_factor = 0;

        // Loop untuk setiap elemen A[k]
        for (int k = 0; k < N; k++) {
            bool found = false; // penanda apakah A[k] bisa dibentuk dari dua elemen lain

            for (int i = 0; i < N && !found; i++) {
                for (int j = i + 1; j < N && !found; j++) {
                    if (i != k && j != k) { // pastikan dua elemen yang berbeda dari A[k]
                        if (A[i] + A[j] == A[k]) {
                            found = true;
                            cool_factor++;
                        }
                    }
                }
            }
        }

        printf("Case #%d: %d\n", t, cool_factor);
    }

    return 0;
}
