// Bubble sort
#include <iostream>
#include <string>
using namespace std;

const int MAX_PLAYERS = 5;

struct Player {
    string name;
    int score;
};

// Bubble Sort: Mengurutkan dari skor tertinggi ke terendah
void bubbleSort(Player arr[], int n) {
    for (int i = 0; i < n - 1; ++i) { // bandingin sebelah kanan
        for (int j = 0; j < n - i - 1; ++j) { // bandingin sebelah kiri
            if (arr[j].score < arr[j + 1].score) { // bandingin score
                swap(arr[j], arr[j + 1]); // dia bakal sorting atau nge swapped
            }
        }
    }
}

int main() {
    Player players[MAX_PLAYERS];

    cout << "=== Input Skor Pemain ===" << endl;
    for (int i = 0; i < MAX_PLAYERS; ++i) {
        cout << "Nama Pemain " << i + 1 << ": ";
        cin >> players[i].name;
        cout << "Skor       : ";
        cin >> players[i].score;
    }

    bubbleSort(players, MAX_PLAYERS);

    cout << "\n=== Leaderboard ===" << endl;
    for (int i = 0; i < MAX_PLAYERS; ++i) {
        cout << i + 1 << ". " << players[i].name << " - " << players[i].score << endl;
    }

    return 0;
}
