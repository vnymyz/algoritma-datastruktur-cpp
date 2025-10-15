# Pertemuan 18

## Sorting Algorithms

Sorting adalah proses mengatur data dalam urutan tertentu (biasanya ascending atau descending).

Contoh:

- Sebelum sorting → {5, 2, 9, 1, 5, 6}

- Sesudah sorting (ascending) → {1, 2, 5, 5, 6, 9}

## Sorting - 1

### 1. Bubble Sort

https://www.youtube.com/watch?v=Dv4qLJcxus8

- Bekerja dengan cara membandingkan elemen bersebelahan dan menukarnya jika salah urut.

- Dilakukan berulang kali sampai tidak ada lagi pertukaran.

- Paling mudah dipahami, tapi tidak efisien untuk data besar (O(n²)).

**Visualisasi (contoh array: [5, 3, 8, 4])**

```csharp
Pass 1:
[5, 3, 8, 4]
 ↓
[3, 5, 8, 4]
        ↓
[3, 5, 4, 8]

Pass 2:
[3, 5, 4, 8]
      ↓
[3, 4, 5, 8]

```

Hasil Akhir : [3, 4, 5, 8]

```c
#include <stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr, n);

    printf("Hasil sorting (Bubble Sort): ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
```

### 2. Selection Sort

https://www.youtube.com/watch?v=EwjnF7rFLns

- Cari elemen terkecil, lalu taruh di depan.

- Lanjut ke elemen berikutnya sampai akhir.

- Kompleksitas O(n²), tapi jumlah pertukaran lebih sedikit daripada Bubble Sort.

**Visualisasi (contoh array: [64, 25, 12, 22, 11])**

```less
Step 1: cari min → 11 → [11, 25, 12, 22, 64]
Step 2: cari min dari indeks 1 → 12 → [11, 12, 25, 22, 64]
Step 3: cari min dari indeks 2 → 22 → [11, 12, 22, 25, 64]
Step 4: array sudah terurut → [11, 12, 22, 25, 64]
```

**Kode C Selection Sort**

```c
#include <stdio.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    selectionSort(arr, n);

    printf("Hasil sorting (Selection Sort): ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
```

### 3. Insertion Sort

https://www.youtube.com/watch?v=8mJ-OhcfpYg

- Bayangkan seperti menyusun kartu.

- Ambil satu elemen, masukkan ke posisi yang sesuai di bagian array yang sudah terurut.

- Efisien untuk data kecil atau hampir terurut (O(n²), best case O(n)).

**Visualisasi (contoh array: [5, 3, 4, 6, 2])**

```sql
Mulai: [5 | 3, 4, 6, 2]
Insert 3 → [3, 5 | 4, 6, 2]
Insert 4 → [3, 4, 5 | 6, 2]
Insert 6 → [3, 4, 5, 6 | 2]
Insert 2 → [2, 3, 4, 5, 6]
```

**Kode C Insertion Sort**

```c
#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main() {
    int arr[] = {5, 3, 4, 6, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    insertionSort(arr, n);

    printf("Hasil sorting (Insertion Sort): ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
```
