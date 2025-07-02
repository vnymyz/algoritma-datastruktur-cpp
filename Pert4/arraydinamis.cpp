#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah elemen array: ";
    cin >> n;  
    
    int* arr = new int[n];
   
    for (int i = 0; i < n; i++) {
        cout << "Masukkan elemen ke-" << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "Isi array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Bebaskan memori array dari heap
    delete[] arr;

    cout << "Setelah delete aja: \n";
    cout << "Alamat Pointer : " << arr << endl;

    arr = nullptr;

    cout << "Setelah set nullptr, alamatnya : " << arr;

    return 0;
}
