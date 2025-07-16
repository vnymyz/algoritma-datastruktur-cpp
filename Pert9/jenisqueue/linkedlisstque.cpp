#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;

    // Enqueue 3 elemen
    Node* n1 = new Node{10, nullptr};
    front = rear = n1;

    Node* n2 = new Node{20, nullptr};
    rear->next = n2;
    rear = n2;

    Node* n3 = new Node{30, nullptr};
    rear->next = n3;
    rear = n3;

    // Dequeue (hapus elemen depan)
    Node* temp = front;
    front = front->next;
    delete temp;

    // Tampilkan queue
    cout << "Linked List Queue: ";
    Node* current = front;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}
