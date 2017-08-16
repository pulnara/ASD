// bubble sort
#include <iostream>
using namespace std;

void bsort (int A[], int n) {
    for (int i = 1; i <  n; i++) {
        for (int j = 0; j < i; j++) {
            if (A[i] < A[j]) swap (A[i], A[j]);
        }
    }
}

void print (int A[], int n) {
    for (int i = 0; i < n; i++) cout<<A[i]<<" ";
    cout<<endl;
}

int main() {
    int A[10]={-2, 1, 253, -28, 0, 33, 15, 12, -28, 110};
    print (A, 10);
    bsort(A, 10);
    print (A, 10);
}
