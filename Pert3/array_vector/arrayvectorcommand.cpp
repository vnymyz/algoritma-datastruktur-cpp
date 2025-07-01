#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> angka;

    // 1. Menambahkan data
    angka.push_back(10);
    angka.push_back(20);
    angka.push_back(30);
    angka.push_back(40);

    cout << "Isi vector setelah push_back:\n";
    for (int i = 0; i < angka.size(); i++) {
        cout << angka[i] << " ";
    }
    cout << "\n";

    // 2. Menampilkan elemen depan dan belakang
    cout << "Elemen pertama (front): " << angka.front() << endl;
    cout << "Elemen terakhir (back): " << angka.back() << endl;

    // 3. Menghapus elemen terakhir
    angka.pop_back();
    cout << "Setelah pop_back (hapus elemen terakhir):\n";
    for (int i = 0; i < angka.size(); i++) {
        cout << angka[i] << " ";
    }
    cout << "\n";

    // 4. Mengakses dengan .at()
    cout << "Akses elemen ke-1 dengan .at(): " << angka.at(1) << endl;

    // 5. Mengecek ukuran vector
    cout << "Ukuran vector saat ini: " << angka.size() << endl;

    // 6. Menghapus semua isi vector
    angka.clear();
    cout << "Setelah clear(), apakah kosong? " << (angka.empty() ? "Ya" : "Tidak") << endl;

    return 0;
}
