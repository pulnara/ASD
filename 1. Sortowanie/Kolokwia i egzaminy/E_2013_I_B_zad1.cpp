#include <iostream>
using namespace std;

struct Rectangle {
    double x, y;
    double w, h;
};

int LSon (int i) {
    return 2*i + 1;
}

int RSon (int i) {
    return 2*i + 2;
}

int P(int i) {
    return (i-1)/2;
}

double Pole (Rectangle A) {
    return A.w*A.h;
}

void heapify (Rectangle* A, int i, int n) {
    int ind_max = i;
    if (LSon(i) < n and Pole(A[LSon(i)]) > Pole(A[ind_max])) ind_max = LSon(i);
    if (RSon(i) < n and Pole(A[RSon(i)]) > Pole(A[ind_max])) ind_max = RSon(i);
    if (ind_max != i) {
        swap (A[i], A[ind_max]);
        heapify(A, ind_max, n);
    }
}

void buildHeap(Rectangle* A, int n) {
    for (int i = P(n-1); i >= 0; i--) {
        heapify(A, i, n);
    }
}

void heapsort (Rectangle* A, int n) {
    buildHeap(A, n);
    for (int i = n-1; i > 0; i--) {
        swap(A[0], A[i]);
        heapify(A, 0, i);
    }
}

int main() {
    int N = 10;
    Rectangle* A = new Rectangle [N];
    int X[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int Y[N] = {2, 5, 2, 1, 3, 5, 7, 3, 5, 2};
    int W[N] = {2, 5, 3, 12, 3, 7, 2, 5, 1, 8};
    int H[N] = {5, 6, 2, 3, 9, 8, 1, 11, 3, 2};
    for (int i = 0; i < N; i++) {
        A[i].x = X[i];
        A[i].y = Y[i];
        A[i].w = W[i];
        A[i].h = H[i];
    }
    heapsort(A, N);
    for (int i = 0; i < N; i++) cout << Pole(A[i]) << " ";
}
