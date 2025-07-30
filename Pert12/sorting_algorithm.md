# Pertemuan 12

# Sorting Algorithm

### Apa saja yang dipelajari ?

1. Bubble Sort

2. Selection Sort

3. Insertion Sort

4. Merge Sort

5. Quick Sort

### Sorting itu apa ?

- Proses menyusun elemen dalam urutan tertentu (naik/turun)

- Tujuan dari sorting adalah efisiensi pencarian, analisis data, visualisasi.

- Klasifikasi:
  - Comparison-based : Bubble, Selection, Insertion, Merge, Quick.
  - Non-comparison: Counting, Radix (tidak dibahas).
- Kriteria :

  - Time complexity (worst/best/avg)
  - Space complexity
  - Stable vs Unstable

### 1. Bubble Sort

Bubble sort ini cara kerjanya adalah membandingkan nilai atau elemen yang bersebelahan.

Dia akan menukar nilai tersebut jika urutan nya salah.

Diulang hingga tidak ada lagi namanya pertukaran atau swapped.

Cocok untuk: edukasi, visualisasi dasar sorting.

#### Visual

![Bubble Sort](https://upload.wikimedia.org/wikipedia/commons/c/c8/Bubble-sort-example-300px.gif)

#### Kompleksitas Buruk

- O(n²) → artinya untuk data sebanyak n, waktu yang dibutuhkan akan meningkat sangat cepat seiring pertambahan n.

- Setiap elemen bisa dibandingkan dengan semua elemen lainnya.

#### Penggunaan Nyata

- Jarang digunakan di industri, hanya untuk belajar dan demo animasi sorting.

- Dalam game: dipakai untuk edukasi atau simulasi visual sederhana saja.

#### Ciri khas

- Sederhana tapi lambat

- Kompleksitas waktu terburuk: O(n²)

- Cocok untuk belajar dasar sorting

```cpp
#include <iostream>

using namespace std;

void bubble_sort(int a[], int length)
{
    bool swapped;
    int i = 0;
    do
    {
        swapped = false;
        for (int j = 0; j < length - 1 - i; j++)
        {
            // semisal j lebih gede dari element sebelah kanannya
            // bisa ascending > bisa descending <
            if (a[j] > a[j + 1])
            // if (a[j] < a[j + 1])
            {
                // maka di swap angka tersebut
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = true;
            }
        }
        i++;
    } while (swapped);
}

int main(){
    int a[] = {4, 1, 5, 8, 9, 0, 2, 7, 3, 6};

    int length = 10;

    // Memanggil function void
    bubble_sort(a, length);

    for (int i = 0; i < length; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl << endl;

    return 0;
}

```

### 2. Selection Sort

Selection sort berarti dia menyeleksi angka atau array dengan menentukan value atau nilai yang paling kecil dan menempatkan ke posisi yang benar.

Tidak perlu banyak swap jika bandingkan banyak tapi tukar sedikit.

Temukan elemen terkecil, lalu tukar dengan elemen pertama.

Lanjutkan dari indeks berikutnya → cari elemen terkecil lagi → tukar.

#### Kompleksitas Buruk

- O(n²) → tetap butuh membandingkan seluruh elemen pada setiap iterasi.
- Tidak efisien untuk dataset besar.

#### Penggunaan Nyata

- Berguna di lingkungan resource terbatas, seperti sistem embedded.

- Dalam game: bisa dipakai di game dengan sorting inventory yang kecil, misalnya daftar item pemain.

#### Ciri Khas

- Jumlah pertukaran sedikit

- Tetap lambat karena tetap membandingkan semua pasangan

- Kompleksitas waktu terburuk: O(n²)

- Tidak stabil (urutan sama bisa berubah)

```cpp
#include <iostream>

using namespace std;

// membuat function selection sort
void selection_sort(int a[], int length)
{
    for (int i = 0; i < (length - 1); i++) // indeks pertama yang kita lihat
    {
        int min_position = i; // cek nilai terkecil dan disimpen
        for (int j = i + 1; j < length; j++) // cek elemen sisanya
        {
            if (a[j] < a[min_position])
            {
                min_position = j;
            }
        }

        if (min_position != i)
        {
            int temp = a[i];
            a[i] = a[min_position];
            a[min_position] = temp;
        }
    }
}

// program utama nya
int main(){
    int a[] = {6, 5, 3, 2, 1, 4};
    int length = 6;

    selection_sort(a, length);

    for (int i = 0; i < length; i++ )
    {
        cout << "a[" << i << "] = " << a[i] << endl;
    }

    return 0;
}

```

#### Visual

```yaml
original_array: [6, 5, 3, 2, 1, 4]
steps:
  - step_1: [1, 5, 3, 2, 6, 4]
  - step_2: [1, 2, 3, 5, 6, 4]
  - step_3: [1, 2, 3, 5, 6, 4]
  - step_4: [1, 2, 3, 4, 6, 5]
  - step_5: [1, 2, 3, 4, 5, 6]
```

Penjelasan :

1. Angka yang belum diurut atau unsorted akan dimulai dari indeks pertama.

2. Misal dari indeks pertama berarti Angka 6 sisanya adalah angka2 yang belum diurutkan.

3. kita akan cari angka yang paling kecil untuk menentukan indeks pertama atau dari si 6

### 3. Insertion Sort

Menyisipkan elemen ke posisi yang tepat dalam array yang sudah tersortir sebagian. Ulangi untuk semua elemen.

Cocok untuk data kecil atau hampir tersortir.

Ambil elemen, bandingkan ke kiri sampai posisi tepat ditemukan

#### Kompleksitas Buruk

O(n²) → jika data dalam urutan terbalik, maka setiap elemen harus dibandingkan dengan semua sebelumnya.

#### Penggunaan Nyata

Banyak digunakan untuk:

- Optimasi akhir di Hybrid Sort (contoh: Timsort di Python)

- Autocompletion / suggestions (saat input hampir terurut)

- Dalam game, sorting input kecil di AI decision-making sederhana atau UI inventory list.

#### Ciri Khas

- Cepat untuk data kecil atau hampir terurut

- Kompleksitas waktu terburuk: O(n²)

- Stabil (urutan tetap jika nilainya sama)

#### Visual

![Insertion Sort](https://upload.wikimedia.org/wikipedia/commons/0/0f/Insertion-sort-example-300px.gif)

### 4. Merge Sort

Divide and Conquer :

- Bagi array menjadi dua bagian

- Sort masing-masing bagian secara rekursif

- Gabungkan dua bagian yang sudah terurut

Selalu O(n log n) stabil, cocok untuk data besar dan struktur data kompleks.

### Kompleksitas Buruk

- O(n log n) (masih baik!)

- Tapi perlu memori tambahan O(n) karena array dibagi-bagi.

#### Penggunaan Nyata

- Sorting file besar (external sort) seperti database dan big data

- Dalam game: pathfinding dengan banyak node, atau AI decision tree sorting.

- Digunakan dalam standard library seperti std::stable_sort di C++.

#### Ciri Khas

- Kompleksitas waktu selalu O(n log n)

- Butuh memori tambahan

- Stabil

- Cocok untuk data besar dan pengolahan file

#### Visualisasi

Array awal : [6, 5, 3, 2]

```less
Step 1: Bagi menjadi dua bagian
[6, 5]        [3, 2]

Step 2: Bagi lagi hingga masing-masing 1 elemen
[6] [5]       [3] [2]

Step 3: Urutkan dan gabungkan
[5, 6]        [2, 3]

Step 4: Gabungkan final (merge)
      [2, 3, 5, 6]
```

Proses rekursif :

```sql
mergeSort([6,5,3,2])
├─ mergeSort([6,5])
│  ├─ mergeSort([6])
│  └─ mergeSort([5])
│  → merge([6], [5]) = [5,6]
├─ mergeSort([3,2])
│  ├─ mergeSort([3])
│  └─ mergeSort([2])
│  → merge([3], [2]) = [2,3]
→ merge([5,6], [2,3]) = [2,3,5,6]
```

link video visual : https://www.youtube.com/watch?v=3j0SWDX4AtU

### 5. Quick Sort

Pilih pivot, partisi array jadi <pivot dan >pivot, lalu sort rekursif.

Sangat cepat secara umum untuk data besar.

Divide and Conquer

Pilih pivot, partisi array jadi < pivot dan > pivot

#### Kompleksitas Buruk

- O(n²) jika pivot selalu buruk (misal: elemen terbesar/terkecil).

- Tapi average-case tetap O(n log n).

#### Penggunaan Nyata

Dipakai di:

- Library C/C++ (qsort())

- In-memory sorting (RAM) karena efisien dan tidak butuh banyak memori tambahan.

- Dalam game: untuk sorting objek berdasarkan jarak (misal: z-index), leaderboard, atau proses rendering

#### Ciri Khas

- Sangat cepat dalam praktik: average O(n log n)

- In-place (tidak perlu banyak memori tambahan)

- Worst-case O(n²) jika pivot buruk (misalnya data sudah terurut)

- Tidak stabil

#### Visualisasi

Array awal : [6, 5, 3, 2]

```yaml
Step 1: Pilih pivot = 2
[6, 5, 3] | 2 → Semua elemen lebih besar dari pivot
Left: []       Pivot: 2       Right: [6, 5, 3]

Step 2: Sort bagian kanan → pivot = 3
[6, 5] | 3
Left: []       Pivot: 3       Right: [6, 5]

Step 3: Sort [6, 5] → pivot = 5
[6] | 5
Left: []       Pivot: 5       Right: [6]

Gabung mundur:
→ [5, 6]
→ [3, 5, 6]
→ [2, 3, 5, 6]
```

Proses Rekursif :

```yaml
quickSort([6,5,3,2])
├─ pivot = 2
│  → left: [] | pivot: 2 | right: [6,5,3]
    ├─ pivot = 3
    │  → left: [] | pivot: 3 | right: [6,5]
        ├─ pivot = 5
        │  → left: [] | pivot: 5 | right: [6]
        → hasil: [5,6]
    → hasil: [3,5,6]
→ hasil: [2,3,5,6]
```

### Kesimpulan Sorting

| Algoritma          | Strategi              | Proses Visual                                            |
| ------------------ | --------------------- | -------------------------------------------------------- |
| **Bubble Sort**    | Banding & Tukar       | Bandingkan elemen bersebelahan, gelembungkan ke atas     |
| **Selection Sort** | Pilih Minimum         | Cari elemen terkecil lalu tukar ke posisi awal           |
| **Insertion Sort** | Sisipkan ke tempatnya | Ambil satu elemen, geser kiri hingga posisi benar        |
| **Merge Sort**     | Divide lalu gabung    | Pecah semua bagian kecil, lalu gabungkan terurut         |
| **Quick Sort**     | Pivot & partisi       | Pecah sekitar pivot, sort kiri dan kanan secara rekursif |

### Sorting Dalam Game Development

- Bubble Sort: meskipun lambat, sering digunakan untuk ilustrasi animasi sorting, terutama dalam pendidikan/game edukasi.

- Selection Sort: berguna saat ukuran data tetap kecil dan stabil, seperti sorting karakter berdasar skor dalam UI game kecil.

- Insertion Sort: cocok ketika data bertambah satu-satu secara real-time, misalnya saat pemain masuk leaderboard satu per satu.

- Merge Sort: efisien dan stabil, bagus untuk menyortir banyak objek saat game mulai atau loading besar (mis. banyak NPC).

- Quick Sort: sangat cepat dan populer di backend engine, digunakan saat menyortir objek di dunia 3D berdasarkan jarak ke kamera.
