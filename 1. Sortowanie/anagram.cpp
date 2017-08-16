#include <iostream>
#include <string.h>
using namespace std;

bool anagram (char* A, char* B) {
    if (strlen(A) != strlen(B)) return false;
    int lettersNum = 'z'-'a'+1;
    int C[lettersNum];
    for (int i = 0; i < lettersNum; i++) C[i] = 0;
    for (int i = 0; A[i] != 0; i++) C[A[i]-'a']++;
    for (int i = 0; B[i] != 0; i++) C[B[i]-'a']--;
    for (int i = 0; i < lettersNum; i++) if(C[i] != 0) return false;
    return true;
}

int main() {
    char* a = "donek";
    char* b = "nodhk";
    if (anagram(a,b)) cout << "Sa anagramami";
    else cout << "Nie sa anagramami";
}
