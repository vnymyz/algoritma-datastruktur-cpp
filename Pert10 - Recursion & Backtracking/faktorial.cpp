// 5! = 5 × 4 × 3 × 2 × 1 = 120
// n! = n × (n-1) × (n-2) × ... × 1
#include <iostream>
using namespace std;

int faktorial(int n) {
    if (n == 0) return 1;           // base case
    else return n * faktorial(n - 1); // recursive case
}

int main() {
    int n;
    cout << "Masukkan bilangan bulat non-negatif: ";
    cin >> n;

    if (n < 0) {
        cout << "Faktorial hanya berlaku untuk bilangan >= 0." << endl;
    } else {
        cout << "Faktorial dari " << n << " adalah: " << faktorial(n) << endl;
    }

    return 0;
}
