// selection sort
#include <iostream>
#include <string>
using namespace std;

const int ITEM_COUNT = 5;

struct Item {
    string name;
    int weight;
};

// Selection Sort (dari ringan ke berat)
void selectionSort(Item arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j].weight < arr[minIdx].weight) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swap(arr[i], arr[minIdx]);
        }
    }
}

void displayItems(Item arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << i + 1 << ". " << arr[i].name << " (" << arr[i].weight << "kg)" << endl;
    }
}

int main() {
    Item items[ITEM_COUNT] = {
        {"Batu", 10},
        {"Bola", 2},
        {"Laptop", 5},
        {"Buku", 3},
        {"Sepatu", 4}
    };

    Item sortedItems[ITEM_COUNT];
    copy(begin(items), end(items), begin(sortedItems));

    // Sort versi jawaban benar
    selectionSort(sortedItems, ITEM_COUNT);

    cout << "=== Urutkan Barang dari yang PALING RINGAN ke PALING BERAT ===\n";
    displayItems(items, ITEM_COUNT);

    int userOrder[ITEM_COUNT];
    cout << "\nMasukkan urutan nomor barang (dipisah spasi): ";
    for (int i = 0; i < ITEM_COUNT; ++i) {
        cin >> userOrder[i];
    }

    // Periksa jawaban
    bool correct = true;
    for (int i = 0; i < ITEM_COUNT; ++i) {
        if (items[userOrder[i] - 1].name != sortedItems[i].name) {
            correct = false;
            break;
        }
    }

    if (correct) {
        cout << "\n Jawaban Benar! Kamu berhasil mengurutkan barang dengan benar!" << endl;
    } else {
        cout << "\n Jawaban Salah. Urutan yang benar adalah:\n";
        displayItems(sortedItems, ITEM_COUNT);
    }

    return 0;
}
