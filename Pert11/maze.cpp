#include <iostream>
using namespace std;

const int N = 3;

// Maze 3x3: 1 = bisa dilewati, 0 = tembok
int maze[N][N] = {
    {1, 1, 0},
    {0, 1, 0},
    {0, 1, 1}
};

// Fungsi rekursif untuk mencari solusi maze dari posisi (x, y)
bool solveMaze(int x, int y, int sol[N][N]) {
    // BASE CASE: Jika sudah sampai tujuan (pojok kanan bawah)
    if (x == N - 1 && y == N - 1) {
        sol[x][y] = 1; // Tandai sebagai bagian dari solusi
        return true;   // Maze berhasil diselesaikan
    }

    // CEK apakah posisi (x, y) valid dan bisa dilewati
    if (x >= 0 && y >= 0 && x < N && y < N && maze[x][y] == 1) {
        sol[x][y] = 1; // Tandai posisi sekarang sebagai bagian dari solusi

        // REKURSIF: Coba bergerak ke bawah
        if (solveMaze(x + 1, y, sol)) return true;

        // REKURSIF: Coba bergerak ke kanan
        if (solveMaze(x, y + 1, sol)) return true;

        // BACKTRACK: Jika kedua arah gagal, batalkan tanda dan kembali mundur
        sol[x][y] = 0;
    }

    // Jika tidak valid atau semua arah gagal
    return false;
}

int main() {
    int sol[N][N] = {0}; // Matriks solusi, awalnya semua 0

    // Coba cari solusi mulai dari posisi (0, 0)
    if (solveMaze(0, 0, sol)) {
        cout << "Solusi Maze:\n";
        // Cetak solusi
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << sol[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "Tidak ada solusi!";
    }

    return 0;
}
