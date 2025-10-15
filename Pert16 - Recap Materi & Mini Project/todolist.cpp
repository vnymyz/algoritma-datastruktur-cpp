#include <iostream>
#include <string>

using namespace std;

// Struktur Node untuk Single Linked List
struct Node {
    string task;
    Node* next;
};

// Fungsi untuk menambahkan task di akhir list
void insertTask(Node*& head, const string& newTask) {
    Node* newNode = new Node();
    newNode->task = newTask;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Task berhasil ditambahkan!\n";
}

// Fungsi untuk menghapus task berdasarkan nomor
void deleteTaskByNumber(Node*& head, int taskNumber) {
    if (head == nullptr) {
        cout << "List kosong!\n";
        return;
    }

    if (taskNumber < 1) {
        cout << "Nomor task tidak valid!\n";
        return;
    }

    Node* temp = head;

    // Jika task yang dihapus adalah head
    if (taskNumber == 1) {
        head = head->next;
        delete temp;
        cout << "Task berhasil dihapus!\n";
        return;
    }

    // Cari node sebelum node yang akan dihapus
    for (int i = 1; i < taskNumber - 1; i++) {
        if (temp->next == nullptr) {
            cout << "Nomor task tidak ditemukan!\n";
            return;
        }
        temp = temp->next;
    }

    Node* nodeToDelete = temp->next;
    if (nodeToDelete == nullptr) {
        cout << "Nomor task tidak ditemukan!\n";
        return;
    }

    temp->next = nodeToDelete->next;
    delete nodeToDelete;
    cout << "Task berhasil dihapus!\n";
}

// Fungsi menampilkan semua task dengan nomor
void displayTasks(Node* head) {
    if (head == nullptr) {
        cout << "Tidak ada task.\n";
        return;
    }

    cout << "\nDaftar Task:\n";
    Node* temp = head;
    int i = 1;
    while (temp != nullptr) {
        cout << i << ". " << temp->task << endl;
        temp = temp->next;
        i++;
    }
}

int main() {
    Node* head = nullptr;
    int choice;
    string task;

    do {
        cout << "\n=== To-Do List ===\n";
        cout << "1. Tambah Task\n";
        cout << "2. Hapus Task (pilih nomor)\n";
        cout << "3. Tampilkan Semua Task\n";
        cout << "4. Keluar\n";
        cout << "Pilihan: ";
        cin >> choice;
        cin.ignore(); // membersihkan newline

        switch (choice) {
            case 1:
                cout << "Masukkan task: ";
                getline(cin, task);
                insertTask(head, task);
                break;
            case 2:
                displayTasks(head); // tampilkan task supaya tahu nomornya
                int taskNumber;
                cout << "Masukkan nomor task yang akan dihapus: ";
                cin >> taskNumber;
                deleteTaskByNumber(head, taskNumber);
                break;
            case 3:
                displayTasks(head);
                break;
            case 4:
                cout << "Keluar program.\n";
                break;
            default:
                cout << "Pilihan salah, coba lagi.\n";
        }
    } while (choice != 4);

    // Bersihkan memori
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
