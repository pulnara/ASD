/*
Rownanie rekurencyjne:
f(i, u) = max( P(i) + f(i-1, u-W(i)), f(i-1, u)), W(i) <= u
          f(i-1, u), W(i) > u
*/
#include <iostream>
using namespace std;


int Rucksack (int p[], int w[], int T, int N) {
    int A[N+1][T+1];

    for (int i = 0; i < N+1; i++) A[i][0] = 0;
    for (int i = 1; i < T+1; i++) A[0][i] = 0;

    for (int i = 1; i < N+1; i++) {
        for (int u = 1; u < T+1; u++) {
            if (w[i] <= u) {
                int waga = w[i];
                A[i][u] = max(A[i-1][u], p[i] + A[i-1][u-waga]);
            }
            else {
                A[i][u] = A[i-1][u];
            }
        }
    }
    cout << "   ";
    for (int i = 1; i < T+1; i++) cout << i << "\t";
    cout << endl;
    for (int i = 1; i < N+1; i++) {
        cout << i << "| ";
        for (int j = 1; j < T+1; j++)
            cout << A[i][j] << "\t";
        cout << endl;
    }
    return A[N][T];
}


int main () {
    int N = 6;
    int P[7] = {0, 9, 11, 2, 5, 13, 100};
    int W[7] = {0, 6, 7, 3, 20, 2, 3};
    int T = 13;
    cout << Rucksack(P, W, T, N);
}
