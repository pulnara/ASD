#include <iostream>
#include <math.h>
using namespace std;

int Parent(int k) { return (k-1)/2; }
int LSon(int k) { return 2*k+1; }
int RSon(int k) { return 2*k+2; }

//void printHeap(int A[], int hsize) {
//    int height = log2(hsize) + 1;
//    int level = 1;
//    int j = 0;
//    for (int i = 0; i < height; i++) {
//        int levelCopy = level;
//        while (levelCopy != 0 and j < hsize) {
//            cout << A[j] << " ";
//            j++;
//            levelCopy--;
//        }
//        level *= 2;
//        cout << endl;
//    }
//    cout << endl;
//}

void printHeap(int A[], int hsize) {
    cout << A[0];
    for (int i = 1; i < hsize; i++) {
        if (int(log2(i+1)) == log2(i+1)) cout << endl;
        cout << A[i] << " ";
    }
    cout << endl << endl;
}

void printHeapBetter(int A[], int hsize) {
    int i, start, finish;
    for (i = start = 0, finish = 1; i < hsize; start = finish, finish = LSon(finish)) {
        for (i = start; i < hsize and i < finish; i++) cout << A[i] << " ";
        cout << endl;
    }
}

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

void RemoveMax(int A[], int n, int& hsize) {
    swap(A[hsize-1], A[0]);
    Heapify(A, 0, n-1);
    hsize--;
}

void Insert(int A[], int n, int& hsize, int x) {
    if (hsize < n) {
        A[hsize] = x;
    }
    int i = hsize;
    while(i > 0 and A[Parent(i)] < A[i]) {
        swap (A[Parent(i)], A[i]);
        i = Parent(i);
    }
    hsize++;
}

void DecreaseKey(int A[], int hsize, int ind, int key) {
    if (A[ind] < key) return;
    A[ind] = key;
    int i = ind;
    if ((LSon(i) >= hsize or (LSon(i) < hsize and A[LSon(i)] < A[i])) and (RSon(i) >= hsize or (RSon(i) < hsize and A[RSon(i)] < A[i]))) return;
    Heapify(A, i, hsize);
}

void IncreaseKey(int A[], int hsize, int ind, int key) {
    if (A[ind] > key) return;
    A[ind] = key;
    int i = ind;
    while(i > 0 and A[Parent(i)] < A[i]) {
        swap(A[i], A[Parent(i)]);
        i = Parent(i);
    }
}

int main() {
    int N = 20;
    int A[N] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1, 7, 12};
    int heapSize = 12;
    printHeap(A, heapSize);
    BuildHeap(A, heapSize);
    printHeap(A, heapSize);
    RemoveMax(A, N, heapSize);
    printHeap(A, heapSize);
//    Insert(A, N, heapSize, 13);
//    printHeap(A, heapSize);
//    IncreaseKey(A, heapSize, 8, 13);
//    printHeap(A, heapSize);
    DecreaseKey(A, heapSize, 1, -1);
    printHeap(A, heapSize);
    printHeapBetter(A, heapSize);
}
