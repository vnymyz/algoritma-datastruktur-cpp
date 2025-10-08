#include <iostream>
using namespace std;

// Struct Node untuk merepresentasikan elemen dalam linked list
struct Node {
    int data;       // menyimpan nilai data
    Node* next;     // pointer ke node berikutnya
};

// Fungsi untuk menambahkan node di awal linked list
void insertDepan(Node*& head, int data) {
    Node* newNode = new Node{data, head}; // buat node baru dan sambungkan ke head
    head = newNode;                       // jadikan node baru sebagai head
}

// Fungsi untuk menambahkan node di akhir linked list
void insertBelakang(Node*& head, int data) {
    Node* newNode = new Node{data, nullptr}; // buat node baru
    if (head == nullptr) {
        head = newNode;                      // jika kosong, jadi head
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {      // cari node terakhir
            temp = temp->next;
        }
        temp->next = newNode;                // sambungkan di akhir
    }
}

// Fungsi untuk menghapus node dari depan linked list
void deleteDepan(Node*& head) {
    if (head != nullptr) {
        Node* temp = head;
        head = head->next;       // pindahkan head ke node berikutnya
        delete temp;             // hapus node lama
    }
}

// Fungsi untuk menghapus node dari belakang linked list
void deleteBelakang(Node*& head) {
    if (head == nullptr) return;           // jika list kosong
    if (head->next == nullptr) {           // jika hanya 1 node
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next->next != nullptr) {  // cari node sebelum terakhir
        temp = temp->next;
    }
    delete temp->next;                     // hapus node terakhir
    temp->next = nullptr;                  // set pointer akhir ke null
}

// Fungsi untuk menampilkan isi linked list
void tampilkanList(Node* head) {
    cout << "Isi Linked List: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";      // tampilkan data
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Fungsi utama
int main() {
    Node* head = nullptr;     // inisialisasi linked list kosong
    int pilihan, angka;

    // Menu interaktif
    do {
        cout << "\n=== Menu Linked List ===" << endl;
        cout << "1. Insert di depan\n";
        cout << "2. Insert di belakang\n";
        cout << "3. Delete dari depan\n";
        cout << "4. Delete dari belakang\n";
        cout << "5. Tampilkan list\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan angka: ";
                cin >> angka;
                insertDepan(head, angka);
                break;
            case 2:
                cout << "Masukkan angka: ";
                cin >> angka;
                insertBelakang(head, angka);
                break;
            case 3:
                deleteDepan(head);
                cout << "Node depan dihapus.\n";
                break;
            case 4:
                deleteBelakang(head);
                cout << "Node belakang dihapus.\n";
                break;
            case 5:
                tampilkanList(head);
                break;
            case 0:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 0);  // ulangi selama tidak memilih keluar

    return 0;
}
