#include <iostream>     // Untuk input/output (cout, cin)
#include <queue>        // Untuk menggunakan struktur data queue STL
#include <string>       // Untuk menggunakan tipe data string
using namespace std;

// ==============================
// Struktur data Entity (untuk player dan monster)
// ==============================
struct Entity {
    string name;   // Nama karakter (Hero atau Goblin)
    int hp;        // Health Points (nyawa)
};

int main() {
    queue<Entity> turnQueue;  // Membuat queue untuk antrian giliran serang

    // ==============================
    // Inisialisasi entitas
    // ==============================
    Entity player = {"Hero", 100};    // Pemain dengan HP 100
    Entity monster = {"Goblin", 50};  // Monster dengan HP 50

    // Masukkan kedua entitas ke dalam queue (giliran)
    turnQueue.push(player);    // Hero giliran pertama
    turnQueue.push(monster);   // Goblin giliran kedua

    // ==============================
    // Pertarungan berlanjut selama dua-duanya masih hidup
    // ==============================
    while (player.hp > 0 && monster.hp > 0) {
        Entity current = turnQueue.front();  // Ambil yang sedang giliran
        turnQueue.pop();                     // Keluarkan dari queue

        // === Giliran Hero menyerang
        if (current.name == "Hero") {
            cout << current.name << " menyerang!\n";
            monster.hp = max(0, monster.hp - 20);
        }
        // === Giliran Monster menyerang
        else {
            cout << current.name << " menyerang!\n";
            player.hp = max(0, player.hp - 10);
        }

        // Tampilkan kondisi HP setelah serangan
        cout << "HP Hero: " << player.hp << ", HP Goblin: " << monster.hp << "\n";

        // Kembalikan karakter ke belakang queue untuk giliran berikutnya
        turnQueue.push(current);

        // Tunggu pengguna tekan Enter agar bisa lihat step-by-step
        cin.get();
    }

    // ==============================
    // Tampilkan hasil akhir
    // ==============================
    if (player.hp > 0)
        cout << "Hero menang!" << endl;
    else
        cout << "Goblin menang!" << endl;

    return 0;
}
