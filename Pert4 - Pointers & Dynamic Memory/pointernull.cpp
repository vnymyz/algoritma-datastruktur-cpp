#include <iostream>
using namespace std;

int main() {

    int *pointer = nullptr;
    // int x =123;

    // pointer = &x;

    if(pointer == nullptr){
        cout << "alamat belum dikasih\n";
    }
    else {
        cout << "alamat sudah dikasih\n";
    }

    return 0;
}
