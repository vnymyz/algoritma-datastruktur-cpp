// Konversi ekspresi Postfix ke Infix
// Contoh:
// Postfix:  AB+
// Infix  :  (A + B)

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Fungsi untuk mengubah ekspresi postfix menjadi infix
string postfixToInfix(string postfix) {
    stack<string> s;  // Stack untuk menyimpan operand

    for (char c : postfix) {
        if (c == ' ') continue; // Lewati spasi

        if (isalnum(c)) {
            // Jika karakter adalah operand (huruf/angka), masukkan ke stack
            s.push(string(1, c));
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            // Jika operator, ambil dua operand teratas dari stack
            string right = s.top(); s.pop();
            string left  = s.top(); s.pop();

            // Gabungkan menjadi ekspresi infix dengan tanda kurung
            string expr = "(" + left + " " + c + " " + right + ")";
            s.push(expr); // Masukkan kembali ke stack
        }
    }

    return s.top(); // Hasil akhir ada di puncak stack
}

int main() {
    string postfix;

    // Input ekspresi postfix dari user
    cout << "Masukkan ekspresi postfix (contoh: AB+): ";
    getline(cin, postfix);

    // Konversi dan tampilkan hasil
    string infix = postfixToInfix(postfix);
    cout << "Infix: " << infix << endl;

    return 0;
}
