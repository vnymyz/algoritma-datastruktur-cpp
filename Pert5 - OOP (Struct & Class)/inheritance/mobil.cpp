#include <iostream>
using namespace std;

// Base class (induk)
class Kendaraan {
public:
    string merk;

    void maju() {
        cout << merk << " sedang maju!" << endl;
    }
};

// Derived class (turunan)
class Mobil : public Kendaraan {
public:
    int jumlahPintu;

    void info() {
        cout << "Mobil " << merk << " punya " << jumlahPintu << " pintu." << endl;
    }
};

int main() {
    Mobil avanza;
    avanza.merk = "Toyota";
    avanza.jumlahPintu = 4;

    avanza.maju();     // dari class Kendaraan
    avanza.info();     // dari class Mobil

    return 0;
}
