/*
LCS(i, j) = IF ( A[i] == B[i] ) LCS(i-1, j-1) + 1,
            ELSE max( LCS(i-1, j), LCS(i, j-1) )

LCS(0, j) = 0
LCS(j, 0) = 0
*/
#include <iostream>
using namespace std;


int LCS (int A[], int B[], int n) {
    int T[n+1][n+1];
    for (int i = 0; i < n+1; i++) T[i][0] = 0;
    for (int i = 1; i < n+1; i++) T[0][i] = 0;
    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < n+1; j++) {
            if (A[i-1] == B[j-1]) T[i][j] = 1 + T[i-1][j-1];
            else T[i][j] = max(T[i-1][j], T[i][j-1]);
        }
    }
    return T[n][n];
}


int main() {
    int A[5] = {1, 3, 5, 2, 7};
    int B[5] = {1, 7, 5, 4, 2};
    cout << LCS(A, B, 5);
}
