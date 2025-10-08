#include <iostream>
using namespace std;
                // start     step    stop
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // ditemukan di indeks ke-i
        }
    }
    return -1; // tidak ditemukan
}

int main() {
    int data[] = {5, 3, 7, 9, 1, 6};
    int size = sizeof(data)/sizeof(data[0]);
    int target = 10;

    int hasil = linearSearch(data, size, target);

    if (hasil != -1)
        cout << "Elemen ditemukan di indeks: " << hasil << endl;
    else
        cout << "Elemen tidak ditemukan" << endl;

    return 0;
}