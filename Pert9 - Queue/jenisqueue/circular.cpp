#include <iostream>
using namespace std;

int main() {
    int size = 5;
    int queue[5];
    int front = -1, rear = -1;

    // Enqueue 3 elemen
    front = rear = 0; queue[rear] = 10;
    rear = (rear + 1) % size; queue[rear] = 20;
    rear = (rear + 1) % size; queue[rear] = 30;

    // Dequeue 1 elemen
    front = (front + 1) % size;

    // Enqueue lagi (akan mengisi dari awal jika ada space)
    rear = (rear + 1) % size; queue[rear] = 40;

    // Tampilkan isi queue (tidak urut di memori)
    cout << "Circular Queue: ";
    int i = front;
    do {
        cout << queue[i] << " ";
        i = (i + 1) % size;
    } while (i != (rear + 1) % size);
    cout << endl;

    return 0;
}
