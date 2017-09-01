// http://algorytmikavlo.wikidot.com/lis
// http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
#include <iostream>
using namespace std;

int binSearch (int A[], int p, int k, int n) {
    if (p <= k) {
        int q = (p+k)/2;
        if (A[q] == n) return q;
        if (A[q] < n) return binSearch(A, q+1, k, n);
        return binSearch(A, p, q-1, n);
    }
    return p;   // jesli nie ma go w tablicy, to zwraca indeks, po ktorym jest pierwsza liczba wieksza od niego
}

int LIS_nlogn (int A[], int n) {
    int T[n];
    for (int i = 0; i < n; i++) T[i] = INT_MAX;
    T[0] = A[0];
    for (int i = 1; i < n; i++) {
        int x = binSearch(T, 0, n-1, A[i]);
        T[x] = A[i];
    }
    int i = 0;
    while (T[i] != INT_MAX) i++;
    return i;
}

int main() {
    int A[10] = {7, 13, 6, 21, 37, 1, 5, 10, 15, 42};
    cout << LIS_nlogn (A, 10);
}
