#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    long long weight;
    int child_index;
    int position_index;
} Chocolate;

int compareChocolates(const void *a, const void *b) {
    Chocolate *chocA = (Chocolate *)a;
    Chocolate *chocB = (Chocolate *)b;

    if (chocB->weight > chocA->weight) return 1;
    if (chocB->weight < chocA->weight) return -1;
    return 0;
}

long long solve() {
    int N, M;
    scanf("%d %d", &N, &M);

    int total_chocolates = N * M;
    Chocolate all_chocolates[total_chocolates];
    int k = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            all_chocolates[k].child_index = i;
            all_chocolates[k].position_index = j;
            scanf("%lld", &all_chocolates[k].weight);
            k++;
        }
    }

    qsort(all_chocolates, total_chocolates, sizeof(Chocolate), compareChocolates);

    long long max_total_weight = 0;
    int chocolates_taken_count = 0;
    bool child_taken[501] = {false};
    bool position_taken[501] = {false};

    for (int i = 0; i < total_chocolates; i++) {
        if (chocolates_taken_count == N) break;

        int current_child = all_chocolates[i].child_index;
        int current_pos = all_chocolates[i].position_index;

        if (!child_taken[current_child] && !position_taken[current_pos]) {
            max_total_weight += all_chocolates[i].weight;
            child_taken[current_child] = true;
            position_taken[current_pos] = true;
            chocolates_taken_count++;
        }
    }

    return max_total_weight;
}

int main() {
    int T;
    scanf("%d", &T);

    long long results[T]; // simpan hasil tiap case

    for (int i = 0; i < T; i++) {
        results[i] = solve();
    }

    // tampilkan hasil di akhir saja
    for (int i = 0; i < T; i++) {
        printf("Case #%d: %lld\n", i + 1, results[i]);
    }

    return 0;
}

// 1. Pertama kita input jumlah anak N dan jumlah posisi M.
// 2. Kita buat struct untuk menyimpan informasi berat, index anak, dan index posisi.
// 3. Kita simpan semua coklat dalam satu array, lalu kita urutkan berdasarkan berat (descending).
// 4. Kita iterasi array yang sudah diurutkan, dan pilih coklat dengan syarat:
//    - Anak tersebut belum mengambil coklat.
//    - Posisi tersebut belum diambil.
// 5. Kita simpan hasil tiap test case, dan tampilkan di akhir.
// 6. Gunakan qsort untuk mengurutkan coklat berdasarkan berat.
// 7. Gunakan array boolean untuk melacak anak dan posisi yang sudah diambil coklat.
// 8. Hasil akhir adalah total berat coklat yang diambil sesuai aturan.
