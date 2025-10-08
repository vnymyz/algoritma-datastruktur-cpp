#include <iostream>
using namespace std;

// Definisi node linked list
struct node {
    int data;       // menyimpan nilai
    node* next;     // menunjuk ke node berikutnya
};

node* head = nullptr; // kepala dari linked list

// Fungsi untuk menambahkan node di akhir list
void tambah(int nilai) {
    node* baru = new node{nilai, nullptr};
    
    if (!head) {
        head = baru; // jika kosong, node baru jadi head
    } else {
        node* temp = head;
        while (temp->next) {   // cari node terakhir
            temp = temp->next;
        }
        temp->next = baru;     // sambungkan di akhir
    }
}

// Fungsi untuk menampilkan isi linked list
void tampilkan() {
    node* temp = head;
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
    tambah(40);
    tambah(50);

    tampilkan();  // Output: 10 -> 20 -> 30 -> NULL

    return 0;
}
