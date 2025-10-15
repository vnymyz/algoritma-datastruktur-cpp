# Pointer & Dynamic Memory in C++

---

## Apa Itu Pointer?

**Pointer** adalah variabel yang menyimpan **alamat memori** dari variabel lain. Dideklarasikan dengan tanda `*`.

```cpp
int a = 10;
int* p = &a;
```

```
Jika a disimpan di alamat 0x100, maka:

a = 42

&a = 0x100

p = 0x100

*p = 42
```

a adalah variabel biasa yang menyimpan nilai 10.

p adalah pointer yang menyimpan alamat dari a (bukan nilainya langsung).

**Pointer adalah konsep penting dalam C++ karena memungkinkan:**

- Mengakses dan memodifikasi data melalui alamat memori

- Alokasi memori secara dinamis (heap)

- Efisiensi pada struktur data (linked list, tree, dsb.)

- Interaksi langsung dengan perangkat keras (embedded system)

---

| Operasi       | Contoh         | Keterangan                            |
| ------------- | -------------- | ------------------------------------- |
| Ambil alamat  | `&a`           | Mendapatkan alamat dari variabel `a`  |
| Simpan alamat | `int* p = &a;` | Pointer `p` menyimpan alamat `a`      |
| Dereference   | `*p`           | Mengakses nilai yang ditunjuk pointer |

## Dynamic Memory Allocation (new & delete)

new digunakan untuk mengalokasikan memori secara dinamis.

delete digunakan untuk menghapus alokasi memori agar tidak terjadi memory leak.
