#include <iostream>
using namespace std;

int main() {
    // Alokasikan memori secara dinamis untuk menyimpan satu nilai integer
    int* ptr = new int;

    // Isi nilai ke alamat memori tersebut
    *ptr = 10;

    // Tampilkan nilai yang disimpan melalui pointer
    cout << "Nilai: " << *ptr << endl;

    // Tampilkan alamat memori yang ditunjuk pointer
    cout << "Alamat memori: " << ptr << endl;

    // Bebaskan memori setelah selesai digunakan
    delete ptr;
    
    return 0;
}
