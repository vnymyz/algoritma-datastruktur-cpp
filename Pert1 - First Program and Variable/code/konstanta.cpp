#include <iostream>
using namespace std;

int main() {
    const int a = 20;
    a = 10; // Error: assignment of read-only variable 'a'
    cout << a;
    return 0;
}
