#include <iostream> // Library standar untuk input dan output (cout, cin, dll)

using namespace std; // Agar tidak perlu menulis std:: sebelum fungsi standar

int main() {
    string mobil[] = {"Corvette", "Mustang", "Camry", "BMW", "Wuling", "Toyota"};

    mobil[2] = "Mitsubishi";

    cout << mobil[0] << '\n';
    cout << mobil[2] << '\n';
    cout << mobil[5] << '\n';

    cout << "print ukuran array: " << sizeof(mobil)/sizeof(*mobil);

    return 0; 
}

