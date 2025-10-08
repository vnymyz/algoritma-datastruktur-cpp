#include <iostream>
using namespace std;

int main() {
    int nilai;
    cout << "Masukkan nilai ujian: ";
    cin >> nilai;

    // Mengecek rentang nilai dan menampilkan hasil
    if (nilai >= 85) {
        cout << "Nilai Anda: A" << endl;
    } else if (nilai >= 70) {
        cout << "Nilai Anda: B" << endl;
    } else {
        cout << "Nilai Anda: C atau di bawahnya" << endl;
    }

    return 0;
}
