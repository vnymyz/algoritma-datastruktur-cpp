// quick sort
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Treasure {
    string name;
    int value;
};

// Quick Sort partition
int partition(vector<Treasure>& arr, int low, int high) {
    int pivot = arr[high].value;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        // untuk descending order
        if (arr[j].value > pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick Sort recursive
void quickSort(vector<Treasure>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    vector<Treasure> treasures = {
        {"Emas", 100000},
        {"Permata", 200000},
        {"Artefak Kuno", 150000},
        {"Koin Perak", 50000},
        {"Mahkota", 300000}
    };

    cout << "=== Game Pemburu Harta Karun ===\n";
    cout << "Daftar harta yang ditemukan:\n";
    for (auto& t : treasures) {
        cout << "- " << t.name << " (Nilai: Rp " << t.value << ")\n";
    }

    quickSort(treasures, 0, treasures.size() - 1);

    cout << "\nHarta setelah disortir dari termahal ke termurah:\n";
    for (auto& t : treasures) {
        cout << "- " << t.name << " (Nilai: Rp " << t.value << ")\n";
    }

    cout << "\nPilih harta paling berharga untuk dibawa pulang: ";
    cout << treasures[0].name << " senilai Rp " << treasures[0].value << "\n";

    return 0;
}
