#include <iostream>
#include <conio.h>
using namespace std;

void print (string A[], int n) {
    for (int i = 0; i < n; i++) cout<<A[i]<<" ";
    cout<<endl;
}

void sortByPos(string A[], int pos, int from, int to) {
    int lettersNum = 'z'-'a'+1;
    string B[to-from+1];
    int C[lettersNum];
    for (int i = 0; i < lettersNum; i++) C[i] = 0;
    for (int i = from; i <= to; i++) C[int(A[i][pos])-97]++;
    for (int i = 1; i < lettersNum; i++) C[i] += C[i-1];
    for (int i = to; i >= from; i--) {
        B[C[int(A[i][pos])-97] - 1] = A[i];
        C[int(A[i][pos])-97]--;
    }

    for (int i = from; i <= to; i++) A[i] = B[i];
}

void RadixSort(string A[], int n) {
    for (int i = A[0].length()-1; i >= 0; i--) {
        sortByPos(A, i, 0, n-1);
    }
}


int main() {
    string A[9] = {"kot", "dom", "dup", "kac", "rak", "lak", "zab", "dab", "sru"};
    print(A, 9);
//    cout << int(A[3][2]) << endl;
//    swap(A[0][1], A[0][2]);
//    print(A, 9);
    RadixSort(A, 9);
    print(A, 9);
}
