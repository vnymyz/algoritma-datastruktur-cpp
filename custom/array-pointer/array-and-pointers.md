# Arrays and Pointers

## Arrays

### 1. Apa itu array ?

Array adalah kumpulan variabel dengan tipe data yang sama, disimpan secara berurutan di memori dan diakses menggunakan indeks. Contoh :

```c
int angka[5] = {10, 20, 30, 40, 50};
```

| Indeks   | Nilai | Alamat Memori (ilustrasi) |
| -------- | ----- | ------------------------- |
| angka[0] | 10    | 0x1000                    |
| angka[1] | 20    | 0x1004                    |
| angka[2] | 30    | 0x1008                    |
| angka[3] | 40    | 0x100C                    |
| angka[4] | 50    | 0x1010                    |

### 2. Struktur Dasar Array

```c
tipe_data nama_array[ukuran];
```

contoh :

```c
int nilai[3];          // deklarasi array kosong
nilai[0] = 10;         // isi elemen pertama
nilai[1] = 20;
nilai[2] = 30;

printf("%d", nilai[1]); // menampilkan 20
```

## Pointers

### 1. Apa itu Pointer

Pointer adalah variabel yang menyimpan alamat memori dari variabel lain.

```c
int a = 10;
int *p = &a;  // pointer p menyimpan alamat variabel a
```

| Variabel | Nilai             | Alamat Memori |
| -------- | ----------------- | ------------- |
| a        | 10                | 0x2000        |
| p        | 0x2000 (alamat a) | 0x3000        |

### 2. Struktur Dasar Pointer

```c
tipe_data *nama_pointer;
```

Contoh :

```c
int x = 7;
int *ptr = &x;     // ptr menunjuk ke alamat x

printf("Nilai x: %d\n", x);
printf("Alamat x: %p\n", &x);
printf("Nilai ptr: %p\n", ptr);
printf("Nilai yang ditunjuk ptr: %d\n", *ptr);
```

Penjelasan :

🧩 Penjelasan:

- &x = alamat memori dari x

- ptr = menyimpan alamat x

- \*ptr = mengakses nilai dari alamat tersebut (yaitu 7)

### 3. Hubungan Antara Array dan Pointer

Sebenarnya nama array adalah pointer yang menunjuk ke elemen pertama array!

```c
int angka[3] = {10, 20, 30};
printf("%p\n", angka);     // alamat elemen pertama
printf("%p\n", &angka[0]); // alamat elemen pertama (sama!)
```

Keduanya memberikan hasil sama.

### Akses Elemen Menggunakan Pointer

Kita bisa akses elemen array pakai pointer:

```c
int angka[3] = {10, 20, 30};
int *ptr = angka; // sama dengan &angka[0]

printf("%d\n", *ptr);       // 10
printf("%d\n", *(ptr + 1)); // 20
printf("%d\n", *(ptr + 2)); // 30
```

Visualisasi Memori :

```
angka[0] = 10   ← ptr menunjuk ke sini
angka[1] = 20   ← ptr + 1
angka[2] = 30   ← ptr + 2
```

### Program Array + Pointer

```c
#include <stdio.h>

int main() {
    int nilai[5] = {10, 20, 30, 40, 50};
    int *ptr;

    ptr = nilai; // ptr menunjuk ke elemen pertama array

    printf("Isi array menggunakan indeks:\n");
    for (int i = 0; i < 5; i++) {
        printf("nilai[%d] = %d\n", i, nilai[i]);
    }

    printf("\nIsi array menggunakan pointer:\n");
    for (int i = 0; i < 5; i++) {
        printf("*(ptr + %d) = %d\n", i, *(ptr + i));
    }

    printf("\nAlamat memori tiap elemen:\n");
    for (int i = 0; i < 5; i++) {
        printf("&nilai[%d] = %p\n", i, &nilai[i]);
    }

    return 0;
}
```

Output :

```yaml
Isi array menggunakan indeks:
nilai[0] = 10
nilai[1] = 20
nilai[2] = 30
nilai[3] = 40
nilai[4] = 50

Isi array menggunakan pointer:
*(ptr + 0) = 10
*(ptr + 1) = 20
*(ptr + 2) = 30
*(ptr + 3) = 40
*(ptr + 4) = 50

Alamat memori tiap elemen:
&nilai[0] = 0x61fe00
&nilai[1] = 0x61fe04
&nilai[2] = 0x61fe08
&nilai[3] = 0x61fe0c
&nilai[4] = 0x61fe10
```

### Ilustrasi Hubungan Array dan Pointer

```sql
Array (nilai):
+--------+--------+--------+--------+--------+
|  10    |  20    |  30    |  40    |  50    |
+--------+--------+--------+--------+--------+
   ^
   |
  ptr (pointer menunjuk ke nilai[0])
```

- \_(ptr + 0) → 10
- \_(ptr + 1) → 20
- \*(ptr + 2) → 30

### Ringkasan Konsep

| Konsep       | Simbol                  | Arti                             |
| ------------ | ----------------------- | -------------------------------- |
| `&`          | address-of              | mengambil alamat memori          |
| `*`          | dereference             | mengambil nilai dari alamat      |
| `arr`        | pointer                 | menunjuk ke elemen pertama array |
| `*(arr + i)` | akses array via pointer | sama dengan `arr[i]`             |

| Konsep     | Simbol             | Arti                                              |
| :--------- | :----------------- | :------------------------------------------------ |
| `&`        | Address-of         | Mengambil alamat dari variabel                    |
| `*`        | Dereference        | Mengambil nilai dari alamat yang ditunjuk pointer |
| `p = &x`   | Pointer assignment | Pointer menunjuk ke variabel `x`                  |
| `*(p + i)` | Pointer arithmetic | Mengakses elemen array dengan pointer             |

## Latihan Array dan Pointers

#### Latihan 1:

Tulislah program yang menampilkan isi array dan alamat memorinya menggunakan pointer.

#### Latihan 2:

Coba buat array char berisi nama kamu, lalu tampilkan huruf demi huruf menggunakan pointer.

#### Latihan 3:

Coba tambahkan input dari user untuk mengisi array, dan tampilkan hasilnya dengan pointer.

#### Selesaikan Codingan dibawah ini :

```c
// Nomor 1
#include <stdio.h>

int main() {
    int nilai[5] = {10, 20, 30, 40, 50};
    int *ptr;

    ptr = _______;  // TODO: arahkan pointer ke array 'nilai'

    printf("Menampilkan isi array dan alamat memori:\n");
    for (int i = 0; i < 5; i++) {
        printf("Elemen ke-%d: %d\tAlamat: %p\n", i, _______, _______);
        // TODO: tampilkan nilai dan alamat menggunakan pointer
    }

    return 0;
}
```

```c
// Nomor 2
#include <stdio.h>

int main() {
    char nama[] = "_______";  // TODO: isi dengan nama kamu
    char *p;

    p = _______;  // TODO: arahkan pointer ke array 'nama'

    printf("Huruf demi huruf dari nama kamu:\n");

    while (*p != '\0') {  // '\0' menandakan akhir string
        printf("%c ", _______);  // TODO: tampilkan karakter yang ditunjuk pointer
        _______;  // TODO: geser pointer ke karakter berikutnya
    }

    return 0;
}
```

```c
// Nomor 3
#include <stdio.h>

int main() {
    int data[5];
    int *ptr;
    ptr = _______;  // TODO: arahkan pointer ke array 'data'

    printf("Masukkan 5 nilai integer:\n");
    for (int i = 0; i < 5; i++) {
        printf("Data ke-%d: ", i + 1);
        scanf("%d", _______);  // TODO: simpan input ke alamat data[i]
    }

    printf("\nMenampilkan data menggunakan pointer:\n");
    for (int i = 0; i < 5; i++) {
        printf("Data ke-%d: %d\n", i + 1, _______);  // TODO: tampilkan nilai menggunakan pointer
    }

    return 0;
}
```
