// Struct dengan Member Function
#include <iostream>
using namespace std;

// function struct
struct Buku {
    string judul;
    int halaman;

    // method
    void tampilkanInfo() {
        cout << "Judul: " << judul << ", Halaman: " << halaman << endl;
    }
};

int main() {
    Buku buku1 = {"Belajar C++", 100};
    buku1.tampilkanInfo();

    return 0;
}

//  Fungsi tampilkanInfo() berada di dalam struct dan bisa dipanggil dari objek.

// Fungsi tersebut didefinisikan langsung di dalam struct, jadi disebut member function (fungsi anggota).

// C++ memperbolehkan struct memiliki function, seperti class.

// Method ini mengakses data dalam struct (judul dan halaman) dan menampilkannya.


