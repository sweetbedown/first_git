#include <iostream>

using namespace std;

int main()
{
    int x, a = 0, b = 1;
    cin >> x;
    int chislo = 0;
    for (int i = 0; i<x;i++){
        if (i<2){
            cout << i << endl;
        }
        else{
            chislo = a + b;
            cout << chislo << endl;
            a = b;
            b = chislo;
        }
    }
    return 0;
}
