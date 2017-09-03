/*

f(i) = max {A[i] + f(i-2), f(i-1)}, i >= 2
f(0) = A[0]
f(1) = max {A[0], A[1]}

*/
#include <iostream>
using namespace std;

int goodThief (int A[], int N) {
    int F[N];
    int taken[N];

    int parent[N];

    for (int i = 0; i < N; i++)
        taken[i] = -1;
    int last_taken;
    F[0] = A[0];

    parent[0] = 0;

    taken[0] = 1;
    taken[1] = -1;
    if (A[0] > A[1]) {
        F[1] = A[0];
        taken[1] = 0;
        taken[0] = 1;

        parent[1] = parent[0];
    }
    else {
        F[1] = A[1];
        taken[1] = 1;
        taken[0] = 0;

        parent[1] = 1;
    }
    for (int i = 2; i < N; i++) {
        if (A[i] + F[i-2] > F[i-1]) {
            F[i] = A[i] + F[i-2];
            taken[i] = 1;

            parent[i] = i;

            last_taken = i;
        }
        else {
            F[i] = F[i-1];
            taken[i] = 0;

            parent[i] = parent[i-1];

        }
    }
//    for (int i = 0; i < N; i++) cout << parent[i] << " ";
//    cout << endl;
    cout << "Wybieramy: " << endl;
    int j = N-1;
    while (j != 0 and j > 0) {
        while (parent[j] != j) j--;
        cout << j << " ";
        j -= 2;
    }

    int i = last_taken;
    cout << endl;
    int sum = F[N-1];
    i = last_taken;
    while (i >= 0) {
        cout << i << " ";
        sum -= A[i];
        i -= 2;
        while (taken[i] == 0) i--;
    }
    cout << endl;
    return F[N-1];
}
// 0 1 2  3 4  5  6  7  8
// 3 5 5 12 16 16 18 21 24
// 8, 6, 4, 1
int main() {
    int N = 9;//0  1  2  3  4   5  6  7  8
    int A[N] = {3, 5, 1, 7, 11, 4, 2, 5, 6};
//    int A[N] = {12, 1, 3, 4, 1, 5, 7, 9, 5};
    cout << "Suma: " << goodThief(A, N);
}
