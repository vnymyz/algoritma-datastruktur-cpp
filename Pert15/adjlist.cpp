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
