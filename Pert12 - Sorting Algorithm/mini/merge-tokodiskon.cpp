// merge sort
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Struct barang
struct Item {
    string name;
    int price;
};

// Merge function
                                // left, mid, right
void merge(vector<Item>& items, int l, int m, int r) {
    int n1 = m - l + 1; // buat kiri
    int n2 = r - m; // kanan

    vector<Item> L(n1), R(n2); // misahin vektor

    for (int i = 0; i < n1; i++) L[i] = items[l + i];
    for (int j = 0; j < n2; j++) R[j] = items[m + 1 + j];

    int i = 0, j = 0, k = l; 

    // perbandingan sebelah kiri dan sebelah kanan
    while (i < n1 && j < n2) {
        if (L[i].price < R[j].price) {
            items[k++] = L[i++];
        } else {
            items[k++] = R[j++];
        }
    }

    while (i < n1) items[k++] = L[i++];
    while (j < n2) items[k++] = R[j++];
}

void mergeSort(vector<Item>& items, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2; // ini dia bagi 2 array nya
        mergeSort(items, l, m); // ini dia ngurutin dan nge gabung array nya (kiri)
        mergeSort(items, m + 1, r); // ini dia ngurutin dan nge gabung array ( kanan)
        merge(items, l, m, r); // kalau kanan sama kiri udah di urutin baru di gabung semua
    }
}

int main() {
    vector<Item> items = {
        // name, price
        {"Kaos", 75000},
        {"Celana", 120000},
        {"Jaket", 200000},
        {"Sepatu", 180000},
        {"Topi", 40000},
        {"Kacamata", 90000}
    };

    cout << "=== Game Toko Diskon ===\n";
    cout << "Daftar harga sebelum disortir:\n";
    for (auto& item : items) {
        cout << "- " << item.name << " : Rp " << item.price << endl;
    }

    mergeSort(items, 0, items.size() - 1);

    cout << "\nSetelah disorting dari termurah ke termahal:\n";
    for (auto& item : items) {
        cout << "- " << item.name << " : Rp " << item.price << endl;
    }

    cout << "\nPelanggan bertanya: Mana barang termurah di toko ini?\n";
    cout << "Jawaban: " << items[0].name << " seharga Rp " << items[0].price << "\n";

    return 0;
}
