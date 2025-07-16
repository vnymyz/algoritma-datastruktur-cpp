#include <iostream>   // Library untuk input-output (cout, cin, dll)
using namespace std;

#define MAX 5         // Ukuran maksimum queue (jumlah elemen maksimal)

int queue[MAX];       // Array untuk menyimpan elemen queue
int front = -1;       // Penunjuk elemen depan (pertama keluar)
int rear = -1;        // Penunjuk elemen belakang (terakhir masuk)


// ============================
// Fungsi untuk menambahkan data ke queue (enqueue)
// ============================
void enqueue(int value) {
    if (rear == MAX - 1) {
        // Jika rear sudah mencapai batas array, queue penuh
        cout << "Queue penuh!\n";
    } else {
        if (front == -1) 
            front = 0; // Jika queue awalnya kosong, atur front ke 0

        rear++;                 // Geser rear ke posisi selanjutnya
        queue[rear] = value;    // Masukkan nilai ke posisi rear
        cout << "Elemen " << value << " dimasukkan ke queue.\n";
    }
}


// ============================
// Fungsi untuk menghapus data dari queue (dequeue)
// ============================
void dequeue() {
    if (front == -1 || front > rear) {
        // Jika queue kosong (belum pernah ada data atau sudah semua dikeluarkan)
        cout << "Queue kosong!\n";
    } else {
        // Tampilkan elemen yang dihapus
        cout << "Elemen " << queue[front] << " dihapus dari queue.\n";
        front++;    // Geser front ke elemen berikutnya
    }
}


// ============================
// Fungsi untuk menampilkan isi queue
// ============================
void display() {
    if (front == -1 || front > rear) {
        // Jika queue kosong
        cout << "Queue kosong!\n";
    } else {
        cout << "Isi queue: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";   // Cetak elemen dari front ke rear
        }
        cout << endl;
    }
}


// ============================
// Fungsi utama (main program)
// ============================
int main() {
    enqueue(10);     // Tambah 10 ke queue
    enqueue(20);     // Tambah 20 ke queue
    enqueue(30);     // Tambah 30 ke queue
    display();       // Tampilkan isi queue → [10, 20, 30]

    dequeue();       // Hapus elemen pertama (10)
    display();       // Tampilkan isi queue → [20, 30]

    enqueue(40);     // Tambah 40
    enqueue(50);     // Tambah 50
    enqueue(60);     // Gagal karena queue sudah penuh (MAX = 5)
    display();       // Tampilkan isi akhir queue

    return 0;
}
