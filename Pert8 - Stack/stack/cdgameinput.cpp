#include <iostream>
#include <string>
using namespace std;

// ============================
// CLASS STACKCD
// ============================
class StackCD {
private:
    string cd[5];  // Array untuk menyimpan maksimal 5 judul CD
    int top;       // Menunjukkan posisi elemen paling atas

public:
    // Konstruktor: inisialisasi stack kosong
    StackCD() {
        top = -1;
    }

    // Fungsi untuk menambahkan CD ke stack (push)
    void push(string judul) {
        if (top >= 4) { // Cek apakah stack sudah penuh
            cout << "Tumpukan CD sudah penuh!\n";
            return;
        }
        cd[++top] = judul; // Tambah CD ke atas tumpukan
        cout << "CD \"" << judul << "\" berhasil ditaruh di atas tumpukan.\n";
    }

    // Fungsi untuk mengambil CD dari stack (pop)
    void pop() {
        if (top < 0) { // Cek apakah stack kosong
            cout << "Tidak ada CD yang bisa diambil!\n";
            return;
        }
        cout << "CD \"" << cd[top] << "\" telah diambil dari tumpukan.\n";
        top--;
    }

    // Fungsi untuk menampilkan isi stack
    void display() {
        cout << "\nIsi Tumpukan CD:\n";
        if (top < 0) {
            cout << "(Tumpukan kosong)\n";
            return;
        }

        // Tampilkan isi dari atas ke bawah
        for (int i = top; i >= 0; i--) {
            cout << "- " << cd[i];
            if (i == top) cout << " (paling atas)";
            cout << endl;
        }
        cout << endl;
    }
};

// ============================
// PROGRAM UTAMA
// ============================
int main() {
    StackCD rakCD;            // Objek stack
    int pilihan;              // Menyimpan pilihan menu user
    string judul;             // Menyimpan input judul CD

    do {
        // Tampilkan menu
        cout << "=== MENU STACK CD GAME ===\n";
        cout << "1. Tambah CD (Push)\n";
        cout << "2. Ambil CD Teratas (Pop)\n";
        cout << "3. Lihat Isi Tumpukan\n";
        cout << "4. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;
        cin.ignore(); // Membersihkan karakter newline dari input

        switch (pilihan) {
        case 1:
            // Tambah CD
            cout << "Masukkan judul CD: ";
            getline(cin, judul);
            rakCD.push(judul);
            break;

        case 2:
            // Ambil CD teratas
            rakCD.pop();
            break;

        case 3:
            // Tampilkan isi stack
            rakCD.display();
            break;

        case 4:
            // Keluar dari program
            cout << "Terima kasih! Program selesai.\n";
            break;

        default:
            // Penanganan jika input tidak sesuai
            cout << "Pilihan tidak valid. Coba lagi.\n";
        }

        cout << endl;

    } while (pilihan != 4); // Program akan berjalan terus sampai user memilih keluar

    return 0;
}
