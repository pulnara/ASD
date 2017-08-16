#include <iostream>
using namespace std;

void print (float A[], int n) {
    for (int i = 0; i < n; i++) cout<<A[i]<<" ";
    cout<<endl;
}

int index (int n, float x) {
    return n*x;
}

void iSort (float A[], int n) {
    for (int i = 1; i < n; i++) {
        int q = i-1;
        float x = A[i];
        while (q > -1 and A[q] > x) {
            A[q+1] = A[q];
            q--;
        }
        A[q+1] = x;
    }
}

void BucketSort (float A[], int n) {
    float B[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            B[i][j] = -1;
    }
    int C[n]; // counters
    for (int i = 0; i < n; i++) C[i] = 0;
    for (int i = 0; i < n; i++) {
        B[index(n, A[i])][C[index(n, A[i])]] = A[i];
        C[index(n, A[i])]++;
    }
    for (int i = 0; i < n; i++) iSort(B[i], C[i]);
    int i = 0, j = 0;
    while (j < n) {
        int k = 0;
        while (k < C[j]) {
            A[i] = B[j][k];
            k++;
            i++;
        }
        j++;
    }
//    cout << endl;
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++)
//            cout << B[i][j] << "\t";
//        cout << endl;
//    }
}


int main() {
    int N = 10;
    float A[N] = {0.7, 0.01, 0.71, 0.6, 0.33, 0.49, 0.41, 0.97, 0.09, 0.52};
    print (A, N);
    BucketSort(A, N);
    print(A, N);
//    cout << index(A, N, 6);

}
