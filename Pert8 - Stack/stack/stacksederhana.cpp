// 0. Stack Sederhana – menggunakan array statik
#include <iostream>
using namespace std;

const int MAX = 5;        // Kapasitas maksimum stack
int stack[MAX];           // Array stack
int top = -1;             // Menunjukkan posisi elemen paling atas

// ==========================================================
// PUSH – Menambahkan elemen ke atas stack
// ==========================================================
void push(int data) {
    if (top >= MAX - 1) { // Jika top sudah mencapai batas
        cout << "Stack penuh!\n";
    } else {
        top++;
        stack[top] = data;
        cout << "- " << data << " ditambahkan ke stack.\n";
    }
}

// ==========================================================
// POP – Menghapus elemen paling atas dari stack
// ==========================================================
void pop() {
    if (top < 0) { // Stack kosong
        cout << "Stack kosong!\n";
    } else {
        cout << "- " << stack[top] << " dihapus dari stack.\n";
        top--;
    }
}

// ==========================================================
// PEEK – Melihat elemen paling atas dari stack
// ==========================================================
void peek() {
    if (top < 0) {
        cout << "Stack kosong, tidak ada elemen di atas.\n";
    } else {
        cout << "Elemen paling atas: " << stack[top] << endl;
    }
}

// ==========================================================
// isEmpty – Mengecek apakah stack sedang kosong
// ==========================================================
void isEmpty() {
    if (top < 0) {
        cout << "Stack sedang kosong.\n";
    } else {
        cout << "Stack tidak kosong, ada " << (top + 1) << " elemen.\n";
    }
}

// ==========================================================
// PROGRAM UTAMA
// ==========================================================
int main() {
    // Contoh pemakaian fungsi-fungsi stack
    isEmpty();        // Cek apakah kosong
    push(10);         // Tambah elemen 10
    push(20);         // Tambah elemen 20
    push(30);         // Tambah elemen 30
    peek();           // Lihat elemen paling atas (30)
    pop();            // Hapus elemen paling atas (30)
    peek();           // Lihat elemen paling atas (20)
    isEmpty();        // Stack tidak kosong
    pop();            // Hapus elemen (20)
    pop();            // Hapus elemen (10)
    isEmpty();        // Stack sekarang kosong

    return 0;
}
