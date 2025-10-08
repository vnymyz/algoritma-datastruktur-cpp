## Pertemuan 1 – Intro to C++ & Problem Solving

- C++: bahasa pemrograman, IDE & compiler.

- Struktur program: #include, main(), using namespace std.

- Tipe data: int, float, double, char, string, bool.

- Variabel & konstanta (const).

- Input/output: cin, cout.

- Algoritma dasar & flowchart.

```cpp
#include <iostream>
using namespace std;

int main() {
    int umur;
    cout << "Masukkan umur: ";
    cin >> umur;
    cout << "Umur Anda: " << umur << endl;
    return 0;
}

```

## Pertemuan 2 – Control Flow & Functions

- Percabangan: if, else if, else, switch.

- Perulangan: for, while, do-while.

- Fungsi: deklarasi, parameter, return value.

- Rekursi sederhana.

```cpp
#include <iostream>
using namespace std;

int tambah(int a, int b) { return a+b; }

int main() {
    int x=5, y=3;
    if(x>y) cout << "X lebih besar\n";
    else cout << "Y lebih besar\n";

    cout << "Hasil tambah: " << tambah(x,y) << endl;
}
```

## Pertemuan 3 – Array & String

- Array 1D & 2D: deklarasi, traversal.

- Operasi: akses, update, penjumlahan.

- String: panjang, concat, substring, upper/lower case.

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[5]={1,2,3,4,5};
    for(int i=0;i<5;i++) cout << arr[i] << " ";
    cout << endl;

    string nama="Vanya";
    cout << "Panjang: " << nama.length() << ", Upper: ";
    for(char &c:nama) c=toupper(c);
    cout << nama << endl;
}
```

## Pertemuan 4 – Pointer & Dynamic Memory

- Pointer: \*, &.

- Pointer & array.

- Memory dinamis: new, delete.

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int *p = &a;
    cout << "Alamat: " << p << ", Nilai: " << *p << endl;

    int *d = new int;
    *d = 50;
    cout << "Dynamic: " << *d << endl;
    delete d;
}
```

## Pertemuan 5 – Struct & Class

- struct vs class, enkapsulasi public/private.

- Constructor & objek.

```cpp
#include <iostream>
using namespace std;

struct Buku { string judul; int harga; };

class Menu {
public:
    string name; int price;
    Menu(string n,int p){ name=n; price=p; }
};

int main() {
    Buku b = {"C++ Dasar", 50000};
    cout << b.judul << " - " << b.harga << endl;

    Menu m("Nasi Goreng",20000);
    cout << m.name << " - " << m.price << endl;
}
```

## Pertemuan 6 – Single Linked List

- Node, head, next.

- Operasi: insert, delete, traverse.

```cpp
#include <iostream>
using namespace std;

struct Node { int data; Node* next; };
int main() {
    Node* head = new Node();
    head->data = 10; head->next = nullptr;
    cout << "Node pertama: " << head->data << endl;
}
```

## Pertemuan 7 – Doubly Linked List

- Node dengan prev & next.

- Operasi insert depan/belakang, traverse maju & mundur.

```cpp
struct Node { int data; Node* next; Node* prev; };
Node* head = nullptr;
Node* n = new Node();
n->data = 5; n->next = n->prev = nullptr;
head = n;
```

## Pertemuan 8 – Stack (Array & Linked List)

- Konsep LIFO. (Last in First Out)

- Implementasi array & linked list.

- Evaluasi ekspresi postfix/infix.

```cpp
#include <iostream>
using namespace std;

int main() {
    int stack[5], top=-1;
    stack[++top]=10; stack[++top]=20;
    cout << "Top: " << stack[top] << endl;
    top--; // pop
}
```

## Pertemuan 9 – Queue (Array & Linked List)

- Konsep FIFO. (First in First Out)

- Queue biasa & circular queue.

- Kasus: antrian pelanggan.

```cpp
#include <iostream>
using namespace std;

int main() {
    int queue[5], front=0, rear=-1;
    queue[++rear]=5; queue[++rear]=10;
    cout << "Front: " << queue[front] << endl;
    front++; // dequeue
}
```

## Pertemuan 10 – Recursion & Backtracking

- Rekursi lanjutan.

- Backtracking: maze, N-Queens.

- Fokus praktik: cari jalan keluar labirin.

```cpp
#include <iostream>
using namespace std;

void printN(int n) {
    if(n==0) return;
    cout << n << " ";
    printN(n-1); // rekursi
}

int main() {
    printN(5);
}
```

## Pertemuan 11 – Searching Algorithms

### Linear Search: O(n)

- Linear Search
  Konsep: Mencari data satu per satu dari awal sampai akhir.

- Syarat: Tidak perlu data terurut.

- Kelebihan: Sederhana, cocok untuk array kecil atau data acak.

- Kekurangan: Lambat untuk data besar.

- Kompleksitas: O(n) — jumlah elemen yang dicek sebanding dengan ukuran data.

```cpp
int arr[5] = {4, 2, 7, 1, 5};
int x = 7;
for(int i=0; i<5; i++){
    if(arr[i]==x){
        cout << "Ditemukan di indeks " << i;
        break;
    }
}
```

### Binary Search: O(log n) (array terurut)

- Konsep: Mencari data dengan bagi dua (divide & conquer).

- Syarat: Data harus terurut.

- Kelebihan: Sangat cepat untuk data besar.

- Kekurangan: Harus data terurut.

- Kompleksitas: O(log n) — setiap langkah mengurangi setengah data.

- Fokus: tampilkan posisi & jumlah perbandingan.

```cpp
int arr[5] = {1, 2, 4, 5, 7}; // harus urut
int x = 5;
int l = 0, r = 4;
while(l <= r){
    int mid = (l + r)/2;
    if(arr[mid] == x) { cout << "Ditemukan di indeks " << mid; break; }
    else if(arr[mid] < x) l = mid + 1;
    else r = mid - 1;
}
```

| Linear Search                 | Binary Search          |
| ----------------------------- | ---------------------- |
| Cek satu per satu             | Bagi dua tiap langkah  |
| Data **tidak harus terurut**  | Data **harus terurut** |
| O(n)                          | O(log n)               |
| Sederhana, lambat untuk besar | Cepat, tapi butuh urut |

## Pertemuan 12 – Sorting Algorithms

- Bubble, Selection, Insertion, Merge, Quick Sort.

- Fokus: urutkan data mahasiswa.

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[5]={5,2,4,1,3};
    for(int i=0;i<4;i++)
        for(int j=0;j<4-i;j++)
            if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
    for(int i:arr) cout << i << " ";
}
```

| Sorting            | Cara Kerja                                                                                 | Kelebihan                               | Kekurangan                                  | Kompleksitas Waktu                     |
| ------------------ | ------------------------------------------------------------------------------------------ | --------------------------------------- | ------------------------------------------- | -------------------------------------- |
| **Bubble Sort**    | Bandingkan elemen bersebelahan dan tukar jika salah urut. Ulangi sampai tidak ada swap.    | Sederhana, mudah dipahami               | Lambat untuk data besar                     | O(n²)                                  |
| **Selection Sort** | Cari elemen terkecil (atau terbesar) dan tukar dengan posisi pertama yang belum diurutkan. | Minim swap, mudah diimplementasikan     | Tetap O(n²), tidak efisien untuk data besar | O(n²)                                  |
| **Insertion Sort** | Ambil satu elemen dan tempatkan di posisi yang tepat pada bagian array yang sudah terurut. | Cepat untuk data hampir terurut, stabil | Kurang efisien untuk array besar            | O(n²)                                  |
| **Merge Sort**     | Bagi array menjadi 2, urutkan masing-masing secara rekursif, lalu gabungkan (merge).       | Cepat untuk data besar, stabil          | Butuh memori tambahan                       | O(n log n)                             |
| **Quick Sort**     | Pilih pivot, pisahkan elemen < pivot dan > pivot, lalu rekursif urutkan tiap bagian.       | Cepat rata-rata, efisien di memori      | Buruk jika pivot selalu ekstrem (terurut)   | O(n log n) rata-rata, O(n²) worst-case |

## Pertemuan 13 – Trees: Binary Tree

- Node, root, leaf.

- Traversal: preorder, inorder, postorder.

```cpp
struct Node { int data; Node* left; Node* right; };

void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
```

| Traversal     | Urutan Kunjungan Node |
| ------------- | --------------------- |
| **Preorder**  | Root → Left → Right   |
| **Inorder**   | Left → Root → Right   |
| **Postorder** | Left → Right → Root   |

## Pertemuan 14 – Binary Search Tree (BST)

- Insert, delete, search di BST.

- Fokus praktik: database mahasiswa (NIM).

```cpp
Node* insert(Node* root,int val){
    if(!root) { Node* n = new Node(); n->data=val; n->left=n->right=nullptr; return n; }
    if(val<root->data) root->left=insert(root->left,val);
    else root->right=insert(root->right,val);
    return root;
}
```

## Pertemuan 15 – Graph

- Representasi: adjacency list & matrix.

- BFS (Bread First Search) & DFS (Dept First Search) traversal.

- Fokus praktik: rute perjalanan peta mini.

```cpp
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> adj[5]; // graph 0..4

void bfs(int start){
    bool visited[5]={0};
    queue<int> q; q.push(start); visited[start]=true;
    while(!q.empty()){
        int u=q.front(); q.pop();
        cout<<u<<" ";
        for(int v: adj[u]) if(!visited[v]) { visited[v]=true; q.push(v); }
    }
}
```
