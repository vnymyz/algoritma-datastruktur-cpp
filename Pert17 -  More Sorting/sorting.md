## Pertemuan 17 - Sorting Algorithm

## Tujuan Pembelajaran

1. Memahami konsep dasar algoritma sorting.

2. Menjelaskan cara kerja Bubble Sort, Selection Sort, dan Insertion Sort.

3. Mengimplementasikan masing-masing algoritma dalam bahasa C++.

4. Menganalisis kompleksitas waktu (Time Complexity) dan ruang (Space Complexity).

## 1. Apa itu Sorting ?

Sorting adalah proses mengatur elemen dalam urutan tertentu (Ascending / Descending).

Aplikasi di dunia nyata:

- Mengurutkan data mahasiswa berdasarkan nilai.

- Sorting produk e-commerce berdasarkan harga.

- Sorting file berdasarkan tanggal.

- Sorting mempermudah pencarian (Search), pengolahan data, dan analisis.

## 2. Bubble Sort

- Membandingkan elemen bersebelahan (adjacent).

- Jika urutannya salah, tukar posisi.

- Ulangi hingga tidak ada lagi pertukaran.

## 2.1 Contoh Ilustrasi Bubble Sort

Array: [64, 25, 12, 22, 11]

1. Bandingkan 64 dan 25 → tukar.

2. Bandingkan 64 dan 12 → tukar.

sampai elemen terbesar "bubble up" ke akhir.

## 2.2 Kompleksitas Bubble Sort

Best Case: O(n) (sudah terurut, dengan optimasi early stop).

Worst & Average Case: O(n²).

Space: O(1) (in-place).

## 3. Selection Sort

- Bagi array menjadi dua bagian: sorted dan unsorted.

- Temukan elemen terkecil dari unsorted, tukar dengan elemen pertama unsorted.

- Lanjutkan hingga seluruh array terurut.

## 3.1 Ilustrasi Selection Sort

Array [64, 25, 12, 22, 11]:

1. Cari minimum (11), tukar dengan arr[0].

2. Cari minimum dari sisa (12), tukar dengan arr[1].
   ... dst.
