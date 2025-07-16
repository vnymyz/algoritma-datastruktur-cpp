# Pertemuan 9

## Queue (Array & Linked List) + Circular Queue + Implementasi dan Kasus Penggunaan

## 1. Pengantar queue

### 1.1 Apa itu queue ?

Queue (antrian) adalah struktur data linear yang mengikuti prinsip FIFO (First In First Out). Elemen pertama yang masuk akan menjadi elemen pertama yang keluar.

### 1.2 Analogi Sederhana

Bayangkan kamu sedang mengantri di kasir supermarket — orang pertama yang datang adalah yang pertama dilayani.

### 1.3 Perbedaan Stack VS Queue

| Fitur      | **Stack**                            | **Queue**                                                         |
| ---------- | ------------------------------------ | ----------------------------------------------------------------- |
| Prinsip    | LIFO (Last In First Out)             | FIFO (First In First Out)                                         |
| Arah kerja | Masuk dan keluar di **atas** (`top`) | Masuk dari **belakang** (`rear`), keluar dari **depan** (`front`) |
| Metode     | `push()` dan `pop()`                 | `enqueue()` dan `dequeue()`                                       |
| Visual     | Tumpukan piring                      | Antrian kasir atau tiket                                          |

### 1.4 Gambaran

#### Stack

```lua
        +-----+
TOP ->  | 30  |  <- terakhir masuk, pertama keluar (pop)
        +-----+
        | 20  |
        +-----+
        | 10  |  <- pertama masuk, terakhir keluar
        +-----+
```

#### Queue

```lua
FRONT                           REAR
  ↓                               ↓
+-----+  +-----+  +-----+
| 10  |  | 20  |  | 30  |
+-----+  +-----+  +-----+
   ↑                        ↑
 keluar pertama       masuk terakhir
```

## 2.Jenis Queue

### 2.1 Linear Queue (Menggunakan Array)

- Operasi: enqueue, dequeue

- Kelemahan: space tidak reusable setelah dequeue

### 2.2 Circular Queue (Array)

- Memanfaatkan kembali space dengan perhitungan modulus

- Cocok untuk memory yang terbatas (buffer, printer queue)

## 2.3 Queue menggunakan Linked List

- Dinamis, tidak dibatasi ukuran

- Tidak membuang space seperti array biasa

## 3. Struktur Umum Program Queue

Struktur Operasi Umum :

- enqueue(): Menambahkan elemen ke belakang

- dequeue(): Menghapus elemen dari depan

- isEmpty(): Mengecek apakah queue kosong

- isFull() (untuk array): Mengecek apakah penuh

- display(): Menampilkan isi queue

## 4. Implementasi Program C++

### 4.1 Linear Queue menggunakan Array

```cpp
#include <iostream>
using namespace std;

#define SIZE 5

class Queue {
    int items[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == SIZE - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue penuh!\n";
            return;
        }
        if (isEmpty()) front = 0;
        items[++rear] = element;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue kosong!\n";
            return;
        }
        cout << "Menghapus: " << items[front++] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue kosong!\n";
            return;
        }
        cout << "Queue: ";
        for (int i = front; i <= rear; i++)
            cout << items[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.display();
    q.dequeue();
    q.display();
}
```

### 4.2 Circular Queue

```cpp
#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
    int items[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue penuh!\n";
            return;
        }
        if (isEmpty()) front = 0;
        rear = (rear + 1) % SIZE;
        items[rear] = element;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue kosong!\n";
            return;
        }
        cout << "Menghapus: " << items[front] << endl;
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue kosong!\n";
            return;
        }
        cout << "Queue: ";
        int i = front;
        while (true) {
            cout << items[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display();
    q.dequeue();
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6); // akan putar ke awal
    q.display();
}
```

### 4.3 Queue menggunakan Linked List

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
    Node *front, *rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node{value, nullptr};
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue kosong!\n";
            return;
        }
        Node* temp = front;
        cout << "Menghapus: " << temp->data << endl;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete temp;
    }

    void display() {
        if (front == nullptr) {
            cout << "Queue kosong!\n";
            return;
        }
        Node* temp = front;
        cout << "Queue: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.display();
    q.dequeue();
    q.display();
}
```

## 5. Kasus nyata menggunakan Queue

- Sistem antrian bank

- Cetak dokumen (printer queue)

- Pengaturan giliran pada game

- Circular buffer untuk streaming/audio/video

## Kesimpulan

| Jenis Queue       | Kelebihan                   | Kekurangan                    |
| ----------------- | --------------------------- | ----------------------------- |
| Array Queue       | Mudah dipahami              | Tidak efisien setelah dequeue |
| Circular Queue    | Efisien dengan memori tetap | Agak kompleks implementasi    |
| Linked List Queue | Dinamis, efisien            | Perlu manajemen memori manual |
