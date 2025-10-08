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
