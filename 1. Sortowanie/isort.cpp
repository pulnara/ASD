// insertion sort
#include <iostream>
using namespace std;

void isort (int A[], int n) {
   for (int i = 1; i < n; i++) {
        int tmp = A[i];
        int j = i - 1;
        while (j > -1 && A[j] > tmp) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = tmp;
   }
}

void print (int A[], int n) {
    for (int i = 0; i < n; i++) cout<<A[i]<<" ";
    cout<<endl;
}

int main() {
    int A[10]={-2, 1, 253, -28, 0, 33, 15, 12, -28, 110};
    print (A, 10);
    isort (A, 10);
    print (A, 10);
}
