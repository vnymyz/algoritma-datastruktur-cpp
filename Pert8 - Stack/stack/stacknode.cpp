/* ===========================================================
 * Stack Linked List – Tumpukan CD Dinamis
 * -----------------------------------------------------------
 * • Kapasitas dapat ditentukan pengguna (0 = tanpa batas).
 * • Operasi: push, pop, display, exit.
 * • Validasi:
 *   - Input numerik dibersihkan dengan cin.ignore().
 *   - Judul CD tidak boleh kosong.
 *   - Size tidak bertambah jika push gagal.
 * =========================================================== */

#include <iostream>
#include <string>
#include <limits>
using namespace std;

// ===========================================================
// KELAS StackCD (implementasi linked list)
// ===========================================================
class StackCD {
private:
    // Struktur node untuk menyimpan judul CD dan pointer ke node berikutnya
    struct Node {
        string title;
        Node*  next;
        Node(const string& t, Node* n = nullptr) : title(t), next(n) {}
    };

    Node* top;      // Pointer ke node paling atas
    int   size;     // Jumlah elemen saat ini
    int   capacity; // Kapasitas maksimum (0 = tanpa batas)

public:
    // Konstruktor: inisialisasi stack kosong
    StackCD(int maxCap = 0) : top(nullptr), size(0), capacity(maxCap) {}

    // Destruktor: hapus semua node agar tidak ada memory leak
    ~StackCD() {
        while (top) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    // -------------------------------------------------------
    // PUSH – menambahkan judul CD ke puncak stack
    // -------------------------------------------------------
    void push(const string& title) {
        // Cek kapasitas
        if (capacity != 0 && size >= capacity) {
            cout << "Tumpukan penuh! Maksimal " << capacity << " CD.\n";
            return;
        }
        // Cek judul kosong
        if (title.empty()) {
            cout << "Judul CD tidak boleh kosong.\n";
            return;
        }
        // Buat node baru di puncak
        top = new Node(title, top);
        ++size;
        cout << "CD \"" << title << "\" ditambahkan (Total: " << size << ").\n";
    }

    // -------------------------------------------------------
    // POP – mengambil CD teratas dari stack
    // -------------------------------------------------------
    void pop() {
        if (isEmpty()) {
            cout << "Tumpukan kosong! Tidak ada CD yang bisa diambil.\n";
            return;
        }
        Node* temp = top;
        cout << "CD \"" << top->title << "\" diambil.\n";
        top = top->next;
        delete temp;
        --size;
    }

    // -------------------------------------------------------
    // DISPLAY – menampilkan seluruh isi stack
    // -------------------------------------------------------
    void display() const {
        cout << "\nIsi Tumpukan CD (" << size
             << (capacity ? "/" + to_string(capacity) : "") << "):\n";
        if (isEmpty()) {
            cout << "(kosong)\n\n";
            return;
        }
        for (Node* cur = top; cur; cur = cur->next) {
            cout << "- " << cur->title;
            if (cur == top) cout << "  <-- paling atas";
            cout << '\n';
        }
        cout << '\n';
    }

    // -------------------------------------------------------
    // isEmpty – mengecek apakah stack kosong
    // -------------------------------------------------------
    bool isEmpty() const { return top == nullptr; }
};

// ===========================================================
// PROGRAM UTAMA
// ===========================================================
int main() {
    int maxCap;
    cout << "Masukkan kapasitas maksimum tumpukan CD (0 = tanpa batas): ";
    cin  >> maxCap;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // hapus newline

    StackCD rak(maxCap); // Membuat objek stack dengan kapasitas user
    int    menu;
    string judul;

    do {
        // Menu sederhana
        cout << "\n=== MENU STACK CD GAME ===\n"
             << "1. Tambah CD (Push)\n"
             << "2. Ambil CD Teratas (Pop)\n"
             << "3. Lihat Isi Tumpukan\n"
             << "4. Keluar\n"
             << "Pilihan Anda: ";
        if (!(cin >> menu)) {                         // Validasi input numerik
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input harus angka!\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // hapus newline

        switch (menu) {
            case 1: // PUSH
                cout << "Judul CD: ";
                getline(cin, judul);
                rak.push(judul);
                break;

            case 2: // POP
                rak.pop();
                break;

            case 3: // DISPLAY
                rak.display();
                break;

            case 4: // EXIT
                cout << "Terima kasih! Program selesai.\n";
                break;

            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (menu != 4);

    return 0;
}
