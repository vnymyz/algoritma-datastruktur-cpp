#include <iostream>
using namespace std;

int main() {
    int queue[5];
    int front = -1, rear = -1;

    // Enqueue
    rear++; queue[rear] = 10;
    rear++; queue[rear] = 20;
    rear++; queue[rear] = 30;
    if (front == -1) front = 0;

    // Tampilkan queue
    cout << "Linear Queue: ";
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;

    // Dequeue (menghapus 1 elemen dari depan)
    front++;

    // Tampilkan setelah dequeue
    cout << "Setelah dequeue: ";
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;

    return 0;
}
