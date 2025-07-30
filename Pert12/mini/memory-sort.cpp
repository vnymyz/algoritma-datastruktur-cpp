// insertion sort
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

void insertionSort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {
    srand(time(0));
    vector<int> numbers;
    int n = 6;

    // Generate angka acak
    for (int i = 0; i < n; i++) {
        numbers.push_back(rand() % 100); // angka dari 0–99
    }

    cout << "=== Memory Sort Challenge ===\n";
    cout << "Ingat angka-angka berikut (ditampilkan selama 5 detik):\n";

    for (int num : numbers) {
        cout << num << " ";
    }
    cout << "\n";

    // Tunggu 5 detik
    this_thread::sleep_for(chrono::seconds(5));

    // Bersihkan layar (opsional: untuk Windows)
    system("CLS"); // pakai "clear" di Linux/Mac

    cout << "\nSekarang tuliskan kembali angka-angka tadi dalam urutan yang kamu ingat:\n";
    vector<int> userInput(n);
    for (int i = 0; i < n; i++) {
        cin >> userInput[i];
    }

    // Urutkan data aslinya untuk ditampilkan
    vector<int> sorted = numbers;
    insertionSort(sorted);

    cout << "\nAngka yang benar tadi:\n";
    for (int num : numbers) cout << num << " ";

    cout << "\n\nUrutan setelah diurutkan (Insertion Sort):\n";
    for (int num : sorted) cout << num << " ";

    // Bandingkan user input vs data asli
    int correct = 0;
    for (int i = 0; i < n; i++) {
        if (userInput[i] == numbers[i])
            correct++;
    }

    cout << "\n\nKamu mengingat dengan benar " << correct << " dari " << n << " angka.\n";

    return 0;
}
