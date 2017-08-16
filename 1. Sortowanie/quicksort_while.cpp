#include <iostream>
using namespace std;

void print (int A[], int n) {
    for (int i = 0; i < n; i++) cout<<A[i]<<" ";
    cout<<endl;
}

int Partition (int A[], int p, int r) {
    int x = A[r];
    int q = p - 1;
    for (int i = p; i < r; i++) {
        if (A[i] < x) {
            swap(A[q+1], A[i]);
            q++;
        }
    }
    swap(A[q+1], A[r]);
    return q+1;
}

//void QuickSort(int A[], int p, int r) {
//    etykieta:
//    if (p < r) {
//        int q = Partition(A, p, r);
//        QuickSort(A, p, q-1);
//        p = q+1;
//        goto etykieta;
//    }
//}

void QuickSort(int A[], int p, int r) {
    while (p < r) {
        int q = Partition(A, p, r);
        QuickSort(A, p, q-1);
        p = q+1;
    }
}

int main() {
    int A[10] = {-2, 11, 253, -28, 0, 33, 15, 12, -28, 1};
    print(A, 10);
    QuickSort(A, 0, 9);
    print(A, 10);
}

