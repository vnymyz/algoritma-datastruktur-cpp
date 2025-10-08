#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;
Node* current = nullptr; // pointer untuk navigasi

// Tambah node di akhir
void tambahData(int nilai) {
    Node* baru = new Node{nilai, nullptr, nullptr};

    if (head == nullptr) {
        head = baru;
        current = head; // posisi awal current
    } else {
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = baru;
        baru->prev = temp;
    }
}

// Menampilkan semua data di DLL
void tampilkanSemua() {
    cout << "\nIsi Linked List:\n";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Menampilkan posisi saat ini
void tampilkanSekarang() {
    if (current == nullptr) {
        cout << " Linked list kosong.\n";
        return;
    }

    cout << "\n📍 Posisi saat ini:\n";
    cout << "Prev: ";
    if (current->prev)
        cout << current->prev->data;
    else
        cout << "NULL";

    cout << " | Current: " << current->data << " | Next: ";
    if (current->next)
        cout << current->next->data;
    else
        cout << "NULL";
    cout << endl;
}

// Menu utama
int main() {
    int pilihan, nilai;
    char ulang;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampilkan Semua Data\n";
        cout << "3. Lihat Posisi Sekarang\n";
        cout << "4. Pindah ke Next\n";
        cout << "5. Pindah ke Prev\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                tambahData(nilai);
                break;
            case 2:
                tampilkanSemua();
                break;
            case 3:
                tampilkanSekarang();
                break;
            case 4:
                if (current && current->next) {
                    current = current->next;
                    tampilkanSekarang();
                } else {
                    cout << " Tidak ada data next.\n";
                }
                break;
            case 5:
                if (current && current->prev) {
                    current = current->prev;
                    tampilkanSekarang();
                } else {
                    cout << " Tidak ada data prev.\n";
                }
                break;
            case 0:
                cout << "Keluar...\n";
                break;
            default:
                cout << " Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}
