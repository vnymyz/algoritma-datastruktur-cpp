#include <iostream>
using namespace std;

// Struktur Node sebagai ruangan
struct Ruangan {
    string nama;
    string deskripsi;
    Ruangan* prev;
    Ruangan* next;
};

// Pointer ke ruangan pertama dan posisi player
Ruangan* head = nullptr;
Ruangan* player = nullptr;

// Tambah ruangan ke akhir list
void tambahRuangan(string nama, string deskripsi) {
    Ruangan* baru = new Ruangan{nama, deskripsi, nullptr, nullptr};
    if (head == nullptr) {
        head = baru;
        player = baru;
    } else {
        Ruangan* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = baru;
        baru->prev = temp;
    }
}

// Tampilkan ruangan sekarang
void tampilkanRuangan() {
    cout << "\nKamu berada di: " << player->nama << endl;
    cout << player->deskripsi << endl;
}

// Navigasi ke kanan
void jalanKanan() {
    if (player->next != nullptr) {
        player = player->next;
        tampilkanRuangan();
    } else {
        cout << "\n🚫 Tidak ada jalan ke kanan lagi!\n";
    }
}

// Navigasi ke kiri
void jalanKiri() {
    if (player->prev != nullptr) {
        player = player->prev;
        tampilkanRuangan();
    } else {
        cout << "\n🚫 Tidak ada jalan ke kiri lagi!\n";
    }
}

int main() {
    // Setup dungeon
    tambahRuangan("Gerbang", "Gerbang tua yang sudah berkarat.");
    tambahRuangan("Koridor", "Lorong panjang yang gelap dan lembap.");
    tambahRuangan("Ruang Senjata", "Terdapat banyak pedang dan tameng di dinding.");
    tambahRuangan("Ruang Rahasia", "Ruangan misterius dengan simbol sihir di lantai.");

    // Game loop
    char perintah;
    tampilkanRuangan();

    do {
        cout << "\nPerintah (a: kiri, d: kanan, q: keluar): ";
        cin >> perintah;

        switch (perintah) {
            case 'a': jalanKiri(); break;
            case 'd': jalanKanan(); break;
            case 'q': cout << "Keluar dari dungeon...\n"; break;
            default: cout << "❓ Perintah tidak dikenali\n";
        }
    } while (perintah != 'q');

    return 0;
}
