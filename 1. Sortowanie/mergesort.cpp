#include <iostream>
using namespace std;

void print (int A[], int n) {
    for (int i = 0; i < n; i++) cout<<A[i]<<" ";
    cout<<endl;
}

void mergeTabs (int A[], int p, int q, int r) {
    int B[r-p+1];
    int i = p, j = q;
    int iter = 0;

    while (i < q and j <= r) {
        if (A[i] < A[j]) {
            B[iter] = A[i];
            i++;
        }
        else {
            B[iter] = A[j];
            j++;
        }
        iter++;
    }

    while (i < q) {
        B[iter] = A[i];
        i++;
        iter++;
    }

    while (j <= r) {
        B[iter] = A[j];
        j++;
        iter++;
    }

    for (int i = 0; i < r-p+1; i++) {
        A[p+i] = B[i];
    }
}

void MergeSort (int A[], int p, int r) {
    if (p < r) {
        int q = (p + r)/2;
        MergeSort(A, p, q);
        MergeSort(A, q+1, r);
        mergeTabs(A, p, q+1, r);
    }

}

int main() {
    int A[10] = {-2, 11, 253, -28, 0, 33, 15, 12, -28, 1};
    print(A, 10);
    MergeSort(A, 0, 9);
    print(A, 10);
}

