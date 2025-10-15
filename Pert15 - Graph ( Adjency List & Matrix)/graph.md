# Pertemuan 15

## Graph (Adjancency List / Matrix)

## Tujuan Pembelajaran ?

- Memahami konsep dasar graph dan komponennya.

- Mengerti dua cara representasi graph: Adjacency List & Adjacency Matrix.

- Mampu mengimplementasikan BFS (Breadth-First Search) dan DFS (Depth-First Search) di C++.

- Membedakan kapan BFS atau DFS lebih sesuai digunakan.

## 1. Graph

Graph adalah struktur data yang terdiri dari node (vertex) dan edge (sisi) yang menghubungkan node tersebut.

Bayangkan kamu punya titik-titik (disebut node atau vertex) dan garis-garis yang menghubungkannya (disebut edge).

Graph Sederhana :

```lua
   (0)---(1)
    |    / \
    |   /   \
   (2)-(4)--(3)
```

### Jenis Graph

#### Berdasarkan arah :

- Directed Graph. graf berarah. Garis hanya bisa dilewati satu arah. Contoh: Jalan satu arah.

- Undirected Graph. graf tak berarah. Garis bisa dilewati bolak-balik. Contoh: Jalan dua arah.

#### Berdasarkan Bobot :

- Weighted Graph. graf berbobot. Setiap garis punya bobot/angka (misalnya jarak, waktu, biaya).

- Unweighted Graph. graf tanpa bobot. Tidak ada angka di garisnya.

#### Komponen Penting :

- V = jumlah vertex

- E = jumlah edge

### Contoh Dunia Nyata

- Titik = kota

- Garis = jalan antar kota

- Kalau ada jalan dari Kota A ke Kota B, artinya ada edge dari A ke B.

### Bagaimana Menyimpan Graph di Program?

Graph bisa disimpan di komputer dalam dua cara utama:

## 2. Adjacency Matrix

- Dia ini bentukan matriks nya 2D ukuran V x V.

- Nilai 1 (atau bobot) menandakan ada edge, 0 jika tidak ada.

- Bentuknya seperti tabel persegi V x V, di mana V adalah jumlah vertex.

- Kalau ada edge, kita isi 1 (atau bobotnya), kalau tidak ada, kita isi 0.

Ilustrasi :

```yaml
Vertex: 0, 1, 2
Edge: (0-1), (1-2)
```

matriks nya :

```yaml
0 1 0
1 0 1
0 1 0
```

Matriks V x V, isi 1 kalau ada edge.

```mathematica
    0 1 2 3 4
  0 0 1 1 0 0
  1 1 0 0 1 1
  2 1 0 0 0 1
  3 0 1 0 0 1
  4 0 1 1 1 0
```

#### Artinya :

- Baris 0 kolom 1 = 1 → node 0 terhubung ke 1

- Baris 1 kolom 4 = 1 → node 1 terhubung ke 4, dst.

### Kelebihan

- Akses cepat O(1) untuk memeriksa hubungan antar node.

- Cocok untuk graph yang dense (banyak edge).

- Cepat untuk cek apakah dua node terhubung.

- Sederhana.

### Kekurangan

- Memakan banyak memori untuk graph sparse.

- Boros memori kalau graf jarang punya edge.

### Contoh implementasi Adj Matrix C++

```cpp
#include <iostream>
using namespace std;

int main() {
    // Jumlah vertex
    int V = 4;

    // Adjacency Matrix untuk graph:
    // 0 --- 1
    // |     |
    // 2 --- 3
    int adjMatrix[4][4] = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0}
    };

    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

```

## 3. Adjacency List

- Menggunakan array atau vector of vectors.

- Setiap vertex atau node memiliki daftar tetangga.

- Disimpan pakai array of vector atau `vector<vector<int>>`.

```yaml
0: 1
1: 0, 2
2: 1
```

Daftar tetangga tiap node :

```
0: 1, 2
1: 0, 3, 4
2: 0, 4
3: 1, 4
4: 1, 2, 3
```

### Artinya :

- Node 0 terhubung ke node 1 dan 2.

- Node 4 terhubung ke 1, 2, 3, dst.

### Kelebihan

- Hemat memori untuk graph sparse.

- Traversal lebih cepat untuk node dengan sedikit atau jarang edge.

### Kekurangan

- Pengecekan edge lebih lambat dibanding adjacency matrix.

- Cek apakah ada edge sedikit lebih lambat.

### Contoh Implementasi Adj List C++

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Jumlah vertex
    int V = 4;

    // Adjacency List untuk graph:
    // 0 --- 1
    // |     |
    // 2 --- 3
    vector<int> adjList[4];

    // Tambahkan edge (undirected)
    adjList[0] = {1, 2};
    adjList[1] = {0, 3};
    adjList[2] = {0, 3};
    adjList[3] = {1, 2};

    // Cetak adjacency list
    cout << "Adjacency List:\n";
    for (int i = 0; i < V; i++) {
        cout << i << ": ";
        for (int neighbor : adjList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    return 0;
}

```

## 4. BFS - Breadth First Search (Queue)

- Queue dan tidak ada backtracking. (FIFO) First In First Out.

- BFS itu seperti kita mencari teman dari teman.

- Kita cek semua tetangga dari node awal, lalu cek tetangga dari tetangga tersebut, dan seterusnya.

- Mengunjungi node level demi level (berbasis queue).

- Cocok untuk mencari jalur terpendek di unweighted graph.

- Bisa menampung ukuran memori yang besar karena bakal nginget semua node nya.

### Langkah

- Pilih node awal, masukkan ke queue.

- Tandai sebagai visited atau sudah dikunjungi.

- Keluarkan dari queue, kunjungi semua tetangga yang belum visited atau dikunjungi.

- Ulangi sampai queue kosong.

### Ilustrasi

Traversal level demi level pakai queue.
Mulai dari node 0.

```yaml
Queue: [0]        → Visit: 0
Queue: [1, 2]     → Visit: 1
Queue: [2, 3, 4]  → Visit: 2
Queue: [3, 4]     → Visit: 3
Queue: [4]        → Visit: 4
Queue: []         → Done!

Urutan kunjungan: 0 → 1 → 2 → 3 → 4
```

ilustrasi per level :

```yaml
Level 0: 0
Level 1: 1, 2
Level 2: 3, 4
```

### Implementasi C++ dalam BFS

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int V = 4;
    vector<int> adjList[4];

    // Graph:
    // 0 --- 1
    // |     |
    // 2 --- 3
    adjList[0] = {1, 2};
    adjList[1] = {0, 3};
    adjList[2] = {0, 3};
    adjList[3] = {1, 2};

    bool visited[4] = {false};
    queue<int> q;

    int start = 0; // mulai BFS dari node 0
    visited[start] = true;
    q.push(start);

    cout << "Hasil BFS: ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;

    return 0;
}
```

## 5. DFS - Depth First Search

- Stack dan ada backtracking. LIFO ( Last In First Out)

- DFS itu seperti masuk ke gua: kita masuk sedalam mungkin, kalau mentok baru mundur.

- Mengunjungi node sedalam mungkin sebelum backtrack.

- Menggunakan rekursi atau stack.

- DFS hanya akan meningat 1 child dari node. Dia tidak bisa menampung banyak memori.

### Langkah

- Mulai dari node awal.

- Tandai node sebagai visited.

- Kunjungi tetangga pertama yang belum dikunjungi (rekursif).

- Jika semua sudah, kembali (backtrack) atau ulangi sampai semua sudah di kunjungi.

### Ilustrasi DFS

Traversal sedalam mungkin pakai rekursi atau stack.
Mulai dari node 0.

```makefile
Visit: 0
 → ke 1
    → ke 3
       → ke 4
          → ke 2
```

urutan kunjungan :

```
0 → 1 → 3 → 4 → 2
```

ASCII ilustrasi jalurnya :

```makefile
0
 \
  1
   \
    3
     \
      4
       \
        2
```

### Contoh implementasi DFS C++ (Rekursi)

```cpp
#include <iostream>
#include <vector>
using namespace std;

bool visited[4];
vector<int> adjList[4];

void dfs(int node) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    int V = 4;

    // Graph:
    // 0 --- 1
    // |     |
    // 2 --- 3
    adjList[0] = {1, 2};
    adjList[1] = {0, 3};
    adjList[2] = {0, 3};
    adjList[3] = {1, 2};

    fill(begin(visited), end(visited), false);

    cout << "Hasil DFS: ";
    dfs(0); // mulai dari node 0
    cout << endl;

    return 0;
}

```

---

## Kesimpulan dari semua

| **Topik**                      | **Penjelasan Singkat**                                                                                                                     | **Kelebihan**                                                                   | **Kekurangan**                                                 | **Contoh Kasus**                                          |
| ------------------------------ | ------------------------------------------------------------------------------------------------------------------------------------------ | ------------------------------------------------------------------------------- | -------------------------------------------------------------- | --------------------------------------------------------- |
| **Graph**                      | Struktur data berisi **vertex** (titik) dan **edge** (garis) yang menghubungkan vertex. Bisa berarah/tak berarah, berbobot/tidak berbobot. | Dapat merepresentasikan hubungan/relasi secara fleksibel.                       | Butuh pemahaman konsep lebih dalam dibanding array/list biasa. | Peta kota, jejaring sosial, jaringan komputer.            |
| **Adjacency Matrix**           | Matriks `V x V` yang menyimpan hubungan antar vertex.                                                                                      | Cek edge sangat cepat (**O(1)**), sederhana diimplementasikan.                  | Boros memori untuk graph yang jarang edge (**sparse**).        | Representasi peta kota kecil yang saling terhubung penuh. |
| **Adjacency List**             | Setiap vertex punya daftar tetangganya, disimpan dalam array/list.                                                                         | Hemat memori untuk graph sparse, traversal cepat.                               | Cek edge lebih lambat dibanding matrix.                        | Representasi hubungan pertemanan di sosial media.         |
| **BFS** (Breadth-First Search) | Menjelajah graph **level demi level** menggunakan **queue**.                                                                               | Menemukan jalur terpendek di unweighted graph, traversal sistematis.            | Butuh memori lebih untuk menyimpan queue.                      | Pencarian rute tercepat di Google Maps.                   |
| **DFS** (Depth-First Search)   | Menjelajah graph **sedalam mungkin** sebelum backtrack, pakai **rekursi** atau stack.                                                      | Implementasi mudah dengan rekursi, cocok untuk mencari semua kemungkinan jalur. | Tidak selalu menemukan jalur terpendek.                        | Memecahkan puzzle maze/labirin.                           |
