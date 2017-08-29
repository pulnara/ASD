/* Sprawdz, czy w grafie danym w postaci macierzowej znajduje sie ujscie,
czyli taki wierzcholek, dla ktorego w wierszu sa same 0, a w kolumnie same 1 (oprocz miejsca [u,u]).
Dziala dla: 0 1 1 0 1 1 0 1 1 1 0 0 0 0 0 1 1 1 0 1 0 1 1 1 0
Nie dziala dla: 0 1 1 0 1 1 0 1 1 1 0 0 0 1 0 1 1 1 0 1 0 1 1 1 0
*/
#include <iostream>
using namespace std;

int ujscie (int** G, int n) {
    int i = 0, j = 0;
    while(i < n and j < n) {
        if (G[i][j] == 0) j++;
        else i++;
    }
    bool check = true;
    for (int k = 0; k < n; k++) {
        if (G[i][k] != 0) check = false;
        if (G[k][i] == 0 and (k != i)) check = false;
    }
    if (check) return i;
    return -1;
}


int main() {
    int N = 5;
    int** A = new int* [N];
    for (int i = 0; i < N; i++) {
        A[i] = new int[N];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> A[i][j];
    }
    cout << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    cout << ujscie(A, N);
}
