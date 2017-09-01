/*
Mamy tablice A[n], reprezentujaca korek A[n] samochodow, gdzie:
A[i] - dlugosc auta i, i nalezy do [1, 2, 3, ... n]

Samochody chca wjechac na prom o dlugosci L. Do wyboru maja lewa czesc promu (dlugosc L) oraz prawa czesc promu (dlugosc L).
Dla kazdego z aut wybierz, czy ma jechac w prawo czy w lewo, wjezdzajac na prom.


left(i, l) = max(left(i-1, l), A[i] + left(i-1, l - A[i])), A[i] <= l
             left(i-1, l), A[i] > l
gdzie l nalezy do [0, 1, 2, ..., L]
*/
#include <windows.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

int Prom (int A[], int N, int L, int** Parent) {
    int B[N+1][L+1];
    for (int i = 0; i < N+1; i++) B[i][0] = 0;

    for (int i = 1; i < L+1; i++) B[0][i] = 0;

    for (int i = 0; i < N+1; i++) {
        for (int l = 0; l < L+1; l++)
            Parent[i][l] = 0;
    }

    for (int i = 1; i < N+1; i++) {
        for (int l = 1; l < L+1; l++) {
            if (A[i] <= l) {
                if (B[i-1][l] < A[i] + B[i-1][l - A[i]]) {
                    B[i][l] = A[i] + B[i-1][l - A[i]];
                    Parent[i][l] = 1;
                }
                else {
                    B[i][l] = B[i-1][l];
                }

            }
            else {
                B[i][l] = B[i-1][l];
            }
        }
    }

    return B[N][L];
}

int main() {
    HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
//    int N = 6;
//    int A[N+1] = {0, 3, 7, 2, 5, 4, 1};
//    int L = 17;
    int N = 13;
    int A[N+1] = {0, 2, 5, 7, 12, 3, 6, 13, 11, 4, 15, 6, 9, 37};
    int L = 52;
    int** Parent = new int* [N+1];
    for (int i = 0; i < N+1; i++) Parent[i] = new int [L+1];

    cout << Prom(A, N, L, Parent) << endl;
    cout << endl;
    for (int i = 1; i < N+1; i++) {
        for (int l = 0; l < L+1; l++) {
            if (l == 0) SetConsoleTextAttribute( hOut, FOREGROUND_GREEN );
            else if (Parent[i][l] == 1) SetConsoleTextAttribute( hOut, FOREGROUND_RED | FOREGROUND_INTENSITY );
            else SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout << Parent[i][l] << " ";
        }
        cout << endl;
    }
    cout << endl << "Na lewo maja jechac auta o numerach: ";
    int j = L;
    while (j != 0) {
        int i = N;
        while (Parent[i][j] != 1) i--;
        cout << i << " ";
        j -= A[i];
    }
    cout << endl << "Reszta na prawo, jesli wystarczy im miejsca.";
}
