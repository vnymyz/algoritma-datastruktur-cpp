# Pertemuan 13

## Trees - Binary Tree & Traversal

## Apa saja yang dipelajari ?

1. Binary Tree

2. Preoder

3. inorder

4. postorder traversal

## Tujuan

1. Memahami konsep dasar struktur data pohon, terutama binary tree.

2. Mampu mengimplementasikan dan menelusuri tree menggunakan preorder, inorder, dan postorder traversal.

## Manfaat

1. Meningkatkan logika algoritmik dalam menyelesaikan masalah berbasis hierarki.

2. Dasar penting untuk belajar struktur data lanjutan seperti BST (Binary Search Tree), AVL Tree, Heap, dan lainnya.

3. Berguna untuk aplikasi seperti compiler, file system, AI, game tree, dan banyak lagi.

## Teori Binary Tree dan Traversal

### Apa itu Binary Tree

Binary Tree adalah struktur data pohon di mana setiap node memiliki paling banyak 2 anak (left dan right). Berikut bentuk pohonnya :

```mathematica
        A
       / \
      B   C
     / \   \
    D   E   F

```

### Sifat-sifat Binary Tree

- Root: Node utama paling atas.

- Child: Anak node (bisa left/right).

- Leaf: Node tanpa anak.

- Subtree: Cabang dari pohon.

```mathematica
           A               ← Root
         /   \
        B     C           ← Child dari A
       / \     \
      D   E     F         ← Child dari B dan C
                         ↳ Leaf Nodes: D, E, F
```

Penjelasan Visual :

#### Root

- Node paling atas dari pohon.

- Di sini: A

#### Child

Node yang memiliki parent (bukan root).

Contoh:

- B dan C adalah anak dari A.

- D dan E adalah anak dari B.

- F adalah anak dari C.

#### Leaf

- Node tanpa anak (left dan right-nya nullptr).

- Di sini: D, E, dan F

#### Subtree

Setiap cabang dari node ke bawah termasuk subtree. Misalnya :

- Subtree kiri dari A:

```mathematica
    B
   / \
  D   E
```

- Subtree kanan dari A:

```mathematica
    C
     \
      F
```

| Elemen  | Node           |
| ------- | -------------- |
| Root    | A              |
| Child   | B, C, D, E, F  |
| Leaf    | D, E, F        |
| Subtree | (B-D-E), (C-F) |

### Traversal pada Binary Tree

Traversal adalah proses mengunjungi setiap node dalam struktur pohon.
| Tipe Traversal | Urutan |
| -------------- | ------------------- |
| Preorder | Root ➝ Left ➝ Right |
| Inorder | Left ➝ Root ➝ Right |
| Postorder | Left ➝ Right ➝ Root |

Hasil Kunjungan Node:
| **Traversal Type** | **Urutan Kunjungan (Langkah)** |
| ------------------ | ------------------------------ |
| **Preorder** | A → B → D → E → C → F |
| **Inorder** | D → B → E → A → C → F |
| **Postorder** | D → E → B → F → C → A |

Penjelasan Visual :

#### 1. Preorder (Root → Left → Right)

Urutan: A → B → D → E → C → F

```mathematica
Traversal Order:
        1
        A < --- ini adalah root
       / \
     2     5
    B       C
   / \       \
 3    4       6
D     E       F

```

#### 2. Inorder (Left ➝ Root ➝ Right)

Urutan: D → B → E → A → C → F

```mathematica
Traversal Order:
        4
        A
       / \
     2     5
    B       C
   / \       \
 1    3       6
D     E       F

```

#### 3. Postorder (Left ➝ Right ➝ Root)

Urutan: D → E → B → F → C → A

```mathematica
Traversal Order:
        6
        A
       / \
     3     5
    B       C
   / \       \
 1    2       4
D     E       F
```

#### Penjelasan singkat

1. Preorder: Root dulu, baru anak-anaknya.

2. Inorder: Anak kiri ➝ root ➝ anak kanan.

3. Postorder: Anak-anak dulu semua ➝ baru root.

### Analogi

Kalau dalam kehidupan sehari-hari. Ceritanya disini kita mau mengemas barang di rumah. Misal kita mau mengatur barang dalam rumah dan rumah tersebut ruangan nya ada 3 :

```mathematica
        Rumah (A)
       /         \
   Kamar (B)    Dapur (C)
   /     \           \
Lemari(D) Meja(E)    Kulkas(F)
```

Berarti :

- Preorder: Mulai dari rumah ➝ masuk kamar ➝ bersihkan lemari ➝ bersihkan meja ➝ pindah ke dapur ➝ bersihkan kulkas

- Inorder: Mulai dari lemari ➝ ke kamar ➝ ke meja ➝ ke rumah ➝ ke dapur ➝ ke kulkas

- Postorder: Mulai dari lemari ➝ meja ➝ kamar ➝ kulkas ➝ dapur ➝ rumah

### Implementasi Coding C++

#### Struktur Node dan Binary Tree

```cpp
#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char val) {
        data = val;
        left = right = nullptr;
    }
};
```

#### Fungsi Traversal

```cpp
void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
```

#### Contoh Penggunaan

```cpp
int main() {
    Node* root = new Node('A');
    root->left = new Node('B');
    root->right = new Node('C');
    root->left->left = new Node('D');
    root->left->right = new Node('E');
    root->right->right = new Node('F');

    cout << "Preorder Traversal: ";
    preorder(root); cout << endl;

    cout << "Inorder Traversal: ";
    inorder(root); cout << endl;

    cout << "Postorder Traversal: ";
    postorder(root); cout << endl;

    return 0;
}

```

#### Penjelasan Kodingan

| Bagian Kode            | Deskripsi                                                                                        |
| ---------------------- | ------------------------------------------------------------------------------------------------ |
| `#include <iostream>`  | Mengimpor library untuk input/output standar di C++.                                             |
| `using namespace std;` | Menghindari penulisan `std::` sebelum `cout`, `endl`, dll.                                       |
| `struct Node`          | Struktur data untuk membuat simpul (node) pada Binary Tree.                                      |
| `char data;`           | Menyimpan data karakter (contoh: 'A', 'B', dst).                                                 |
| `Node* left;`          | Pointer ke anak kiri node.                                                                       |
| `Node* right;`         | Pointer ke anak kanan node.                                                                      |
| `Node(char val)`       | Constructor: saat objek Node dibuat, nilai data diisi dan pointer kiri/kanan diset ke `nullptr`. |

```mathematica
        A
       / \
      B   C
     / \    \
    D   E    F
```

| Kode                                  | Operasi yang Dilakukan              |
| ------------------------------------- | ----------------------------------- |
| `Node* root = new Node('A');`         | Membuat node root dengan nilai 'A'. |
| `root->left = new Node('B');`         | Node B menjadi anak kiri dari A.    |
| `root->right = new Node('C');`        | Node C menjadi anak kanan dari A.   |
| `root->left->left = new Node('D');`   | Node D menjadi anak kiri dari B.    |
| `root->left->right = new Node('E');`  | Node E menjadi anak kanan dari B.   |
| `root->right->right = new Node('F');` | Node F menjadi anak kanan dari C.   |

#### Output Program

```mathematica
Preorder Traversal: A B D E C F
Inorder Traversal: D B E A C F
Postorder Traversal: D E B F C A
```

Bentuk struktur pohonnya :

```mathematica
        A
       / \
      B   C
     / \    \
    D   E    F
```

Penjelasan :

1. A adalah root.

2. A punya dua anak: B di kiri dan C di kanan.

3. B punya dua anak juga: D di kiri dan E di kanan.

4. C hanya punya anak kanan, yaitu F.

### Implementasi di dalam dunia kerja

- Compiler: Membaca syntax program melalui parse tree yang ditelusuri menggunakan preorder/inorder/postorder.

- Database Indexing: Traversal digunakan pada B-Tree dan AVL Tree untuk pencarian data.

- File System: Struktur folder seperti pohon, traversal dipakai untuk menelusuri direktori.

### Implementasi di dalam Game Development

- AI Decision Tree: Pohon keputusan untuk AI musuh sering dibangun seperti binary tree.

- Game State Tree: Digunakan untuk menyimpan semua kemungkinan langkah dalam game seperti catur.

- Scene Graph: Pohon digunakan untuk memetakan objek dalam dunia 3D.

## Kesimpulan

- Binary Tree adalah dasar dari banyak struktur data penting.

- Dengan memahami traversal (preorder, inorder, postorder), kamu bisa memecahkan banyak masalah yang melibatkan hierarki data.

- Traversal sangat berguna di berbagai bidang: dari AI, compiler, game, hingga filesystem.

### Latihan

#### 1. Diberikan sebuah struktur binary tree seperti berikut:

```css
        M
       / \
      B   Q
     / \   \
    A   C   Z
```

Tentukan :

1. Preorder Traversal

2. Inorder Traversal

3. Postorder Traversal

#### 2. Diberikan sebuah struktur binary tree seperti berikut:

```css
         F
       /   \
      D     J
     / \    /
    B   E  G
         \
          C
```

Tentukan :

1. Preorder Traversal

2. Inorder Traversal

3. Postorder Traversal
