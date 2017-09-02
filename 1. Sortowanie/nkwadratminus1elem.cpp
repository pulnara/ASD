/* Mamy tablice A n-elementowa, zawierajaca elementy z przedzialu [0, n^2-1].
Nalezy ja posortowac.
Rozwiazanie:

	System n-kowy
	Liczby z zakresu: [0, n^2-1]
	mo¿na zapisac w postaci: An + B, gdzie A, B naleza do przedzialu [0, n-1]

	Nalezy posortowac pozycyjnie z uzyciem sortowania przez zliczanie.
	Czas sortowania: O(n)
*/
#include <iostream>
using namespace std;

int getNumAtPos (int x, int N, int pos) {
    if (pos == 0) return x%N;

    int i = 0;
    while (x!= 0 and i != pos) {
        x/=N;
        i++;
    }
    return x%N;
}

void SortByPos (int A[], int N, int pos) {
    int C[N];
    int B[N];
    for (int i = 0; i < N; i++) C[i] = 0;
    for (int i = 0; i < N; i++) C[getNumAtPos(A[i], N, pos)]++;
    for (int i = 1; i < N; i++) C[i] += C[i-1];
    for (int i = N-1; i >= 0; i--) {
        B[C[getNumAtPos(A[i], N, pos)]-1] = A[i];
        C[getNumAtPos(A[i], N, pos)]--;
    }
    for (int i = 0; i < N; i++) A[i] = B[i];
}


void Sort (int A[], int N, int p) { // sortuje tablice n-elementowa zawieracaja elementy z przedzialu [0, n^2-1]
   for (int i = 0; i < p; i++) {
        SortByPos(A, N, i);
   }
}

int main() {
    int N = 7;
    int A[N] = {48, 0, 6, 36, 9, 12, 21};
    // 48 = 6*7 + 6
    // 0 = 0*7 + 6
    // 6 = 0*7 + 6
    // 36 = 5*7 + 1
    // 9 = 1*7 + 2
    // 12 = 1*7 + 5
    // 21 = 3*7 + 0
    Sort(A, N, 2);
    for (int i = 0; i < N; i++) cout << A[i] << " ";
}
