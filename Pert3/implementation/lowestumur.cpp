#include <iostream>
using namespace std;

int main() {
  // 1. Membuat array berisi data usia
  int ages[8] = {20, 22, 18, 35, 48, 26, 87, 70};

  // 2. Menghitung jumlah elemen dalam array
  int length = sizeof(ages) / sizeof(*ages);  // 32 / 4 = 8 elemen

  // 3. Menyimpan nilai awal (indeks ke-0) sebagai pembanding pertama
  int lowestAge = ages[0];

  // 4. Melakukan loop untuk membandingkan setiap usia
  for (int age : ages) {
    if (lowestAge > age) {
      lowestAge = age;  // Ganti jika ditemukan usia yang lebih kecil
    }
  }

  // 5. Menampilkan hasil
  cout << "The lowest age is: " << lowestAge << "\n";

  return 0;
}
