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
    int data[] = {1, 3, 5, 7, 9, 11, 13}; // Harus dalam kondisi terurut
    int size = sizeof(data)/sizeof(data[0]);
    int target = 9;

    int hasil = binarySearch(data, size, target);

    if (hasil != -1)
        cout << "Elemen ditemukan di indeks: " << hasil << endl;
    else
        cout << "Elemen tidak ditemukan" << endl;

    return 0;
}