/*
f(i, j) = min { (J[i].start - J[p].end) + f(p, j-1) }, j <= p + 1 < i
f(i, 1) = 0;
f(0, j) = +oo; j >= 1

   0   1    2    3     4  j - ile prac
0     +oo  +oo  +oo  +oo
1      0   +oo  +oo  +oo
2      0        +oo  +oo
3      0             +oo
4      0
5      0
6      0
7      0
8      0
i
|
ostatnia wzieta praca

*/
#include <iostream>
using namespace std;

struct Job {
    int start, end;
};

int timeBetween (Job J[], int p, int i) {
    return J[i].start - J[p].end;
}

int impatientJob (Job J[], int n, int k) {
    int A[n+1][k+1];
    for (int i = 0; i <= n; i++) A[i][1] = 0;
    for (int i = 1; i <= k; i++) A[0][i] = INT_MAX;

    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= i and j <= k; j++) {
            int min = 100100;
            for (int p = j-1; p < i; p++) {
//                cout << endl << i << " " << j << " " << p << ": ";
                int x = timeBetween(J, p-1, i-1);
                if (x < 0) continue;
                else {
                    if (x + A[p][j-1] < min) min = x + A[p][j-1];
//                    cout << A[p][j-1] << " " << min << " " << endl;
                }
            }
            A[i][j] = min;
//            cout << endl;
        }
    }
//    if (A[n][k] == INT_MAX) return -1;
//    for (int i = 1; i < n+1; i++) {
//        for (int j = 1; j <= i and j < k+1; j++)
//            cout << A[i][j] << "\t";
//        cout << endl;
//    }
    int min = A[n][k];
    for (int i = n-1; i >= k; i--) if (A[i][k] < min) min = A[i][k];
    if (min == 100100) return -1;
    return min;
}

int main() {
    int N = 10;
    Job A[N] = {1,3,  2,5,  3,6,  4,8,  5,9,  6,11,  7,13,  9,15,  13,15,  14,19};
    cout << impatientJob(A, 10, 3);
}
