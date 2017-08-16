/*
Napisac funkcje:
    void sortString(string A[]);
Funkcja sortuje tablice n stringow roznej dlugosci. Mozna zalozyc, ze stringi skladaja sie wylacznie z malych liter alfabetu lacinskiego.
*/

#include <iostream>
#include <conio.h>
using namespace std;

void print (string A[], int n) {
    for (int i = 0; i < n; i++) cout<<A[i] << endl;
    cout<<endl;
}

void sortByLen(string A[], int n) {
   int maxLen = 0;
   for (int i = 0; i < n; i++) {
    if (A[i].length() > maxLen) maxLen = A[i].length();
   }
   int C[maxLen+1];
   string B[n];
   for (int i = 0; i < maxLen+1; i++) C[i] = 0;
   for (int i = 0; i < n; i++) C[A[i].length()]++;
   for (int i = 1; i < maxLen+1; i++) C[i] += C[i-1];
   for (int i = n-1; i >= 0; i--) {
        B[C[A[i].length()]-1] = A[i];
        C[A[i].length()]--;
   }
   for (int i = 0; i < n; i++) A[i] = B[i];
}

void sortByPos(string A[], int pos, int from, int to) {
    if (from == to) return;
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
    for (int i = 0; i < to-from+1; i++) A[from+i] = B[i];

}

void sortString(string A[], int n) {
    sortByLen(A, n);
//    cout << "DDDDDDDDDDDDDDDDDDD" << endl;
    int i = n-1;
    for (int pos = A[n-1].length() - 1; pos >=0; pos--) {
        while (i >= 0 and A[i].length() > pos) i--;
        sortByPos(A, pos, i+1, n-1);
//        cout << "........." << endl;
    }
}

int main() {
    string A[17] = {"kota", "domek", "dup", "kacorek", "rak", "la", "zabek", "dab", "sru", "kula", "sra", "al", "zydek", "kumkwat", "wiertarka", "wazonik", "walizka"};
//    print(A, 17);
//    sortByLen(A, 17);
    sortString(A, 17);
    print(A, 17);

}
