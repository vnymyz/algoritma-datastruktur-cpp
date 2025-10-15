#include <iostream>
using namespace std;

struct Film {
    string judul;
    int tahun;
};

int main() {
    Film daftar[3];

    daftar[0] = {"Avengers", 2012};
    daftar[1] = {"Inception", 2010};
    daftar[2] = {"Interstellar", 2014};

    for (int i = 0; i < 3; i++) {
        cout << "Judul: " << daftar[i].judul << ", Tahun: " << daftar[i].tahun << endl;
    }

    return 0;
}
// Kita menggunakan array daftar[] untuk menyimpan banyak data Film.