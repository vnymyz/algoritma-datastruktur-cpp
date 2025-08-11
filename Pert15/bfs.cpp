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
