// Constructor Default
#include <iostream>
using namespace std;

class Hello {
public:
    // Constructor default
    Hello() {
        cout << "Objek Hello dibuat!" << endl;
    }
};

int main() {
    Hello obj1; // otomatis memanggil constructor
    return 0;
}

// Saat objek obj1 dibuat, constructor akan otomatis dijalankan dan mencetak pesan.