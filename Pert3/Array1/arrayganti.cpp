#include <iostream>

using namespace std;

int main(){
    int angka[3] = {1, 2, 3};

    cout << "Sebelum diganti : \n";

    for (int angka : angka){
        cout << angka << " ";
    }
    cout << endl;

    angka[0] = 10;
    angka[1] = 24;
    angka[2] = 30;

    cout << "Setelah diganti : \n";
    
    for (int angka : angka){
        cout << angka << " ";
    }
    cout << endl;

    return 0;
}