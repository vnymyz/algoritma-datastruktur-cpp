#include <stdio.h>

int main() {
    int N;
    printf("Masukkan jumlah elemen (N): ");
    scanf("%d", &N);
    
    int A[N], B[N], arr[N];
    
    printf("Masukkan urutan index (0 hingga N-1) dan nilai: ");
    // Input urutan index
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    
    printf("Masukkan nilai: ");
    // Input nilai
    for (int i = 0; i < N; i++) {
        scanf("%d", &B[i]);
    }
    
    // Proses nilai dimasukkan ke array sesuai urutan index
    // Inisialisasi array hasil dengan nol
    // Masukkan nilai B ke dalam array sesuai urutan A
    for (int i = 0; i < N; i++) {
        arr[A[i]] = B[i];
    }
    
    printf("Array hasil: ");
    // Output array hasil
    for (int i = 0; i < N; i++) {
        printf("%d", arr[i]);
        if (i < N - 1) printf(" "); // Tidak ada spasi di akhir
    }
    
    return 0;
}

// 1. Pertama kita input jumlah elemen N.
// 2. kita input urutan index yang kita ingin masukkan nilai nya
// 3. kita masukkin nilai ke dalam index tersebut
// 4. nanti dia bakal nampilin hasilnya berdasarkan nilai yang dimasukkan
// namun hasil index nya masih berurutan.