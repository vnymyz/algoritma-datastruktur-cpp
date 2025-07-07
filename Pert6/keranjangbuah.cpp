#include <iostream>
using namespace std;

// Struktur Node untuk menyimpan buah
struct Node {
    string buah;
    Node* next;
};

Node* head = nullptr;

// Tambah buah ke belakang linked list
void tambahBuah(string nama) {
    Node* baru = new Node{nama, nullptr};
    if (!head) {
        head = baru;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = baru;
    }
    cout << " Buah '" << nama << "' ditambahkan ke keranjang!\n";
}

// Ambil buah dari depan linked list
void ambilBuah() {
    if (!head) {
        cout << " Keranjang kosong!\n";
        return;
    }
    Node* temp = head;
    cout << " Kamu mengambil buah: " << head->buah << endl;
    head = head->next;
    delete temp;
}

// Tampilkan semua buah di keranjang
void tampilkanKeranjang() {
    if (!head) {
        cout << " Keranjang kosong.\n";
        return;
    }
    Node* temp = head;
    cout << " Isi keranjang: ";
    while (temp) {
        cout << temp->buah;
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << " -> NULL\n";
}

int main() {
    int pilihan;
    string namaBuah;

    do {
        cout << "\n=== GAME KERANJANG BUAH ===\n";
        cout << "1. Tambah buah\n";
        cout << "2. Ambil buah\n";
        cout << "3. Lihat isi keranjang\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;
        cin.ignore();  // <--- penting untuk membersihkan newline sebelum getline

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama buah: ";
                getline(cin, namaBuah);  // <--- bisa baca "Buah Apel"
                tambahBuah(namaBuah);
                break;
            case 2:
                ambilBuah();
                break;
            case 3:
                tampilkanKeranjang();
                break;
            case 0:
                cout << " Terima kasih sudah bermain! \n";
                break;
            default:
                cout << " Pilihan tidak valid.\n";
        }

    } while (pilihan != 0);

    return 0;
}
