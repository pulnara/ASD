/*
Dziwny kraj, dziwne nominaly - wydawanie monet.
N = {3, 1, 5, 8...}
T - kwota
Oblicz minimalna liczbe monet, ktora trzeba uzyc aby wydac kwote T.
f(t) = min (f(t-N[i])), i nalezy do {1, ..., n}
f(0) = 0
*/
#include <iostream>
using namespace std;

int Monety (int A[], int N, int T) {
    int Tab[T+1];
    Tab[0] = 0;
    for (int i = 1; i < T+1; i++) {
        Tab[i] = INT_MAX;
        for (int j = 0; j < N; j++) {
            if (i - A[j] >= 0) {
                if (Tab[i-A[j]] + 1 < Tab[i]) {
                    Tab[i] = Tab[i - A[j]] + 1;
                }

            }
        }
    }
    return Tab[T];
}

// modyfikacja, by wypisal, ktore monety bierzemy
int ChangeAndWypisz (int A[], int N, int T) {
    int Tab[T+1];
    int K[T+1];
    for (int i = 0; i < T+1; i++) K[i] = 0;
    Tab[0] = 0;
    for (int i = 1; i < T+1; i++) {
        Tab[i] = INT_MAX;
        for (int j = 0; j < N; j++) {
            if (i - A[j] >= 0) {
                if (Tab[i-A[j]] + 1 < Tab[i]) {
                    Tab[i] = Tab[i - A[j]] + 1;
                    K[i] = A[j];
                }

            }
        }
    }
    int i = T;
    while (K[i] != 0) {
        cout << K[i] << " ";
        i = K[i-K[i]];
    }
    cout << endl;
    return Tab[T];
}


int main() {
    int A[8] = {1, 5, 8, 3, 12, 7, 4, 2};
    cout << ChangeAndWypisz(A, 8, 11);
}

