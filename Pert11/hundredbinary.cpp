#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main() {
    const int SIZE = 100;
    int arr[SIZE];

    // Mengisi array dengan angka 1 sampai 100
    for (int i = 0; i < SIZE; i++) {
        arr[i] = i + 1;
    }

    int target;
    cout << "Masukkan nilai yang ingin dicari (1 - 100): ";
    cin >> target;

    int hasil = binarySearch(arr, SIZE, target);

    if (hasil != -1)
        cout << "Elemen ditemukan di indeks: " << hasil << endl;
    else
        cout << "Elemen tidak ditemukan." << endl;

    return 0;
}