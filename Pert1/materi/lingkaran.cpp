#include <iostream>
using namespace std;

int main() {
    const float PI = 3.14; // konstanta PI
    float jariJari, luas;

    cout << "Masukkan jari-jari lingkaran: ";
    cin >> jariJari;

    luas = PI * jariJari * jariJari;

    cout << "Luas lingkaran adalah: " << luas << endl;

    return 0;
}