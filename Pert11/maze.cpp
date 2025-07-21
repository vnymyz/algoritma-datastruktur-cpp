#include <iostream>
using namespace std;

const int N = 3;
int maze[N][N] = {
    {1, 1, 0},
    {0, 1, 0},
    {0, 1, 1}
};

bool solveMaze(int x, int y, int sol[N][N]) {
    // Jika sudah di tujuan
    if (x == N - 1 && y == N - 1) {
        sol[x][y] = 1;
        return true;
    }

    // Cek valid dan bisa dilewati
    if (x >= 0 && y >= 0 && x < N && y < N && maze[x][y] == 1) {
        sol[x][y] = 1;

        // Bergerak ke bawah
        if (solveMaze(x + 1, y, sol)) return true;

        // Bergerak ke kanan
        if (solveMaze(x, y + 1, sol)) return true;

        // Backtrack
        sol[x][y] = 0;
    }

    return false;
}

int main() {
    int sol[N][N] = {0};

    if (solveMaze(0, 0, sol)) {
        cout << "Solusi Maze:\n";
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
