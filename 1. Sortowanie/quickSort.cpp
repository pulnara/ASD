#include <iostream>
using namespace std;

void print (int A[], int n) {
    for (int i = 0; i < n; i++) cout<<A[i]<<" ";
    cout<<endl;
}

int Partition (int A[], int p, int r) {
    int q = p-1;
    for (int i = p; i < r; i++) {
        if (A[i] <= A[r]) {
            swap(A[i], A[q+1]);
            q++;
        }
    }
    swap(A[q+1], A[r]);
    return q+1;
}

void QuickSort (int A[], int p, int r) {
    if (p < r) {
        int q = Partition(A, p, r);
        QuickSort(A, p, q-1);
        QuickSort(A, q+1, r);
    }
}

int main() {
    int A[9] = {-2, 11, 253, 0, 33, 15, 12, -28, 1};
    print(A, 10);
    QuickSort(A, 0, 9);
    print(A, 10);
}
