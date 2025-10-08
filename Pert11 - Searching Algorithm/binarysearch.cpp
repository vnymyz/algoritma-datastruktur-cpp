#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target) // dia nge cek nilai tengah
            return mid;
        else if (arr[mid] < target) // dia akan nge cek nilai kiri
            left = mid + 1;
        else // dia kana nge cek nilai kanan
            right = mid - 1;
    }

    return -1; // dia akan terus berjalan kalau tidak ketemu
}

int main() { // ascending A - Z
    int data[] = {1, 3, 5, 7, 9, 11, 13}; // Harus dalam kondisi terurut
    int size = sizeof(data)/sizeof(data[0]); // langkah n ( int n)
    int target = 20; // nilai yang dicari

    int hasil = binarySearch(data, size, target);

    if (hasil != -1)
        cout << "Elemen ditemukan di indeks: " << hasil << endl;
    else
        cout << "Elemen tidak ditemukan" << endl;

    return 0;
}