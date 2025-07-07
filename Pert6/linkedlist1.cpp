#include <iostream>
using namespace std;

// Definisi node linked list
struct Node {
    int data;       // menyimpan nilai
    Node* next;     // menunjuk ke node berikutnya
};

Node* head = nullptr; // kepala dari linked list

// Fungsi untuk menambahkan node di akhir list
void tambah(int nilai) {
    Node* baru = new Node{nilai, nullptr};
    
    if (!head) {
        head = baru; // jika kosong, node baru jadi head
    } else {
        Node* temp = head;
        while (temp->next) {   // cari node terakhir
            temp = temp->next;
        }
        temp->next = baru;     // sambungkan di akhir
    }
}

// Fungsi untuk menampilkan isi linked list
void tampilkan() {
    Node* temp = head;
    cout << "Isi Linked List: ";
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Fungsi utama
int main() {
    tambah(10);
    tambah(20);
    tambah(30);

    tampilkan();  // Output: 10 -> 20 -> 30 -> NULL

    return 0;
}
