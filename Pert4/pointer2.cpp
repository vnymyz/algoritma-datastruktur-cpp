#include <iostream>
using namespace std;

int main() {
    int a = 5;
    int *p = &a;

    cout << "Alamat a: " << &a << endl;
    cout << "Alamat di pointer p: " << p << endl;
    cout << "Nilai dari pointer p (*p): " << *p << endl;

    return 0;
}
