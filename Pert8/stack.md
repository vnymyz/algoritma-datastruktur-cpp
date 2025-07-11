# Pertemuan 8: Stack (Array & Linked List), Infix/Postfix dalam C++

## 1. Pengertian Stack

**Stack** adalah struktur data linear yang menggunakan prinsip **LIFO (Last In, First Out)**, di mana elemen terakhir yang dimasukkan akan menjadi yang pertama keluar.

**Stack** adalah struktur data linear yang menerapkan prinsip LIFO (Last In, First Out), artinya data yang terakhir dimasukkan akan menjadi data pertama yang keluar. Bayangkan seperti tumpukan piring — piring terakhir yang ditaruh akan jadi piring pertama yang diambil.

### Contoh nyata:

- Tumpukan piring
- Undo/Redo di aplikasi
- Navigasi halaman browser (Back)

---

## 2. Konsep, Algoritma, dan Gambar ASCII

### Algoritma Dasar Stack

- **Push**: Menambahkan elemen ke atas stack
- **Pop**: Menghapus elemen teratas
- **Peek/Top**: Melihat elemen paling atas
- **IsEmpty**: Mengecek apakah stack kosong

### ASCII Visualisasi Stack:

```
+-------+     <- Top
|   9   |
+-------+
|   3   |
+-------+
|   5   |
+-------+     <- Bottom
```

---

## 3. Fungsi dan Jenis Stack

### Fungsi Stack:

- Menyimpan history (undo-redo, browser)
- Menyusun ekspresi matematika (postfix)
- Menyimpan fungsi dalam pemanggilan rekursif
- Parsing dan compiler bahasa pemrograman

### Jenis Stack:

1. **Stack dengan Array**
   - Ukuran tetap
   - Akses cepat
   - Tidak fleksibel (overflow)
2. **Stack dengan Linked List**
   - Dinamis (tidak terbatas ukuran)
   - Menggunakan pointer
   - Sedikit lebih lambat dari array karena alokasi dinamis

---

## 4. Struktur Program Stack C++

### Struktur Stack dengan Array (pseudocode)

```cpp
class StackArray {
    int top;
    int arr[100];
public:
    StackArray();
    void push(int);
    int pop();
    int peek();
    bool isEmpty();
};
```

### Struktur Stack dengan Linked List

```cpp
struct Node {
    int data;
    Node* next;
};

class StackLinkedList {
    Node* top;
public:
    StackLinkedList();
    void push(int);
    int pop();
    int peek();
    bool isEmpty();
};
```

---

## 5. Contoh Codingan C++

### Beginner: Stack dengan Array

```cpp
#include <iostream>
using namespace std;

class Stack {
private:
    int arr[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        if (top >= 99) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (top < 0) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (top < 0) return -1;
        return arr[top];
    }

    bool isEmpty() {
        return top < 0;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    cout << "Top: " << s.peek() << endl;
    cout << "Popped: " << s.pop() << endl;
}
```

### Intermediate: Stack dengan Linked List

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(int x) {
        Node* temp = new Node;
        temp->data = x;
        temp->next = top;
        top = temp;
    }

    int pop() {
        if (top == nullptr) {
            cout << "Stack Underflow\n";
            return -1;
        }
        int val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }

    int peek() {
        if (top == nullptr) return -1;
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};
```

---

## 6. Contoh Kasus Dunia Nyata: Infix ke Postfix

### 6.1 Apa itu Infix

Infix adalah notasi matematika yang biasa kita gunakan, yaitu operator berada di antara operand.

```css
A + B
```

### 6.2 Apa itu Postfix (Reverse Polish Notation)

Postfix adalah notasi matematika di mana operator ditulis setelah operand.

```css
A B +
```

### Contoh Soal Postfix ke Infix

#### Soal 1

Postfix :

```css
A B +
```

jawaban (infix) :

```css
A + B
```

#### Soal 2

```css
A B C + *
```

langkah :

```css
1. B + C → (B + C)

2. A * (B + C)
```

jawaban (infix):

```
A * (B + C)
```

#### Soal 3

Postfix :

```css
A B + C D + *
```

Langkah :

```css
1. A + B → (A + B)

2. C + D → (C + D)

3. (A + B) * (C + D)
```

Jawaban (infix):

```css
(A + B) * (C + D)
```

#### Soal 4

Postfix :

```css
A B C * + D -
```

Langkah :

```css
1. B * C → (B * C)

2. A + (B * C) → (A + B * C)

3. (A + B * C) - D
```

Jawaban (infix) :

```css
(A + (B * C)) - D
```

#### Soal 5

Postfix :

```css
A B + C D E + * *
```

Langkah :

```css
1. A + B → (A + B)

2. D + E → (D + E)

3. C * (D + E) → C * (D + E)

4. (A + B) * (C * (D + E))
```

Jawaban (infix) :

```css
(A + B) * (C * (D + E))
```

#### Note penting

| Simbol | Arti   |
| ------ | ------ |
| `+`    | Tambah |
| `-`    | Kurang |
| `*`    | Kali   |
| `/`    | Bagi   |

---

Saat mengubah postfix ke infix:

- Gunakan kurung untuk menunjukkan urutan evaluasi.

- Evaluasi postfix dilakukan dari kiri ke kanan menggunakan stack.

### 6.3 Perbandingan Infix vs Postfix

| Bentuk           | Contoh     | Urutan Eksekusi                       |
| ---------------- | ---------- | ------------------------------------- |
| Infix            | A + B      | A, operator, B                        |
| Postfix          | A B +      | A, B, operator                        |
| Infix (kompleks) | A + B \* C | operator mengikuti aturan prioritas   |
| Postfix          | A B C \* + | diurutkan berdasarkan urutan evaluasi |

---

### 6.4 Kenapa butuh Postfix?

- Infix mudah dibaca manusia, tapi sulit dieksekusi oleh mesin karena perlu aturan prioritas operator dan tanda kurung.

- Postfix mudah diproses oleh komputer menggunakan struktur data Stack tanpa perlu tanda kurung dan aturan prioritas.

### 6.5 Cara kerja evaluasi postfix

```css
3 4 + 5 *
```

artinya :

```css
(3 + 4) * 5 → hasil = 35
```

menggunakan stack :

```css
Postfix: 3 4 + 5 *

Stack:
Step 1: push(3)         → [3]
Step 2: push(4)         → [3, 4]
Step 3: '+' → pop(4,3)  → hitung 3+4 = 7 → push(7)  → [7]
Step 4: push(5)         → [7, 5]
Step 5: '*' → pop(5,7)  → hitung 7*5 = 35 → push(35) → [35]
```

### 6.6 Ilustrasi secara step by step

```sql
Expression: 3 4 + 5 *
           ↑
           token

Stack:
+--------+
|        | ← kosong
+--------+

Token: 3 → PUSH
+--------+
|   3    |
+--------+

Token: 4 → PUSH
+--------+
|   4    |
|   3    |
+--------+

Token: + → POP 4 & 3 → 3+4=7 → PUSH 7
+--------+
|   7    |
+--------+

Token: 5 → PUSH
+--------+
|   5    |
|   7    |
+--------+

Token: * → POP 5 & 7 → 7*5=35 → PUSH 35
+--------+
|  35    |
+--------+

✅ Final result: 35
```

### 6.7 Kesimpulan

| Infix                    | Postfix                     |
| ------------------------ | --------------------------- |
| Operator di tengah       | Operator di belakang        |
| Perlu tanda kurung       | Tidak perlu tanda kurung    |
| Perlu prioritas operator | Evaluasi mudah pakai stack  |
| Mudah dibaca manusia     | Mudah dieksekusi oleh mesin |

---

Postfix sangat berguna saat membuat kalkulator stack, kompiler, dan mesin ekspresi matematika.

### Kasus: Evaluasi ekspresi matematika

Contoh: `3 + 4 * 2` → `3 4 2 * +`

### Kode Infix ke Postfix

```cpp
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infixToPostfix(string expr) {
    stack<char> s;
    string output;

    for (char ch : expr) {
        if (isdigit(ch)) {
            output += ch;
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                output += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty()) {
        output += s.top();
        s.pop();
    }

    return output;
}

int main() {
    string infix = "3+4*2";
    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;  // Output: 342*+
}
```

### Cocok digunakan untuk:

- Aplikasi kalkulator (Android/Web)
- Backend compiler
- Parsing ekspresi matematika di spreadsheet

---

## 7. Kesimpulan

- Stack adalah struktur data penting dengan prinsip LIFO.
- Bisa diimplementasikan dengan array (cepat tapi terbatas) atau linked list (fleksibel).
- Berguna dalam undo-redo, compiler, navigasi, dan evaluasi ekspresi.
- Penting untuk dipahami terutama bagi software engineer dan programmer yang ingin menguasai algoritma.
