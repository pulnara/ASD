#include <iostream>
using namespace std;

int Fib (int n, int F[]) {
    if (F[n] >= 0) return F[n];
    F[n] = Fib(n-1, F) + Fib(n-2, F);
    return F[n];
}


int main () {
    int x;
    cin >> x;
    int F[x+1];
    for (int i = 0; i <= x; i++) F[i] = -1;
    F[0] = 0;
    F[1] = 1;
    F[2] = 1;
    cout << Fib(x, F);
}
