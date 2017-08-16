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

void QuickSortBetterMem(int A[], int p, int r) {
    while (p < r) {
        int q = Partition(A, p, r);
        if (q - p - 1 < r - (q+1))  {   // rekurencje uruchamiamy na mniejszym fragmencie tablicy
            QuickSortBetterMem(A, p, q-1);
            p = q+1;
        }
        else {
            QuickSortBetterMem(A, q+1, r);
            r = q-1;
        }
    }
}

int main() {
    int A[9] = {-2, 11, 253, 0, 33, 15, 12, -28, 1};
    print(A, 10);
    QuickSortBetterMem(A, 0, 9);
    print(A, 10);
}
