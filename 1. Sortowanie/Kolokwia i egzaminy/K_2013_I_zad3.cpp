/*
Prosze napisac funkcje:
    bool possible( char* u, char* v, char* w ),
ktora zwraca prawde jesli z liter slow u i v da sie ulozyc slowo w (nie jest konieczne wykorzystanie wszystkich liter)
oraz falsz w przeciwnym wypadku. Mozna zalozyc, ze w i v skladaja sie wylacznie z malych liter alfabetu lacinskiego.
Prosze krotko uzasadnic wybor zaimplementowanego algorytmu.
*/
#include <iostream>
#include <string.h>
using namespace std;

bool possible( char* u, char* v, char* w ) {
    if (strlen(u) + strlen(v) < strlen(w)) return false;
    int numLetter = 'z'-'a'+1;
    int A[numLetter];
    for (int i = 0; i < numLetter; i++) A[i] = 0;
    for (int i = 0; i < strlen(u); i++) A[u[i]-97]++;
    for (int i = 0; i < strlen(v); i++) A[v[i]-97]++;
    for (int i = 0; i < strlen(w); i++) {
        if (A[w[i]-97] > 0) A[w[i]-97]--;
        else return false;
    }
    return true;
}

int main() {
    char* a = "maslo";
//    cout << strlen(a);
//    cout << a[3];
    char* b = "maka";
    char* w = "slomka";
//    cout << "Podaj slowo w: ";
//    cin >> w;
    cout << "Z liter " << a << " i " << b;
    cout << (possible(a, b, w) ? cout << " da sie ulozyc slowo " << w : cout << " nie da sie ulozyc slowa " << w);
}
