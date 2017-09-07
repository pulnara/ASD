// selection sort
#include <iostream>
using namespace std;

void ssort(int A[], int n) {
    for (int i = 0; i < n; i++) {
        int MIN = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[MIN]) MIN = j;
        }
        swap (A[i], A[MIN]);
    }
}

void print (int A[], int n) {
    for (int i = 0; i < n; i++) cout << A[i] << " ";
    cout << endl;
}

int main() {
    int A[10]={-2, 1, 253, -28, 0, 33, 15, 12, -28, 110};
    print (A, 10);
    ssort (A, 10);
    print (A, 10);
}
