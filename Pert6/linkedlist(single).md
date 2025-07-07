# Pertemuan 6

## Linked List (Single)

## Apa itu linked list ?

**Linked list** adalah struktu data linear yang terdiri dari node2 yang saling terhubung.

Setiap node berisi :

- Data
- Pointer untuk ke node berikutnya.

Array dan linked list berbeda. linked list tidak memerlukan memori kontigu.

## Jenis : Single Linked list

- Linked list itu arah nya hanya 1 arah dari head ke tail dan tidak bisa muncur.
- tidak ada refrensi ke node sebelumnya.

> [Data1] → [Data2] → [Data3] → NULL

```cpp
// Struktur Node C++
struct Node {
    int data;
    Node* next;
};
```

```cpp
// Insert di awal (head)
void insertDepan(Node*& head, int data) {
    Node* newNode = new Node{data, head};
    head = newNode;
}
```

```cpp
// Insert di akhir (tail)
void insertBelakang(Node*& head, int data) {
    Node* newNode = new Node{data, nullptr};
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
```

```cpp
// Delete di awal
void deleteDepan(Node*& head) {
    if (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
```

```cpp
// Delete diakhir
void deleteBelakang(Node*& head) {
    if (head == nullptr) return;

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}
```

```cpp
// Traverse (Menelusuri isi list)
void tampilkanList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL\n";
}
```

| Operasi  | Fungsi                      |
| -------- | --------------------------- |
| Insert   | Menambahkan node            |
| Delete   | Menghapus node              |
| Traverse | Menampilkan isi linked list |

## Perbedaan array dan linked list

| Fitur                     | Array (`vector`, `list`, dsb) | Linked List (Single)           |
| ------------------------- | ----------------------------- | ------------------------------ |
| 📌 Ukuran awal            | Tetap atau bertambah dinamis  | Fleksibel (bebas nambah)       |
| ➕ Tambah di akhir        | Cepat (O(1) jika dinamis)     | Cepat (O(n) jika cari ujung)   |
| ➕ Tambah di depan/tengah | Lambat (butuh geser O(n))     | Cepat di depan (O(1))          |
| ➖ Hapus di depan         | Lambat (harus geser O(n))     | Cepat (O(1))                   |
| 📍 Akses elemen by indeks | Cepat (O(1))                  | Lambat (harus traversing O(n)) |
| 📊 Memory                 | Alokasi blok besar            | Alokasi per elemen             |
| ⚠️ Insert middle besar    | Lambat (geser O(n))           | Sedang (cari node + link)      |

## Contoh C++ Array VS Linked List

**Array**

```
string buah[100];
int n = 0;
buah[n++] = "apel";
buah[n++] = "jeruk";
```

Hapus dari depan:

```cpp
for (int i = 0; i < n - 1; i++) {
    buah[i] = buah[i + 1];  // geser semuanya!
}
n--;
```

**Linked List**

```cpp
struct Node {
    string data;
    Node* next;
};

void hapusDepan(Node*& head) {
    Node* temp = head;
    head = head->next;
    delete temp;  // langsung hapus tanpa geser
}
```

## Analogi Simpel dari Array dan Linked List

Bayangin kamu punya rak buku:

- Array itu rak dengan slot tetap. Kalau mau sisipkan buku di tengah, harus geser buku-buku lain.

- Linked list seperti tali gantungan: kamu tinggal lepas dan kaitin buku di mana saja — gampang dan fleksibel.

## Tabel Perbandingan Array VS Linked List

| Aspek                      | **Array**                                            | **Linked List (Single)**                              |
| -------------------------- | ---------------------------------------------------- | ----------------------------------------------------- |
| 🧠 **Struktur**            | Sekumpulan elemen dalam satu blok memori             | Kumpulan node yang terhubung lewat pointer            |
| 📦 **Alokasi Memori**      | Kontigu (berdekatan)                                 | Tidak kontigu (alokasi dinamis satu per satu)         |
| 📌 **Ukuran**              | Tetap (array biasa) atau bertambah otomatis (vector) | Dinamis, tidak terbatas                               |
| 📍 **Akses by index**      | Cepat (O(1))                                         | Lambat (harus traverse node demi node – O(n))         |
| ➕ **Insert di akhir**     | Cepat (O(1) jika tidak penuh)                        | Lambat (harus traverse ke node terakhir – O(n))       |
| ➕ **Insert di depan**     | Lambat (butuh geser semua elemen – O(n))             | Cepat (langsung buat node baru dan sambungkan – O(1)) |
| ➖ **Hapus di depan**      | Lambat (butuh geser ke kiri – O(n))                  | Cepat (langsung pindah head – O(1))                   |
| ➖ **Hapus di tengah**     | Lambat (geser semua setelahnya – O(n))               | Sedang (traverse + putus link – O(n))                 |
| 🔍 **Cari nilai (search)** | Cepat jika tahu indeks, O(n) jika tidak tahu         | Selalu O(n)                                           |
| 💥 **Overhead memory**     | Lebih kecil                                          | Lebih besar (ada pointer di tiap node)                |
| 🧪 **Cocok untuk**         | Akses acak cepat, data tetap                         | Tambah/hapus data dinamis (queue, stack, dsb)         |
| 🧱 **Contoh**              | `int arr[10]`, `vector<string>`                      | `struct Node { int data; Node* next; };`              |

## Kapan Gunakan Array?

- Saat ukuran data sudah diketahui dari awal

- Saat kamu butuh akses cepat ke elemen tertentu

- Saat penambahan/penghapusan jarang dilakukan

## Kapan Gunakan Linked List?

- Saat data sering bertambah/berkurang

- Saat kamu butuh struktur fleksibel

- Saat kamu ingin buat queue, stack, atau graph

## Cara Kerja Array

Array menyimpan semua elemen berurutan dan berdekatan di memori.

```rust
Index:   0       1       2       3       4
         ↓       ↓       ↓       ↓       ↓
Array = [10] -> [20] -> [30] -> [40] -> [50]
         ↑
       awal
```

akses element ke-2 :

```cpp
arr[2] = 30  // langsung, O(1)
```

contoh hapus depan (arr.pop(0)):

```scss
[20] <- [30] <- [40] <- [50]  // semua harus digeser ke kiri (O(n))
```

## Cara Kerja Single Linked List

Linked List menyimpan data dalam node yang saling terhubung melalui pointer (next), tidak harus bersebelahan di memori.

```css
Head
 ↓
[10 | * ] → [20 | * ] → [30 | * ] → [40 | NULL]
```

Setiap node punya:

- data (misal: 10)

- next (penunjuk ke node berikutnya)

### Menambah data depan (InsertDepan)

```cpp
insertDepan(5);
```

```css
[ 5 | * ] → [10 | * ] → [20 | * ] → [30 | * ] → ...
 ↑
 head
```

**cepat tanpa geser !**

### Menghapus data depan (deleteDepan)

```cpp
hapusDepan();
```

```bash
Sebelum:
[ 5 | * ] → [10 | * ] → [20 | * ]
  ↑
 head

Setelah:
[10 | * ] → [20 | * ]
  ↑
 head
```

**langsung pindah head**

### Akses Data

```less
[10] → [20] → [30]  // Harus lewat satu per satu: O(n)
```

## Ringkasan Linked List VS Array

```mathematica
ARRAY:         [A] [B] [C] [D] [E]   <-- urut, 1 blok
                ↑   ↑   ↑
              arr[0] arr[1] arr[2]   <-- akses langsung (cepat)

LINKED LIST:   [A]->[B]->[C]->[D]->[E]->NULL
                ↑
              Head
                |
              akses harus node per node (traverse)
```

## Kesimpulan Visual

| Operasi        | Array        | Linked List (SLL)          |
| -------------- | ------------ | -------------------------- |
| Tambah depan   | Geser semua  | Tambah langsung (O(1))     |
| Tambah akhir   | Cepat (O(1)) | Harus cari ujung (O(n))    |
| Akses by index | Cepat (O(1)) | Lambat (O(n))              |
| Hapus depan    | Geser semua  | Hapus head langsung (O(1)) |

## Contoh Kasus Penggunaan di dunia nyata

| Masalah                       | Array Cocok? | Linked List Cocok? | Kenapa                           |
| ----------------------------- | ------------ | ------------------ | -------------------------------- |
| Data tetap seperti nama bulan | ✅           | ❌                 | Karena jarang berubah            |
| Sistem antrian (queue)        | ❌           | ✅                 | Tambah & hapus di depan/belakang |
| Undo-redo (seperti Ctrl+Z)    | ❌           | ✅                 | Tambah & hapus dari stack (top)  |
| Game logic peluru bergerak    | ❌           | ✅                 | Peluru nambah & hilang terus     |
