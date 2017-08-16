#include <iostream>
#include <string.h>
using namespace std;

bool anagram (char* A, char* B) {
    if (strlen(A) != strlen(B)) return false;
    int C[SHRT_MAX];
    for (int i = 0; A[i] != 0; i++) C[A[i]] = 0;
    for (int i = 0; B[i] != 0; i++) C[B[i]] = 0;
    for (int i = 0; A[i] != 0; i++) C[A[i]]++;
    for (int i = 0; B[i] != 0; i++) C[B[i]]--;
    for (int i = 0; A[i] != 0; i++) if (C[A[i]] != 0) return false;
    for (int i = 0; B[i] != 0; i++) if (C[B[i]] != 0) return false;
    return true;
}

int main() {
    char* a = "donek";
    char* b = "noehk";
    if (anagram(a,b)) cout << "Sa anagramami";
    else cout << "Nie sa anagramami";
}
