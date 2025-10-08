#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Fungsi untuk menentukan prioritas operator
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Fungsi untuk mengecek apakah karakter adalah operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Fungsi utama konversi infix ke postfix
string infixToPostfix(string infix) {
    string postfix = "";
    stack<char> s;

    for (char c : infix) {
        if (c == ' ') continue; // Lewati spasi

        if (isalnum(c)) {
            // Jika operand (huruf/angka), langsung tambahkan ke postfix
            postfix += c;
            postfix += ' ';
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            // Keluarkan semua operator sampai tanda '('
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                postfix += ' ';
                s.pop();
            }
            if (!s.empty()) s.pop(); // Hapus tanda '('
        }
        else if (isOperator(c)) {
            // Keluarkan operator yang lebih tinggi atau sama dari stack
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                postfix += ' ';
                s.pop();
            }
            s.push(c);
        }
    }

    // Keluarkan semua sisa operator dari stack
    while (!s.empty()) {
        postfix += s.top();
        postfix += ' ';
        s.pop();
    }

    return postfix;
}

int main() {
    string infix;

    cout << "Masukkan ekspresi infix (contoh: A+B*C): ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;

    return 0;
}
