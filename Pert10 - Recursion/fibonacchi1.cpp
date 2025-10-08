#include <iostream>
using namespace std;

int fibonacchi(int n){
    // f1 = 0
    // f2 = 1
    if(n == 0 || n == 1){   // base case
        cout << n << endl;
        return n;
    } else {
        cout << n << endl;
        return(fibonacchi(n-1) + fibonacchi(n-2)); // recursive case
    }
}

int main(){
    int n, i, j = 0;
    cout << "Batas deret : ";
    cin >> n;
    cout << "Deret Fibonacchi : \n";
    for(i = 1; i <= n; i++){
        cout << "f " << i << " : ";
        cout << fibonacchi(j) << endl;
        j++;
    }
    return 0;
}