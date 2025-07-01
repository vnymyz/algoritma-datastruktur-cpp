#include <iostream>

using namespace std;

int faktorial(int n) {
    if (n == 0 || n == 1){
        return 1;
    } else {
        return n * faktorial(n-1);
    }
}

int main(){
    int angka;
    cout << "Masukkan Angka: ";
    cin >> angka;

    int hasil = faktorial(angka);
    cout << "faktorial dari " << angka << " adalah " << hasil << endl;

    return 0;
}