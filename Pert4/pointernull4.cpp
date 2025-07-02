#include <iostream>

using namespace std;

int main(){

    int* ptr = new int(50);

    cout << "Sebelum delete: " << endl;
    cout << "Nilai:  " << *ptr << endl;
    cout << "Alamat: " << ptr << endl;

    // menghapus memori
    delete ptr;

    cout << "Setelah delete (belum diset ke nullptr): " << endl;
    cout << "Alamat: " << ptr << endl;

    ptr = nullptr;

    cout <<"setelah set nullptr: " << endl;
    cout << "Alamat: "<< ptr << endl;

    return 0;
}