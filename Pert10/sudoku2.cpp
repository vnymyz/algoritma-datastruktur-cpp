#include <iostream>
using namespace std;

const int N = 4;

// Cek apakah angka `num` valid untuk posisi (row, col)
bool isValid(int grid[N][N], int row, int col, int num) {
    // Cek baris dan kolom
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num)
            return false;
    }

    // Cek kotak 2x2
    int startRow = row - row % 2;
    int startCol = col - col % 2;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            if (grid[startRow + i][startCol + j] == num)
                return false;

    return true;
}

// Backtracking solver
bool solveSudoku(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                for (int num = 1; num <= N; num++) {
                    if (isValid(grid, row, col, num)) {
                        grid[row][col] = num;
                        if (solveSudoku(grid))
                            return true;
                        grid[row][col] = 0; // backtrack
                    }
                }
                return false;
            }
        }
    }
    return true;
}

// Cetak hasil Sudoku
void printGrid(int grid[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int grid[N][N];

    cout << "Masukkan grid 4x4 (isi 0 untuk sel kosong):\n";
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> grid[i][j];

    if (solveSudoku(grid)) {
        cout << "\nSolusi Sudoku:\n";
        printGrid(grid);
    } else {
        cout << "Tidak ada solusi!\n";
    }

    return 0;
}
