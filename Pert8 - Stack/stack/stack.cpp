// 1. Stack Array
#include <iostream>
#include <string>
using namespace std;

// =============================
// CLASS StackCD
// =============================
class StackCD {
private:
    string cd[5]; // Array statik untuk menyimpan maksimal 5 judul CD
    int top;      // Menunjukkan indeks CD paling atas di stack

public:
    // Konstruktor: inisialisasi stack kosong
    StackCD() {
        top = -1;
    }

    // Fungsi PUSH: menambahkan CD ke atas tumpukan
    void push(string judul) {
        if (top >= 4) { // Stack penuh jika top sudah di indeks terakhir
            cout << "Tumpukan penuh! Tidak bisa menambahkan \"" << judul << "\"\n";
            return;
        }
        cd[++top] = judul; // Naikkan indeks lalu simpan CD
        cout << "Menambahkan CD: \"" << judul << "\" ke tumpukan\n";
    }

    // Fungsi POP: mengambil CD dari tumpukan
    void pop() {
        if (top < 0) { // Stack kosong jika top < 0
            cout << "Tidak ada CD untuk diambil (tumpukan kosong)\n";
            return;
        }
        cout << "Mengambil CD: \"" << cd[top--] << "\" dari tumpukan\n";
    }

    // Fungsi untuk menampilkan isi stack
    void tampilkan() {
        cout << "\nIsi Tumpukan CD:\n";
        if (top < 0) {
            cout << "(Kosong)\n";
            return;
        }

        // Tampilkan semua CD dari atas ke bawah
        for (int i = top; i >= 0; i--) {
            cout << "- " << cd[i] << "\n";
        }
        cout << endl;
    }
};

// =============================
// PROGRAM UTAMA
// =============================
int main() {
    StackCD rak; // Membuat objek stack

    // Menambahkan beberapa CD ke stack
    rak.push("GTA V");
    rak.push("FIFA 23");
    rak.push("The Witcher 3");
    rak.tampilkan(); // Menampilkan isi stack saat ini

    rak.pop();  // Menghapus CD teratas (The Witcher 3)
    rak.push("Elden Ring"); // Menambahkan CD baru
    rak.tampilkan(); // Menampilkan stack terbaru

    // Menghapus semua isi stack
    rak.pop();  // Menghapus Elden Ring
    rak.pop();  // Menghapus FIFA 23
    rak.pop();  // Menghapus GTA V
    rak.pop();  // Stack sudah kosong, tidak bisa hapus lagi

    return 0;
}
