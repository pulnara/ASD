// LIS = Longest Increasing Substring
#include <iostream>
using namespace std;

void print_LIS (int A[], int Pred[], int i) {
    if (Pred[i] >= 0) print_LIS(A, Pred, Pred[i]);
    cout << " " << A[i];
}

int LIS (int A[], int n) {
    int Pred[n];
    int L[n];
    for (int i = 0; i < n; i++) {
        Pred[i] = -1;
        L[i] = 1;
    }
    int M = 1, M_ind = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i]) {
                if (L[j] + 1 > L[i]) {
                    Pred[i] = j;
                    L[i] = L[j] + 1;
                }
                if (L[i] > M) {
                    M = L[i];
                    M_ind = i;
                }
            }
        }
    }
    print_LIS(A, Pred, M_ind);
    return M;
}

int main() {
//    int A[10] = {7, 13, 6, 21, 37, 1, 5, 10, 15, 42};
//    LIS(A, 10);
    int A[8] = {5, 7, 3, 2, 4, 8, 6, 7};
    LIS(A, 8);
}
