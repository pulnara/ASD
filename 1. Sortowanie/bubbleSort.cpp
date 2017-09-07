// bubble sort
#include <iostream>
using namespace std;

void bsort1 (int A[], int n) {  // works & looks like a hybrid of bubble sort & insert sort but literally no idea what I was drinking when I wrote this
    for (int i = 1; i <  n; i++) {
        for (int j = 0; j < i; j++) {
            if (A[i] < A[j]) swap (A[i], A[j]);
        }
    }
}

void bsort (int A[], int n) {
    for (int i = 0; i < n; i++) {
        bool change = true;
        for (int j = 0; j < n - i; j++) {
            if (A[j] > A[j+1]) {
                change = false;
                swap (A[j], A[j+1]);
            }
        }
        if (change) break;
    }
}

void print (int A[], int n) {
    for (int i = 0; i < n; i++) cout<<A[i]<<" ";
    cout<<endl;
}

int main() {
    int A[10] = {-2, 1, 253, -28, 0, 33, 15, 12, -28, 110};
    print (A, 10);
    bsort(A, 10);
    print (A, 10);
}
