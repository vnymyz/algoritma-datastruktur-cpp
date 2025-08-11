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
