#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){

    int* angkaRahasia = new int;

    srand(time(0));
    *angkaRahasia = rand() % 10 + 1;

    int tebakan;
    int kesempatan = 5;

    cout << "Game tebak angka!\n";
    cout << "Tebak angka dari 1 - 10\n";
    cout << "Kamu punya " << kesempatan << " kesempatan.\n";

    while (kesempatan > 0){
        cout << "Tebakan kamu: ";
        cin >> tebakan;

        if(tebakan == *angkaRahasia){
            cout << "Hore tebakan anda benar\n";
            break;
        } else if (tebakan < *angkaRahasia){
            cout << "Terlalu kecil\n";
        } else {
            cout << "Terlalu Besar\n";
        }

        kesempatan--;

        if (kesempatan > 0){
            cout << "kesempatan tersisa: " << kesempatan << "\n\n";
        } else {
            cout << "Kesempatan Habis ! Angka yang benar adalah : " << *angkaRahasia << "\n";
        }
    }

    delete angkaRahasia;
    angkaRahasia =nullptr;

    cout << "Memori sudah dibersihkan!";
    return 0;
}