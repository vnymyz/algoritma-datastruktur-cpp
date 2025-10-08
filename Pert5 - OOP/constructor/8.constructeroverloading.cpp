// Kamu bisa membuat lebih dari satu constructor dalam satu class 
// (namanya constructor overloading) — berguna agar fleksibel saat membuat objek.
#include <iostream>
using namespace std;

class Buku {
private:
    string judul;
    int halaman;

public:
    // Constructor default
    Buku() {
        judul = "Tanpa Judul";
        halaman = 0;
    }

    // Constructor dengan parameter
    Buku(string j, int h) {
        judul = j;
        halaman = h;
    }

    void info() {
        cout << "Judul: " << judul << ", Halaman: " << halaman << endl;
    }
};

int main() {
    Buku buku1; // Memanggil constructor default
    Buku buku2("C++ Dasar", 120); // Memanggil constructor dengan parameter

    buku1.info();
    buku2.info();
    return 0;
}
