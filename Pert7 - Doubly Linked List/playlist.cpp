#include <iostream>
using namespace std;

struct Lagu {
    string judul;
    Lagu* prev;
    Lagu* next;
};

Lagu* head = nullptr;
Lagu* current = nullptr;

void tambahLagu(string judul) {
    Lagu* baru = new Lagu{judul, nullptr, nullptr};
    if (head == nullptr) {
        head = baru;
        current = baru;
    } else {
        Lagu* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = baru;
        baru->prev = temp;
    }
}

void putarSelanjutnya() {
    if (current && current->next) {
        current = current->next;
        cout << "Memutar: " << current->judul << endl;
    } else {
        cout << "Sudah di lagu terakhir.\n";
    }
}

void putarSebelumnya() {
    if (current && current->prev) {
        current = current->prev;
        cout << "Memutar: " << current->judul << endl;
    } else {
        cout << "Sudah di lagu pertama.\n";
    }
}

int main() {
    tambahLagu("Lagu A");
    tambahLagu("Lagu B");
    tambahLagu("Lagu C");
    tambahLagu("Lagu D");

    cout << "Memutar: " << current->judul << endl;
    putarSelanjutnya();
    putarSelanjutnya();
    putarSebelumnya();
    putarSebelumnya();
    putarSebelumnya();
    putarSelanjutnya();
    putarSelanjutnya();

    return 0;
}
