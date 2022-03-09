#include <iostream>

using namespace std;

int fib(int x){
    if (x==1) return 1;
    if (x==2) return 1;
    if (x>2) return (fib(x-2)+fib(x-1));
}

int main()
{
    int a;
    cin >> a;
    cout << fib(a) << endl;

    return 0;
}
