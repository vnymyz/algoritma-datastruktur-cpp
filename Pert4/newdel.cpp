#include <iostream>
using namespace std;

int main() {
    int* p = new int; // alokasi satu int
    *p = 100;

    cout << "Nilai yang dialokasikan: " << *p << endl;

    delete p; // penting! hapus memori

    return 0;
}
