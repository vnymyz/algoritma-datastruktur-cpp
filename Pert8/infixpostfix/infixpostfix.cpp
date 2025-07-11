// Konversi ekspresi Infix ke Postfix (tanpa operator precedence)
// Contoh:
// Infix   : A + B
// Postfix : A B +

#include <iostream>
#include <string>
using namespace std;

// Fungsi untuk mengubah ekspresi infix ke postfix
string infixToPostfix(string infix) {
    string postfix = "";

    for (char c : infix) {
        if (c == ' ') continue; // Lewati spasi

        if (isalnum(c)) {
            // Jika karakter huruf/angka (operand), langsung ditambahkan ke postfix
            postfix += c;
            postfix += ' ';
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            // Jika operator, tambahkan ke postfix
            postfix += c;
            postfix += ' ';
        }
    }

    return postfix;
}

int main() {
    string infix;

    // Input dari user
    cout << "Masukkan ekspresi infix (contoh: A+B): ";
    getline(cin, infix);

    // Konversi dan tampilkan hasil
    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;

    return 0;
}
