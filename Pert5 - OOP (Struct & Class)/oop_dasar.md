# Algoritma C++ & Data Structure

# Pertemuan 5

## Struct vs Class, Encapsulation & Constructor di C++

## Apa saja yang dipelajari ?

1. Struct
2. Class
3. Constructor
4. Inheritance
5. Encapsulation

---

## 🧠 A. Apa Itu OOP (Object-Oriented Programming)?

**Object-Oriented Programming (OOP)** atau **Pemrograman Berorientasi Objek** adalah paradigma (gaya) pemrograman yang berfokus pada objek.

Setiap objek merepresentasikan **entitas nyata** dan memiliki:

- **Data (atribut/properti)**
- **Perilaku (fungsi/method)**

Dengan OOP, program ditulis berdasarkan **objek-objek yang berinteraksi** satu sama lain.

## 🎯 Tujuan OOP

- Menyederhanakan program besar menjadi bagian kecil (objek)
- Mempermudah pengembangan dan pemeliharaan kode
- Meningkatkan **reusability**, **modularitas**, dan **keamanan** kode

## 🧩 Konsep Utama OOP (4 Pilar)

| Pilar             | Penjelasan                                                              |
| ----------------- | ----------------------------------------------------------------------- |
| **Encapsulation** | Menyembunyikan data dan hanya mengaksesnya lewat method (getter/setter) |
| **Inheritance**   | Pewarisan properti dan method dari class induk ke class turunan         |
| **Polymorphism**  | Objek memiliki banyak bentuk (method yang sama tapi aksi berbeda)       |
| **Abstraction**   | Menyembunyikan detail kompleks dan hanya menampilkan fitur penting      |

---

## 📌 Keuntungan OOP

| Keuntungan      | Penjelasan                                |
| --------------- | ----------------------------------------- |
| ✅ Modular      | Kode dibagi menjadi class & objek         |
| ✅ Reusability  | Class bisa digunakan ulang di tempat lain |
| ✅ Maintainable | Mudah dirawat & dikembangkan              |
| ✅ Scalable     | Cocok untuk proyek besar/kompleks         |
| ✅ Secure       | Data bisa dilindungi dengan encapsulation |

## 🎯 Contoh Dunia Nyata

Misalnya kamu ingin membuat sistem akademik:

- Class Mahasiswa: nama, nim, jurusan

- Class Dosen: nama, nip, mata kuliah

- Class Kelas: nama kelas, kapasitas, daftar mahasiswa

Semua itu bisa dibuat sebagai objek berbeda yang saling berhubungan.

## 💬 Kesimpulan

**OOP** adalah cara menulis program yang meniru dunia nyata dengan menggunakan objek.

Dengan OOP, kamu bisa membuat program yang lebih aman, terstruktur, dan mudah berkembang.

Gunakan OOP jika ingin membangun aplikasi skala menengah–besar yang butuh struktur jelas & fleksibel.

## B. Pengertian Object

Dalam **Object-Oriented Programming (OOP)**, **Object (Objek)** adalah **instansi nyata dari class**.  
Jika `class` adalah **blueprint atau cetakan**, maka **object** adalah **hasil nyata** yang dibuat dari blueprint tersebut.

> 🔍 Objek = data + perilaku (fungsi)

## 📦 Contoh Analogi

Bayangkan class `Mahasiswa` adalah **rancangan biodata mahasiswa**.  
Kalau kita membuat `mhs1` dan `mhs2`, mereka adalah **mahasiswa nyata** (objek):

```
Blueprint → Class Mahasiswa
Objek Nyata → mhs1: Vanya, 21 tahun
mhs2: Rudi, 22 tahun
```

````

---

## 🧠 Struktur Class dan Objek dalam C++

```cpp
class Mahasiswa {
public:
    string nama;
    int umur;

    void perkenalan() {
        cout << "Halo, saya " << nama << " umur " << umur << " tahun." << endl;
    }
};

int main() {
    Mahasiswa mhs1;      // Membuat objek mhs1
    mhs1.nama = "Vanya"; // Mengisi atribut nama
    mhs1.umur = 21;      // Mengisi atribut umur

    mhs1.perkenalan();   // Memanggil method pada objek
    return 0;
}

````

## 💡 Penjelasan:

class Mahasiswa: blueprint atau rancangan

mhs1: objek yang dibuat dari class Mahasiswa

nama, umur: atribut objek

perkenalan(): method objek

## 🛠️ Ciri-ciri Objek

| Ciri Objek         | Penjelasan                                                       |
| ------------------ | ---------------------------------------------------------------- |
| Memiliki identitas | Setiap objek bisa punya nama/nama variabel berbeda               |
| Memiliki data      | Objek menyimpan data dalam atribut                               |
| Memiliki perilaku  | Objek dapat melakukan aksi melalui method                        |
| Dibuat dari class  | Objek harus dibuat dari class menggunakan `ClassNama objekNama;` |

## 🎯 Manfaat Menggunakan Objek

| Manfaat                  | Penjelasan                                                                 |
| ------------------------ | -------------------------------------------------------------------------- |
| Modularitas              | Kode lebih terstruktur karena objek fokus pada satu tugas                  |
| Reusability              | Bisa membuat banyak objek dari 1 class                                     |
| Maintainable             | Perubahan di 1 class otomatis berdampak ke semua objek yang menggunakannya |
| Representasi dunia nyata | Cocok untuk menyusun sistem dari dunia nyata seperti User, Buku, Siswa     |

## 📌 Kesimpulan

- Objek adalah wujud nyata dari class (hasil dari blueprint)

- Objek punya atribut (data) dan method (perilaku)

- Objek dibuat menggunakan syntax:

```
NamaClass namaObjek;
```

- Bisa menggunakan constructor untuk memberi nilai awal

> 💡 Object = entitas nyata dari rancangan (class) yang bisa beraksi dan menyimpan data sendiri.

### 1. Apa Itu Struct ?

`struct` adalah **struktur data** yang digunakan untuk mengelompokkan beberapa variabel dalam satu unit. Di C++ (berbeda dari C), `struct` juga bisa memiliki method, constructor, bahkan inheritance seperti `class`.

### 1.1 Bentuk Struct

```cpp
struct NamaStruct {
    // Atribut (variabel)
    // Method (opsional)
};
```

### Ciri-ciri `struct`

- Default akses: `public`
- Digunakan untuk data yang sifatnya **sederhana**
- Dapat memiliki constructor dan method
- Bisa digunakan untuk inheritance (meskipun jarang)

### 2. Apa itu Class ?

`class` adalah cetakan (blueprint) untuk membuat objek. Di dalamnya terdapat data (disebut atribut) dan fungsi (method) yang bisa mengatur perilaku objek.

### 2.1 Bentuk Class

```cpp
class NamaClass {
private:
    // Atribut privat
public:
    // Constructor
    // Method
};
```

### 2.2 Ciri-ciri `class`

- Default akses: private.

- Digunakan untuk membangun sistem yang lebih kompleks.

- Mendukung seluruh fitur OOP: Encapsulation, Inheritance, Polymorphism.

- Sangat fleksibel dan digunakan di hampir semua aplikasi besar

| Fitur          | Struct                        | Class                 |
| -------------- | ----------------------------- | --------------------- |
| Default Access | `public`                      | `private`             |
| OOP Support    | ✅ (bisa ada method, inherit) | ✅ (lengkap)          |
| Umum Digunakan | Data container sederhana      | Struktur OOP kompleks |

**Kesimpulan**:

- `struct` cocok untuk data sederhana (tanpa logika bisnis).
- `class` cocok untuk sistem besar (punya method, aturan, dan logika).

### 2.3 Contoh Struct VS Class

✅ Struct

```cpp
struct Point {
    int x, y;
};
```

✅ Class

```cpp
class Point {
  private:
    int x, y;
  public:
    void set(int _x, int _y) {
        x = _x;
        y = _y;
    }
};
```

### 2.4 Perbandingan Singkat

| Fitur                          | `struct`         | `class`                         |
| ------------------------------ | ---------------- | ------------------------------- |
| Akses default                  | `public`         | `private`                       |
| OOP (Inheritance, Method, dll) | ✅ Ya            | ✅ Ya                           |
| Digunakan untuk                | Data sederhana   | Struktur kompleks / skala besar |
| Inheritance                    | Jarang digunakan | Sering digunakan                |
| Constructor                    | ✅ Bisa          | ✅ Bisa                         |
| Encapsulation                  | Jarang digunakan | Umum digunakan                  |

### 2.5 Kapan Harus Menggunakan?

#### Gunakan struct:

- Untuk data kecil dan sederhana

- Saat tidak butuh keamanan data atau logika kompleks

#### Gunakan class:

- Untuk membangun aplikasi skala besar

- Saat ingin menggunakan prinsip OOP seperti Encapsulation dan Inheritance

---

### 3. Constructor (Konstruktor)

**Constructor** adalah fungsi khusus dalam sebuah `class` (atau `struct` di C++) yang secara otomatis **dipanggil saat objek dibuat**.

Tujuan utama constructor adalah untuk **menginisialisasi atribut** dari objek.

### 3.1 Ciri-ciri Constructor

| Ciri                          | Penjelasan                                                      |
| ----------------------------- | --------------------------------------------------------------- |
| Nama constructor = nama class | Harus sama persis, tanpa tipe pengembalian (`void`, `int`, dll) |
| Dipanggil otomatis            | Tidak perlu dipanggil secara manual                             |
| Bisa overload (banyak versi)  | Bisa membuat beberapa constructor dengan parameter berbeda      |
| Tidak boleh `return` nilai    | Constructor tidak mengembalikan nilai apapun                    |

---

### 3.2 Contoh Constructor Sederhana

```cpp
class Mahasiswa {
  private:
    string nama;
    int umur;
  public:
    // Constructor
    Mahasiswa(string n, int u) {
        nama = n;
        umur = u;
    }

    void tampil() {
        cout << nama << " - " << umur << endl;
    }
};
```

**Penjelasan :**

- Mahasiswa(string n, int u) adalah constructor

- Digunakan untuk mengisi nilai nama dan umur

- Saat Mahasiswa mhs1("Vanya", 21); dibuat, constructor langsung dijalankan.

| Jenis Constructor      | Penjelasan                                                                     |
| ---------------------- | ------------------------------------------------------------------------------ |
| Default Constructor    | Tidak memiliki parameter. Jika tidak dibuat, C++ akan otomatis menyediakannya. |
| Parameterized          | Constructor yang menerima parameter untuk mengisi atribut                      |
| Overloaded Constructor | Beberapa constructor dengan parameter berbeda                                  |

---

### Kesimpulan Constructor

- Constructor digunakan untuk mempermudah inisialisasi objek

- C++ mendukung overloading constructor

- Nama constructor harus sama dengan nama class, dan tidak memiliki return value

- Bisa digabung dengan method lain untuk membangun OOP yang rapi dan aman

**Ingat !!! Tanpa constructor, kita harus set nilai atribut satu per satu secara manual — constructor membuat semuanya lebih efisien dan aman.**

### 4. Inheritance (Pewarisan)

**Inheritance** atau **Pewarisan** adalah konsep dalam pemrograman berorientasi objek (OOP) yang memungkinkan **satu class mewarisi atribut dan method dari class lain**.

Dengan inheritance, kita bisa membuat **class baru (child class)** yang berbasis dari **class yang sudah ada (parent class)** tanpa harus menulis ulang kode yang sama.

### Istilah Penting

| Istilah         | Penjelasan                                                     |
| --------------- | -------------------------------------------------------------- |
| `Base class`    | Class induk/superclass/parent: class yang diwarisi             |
| `Derived class` | Class turunan/subclass/child: class yang mewarisi              |
| `Inheritance`   | Proses pewarisan atribut dan method dari base ke derived class |

---

### 4.1 Struktur Dasar Inheritance

```cpp
class BaseClass {
  // atribut dan method yang diwariskan
};

class DerivedClass : public BaseClass {
  // atribut dan method tambahan
};
```

| Tipe Inheritance | Warisan dari `public` parent menjadi apa di child? |
| ---------------- | -------------------------------------------------- |
| `public`         | Tetap `public`                                     |
| `protected`      | Menjadi `protected`                                |
| `private`        | Tidak diwariskan langsung ke luar class            |

---

### 4.2 Kapan Menggunakan Inheritance?

- Jika beberapa class punya fitur dasar yang sama

- Untuk mengurangi duplikasi kode atau redudansi

- Untuk membuat sistem OOP yang modular, terstruktur, dan scalable

### 4.3 Contoh Hierarki Inheritance

```
  [Hewan]
    |
 ┌──┴───────────────┐
 |                  |
[Burung]         [Ikan]
```

Semua class **Burung** dan **Ikan** bisa **mewarisi method** dari class **Hewan** (misalnya: makan(), tidur()), tapi juga bisa punya method khusus seperti terbang() atau berenang().

### 4.4 Kesimpulan

- Inheritance adalah cara membuat class baru dari class yang sudah ada

- Menghemat kode dan meningkatkan keteraturan program

- Dapat digunakan untuk membangun hierarki class seperti yang ada di dunia nyata

> Inheritance = konsep "anak mewarisi sifat orang tua", tapi anak juga bisa punya sifat unik sendiri.

### 🧱 5. Encapsulation

**Encapsulation** (Enkapsulasi) adalah konsep dalam Object-Oriented Programming (OOP) yang menyembunyikan data dari akses luar dan hanya bisa diakses atau dimodifikasi melalui method tertentu.

**Encapsulation**, "melindungi isi dengan bungkus", dan hanya memberikan akses lewat pintu resmi

### 5.1 Tujuan

- Mencegah data diubah langsung dari luar
- Memberikan **interface aman** untuk akses data
- **Melindungi data internal** objek
- **Mengontrol cara data diakses dan diubah**
- Mencegah kode luar melakukan manipulasi langsung

### 5.2 Analogi Sederhana

Bayangkan kamu punya **ATM**:

- Uang kamu ada **di dalam mesin** (private)
- Kamu hanya bisa **mengakses uang** lewat **tombol/menu resmi** (method public).

### 5.3 Ciri-ciri Encapsulation:

| Fitur           | Penjelasan                                              |
| --------------- | ------------------------------------------------------- |
| `private`       | Digunakan untuk menyembunyikan data (atribut)           |
| `public` method | Digunakan untuk mengakses dan mengubah data secara aman |
| Kontrol ketat   | Tidak semua bagian program bisa sembarangan akses data  |

---

### 5.4 Contoh Encapsulation di C++

```cpp
#include <iostream>
using namespace std;

class Mahasiswa {
private:
    string nama;      // hanya bisa diakses lewat method
    int umur;

public:
    // setter = untuk memberi nilai
    void setNama(string n) {
        nama = n;
    }

    void setUmur(int u) {
        if (u > 0)
            umur = u;
    }

    // getter = untuk mengambil nilai
    string getNama() {
        return nama;
    }

    int getUmur() {
        return umur;
    }
};

int main() {
    Mahasiswa mhs;
    mhs.setNama("Vanya");
    mhs.setUmur(21);

    cout << "Nama: " << mhs.getNama() << endl;
    cout << "Umur: " << mhs.getUmur() << " tahun" << endl;

    return 0;
}
```

**Penjelasan**

- Atribut nama dan umur disembunyikan (private)

- Akses/modifikasi harus melalui setNama(), getNama(), dll

- Kita bisa menambahkan validasi saat mengatur nilai

### Tanpa Encapsulation

❌ Data langsung bisa diubah tanpa kontrol → ini bisa menyebabkan bug.

```cpp
class Mahasiswa {
public:
    string nama;
    int umur;
};

int main() {
    Mahasiswa mhs;
    mhs.umur = -10; // umur tidak masuk akal, tapi tidak dicegah
}
```

### Keuntungan Enkapsulasi

| Keuntungan         | Penjelasan                                                |
| ------------------ | --------------------------------------------------------- |
| ✅ Proteksi Data   | Data tidak bisa diubah sembarangan                        |
| ✅ Validasi Data   | Bisa memeriksa nilai sebelum menyimpannya                 |
| ✅ Modularitas     | Memisahkan antara representasi data dan logika manipulasi |
| ✅ Maintainability | Memudahkan perawatan dan pengembangan kode                |

### Kesimpulan Enkapsulasi

- **Encapsulation** menyembunyikan data dan hanya membolehkan akses lewat method tertentu

- Gunakan private untuk atribut, dan public untuk method akses (getter/setter)

- Ini membuat program lebih aman, terstruktur, dan mudah dikembangkan

### 6. Rangkuman OOP Dasar

struct dan class di C++ itu hampir sama.

Gunakan class jika ingin menerapkan prinsip OOP seperti:

- Encapsulation

- Constructor

- Inheritance

- Encapsulation melindungi data dari akses langsung

- Constructor membuat objek langsung punya nilai saat dibuat
