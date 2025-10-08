#include <iostream>

using namespace std;

int main(){

    // sizeof() = menentukan berapa byte dari :
    // variabel, tipe data, class, object dan lainnya.

    double gpa = 3.5;
    string name = "Coding is awesome";
    char grade = 'F';
    bool student = true;
    char grades[]= {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

    string students[] = {"Andi", "Budi", "Rasya", "Pascal", "Vanya", "Sandy"};

    cout << sizeof(gpa) << " bytes double\n";
    cout << sizeof(name) << " bytes string\n";
    cout << sizeof(grade) << " bytes char\n";
    cout << sizeof(student) << " bytes boolean\n";

    cout << sizeof(grades) << " elements\n";

    cout << sizeof(students)/sizeof(string) << " elements\n";

    return 0;

}
