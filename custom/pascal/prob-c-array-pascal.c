#include <stdio.h>

// Fungsi untuk mengalikan dua matriks (m1 dan m2) berukuran N x N
// dan menyimpan hasilnya di matriks 'result'
void multiplyMatrices(int N, int m1[N][N], int m2[N][N], int result[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // Inisialisasi elemen hasil dengan 0 sebelum memulai penjumlahan
            result[i][j] = 0;
            // Loop ketiga untuk menghitung dot product dari baris m1 dan kolom m2
            for (int k = 0; k < N; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

// Fungsi untuk membaca satu matriks berukuran N x N dari input
void readMatrix(int N, int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Fungsi untuk mencetak satu matriks berukuran N x N sesuai format
void printMatrix(int N, int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d", matrix[i][j]);
            // Cetak spasi jika bukan elemen terakhir di baris
            if (j < N - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int T;
    // Membaca jumlah test case
    scanf("%d", &T);

    for (int caseNum = 1; caseNum <= T; caseNum++) {
        int N;
        // Membaca ukuran matriks
        scanf("%d", &N);

        // Deklarasi matriks
        int matrixA[N][N], matrixB[N][N], matrixC[N][N];
        int tempResult[N][N], finalResult[N][N];

        // Membaca tiga matriks dari input
        readMatrix(N, matrixA);
        readMatrix(N, matrixB);
        readMatrix(N, matrixC);

        // Langkah 1: Mengalikan matriks A dengan B, simpan di tempResult
        multiplyMatrices(N, matrixA, matrixB, tempResult);

        // Langkah 2: Mengalikan tempResult dengan C, simpan di finalResult
        multiplyMatrices(N, tempResult, matrixC, finalResult);

        // Mencetak header output
        printf("Case #%d:\n", caseNum);
        
        // Mencetak matriks hasil akhir
        printMatrix(N, finalResult);
    }

    return 0;
}

// Deskripsi codingan :
// 1. Pertama kita buat fungsi untuk mengalikan dua matriks N x N.
// 2. Lalu kita buat fungsi untuk membaca matriks dari input.
// 3. Kemudian kita buat fungsi untuk mencetak matriks sesuai format.
// 4. Di fungsi main, kita baca jumlah test case T.
// 5. Untuk setiap test case, kita baca ukuran matriks N dan tiga matriks A, B, C.
// 6. Kita kalikan A dengan B, simpan hasilnya di matriks sementara.
// 7. Lalu kita kalikan hasil sementara dengan C, simpan di matriks hasil akhir.
// 8. Terakhir kita cetak hasil akhir sesuai format yang diminta.
