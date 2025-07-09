# Pertemuan 7

## Doubly Linked List

Pengertian Doubly Linked List (DLL)
Doubly Linked List (DLL) adalah struktur data linier yang terdiri dari simpul (node), di mana setiap node memiliki tiga bagian:

- Data (nilai yang disimpan),

- Pointer ke node sebelumnya (prev),

- Pointer ke node berikutnya (next).

- DLL memungkinkan traversal dua arah: maju (forward) dan mundur (backward).

```r
NULL <- [data|prev|next] <-> [data|prev|next] <-> [data|prev|next] -> NULL
```

## Jenis jenis Doubly Linked List

1. Doubly Linked List Biasa

   - Head menunjuk ke node pertama, tail menunjuk ke node terakhir.

   - Arah traversal bisa maju dan mundur.

2. Circular Doubly Linked List

   - Node terakhir menunjuk ke node pertama (next).

   - Node pertama menunjuk ke node terakhir (prev).

   - Tidak memiliki NULL, traversal membentuk lingkaran.

## Fungsi dan Analogi Jenis Doubly Linked List

| Jenis DLL                   | Fungsi Umum                                          | Analogi Kehidupan Nyata                                     |
| --------------------------- | ---------------------------------------------------- | ----------------------------------------------------------- |
| Doubly Linked List Biasa    | - Navigasi data dua arah (maju & mundur)             | Gerbong kereta yang bisa ditarik maju atau mundur           |
|                             | - Menyisipkan atau menghapus node di tengah list     | Jalur rel kereta bolak-balik                                |
| Circular Doubly Linked List | - Digunakan untuk sistem yang berputar terus-menerus | Roda kincir yang terus berputar, tidak memiliki ujung       |
|                             | - Navigasi tidak perlu kembali ke head/tail manual   | Menu pemutar lagu yang bisa loop dari akhir kembali ke awal |

---

## Gambaran SSL dan DLL

### DLL (Doubly Linked List)

```scss
NULL ← [10] ⇄ [20] ⇄ [30] ⇄ [40] → NULL
         ↑      ↑      ↑      ↑
       prev   prev   prev   prev
         ↓      ↓      ↓      ↓
NULL → [10] ⇄ [20] ⇄ [30] ⇄ [40] ← NULL

- Bisa maju (next) dan mundur (prev)
- Lebih fleksibel saat traversal
```

## Perbandingan singkat

| Fitur             | SLL              | DLL                            |
| ----------------- | ---------------- | ------------------------------ |
| Arah Traversal    | Satu arah (next) | Dua arah (prev & next)         |
| Pointer per Node  | 1 (next)         | 2 (prev & next)                |
| Operasi Backtrack | Tidak bisa       | Bisa                           |
| Memori            | Lebih hemat      | Lebih besar (karena 2 pointer) |

---

### SLL (Singly Linked List)

```scss
Head
 ↓
[10] → [20] → [30] → [40] → NULL
        ↑     ↑     ↑
      next  next  next

- Hanya bisa maju (forward)
- Tidak bisa mundur
```

## Struktur Program DLL (C++)

```cpp
struct Node {
    int data;
    Node* prev;
    Node* next;
};
```

#### a. Insert dan print sederhana

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;

void insertDepan(int value) {
    Node* baru = new Node{value, nullptr, head};
    if (head != nullptr)
        head->prev = baru;
    head = baru;
}

void printMaju() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    insertDepan(10);
    insertDepan(20);
    insertDepan(30);
    printMaju(); // 30 <-> 20 <-> 10 <-> NULL
    return 0;
}
```

### b. hapus node

```cpp
void hapusDepan() {
    if (head == nullptr) return;
    Node* temp = head;
    head = head->next;
    if (head != nullptr)
        head->prev = nullptr;
    delete temp;
}
```

### c. print mundur

```cpp
void printMundur() {
    Node* temp = head;
    if (!temp) return;

    while (temp->next != nullptr)
        temp = temp->next;

    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    cout << "NULL\n";
}
```
