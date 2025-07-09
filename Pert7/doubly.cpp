#include <iostream>
using namespace std;

// Struktur Node
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Pointer ke node pertama (head)
Node* head = nullptr;

// Fungsi untuk menambahkan node di akhir
void insertAkhir(int nilai) {
    Node* baru = new Node();
    baru->data = nilai;
    baru->next = nullptr;

    // Jika list kosong
    if (head == nullptr) {
        baru->prev = nullptr;
        head = baru;
        return;
    }

    // Jika list sudah ada isinya
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = baru;
    baru->prev = temp;
}

// Fungsi untuk menampilkan data dari awal ke akhir
void printMaju() {
    cout << "Maju: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Fungsi untuk menampilkan data dari akhir ke awal
void printMundur() {
    cout << "Mundur: ";
    if (head == nullptr) return;

    Node* temp = head;
    // Geser ke node terakhir
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    // Cetak mundur
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    cout << "NULL\n";
}

int main() {
    insertAkhir(10);
    insertAkhir(20);
    insertAkhir(30);

    printMaju();   // Output: 10 <-> 20 <-> 30 <-> NULL
    printMundur(); // Output: 30 <-> 20 <-> 10 <-> NULL

    return 0;
}
