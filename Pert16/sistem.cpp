#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm> // untuk transform
using namespace std;

// ============================
// Struct Mahasiswa
// ============================
struct Mahasiswa {
    string nama;
    string nim;
    float nilai;
    Mahasiswa* next; // Pointer untuk Linked List
};

// Head Linked List
Mahasiswa* head = NULL;

// Stack untuk Undo
stack<Mahasiswa> undoStack;

// Queue untuk Antrian Registrasi
queue<Mahasiswa> antrian;

// ============================
// Fungsi Linked List
// ============================
void tambahMahasiswa(string nama, string nim, float nilai) {
    Mahasiswa* mhs = new Mahasiswa{nama, nim, nilai, NULL};

    if (!head) {
        head = mhs;
    } else {
        Mahasiswa* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = mhs;
    }
    cout << "Mahasiswa " << nama << " berhasil ditambahkan.\n";
}

void tampilMahasiswa() {
    if (!head) {
        cout << "Data kosong.\n";
        return;
    }
    Mahasiswa* temp = head;
    cout << "Daftar Mahasiswa:\n";
    while (temp) {
        cout << temp->nim << " - " << temp->nama << " - Nilai: " << temp->nilai << endl;
        temp = temp->next;
    }
}

void hapusMahasiswa(string nim) {
    if (!head) {
        cout << "Data kosong.\n";
        return;
    }
    Mahasiswa* temp = head;
    Mahasiswa* prev = NULL;

    while (temp && temp->nim != nim) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan.\n";
        return;
    }

    // Simpan ke Stack untuk Undo
    undoStack.push(*temp);

    if (!prev) { // hapus head
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    delete temp;

    cout << "Mahasiswa berhasil dihapus dan dapat di-undo.\n";
}

void undoHapus() {
    if (undoStack.empty()) {
        cout << "Tidak ada data untuk di-undo.\n";
        return;
    }
    Mahasiswa m = undoStack.top();
    undoStack.pop();
    tambahMahasiswa(m.nama, m.nim, m.nilai);
    cout << "Undo berhasil.\n";
}

// ============================
// Fungsi Queue
// ============================
void tambahAntrian(string nama, string nim, float nilai) {
    Mahasiswa m{nama, nim, nilai, NULL};
    antrian.push(m);
    cout << "Mahasiswa " << nama << " masuk antrian.\n";
}

void prosesAntrian() {
    if (antrian.empty()) {
        cout << "Tidak ada antrian.\n";
        return;
    }
    Mahasiswa m = antrian.front();
    antrian.pop();
    cout << "Memproses pendaftaran: " << m.nama << endl;
    tambahMahasiswa(m.nama, m.nim, m.nilai);
}

// ============================
// Searching (tidak case-sensitive & substring)
// ============================
string toLower(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

void cariLinear(string keyword) {
    Mahasiswa* temp = head;
    bool found = false;
    string keyLower = toLower(keyword);

    while (temp) {
        string namaLower = toLower(temp->nama);
        if (namaLower.find(keyLower) != string::npos) {
            cout << "Ditemukan: " << temp->nim << " - " << temp->nama << " - Nilai: " << temp->nilai << endl;
            found = true;
        }
        temp = temp->next;
    }

    if (!found) {
        cout << "Mahasiswa tidak ditemukan.\n";
    }
}

// ============================
// Menu Utama
// ============================
int main() {
    int pilihan;
    string nama, nim;
    float nilai;

    do {
        cout << "\n=== Sistem Manajemen Data Mahasiswa ===\n";
        cout << "1. Tambah Mahasiswa\n";
        cout << "2. Tampilkan Mahasiswa\n";
        cout << "3. Hapus Mahasiswa\n";
        cout << "4. Undo Hapus\n";
        cout << "5. Cari Mahasiswa (Linear, partial & case-insensitive)\n";
        cout << "6. Tambah Antrian Registrasi\n";
        cout << "7. Proses Antrian\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                cout << "Nama: "; getline(cin, nama);
                cout << "NIM: "; getline(cin, nim);
                cout << "Nilai: "; cin >> nilai;
                cin.ignore();
                tambahMahasiswa(nama, nim, nilai);
                break;
            case 2:
                tampilMahasiswa();
                break;
            case 3:
                cout << "NIM yang akan dihapus: "; getline(cin, nim);
                hapusMahasiswa(nim);
                break;
            case 4:
                undoHapus();
                break;
            case 5:
                cout << "Masukkan nama atau sebagian nama: "; getline(cin, nama);
                cariLinear(nama);
                break;
            case 6:
                cout << "Nama: "; getline(cin, nama);
                cout << "NIM: "; getline(cin, nim);
                cout << "Nilai: "; cin >> nilai;
                cin.ignore();
                tambahAntrian(nama, nim, nilai);
                break;
            case 7:
                prosesAntrian();
                break;
            case 0:
                cout << "Keluar program.\n";
                break;
            default:
                cout << "Pilihan salah, coba lagi.\n";
        }
    } while (pilihan != 0);

    return 0;
}
