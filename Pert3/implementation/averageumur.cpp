#include <iostream>
using namespace std;

int main() {
  // 1. Membuat array berisi data usia
  int ages[8] = {20, 22, 18, 35, 48, 26, 87, 70};

  // 2. Menyiapkan variabel untuk jumlah (sum) dan rata-rata (avg)
  float avg, sum = 0;
  int i;

  // 3. Menghitung jumlah elemen array
  int length = sizeof(ages) / sizeof(*ages); // 32 / 4 = 8

  // 4. Looping untuk menjumlahkan seluruh nilai dalam array
  for (int age : ages) {
    sum += age;
  }

  // 5. Hitung rata-rata = total nilai / jumlah elemen
  avg = sum / length;

  // 6. Menampilkan hasil rata-rata
  cout << "The average age is: " << avg << "\n";

  return 0;
}
