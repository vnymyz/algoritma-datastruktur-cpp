#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // != - 1
        }
    }
    return -1; // = -1
}

int main() {
    // start
    int n;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;

    int arr[n];
    // step
    cout << "Masukkan " << n << " elemen array:\n";
    for (int i = 0; i < n; i++) {
        cout << "Elemen ke-" << i << ": ";
        cin >> arr[i];
    }
    // stop
    int target;
    cout << "Masukkan nilai yang ingin dicari: ";
    cin >> target;

    int hasil = linearSearch(arr, n, target);

    if (hasil != -1)
        cout << "Elemen ditemukan di indeks: " << hasil << endl;
    else
        cout << "Elemen tidak ditemukan." << endl;

    return 0;
}