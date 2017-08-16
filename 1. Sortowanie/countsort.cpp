#include <iostream>
using namespace std;

void print (int A[], int n) {
    for (int i = 0; i < n; i++) cout<<A[i]<<" ";
    cout<<endl;
}

void CountSort(int A[], int n, int k) {
    int B[n], C[k];
    for (int i = 0; i < k; i++) C[i] = 0;
    for (int i = 0; i < n; i++) C[A[i]]++;
    for (int i = 1; i < k; i++) C[i] += C[i-1];
    for (int i = n-1; i >= 0; i--) {
        B[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }
    for (int i = 0; i < n; i++) A[i] = B[i];
}


int main() {
    int A[10] = {5, 3, 6, 0, 0, 4, 1, 5, 0, 6};
    print(A, 10);
    CountSort(A, 10, 7);
    print(A, 10);
}
