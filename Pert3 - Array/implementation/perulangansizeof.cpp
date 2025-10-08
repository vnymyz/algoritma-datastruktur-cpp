#include <iostream>

using namespace std;

int main(){
    int angka[] = {10, 20, 30, 40, 50};

    int panjangArray = sizeof(angka) / sizeof(*angka);

    for(int i = 0; i < panjangArray; i++){
        cout << "Elemen ke - " << i << ": " << angka[i] << endl;
    }

    return 0;

}
