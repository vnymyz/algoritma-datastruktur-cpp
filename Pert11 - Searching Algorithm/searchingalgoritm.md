# Pertemuan 11

# Searching Algorithms (Linear & Binary Search)

# Tujuan Belajar

- Memahami konsep searching dalam array

- Mengimplementasikan Linear Search dan Binary Search

- Menganalisis kompleksitas waktu (Time Complexity)

## 1. Konsep Dasar Searching

Searching (pencarian) adalah proses menemukan elemen tertentu (disebut target) di dalam kumpulan data (biasanya array atau list).

## 2. Linear Search

Adalah metode pencarian sederhana di mana setiap elemen dalam array diperiksa satu per satu dari awal hingga akhir sampai elemen yang dicari ditemukan.

Linear search mencocokkan elemen satu per satu dari awal hingga akhir. Cocok digunakan untuk :

- Data kecil

- Data belum terurut

```css
Cari 9 dalam [5, 3, 7, 9, 1, 6]
Cek satu per satu → Ketemu di indeks ke-3
```

### Time Complexity

Time Complexity adalah cara untuk mengukur berapa lama waktu yang dibutuhkan algoritma untuk menyelesaikan tugasnya berdasarkan ukuran input (biasanya n).

- Worst Case: O(n) artinya target ditemukan di elemen terakhir atau tidak ditemukan sama sekali

```cpp
data[] = {3, 5, 7, 9}
target = 9  // Ditemukan di indeks ke-3 → butuh 4 langkah (n = 4)
```

atau

```cpp
data[] = {3, 5, 7, 9}
target = 11  // Tidak ada → harus cek semua → tetap 4 langkah
```

Semakin besar n, semakin banyak elemen yang harus dicek.

- Best Case: O(1) artinya target langsung ditemukan di elemen pertama, contohnya

```cpp
data[] = {9, 3, 5, 7}
target = 9
```

```cpp
#include <iostream>
using namespace std;

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
    int target = 9;

    int hasil = linearSearch(data, size, target);

    if (hasil != -1)
        cout << "Elemen ditemukan di indeks: " << hasil << endl;
    else
        cout << "Elemen tidak ditemukan" << endl;

    return 0;
}
```

### Penjelasan kode :

#### Fungsi Linear Search

| Baris Kode                                       | Penjelasan                                                                |
| ------------------------------------------------ | ------------------------------------------------------------------------- |
| `int linearSearch(int arr[], int n, int target)` | Fungsi untuk mencari `target` dalam array `arr[]` berukuran `n`.          |
| `for (int i = 0; i < n; i++)`                    | Melakukan loop dari indeks ke-0 sampai ke-n-1.                            |
| `if (arr[i] == target)`                          | Mengecek apakah elemen saat ini sama dengan target.                       |
| `return i;`                                      | Jika ditemukan, kembalikan indeks ke-i tempat target berada.              |
| `return -1;`                                     | Jika seluruh array telah dicek dan target tidak ditemukan, kembalikan -1. |

#### Fungsi Main

| Baris Kode                                      | Penjelasan                                                            |
| ----------------------------------------------- | --------------------------------------------------------------------- |
| `int data[] = {5, 3, 7, 9, 1, 6};`              | Array berisi elemen-elemen yang akan dicari.                          |
| `int size = sizeof(data)/sizeof(data[0]);`      | Menghitung jumlah elemen array `data[]` secara otomatis.              |
| `int target = 9;`                               | Menyatakan nilai yang ingin dicari dalam array.                       |
| `int hasil = linearSearch(data, size, target);` | Memanggil fungsi Linear Search untuk mencari `target` dalam `data[]`. |

#### Output

| Baris Kode                                                 | Penjelasan                                                         |
| ---------------------------------------------------------- | ------------------------------------------------------------------ |
| `if (hasil != -1)`                                         | Mengecek apakah hasil pencarian menemukan indeks valid (bukan -1). |
| `cout << "Elemen ditemukan di indeks: " << hasil << endl;` | Menampilkan indeks di mana target ditemukan.                       |
| `else`                                                     | Jika tidak ditemukan (`hasil == -1`)                               |
| `cout << "Elemen tidak ditemukan" << endl;`                | Tampilkan bahwa target tidak ditemukan.                            |

#### Ilustrasi Eksekusi

| Iterasi | `i` | `arr[i]` | `arr[i] == target` | Catatan             |
| ------- | --- | -------- | ------------------ | ------------------- |
| 1       | 0   | 5        | ❌                 | Lanjut cek indeks 1 |
| 2       | 1   | 3        | ❌                 | Lanjut cek indeks 2 |
| 3       | 2   | 7        | ❌                 | Lanjut cek indeks 3 |
| 4       | 3   | 9        | ✅                 | Return 3            |
|         |

Maka hasil output :

```yaml
Elemen ditemukan di indeks: 3
```

## 3. Binary Search

Adalah metode pencarian efisien pada data yang sudah terurut, dengan cara membagi dua bagian array setiap kali pencarian dilakukan.

Binary search hanya bisa digunakan jika data sudah terurut. Algoritma membagi array menjadi dua bagian dan memilih bagian yang mungkin berisi target. Binary Search itu ciri-cirinya :

- Wajib data sudah terurut.

- Jauh lebih cepat dari Linear Search pada dataset besar.

- Menggunakan prinsip divide and conquer.

### Time Complexity Binary Search

- Worst Case: O(log n) artinya setiap kali tidak ketemu, kita buang setengah dari data.

misal n = 16 elemen.

```cpp
Langkah 1: 16 elemen
Langkah 2: 8 elemen
Langkah 3: 4 elemen
Langkah 4: 2 elemen
Langkah 5: 1 elemen → selesai
```

- Best Case: O(1) artinya elemen langsung ditemukan pada langkah pertama.

```cpp
data[] = {10, 20, 30, 40, 50}
target = 30
```

Di langkah pertama, kita ambil elemen tengah:

- Index tengah: (0 + 4)/2 = 2

- data[2] = 30 → langsung ketemu!

- Hanya butuh 1 langkah → kompleksitas konstan → O(1)

### Apa itu Divide and Conquer ?

"Membagi permasalahan besar menjadi lebih kecil, menyelesaikan bagian kecilnya, lalu menggabungkan solusi untuk mendapatkan hasil akhir."

### Bagaimana Binary Search menggunakan prinsip ini?

Binary Search tidak langsung mengecek semua elemen, tapi:

1. Divide:

- Ambil elemen tengah dari array.

- Bandingkan elemen tengah dengan target.

2. Conquer:

- Jika target lebih kecil dari tengah → cari di bagian kiri (setengah array).

- Jika lebih besar → cari di bagian kanan.

3. Repeat (rekursif atau iteratif):

- Lakukan pembagian lagi pada bagian yang tersisa.

- Ulangi sampai ketemu atau tidak ada lagi elemen.

### Contoh singkat

Cari angka 42 dalam array [10, 20, 30, 40, 42, 50, 60]

```yaml
Langkah 1: Tengah = 40 → 42 > 40 → ke kanan
Langkah 2: Tengah = 50 → 42 < 50 → ke kiri
Langkah 3: Tengah = 42 → ✅ ditemukan!
```

Di setiap langkah, array dibagi dua. Itu artinya kita menyelesaikan masalah dalam potongan yang lebih kecil.

atau contoh lain :

```scss
Cari 74 dalam [1, 2, 3, ..., 100]
Mulai dari tengah (50) → 74 lebih besar → pindah ke kanan
→ Cek tengah lagi → dst, hingga ditemukan.
```

### Secara Singkat

- Binary Search menggunakan Divide and Conquer karena ia:

- Membagi array menjadi dua bagian (Divide),

- Mencari hanya di bagian yang sesuai (Conquer),

- Dan mengulangi proses sampai ketemu atau habis (Recursive/Iterative).

```cpp
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
```

Hubungannya dengan Efisiensi
Karena kita mengabaikan setengah data di tiap langkah, waktu pencarian jauh lebih cepat:

- Linear Search: O(n) → harus cek semua

- Binary Search: O(log n) → cukup ~7 kali cek untuk 100 elemen!

## 4. Perbandingan Linear VS Binary Search

| Aspek               | Linear Search                 | Binary Search                |
| ------------------- | ----------------------------- | ---------------------------- |
| Data harus terurut? | ❌ Tidak                      | ✅ Ya                        |
| Kecepatan           | Lambat (O(n))                 | Cepat (O(log n))             |
| Implementasi        | Sangat mudah                  | Agak lebih kompleks          |
| Kapan digunakan     | Data kecil atau tidak terurut | Data besar dan sudah terurut |

### Manfaat Linear & Binary Search

| Manfaat                               | Linear Search               | Binary Search                           |
| ------------------------------------- | --------------------------- | --------------------------------------- |
| Mudah diimplementasikan               | ✅ Sangat mudah             | ❌ Agak lebih kompleks                  |
| Cocok untuk data kecil                | ✅                          | ❌ Kurang optimal                       |
| Efisien untuk data besar              | ❌ Tidak efisien (O(n))     | ✅ Sangat cepat (O(log n))              |
| Tidak perlu sorting                   | ✅ Bisa langsung jalan      | ❌ Perlu data terurut                   |
| Bisa diterapkan di struktur data lain | ✅ Bisa juga di linked list | ❌ Hanya cocok untuk array yang terurut |

### Dalam Dunia Data / Backend / Developer (Kerja)

#### Linear Search:

- Cocok untuk pencarian cepat di array kecil atau struktur sederhana.

- Digunakan saat data belum disortir atau tidak bisa disortir.

#### Binary Search:

Digunakan dalam algoritma pencarian besar, misalnya:

- Database indexing

- Binary Search Tree (BST)

- Optimasi performa pencarian logika bisnis

### Dalam Dunia Game Development

| Contoh Situasi                                               | Jenis Search              | Penjelasan                                                  |
| ------------------------------------------------------------ | ------------------------- | ----------------------------------------------------------- |
| Cek apakah player punya item tertentu dalam inventori        | Linear Search             | Inventori biasanya list kecil, cocok dengan linear          |
| Mencari posisi musuh dalam array posisi yang sudah diurutkan | Binary Search             | Lebih efisien jika posisi disort terlebih dahulu            |
| Pathfinding / AI decision trees                              | Binary (atau tree) Search | Digunakan untuk optimasi keputusan NPC atau AI              |
| Level loading / resource management                          | Binary Search             | Untuk mempercepat akses file besar atau struktur index game |

## 5. Latihan

### Soal 1 (Linear Search dengan Input User)

Buatlah program C++ Linear Search yang:

- Meminta pengguna memasukkan banyak elemen array.

- Meminta pengguna mengisi elemen-elemen array.

- Meminta pengguna memasukkan nilai yang ingin dicari.

- Menggunakan Linear Search untuk mencari nilai tersebut.

- Menampilkan hasil indeks jika ditemukan, atau pesan jika tidak ditemukan.

```cpp
#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;

    int arr[n];

    cout << "Masukkan " << n << " elemen array:\n";
    for (int i = 0; i < n; i++) {
        cout << "Elemen ke-" << i << ": ";
        cin >> arr[i];
    }

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
```

### Penjelasan

#### Bagaimana cara kerja nya ?

Linear Search mengecek satu per satu dari elemen pertama hingga terakhir.

- Jika ditemukan → return indeks.

- Jika tidak → return -1.

Misal kita melakukan input :

```yaml
Jumlah elemen: 6
Isi array: [5, 3, 7, 9, 1, 6]
Target: 9
```

Visualisasi :

```makefile
Index:      0   1   2   3   4   5
Array:     [5] [3] [7] [9] [1] [6]
            ↑   ↑   ↑   ↑
Step:      ❌  ❌ ❌  ✅ ← ditemukan!
```

- Loop dimulai dari i = 0

- Periksa arr[0] = 5 → ❌

- Periksa arr[1] = 3 → ❌

- Periksa arr[2] = 7 → ❌

- Periksa arr[3] = 9 → ✅

- Return 3

### Soal 2 (Binary Search dengan Array 100 Elemen)

Buatlah program C++ yang:

- Membuat array terurut berisi 100 elemen (misal: 1 sampai 100).

- Meminta pengguna memasukkan nilai yang ingin dicari.

- Menggunakan Binary Search untuk mencari nilai tersebut.

- Menampilkan indeks elemen jika ditemukan, atau pesan jika tidak ditemukan.

```cpp
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
```

### Cara Kerja

- Mulai dari tengah (mid), bandingkan dengan target.

- Jika target < mid, cari di kiri.

- Jika target > mid, cari di kanan.

- Ulangi sampai ditemukan atau left > right.

---

Misal :
Array: [1, 2, 3, ..., 100]

Target: 74

---

### Langkah Pencarian Binary Search

| Step | Left | Right | Mid | `arr[mid]` | Bandingkan | Arah selanjutnya |
| ---- | ---- | ----- | --- | ---------- | ---------- | ---------------- |
| 1    | 0    | 99    | 49  | 50         | 74 > 50    | ke kanan         |
| 2    | 50   | 99    | 74  | 75         | 74 < 75    | ke kiri          |
| 3    | 50   | 73    | 61  | 62         | 74 > 62    | ke kanan         |
| 4    | 62   | 73    | 67  | 68         | 74 > 68    | ke kanan         |
| 5    | 68   | 73    | 70  | 71         | 74 > 71    | ke kanan         |
| 6    | 71   | 73    | 72  | 73         | 74 > 73    | ke kanan         |
| 7    | 73   | 73    | 73  | 74         | ✅ cocok   | selesai          |

Secara Visual :

```less
Array (elemen ke-70 sampai 76):

Index:    70  71  72  73  74  75  76
Array:   [71][72][73][74][75][76][77]
                       ↑   ← ditemukan!
```

## Kesimpulan Visual

| Algoritma     | Visual                          | Ciri Khas                              |
| ------------- | ------------------------------- | -------------------------------------- |
| Linear Search | 🔍 ← ← ← ✅                     | Cek satu per satu dari kiri            |
| Binary Search | 🎯 Potong tengah → lebih sempit | Cek tengah, potong setengah kiri/kanan |
