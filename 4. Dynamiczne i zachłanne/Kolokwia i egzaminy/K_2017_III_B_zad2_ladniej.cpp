/*

f(i) = max {A[i] + f(i-2), f(i-1)}, i >= 2
f(0) = A[0]
f(1) = max {A[0], A[1]}

*/
#include <iostream>
using namespace std;

int goodThief (int A[], int N) {
    if (N == 0) return 0;
    if (N == 1) {
        cout << "Wybieramy: 0";
        return A[0];
    }
    int F[N];
    F[0] = A[0];
    F[1] = max (A[0], A[1]);
    for (int i = 2; i < N; i++) {
        F[i] = max(A[i] + F[i-2], F[i-1]);
    }

    cout << "Wybieramy: " << endl;
    int i = N - 1;
    while (i >= 0) {
        if (i == 1) {
            if (F[1] > F[0]) cout << i << " ";
            else cout << 0;
            break;
        }
        if (F[i] == A[i] + F[i-2]) {
            cout << i << " ";
            i -= 2;
        }
        else i -= 1;
    }
    cout << endl;
    return F[N-1];
}

int main() {
    int N = 9;//0  1  2  3  4   5  6  7  8
    int A[N] = {3, 5, 1, 7, 11, 4, 2, 5, 6};
//    int A[N] = {12, 1, 3, 4, 1, 5, 7, 9, 5};
    cout << "Suma: " << goodThief(A, N);
}
