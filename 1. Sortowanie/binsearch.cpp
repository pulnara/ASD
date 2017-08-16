#include <iostream>
using namespace std;

bool binSearch(int A[], int num, int p, int r) {
    if (p <= r) {
        int q = (p+r)/2;
        if (A[q] == num) return true;
        else if (A[q] < num) return binSearch(A, num, q+1, r);
        else return binSearch(A, num, p, q-1);
    }
    return false;
}

int main() {
    int A[10] = {5, 3, 6, 0, 0, 4, 1, 5, 0, 6};
    int number;
    cout << "Input a number to be found: ";
    cin >> number;
    binSearch(A, number, 0, 9) ? cout << "Appears." : cout << "Doesn't appear.";
}
