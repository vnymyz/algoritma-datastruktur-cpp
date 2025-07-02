#include <iostream>

using namespace std;

int main(){

    string name = "Bro";
    int umur = 21;

    // ceritanya ngebuat pointer pName
    // pName mengambil alamat atau address dari string name

    string *Name = &name;

    int *Umur = &umur;

    // memanggil pointer tersebut
    cout << *Name << endl;
    cout << *Umur;

    return 0;
    
}