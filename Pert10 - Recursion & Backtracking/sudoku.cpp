#include <iostream>
using namespace std;

const int N = 9;

bool isSafe(int grid[N][N], int row, int col, int num) {
    // Cek baris
    for (int x = 0; x < N; x++)
        if (grid[row][x] == num)
            return false;

    // Cek kolom
    for (int x = 0; x < N; x++)
        if (grid[x][col] == num)
            return false;

    // Cek 3x3 box
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}

bool solveSudoku(int grid[N][N], int row, int col) {
    // Jika sudah sampai baris ke-9, selesai
    if (row == N - 1 && col == N)
        return true;

    // Pindah ke baris selanjutnya jika sudah sampai kolom ke-9
    if (col == N) {
        row++;
        col = 0;
    }

    // Jika kotak sudah diisi, lanjut
    if (grid[row][col] != 0)
        return solveSudoku(grid, row, col + 1);

    // Coba angka 1-9
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid, row, col + 1))
                return true;
        }

        grid[row][col] = 0; // backtrack
    }

    return false;
}

void printGrid(int grid[N][N]) {
    for (int r = 0; r < N; r++) {
        for (int d = 0; d < N; d++) {
            cout << grid[r][d] << " ";
        }
        cout << endl;
    }
}

int main() {
    int grid[N][N] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    if (solveSudoku(grid, 0, 0))
        printGrid(grid);
    else
        cout << "Tidak ada solusi!\n";

    return 0;
}
