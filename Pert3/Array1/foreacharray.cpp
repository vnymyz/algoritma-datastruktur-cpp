#include <iostream>

using namespace std;

int main(){

     string murid[] = {"Spongebob", "Patrick", "Squidward", "Mr.Krab", "Ms.Puff", "Mr.Krab"};

     int nilai[] ={70, 65, 78, 50, 100, 20};

     for(string murid : murid){
        cout << murid << '\n';
     }

     cout << "================================\n";

     for(int nilai : nilai){
        cout << nilai << '\n';
     }

     return 0;
}