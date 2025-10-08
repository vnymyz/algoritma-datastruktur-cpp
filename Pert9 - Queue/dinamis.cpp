#include <iostream>
#include <string>
using namespace std;

// =========================
// Struktur Node Queue
// =========================
struct Node {
    string name;
    bool isVIP;
    Node* next;
};

// Pointer ke depan dan belakang antrian
Node* front = nullptr;
Node* rear = nullptr;
int currentSize = 0;
int maxSize = 0;

// =========================
// Fungsi Enqueue (dengan prioritas VIP)
// =========================
void enqueue(string name, bool isVIP) {
    if (currentSize == maxSize) {
        cout << "Antrian penuh!\n";
        return;
    }

    Node* newNode = new Node{name, isVIP, nullptr};

    if (!front) {
        front = rear = newNode;
    } else if (isVIP) {
        // VIP langsung ke depan antrian
        newNode->next = front;
        front = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    currentSize++;
    cout << name << " masuk antrian (" << (isVIP ? "VIP" : "Reguler") << ")\n";
}

// =========================
// Fungsi Dequeue
// =========================
void dequeue() {
    if (!front) {
        cout << "Antrian kosong!\n";
        return;
    }

    Node* temp = front;
    front = front->next;
    cout << temp->name << " keluar dari antrian.\n";
    delete temp;
    currentSize--;

    if (!front) rear = nullptr; // Jika kosong semua
}

// =========================
// Fungsi Menampilkan Antrian
// =========================
void displayQueue() {
    if (!front) {
        cout << "Antrian kosong.\n";
        return;
    }

    cout << "Antrian saat ini:\n";
    Node* temp = front;
    int no = 1;
    while (temp) {
        cout << no++ << ". " << temp->name << " (" << (temp->isVIP ? "VIP" : "Reguler") << ")\n";
        temp = temp->next;
    }
}

// =========================
// Fungsi Utama
// =========================
int main() {
    cout << "Masukkan kapasitas maksimal antrian diskon game: ";
    cin >> maxSize;
    cin.ignore(); // buang newline

    int choice;
    do {
        cout << "\n--- Menu Antrian Diskon Game ---\n";
        cout << "1. Tambah orang ke antrian (enqueue)\n";
        cout << "2. Layani orang pertama (dequeue)\n";
        cout << "3. Tampilkan antrian\n";
        cout << "4. Keluar\n";
        cout << "Pilih: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string nama;
            char vipStatus;

            cout << "Nama orang: ";
            getline(cin, nama);
            cout << "Apakah VIP? (y/n): ";
            cin >> vipStatus;
            cin.ignore();

            enqueue(nama, (vipStatus == 'y' || vipStatus == 'Y'));
        } 
        else if (choice == 2) {
            dequeue();
        } 
        else if (choice == 3) {
            displayQueue();
        }

    } while (choice != 4);

    cout << "Program selesai.\n";
}