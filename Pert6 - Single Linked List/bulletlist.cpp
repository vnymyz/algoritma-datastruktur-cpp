#include <iostream>
using namespace std;

// Struct Bullet mewakili peluru
struct Bullet {
    int posisiX;      // posisi peluru di sumbu X
    Bullet* next;     // pointer ke peluru berikutnya (linked list)
};

// Head dari linked list peluru
Bullet* head = nullptr;

// Menambahkan peluru baru ke akhir linked list
void tambahPeluru(int x) {
    Bullet* baru = new Bullet{x, nullptr}; // buat node baru
    if (!head)                             // jika belum ada peluru
        head = baru;                       // peluru baru jadi head
    else {
        Bullet* temp = head;
        while (temp->next)                 // cari node terakhir
            temp = temp->next;
        temp->next = baru;                 // sambungkan ke peluru baru
    }
}

// Menggerakkan semua peluru ke kanan (+1 posisi X)
void gerakPeluru() {
    Bullet* temp = head;
    while (temp) {
        temp->posisiX += 1;                // geser posisi peluru
        temp = temp->next;                 // lanjut ke peluru berikutnya
    }
}

// Menghapus peluru yang keluar layar (posisiX > 10)
void hapusPeluruKeluarLayar() {
    // Hapus peluru dari depan jika lebih dari 10
    while (head && head->posisiX > 10) {
        Bullet* hapus = head;
        head = head->next;
        delete hapus;                      // hapus dari memori
    }

    // Cek peluru lain di tengah list
    Bullet* temp = head;
    while (temp && temp->next) {
        if (temp->next->posisiX > 10) {
            Bullet* hapus = temp->next;
            temp->next = hapus->next;     // lewati node yang dihapus
            delete hapus;
        } else {
            temp = temp->next;            // lanjut jika belum melebihi 10
        }
    }
}

// Menampilkan semua peluru dan posisinya
void tampilPeluru() {
    Bullet* temp = head;
    while (temp) {
        cout << "Peluru di x=" << temp->posisiX << endl;
        temp = temp->next;
    }
}

// Fungsi utama
int main() {
    int waktu = 0;
    while (waktu < 5) {                   // simulasi selama 5 detik/frame
        tambahPeluru(0);                 // setiap detik muncul 1 peluru baru
        gerakPeluru();                   // semua peluru bergerak ke kanan
        hapusPeluruKeluarLayar();        // hapus peluru yang keluar layar
        tampilPeluru();                  // tampilkan posisi semua peluru
        waktu++;                         // tambah waktu
        cout << "----\n";                // pemisah tampilan antar waktu
    }
    return 0;
}
