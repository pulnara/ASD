#include <iostream>
using namespace std;

void mirror (int A[], int p, int k) {
    for (int i = p; i < (k-p+1)/2; i++) swap (A[i], A[k-i+p]);
}

void shift (int A[], int n, int x) {
    mirror(A, 0, n-1);
    mirror(A, 0, n-x-1);
    mirror(A, n-x, n-1);
}

int main() {
    int A[6] = {3, 1, 5, 7, 9, -2};
//    mirror(A, 0, 5);
    shift(A, 6, 2);
    for (int i = 0; i < 6; i++) cout << A[i] << " ";
}
