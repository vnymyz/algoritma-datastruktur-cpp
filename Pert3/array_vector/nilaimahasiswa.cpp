#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nilai;
    int input, n;

    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Nilai mahasiswa ke-" << i+1 << ": ";
        cin >> input;
        nilai.push_back(input);
    }

    cout << "\nDaftar Nilai:\n";
    for (int i = 0; i < nilai.size(); i++) {
        cout << "Mahasiswa " << i+1 << " = " << nilai[i] << endl;
    }

    return 0;
}
