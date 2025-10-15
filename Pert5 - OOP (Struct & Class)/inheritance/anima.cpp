// | Istilah     | Arti                                                           |
// | ----------- | -------------------------------------------------------------- |
// | Class Induk | Class yang diturunkan (misal: `Hewan`)                         |
// | Class Anak  | Class yang mewarisi (misal: `Kucing`)                          |
// | `public`    | Akses modifier agar member class induk tetap bisa diakses anak |
// | Reusable    | Kita tidak perlu menulis `makan()` lagi di class `Kucing`      |

#include <iostream>
using namespace std;

// Class Induk
class Hewan {
public:
    string nama;

    void makan() {
        cout << nama << " sedang makan." << endl;
    }
};

// Class Anak yang mewarisi dari Hewan
class Kucing : public Hewan {
public:
    void suara() {
        cout << nama << " mengeong: Meow~" << endl;
    }
};

int main() {
    // Membuat objek dari class Kucing
    Kucing kucing1;

    // Mengisi nama (diturunkan dari class Hewan)
    kucing1.nama = "Milo";

    // Memanggil method dari class Induk
    kucing1.makan();

    // Memanggil method dari class Anak
    kucing1.suara();

    return 0;
}
