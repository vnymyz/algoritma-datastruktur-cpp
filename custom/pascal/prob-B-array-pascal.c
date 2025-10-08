#include <stdio.h>

void solve() {
    int N, M, Q;
    // Membaca jumlah teman (N), jumlah ruangan (M), dan jumlah kunjungan (Q)
    scanf("%d %d %d", &N, &M, &Q);

    // Membuat array 2D untuk menyimpan pola kunjungan setiap teman
    // patterns[i][j] = 1 jika teman ke-(i+1) mengunjungi ruangan ke-(j+1)
    int patterns[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &patterns[i][j]);
        }
    }

    // Membuat array untuk menyimpan urutan teman yang berkunjung
    int visiting_friends[Q];
    for (int i = 0; i < Q; i++) {
        scanf("%d", &visiting_friends[i]);
    }

    // Array untuk menghitung berapa kali setiap lampu di-toggle
    // Inisialisasi semua dengan 0
    int light_toggle_counts[M];
    for (int i = 0; i < M; i++) {
        light_toggle_counts[i] = 0;
    }

    // Mensimulasikan kunjungan
    for (int i = 0; i < Q; i++) {
        // Ambil ID teman (input 1-based), ubah ke index array (0-based)
        int friend_index = visiting_friends[i] - 1;

        // Iterasi melalui semua ruangan untuk melihat pola teman ini
        for (int j = 0; j < M; j++) {
            // Jika teman ini mengunjungi ruangan j (polanya = 1)
            if (patterns[friend_index][j] == 1) {
                // Tambahkan 1 ke jumlah toggle untuk lampu di ruangan tersebut
                light_toggle_counts[j]++;
            }
        }
    }

    // Mencetak hasil akhir
    for (int i = 0; i < M; i++) {
        // Jika jumlah toggle ganjil, lampu menyala (YES)
        if (light_toggle_counts[i] % 2 == 1) {
            printf("YES\n");
        } 
        // Jika jumlah toggle genap, lampu mati (NO)
        else {
            printf("NO\n");
        }
    }
}

int main() {
    int T;
    // Membaca jumlah kasus uji
    scanf("%d", &T);

    for (int i = 1; i <= T; i++) {
        printf("Case #%d:\n", i);
        solve();
    }

    return 0;
}