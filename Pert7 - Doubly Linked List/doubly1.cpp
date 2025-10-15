#include <iostream>
using namespace std;

// Struktur node DLL
struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;

// Fungsi untuk menambahkan node ke depan
void tambahDepan(int nilai) {
    Node* baru = new Node();
    baru->data = nilai;
    baru->prev = nullptr;
    baru->next = head;

    if (head != nullptr)
        head->prev = baru;

    head = baru;
}

// Fungsi untuk mencetak list dari depan
void printList() {
    Node* temp = head;
    cout << "Isi list: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    tambahDepan(10);
    tambahDepan(20);
    tambahDepan(30);
    tambahDepan(40);
    tambahDepan(50);

    printList(); // Output: 30 20 10

    return 0;
}
