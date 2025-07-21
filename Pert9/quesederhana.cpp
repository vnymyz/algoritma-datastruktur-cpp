#include <iostream>    // Mengimpor library standar untuk input/output
using namespace std;

int main() {
    int queue[5];       // Membuat array queue dengan kapasitas 3 elemen
    int front = 0;      // Menunjukkan posisi elemen pertama (antrian depan)
    int rear = 0;       // Menunjukkan posisi elemen setelah elemen terakhir (ekor queue)

    // ========================
    // Enqueue (menambahkan elemen ke queue)
    // ========================
    queue[rear++] = 10;   // Tambah 10 ke queue, rear jadi 1
    queue[rear++] = 20;   // Tambah 20 ke queue, rear jadi 2
    queue[rear++] = 30;
    queue[rear++] = 40;
    queue[rear++] = 50;   

    // ========================
    // Menampilkan isi queue
    // ========================
    cout << "Isi queue: ";
    for (int i = front; i < rear; i++) {
        cout << queue[i] << " ";    // Cetak dari front sampai sebelum rear
    }
    cout << endl;

    // ========================
    // Dequeue (menghapus 1 elemen dari depan queue)
    // ========================
    front++;
    front++; 
    front++; 
    
    // ========================
    // Tampilkan isi queue setelah dequeue
    // ========================
    cout << "Setelah 1x dequeue: ";
    for (int i = front; i < rear; i++) {
        cout << queue[i] << " ";   // Cetak dari elemen ke-2 (20) hingga terakhir
    }
    cout << endl;

    return 0;
}

