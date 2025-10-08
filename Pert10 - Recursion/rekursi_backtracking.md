# Pertemuan 11

# Recursion & Backtracking

## Apa saja yang dipelajari ?

1. Rekursi Lanjutan
2. Backtracking

---

## 1. Recursion ( Rekursi)

- Rekursi adalah teknik dalam pemrograman di mana sebuah fungsi memanggil dirinya sendiri untuk menyelesaikan masalah yang lebih kecil dari versi asli masalah tersebut.

- Tujuan utama nya adalah Memecah masalah menjadi bagian yang lebih kecil, sampai mencapai base case (kasus dasar).

- fungsi tersebut ada waktu atau base case (berhenti) dan recursive case (lanjut).

- Harus memiliki base case (kasus dasar) agar tidak infinite loop.

### Ciri - ciri :

1.  Base Case - Kondisi Berhenti

2.  Recursive Case - Fungsi yang memanggil dirinya sendiri.

**Contoh : Faktorial**

```cpp
int faktorial(int n) {
    if (n == 0) return 1;
    return n * faktorial(n - 1);
}
```

Penjelasan :

- Ada base case: kondisi berhenti (if (n == 0))

- Ada recursive case: memanggil dirinya sendiri (faktorial(n - 1))

## 2. Backtracking

- Backtracking adalah metode rekursif untuk menyelesaikan masalah dengan mencoba semua kemungkinan, dan "mundur" atau backtrack jika satu jalan tidak berhasil.

- Backtracking selalu menggunakan rekursi, tapi tidak semua rekursi adalah backtracking.

- Analoginya seperti menjelajahi labirin:

```txt
Coba satu kemungkinan ➜ Jika gagal, mundur ➜ Coba kemungkinan lain ➜ Ulangi sampai berhasil atau habis pilihan.
```

### Struktur

```cpp
bool solve(posisi sekarang) {
    if (sudah di tujuan) return true;

    for (setiap kemungkinan langkah) {
        jika langkah valid:
            lakukan langkah (misal: tandai jalan)
            if (solve(posisi baru)) return true;
            batalkan langkah (backtrack) —> undo tanda
    }

    return false; // semua langkah gagal
}
```

berikut beberapa program yang menggunakan backtracking :

1. Maze Problem (Rat in a Maze)

   Tikus cari jalan dari start ke goal. Kalau mentok, dia mundur dan cari jalan lain.

2. N-Queens

   Tempatkan ratu di papan catur 8x8 tanpa saling menyerang. Coba-coba posisi, dan jika tidak memungkinkan, mundur dan ganti posisi sebelumnya.

```cpp
- Letakkan Queen di baris ke-0
- Lanjut ke baris berikutnya
- Kalau tidak bisa tempatkan Queen (terhalang), balik ke baris sebelumnya → backtrack
```

3. Sudoku Solver

Isi kotak kosong satu per satu. Kalau tidak bisa isi angka yang valid, mundur dan ganti angka sebelumnya.

| Kriteria                     | Penjelasan                        |
| ---------------------------- | --------------------------------- |
| Banyak kemungkinan solusi    | Misal: kombinasi, penempatan      |
| Bisa dibagi jadi sub-masalah | Problem bisa direkursi            |
| Bisa deteksi langkah salah   | Langkah tidak valid bisa dicek    |
| Ada kemungkinan harus mundur | Tidak semua cabang membawa solusi |

## 2.1 Analogi backtracking sehari-hari

- Puzzle atau Labirin. Kamu jalan di labirin, kalau mentok kamu balik (backtrack) ke persimpangan sebelumnya dan coba jalan lain.

- Kombinasi Kunci. Coba semua kombinasi angka 1–9 untuk 3 digit. Jika kombinasi salah, coba kombinasi berikutnya.

| Perbedaan              | Rekursi                             | Backtracking                                           |
| ---------------------- | ----------------------------------- | ------------------------------------------------------ |
| 🔁 Tujuan              | Memecah masalah jadi sub-masalah    | Menyelesaikan masalah dengan mencoba semua kemungkinan |
| 🔁 Sifat               | Linear atau struktural              | Percabangan eksplorasi                                 |
| ↩️ Ada backtrack/undo? | Tidak perlu                         | Perlu "undo" langkah saat mundur                       |
| 🎯 Contoh              | Faktorial, Fibonacci, binary search | Maze solver, N-Queens, Sudoku                          |
| 🚀 Efisiensi           | Lebih cepat, deterministik          | Lebih lambat, eksploratif                              |
