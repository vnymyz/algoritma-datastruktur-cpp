# Pertemuan 14

# Binary Search Tree (BST)

## 1. Apa itu BST ?

Binary Search Tree (BST) adalah struktur data pohon biner di mana setiap node memiliki:

- Nilai di kiri lebih kecil dari root

- Nilai di kanan lebih besar dari root

```mathematica
      50
     /  \
   30    70
  / \    / \
20  40  60  80

```

## 2. Operasi Dasar pada BST

Insert: Menambahkan node sesuai aturan BST

Search: Mencari node berdasarkan nilai

Delete: Menghapus node dengan 3 kemungkinan:

- Node adalah leaf

- Node punya satu child

- Node punya dua child

## 3. Implementasi C++ BST

#### 1. Struktur Node

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;        // Nilai dari node
    Node* left;      // Anak kiri (lebih kecil)
    Node* right;     // Anak kanan (lebih besar)

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
```

#### 2. Insert Node

```cpp
Node* insert(Node* root, int val) {
    if (root == nullptr) return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}
```

#### 3. Search Node

```cpp
bool search(Node* root, int key) {
    if (root == nullptr) return false;
    if (root->data == key) return true;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}
```

#### 4. Delete Node

```cpp
Node* findMin(Node* root) {
    while (root->left != nullptr)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // 1 atau 0 child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // 2 child
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}
```

#### 5. Inorder Traversal

```cpp
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
```

#### 6. Aplikasi Menu BST

```cpp
int main() {
    Node* root = nullptr;
    int choice, value;

    do {
        cout << "\n1. Insert\n2. Search\n3. Delete\n4. Tampilkan Inorder\n0. Keluar\nPilih: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> value;
                root = insert(root, value);
                break;
            case 2:
                cout << "Masukkan nilai yang dicari: ";
                cin >> value;
                if (search(root, value))
                    cout << "Data ditemukan\n";
                else
                    cout << "Data tidak ditemukan\n";
                break;
            case 3:
                cout << "Masukkan nilai yang dihapus: ";
                cin >> value;
                root = deleteNode(root, value);
                break;
            case 4:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;
            case 0:
                cout << "Terima kasih\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (choice != 0);

    return 0;
}
```

## Alur Binary Search Tree (BST)

---

### Alur Fungsi insert(Node\* root, int val)

```sql
         Apakah root == nullptr?
               |
             Ya → Buat node baru dan return
               |
             Tidak
               ↓
     Apakah val < root->data?
        /                \
      Ya                  Tidak
     /                      \
Ke subtree kiri        Ke subtree kanan
     |                        |
 Rekursif insert        Rekursif insert
     ↓                        ↓
  root->left = ...        root->right = ...
```

### 1. Insert

Contoh: Insert angka **50, 30, 70, 20, 40, 60, 80**

### Langkah 1: Insert 50

Pohon masih kosong → 50 jadi root.

```
50
```

### Langkah 2: Insert 30

30 < 50 → masuk ke kiri dari 50

```
   50
  /
30
```

### Langkah 3: Insert 70

70 > 50 → masuk ke kanan dari 50

```
   50
  /  \
30   70
```

### Langkah 4: Insert 20

20 < 50 → kiri

20 < 30 → kiri dari 30

```
     50
    /  \
  30   70
  /
20
```

### Langkah 5: Insert 40

40 < 50 → kiri

40 > 30 → kanan dari 30

```
     50
    /  \
  30   70
  / \
20  40
```

### Langkah 6: Insert 60

60 > 50 → kanan

60 < 70 → kiri dari 70

```
     50
    /  \
  30   70
  / \   /
20  40 60
```

### Langkah 7: Insert 80

80 > 50 → kanan

80 > 70 → kanan dari 70

```
     50
    /  \
  30   70
  / \   / \
20  40 60 80
```

### Ringkasan

1. Mulai dari root.

2. Jika val < root->data, pindah ke kiri.

3. Jika val > root->data, pindah ke kanan.

4. Ulangi sampai menemukan posisi kosong (nullptr), lalu buat node baru.

5. Setiap return akan menyambungkan node baru ke parent-nya.

### Alur Fungsi deleteNode(Node\* root, int key)

```sql
     Apakah root == nullptr?
            |
           Ya → return root (tidak ditemukan)
            |
           Tidak
            ↓
  Apakah key < root->data?
      /               \
    Ya                 Tidak
   /                      \
 Rekursif kiri        Apakah key > root->data?
                         /       \
                       Ya         Tidak (key == root->data)
                      /                 \
         Rekursif kanan             Proses penghapusan
                                       |
                            --------------------------
                            |                        |
                Apakah hanya 1 anak / tidak ada anak? |
                /                    \                |
          Ya (leaf/1 anak)       Tidak (2 anak)       |
                |                    |                |
         Ganti node dg         Cari nilai min        |
          anak kiri/kanan     dari subtree kanan     |
                |                    |                |
            Hapus node       Salin data min ke root  |
                |            Hapus node duplikat     |
            return temp      di subtree kanan        |
                            --------------------------
```

### 2. Delete Node

pohon sebelum dihapus

```
     50
    /  \
  30   70
  / \   / \
20  40 60 80
```

#### Ada 3 kemungkinan saat menghapus node

- Node adalah daun (tidak punya anak) → langsung hapus.

- Node punya 1 anak → sambungkan anaknya ke parent node yang dihapus.

- Node punya 2 anak → ganti data node dengan in-order successor (node terkecil di subtree kanan), lalu hapus node pengganti.

### Langkah-Langkah Fungsi deleteNode(root, key)

### Langkah 1: Cari node yang ingin dihapus

```cpp
if (key < root->data)
    root->left = deleteNode(root->left, key);
else if (key > root->data)
    root->right = deleteNode(root->right, key);
```

> Rekursif: bergerak ke kiri atau kanan hingga menemukan node dengan nilai key.

### Langkah 2: Node ditemukan, cek jumlah anaknya

```cpp
else {
    // Kasus node ditemukan
```

### Kasus 1: Node tanpa anak (daun)

```
if (root->left == nullptr && root->right == nullptr) {
    delete root;
    return nullptr;
}
```

Contoh: hapus 20 → langsung dihapus karena tidak punya anak.

```
   30
  /
20   ← dihapus
```

### Kasus 2: Node dengan 1 anak

```cpp
else if (root->left == nullptr) {
    Node* temp = root->right;
    delete root;
    return temp;
}
else if (root->right == nullptr) {
    Node* temp = root->left;
    delete root;
    return temp;
}
```

Contoh: hapus 30 (hanya punya anak kiri 20)

```yaml
  50
 /
30   ← dihapus, digantikan 20
/
20

→ menjadi:
  50
 /
20
```

### Kasus 3: Node dengan 2 anak

```cpp
else {
    Node* temp = findMin(root->right);  // cari nilai terkecil di kanan
    root->data = temp->data;            // ganti data root
    root->right = deleteNode(root->right, temp->data); // hapus pengganti
}
```

Contoh: hapus 50 (punya dua anak: 30 dan 70)

→ cari min di kanan → 60

→ ganti 50 dengan 60

→ hapus 60 dari subtree kanan

```
     50
    /  \
  30   70
       /
     60

→ setelah dihapus:

     60
    /  \
  30   70
```

### Ringkasan alur deletenode

Ringkasan Alur deleteNode

1. Cari node dengan nilai key secara rekursif.

2. Jika ditemukan:

- Jika tidak ada anak → hapus langsung.

- Jika 1 anak → sambungkan anaknya ke parent.

- Jika 2 anak:

  - Cari in-order successor (findMin dari subtree kanan).

  - Ganti nilai node dengan nilai successor.

  - Hapus node successor dari subtree.

### 3. Findmin()

### Alur Fungsi findMin(Node\* root)

```sql
Selama root->left != nullptr:
       |
     root = root->left
       |
     (looping kiri terus)
       ↓
return root (paling kiri)
```

### Kode fungsi findmind()

```cpp
Node* findMin(Node* root) {
    while (root->left != nullptr)
        root = root->left;
    return root;
}
```

### Langkah - Langkah Findmin()

Misal kita punya BST :

```
      50
     /  \
   30    70
  / \    / \
20  40  60 80
```

### Langkah 1: Mulai dari root

```cpp
root = 50;
```

Cek root->left → ada (yaitu 30), lanjut turun ke kiri.

### Langkah 2: Pindah ke 30

```cpp
root = 30;
```

Cek root->left → ada (yaitu 20), lanjut turun ke kiri.

### Langkah 3: Pindah ke 20

```cpp
root = 20;
```

Cek root->left → nullptr, berarti ini node terkecil.

### Return

Kembalikan root, yaitu node dengan data 20.

```cpp
return root;  // node 20
```

### Kesimpulan Findmin()

- Fungsi findMin() akan terus bergerak ke kiri hingga menemukan node yang tidak punya anak kiri lagi.

- Node tersebut adalah node dengan nilai terkecil di subtree atau seluruh BST.

### 4. Inorder

### Alur Fungsi inorder(Node\* root)

Fungsi ini digunakan untuk traversal Inorder pada Binary Tree atau Binary Search Tree (BST).
Inorder traversal berarti mengunjungi node dalam urutan:

Left → Root → Right

```sql
Base case: root == nullptr → return

Langkah-langkah:
1. inorder(root->left)
2. Cetak root->data
3. inorder(root->right)

(Left → Root → Right)
```

### Kode Fungsi Inorder

```cpp
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
```

Misal kita punya BST :

```
      50
     /  \
   30    70
  / \    / \
20  40  60 80
```

Langkah-langkah rekursifnya:

1. Mulai dari root (50)

2. Panggil inorder(root->left) → masuk ke 30

3. Panggil inorder(root->left) → masuk ke 20

4. 20 tidak punya anak kiri → cetak 20 → lanjut inorder(root->right) → kosong

5. Kembali ke 30 → cetak 30 → lanjut ke kanan → 40

6. 40 tidak punya anak kiri → cetak 40 → lanjut kanan → kosong

7. Kembali ke 50 → cetak 50 → lanjut ke kanan → 70

8. Masuk ke 70 → kiri: 60 → cetak 60

9. Cetak 70 → kanan: 80 → cetak 80

### Output

```
20 30 40 50 60 70 80
```

### Ringkasan

1. Insert – Tempatkan node baru di posisi yang sesuai (rekursif berdasarkan nilai).

2. Search – Telusuri BST secara efisien (kiri atau kanan tergantung perbandingan nilai).

3. Delete – Tangani 3 kasus:

- Leaf (hapus langsung)

- 1 anak (ganti dengan anak)

- 2 anak (ambil successor → salin → hapus successor)

4. Inorder Traversal – Cetak isi BST secara urut (ascending).
