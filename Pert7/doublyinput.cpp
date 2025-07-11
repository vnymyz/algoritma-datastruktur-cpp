#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;

// Fungsi untuk menambah node di akhir
void tambahAkhir(int nilai) {
    Node* baru = new Node();
    baru->data = nilai;
    baru->prev = nullptr;
    baru->next = nullptr;

    if (head == nullptr) {
        head = baru;
    } else {
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = baru;
        baru->prev = temp;
    }
}

// Fungsi untuk menampilkan semua data
void tampilkanSemua() {
    Node* temp = head;
    cout << "\n=== Semua Data DLL ===\n";
    while (temp != nullptr) {
        cout << "Prev: ";
        if (temp->prev != nullptr)
            cout << temp->prev->data;
        else
            cout << "NULL";

        cout << " | Data: " << temp->data << " | Next: ";
        if (temp->next != nullptr)
            cout << temp->next->data;
        else
            cout << "NULL";

        cout << endl;
        temp = temp->next;
    }
}

int main() {
    int jumlah, nilai;

    cout << "Berapa data yang ingin dimasukkan? ";
    cin >> jumlah;

    for (int i = 0; i < jumlah; i++) {
        cout << "Masukkan data ke-" << i + 1 << ": ";
        cin >> nilai;
        tambahAkhir(nilai);
    }

    tampilkanSemua();

    return 0;
}
