#include <iostream>
using namespace std;

void print (int A[], int n) {
    for (int i = 0; i < n; i++) cout << A[i] << " ";
    cout << endl;
}

int Parent(int k) { return (k-1)/2; }
int LSon(int k) { return 2*k+1; }
int RSon(int k) { return 2*k+2; }

void Heapify(int A[], int i, int n) {
    int max_ind = i;
    if (LSon(i) < n and A[LSon(i)] > A[i]) max_ind = LSon(i);
    if (RSon(i) < n and A[RSon(i)] > A[max_ind]) max_ind = RSon(i);
    if (max_ind != i) {
        swap(A[max_ind], A[i]);
        Heapify(A, max_ind, n);
    }
}

void BuildHeap(int A[], int n) {
    for (int i = Parent(n-1); i >= 0; i--) {
        Heapify(A, i, n);
    }
}

void HeapSort(int A[], int n) {
    BuildHeap(A, n);
    for (int i = n-1; i >= 1; i--) {
        swap(A[0], A[i]);
        Heapify(A, 0, i);
    }
}



int main() {
    int A[10] = {-2, 11, 253, -28, 0, 33, 15, 12, -28, 1};
    print(A, 10);
    HeapSort(A, 10);
    print(A, 10);
}

