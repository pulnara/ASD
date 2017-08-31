#include <iostream>
using namespace std;


int** TransitiveClosure (int** G, int N) {
    int** TC = new int* [N];
    for (int i = 0; i < N; i++) {
        TC[i] = new int [N];
        for (int j = 0; j < N; j++) {
            if (G[i][j] != 0) TC[i][j] = 0;
            else TC[i][j] = 1; // przyjmujemy, ze gdy G[i][j] = 0, to brak krawedzi
        }
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (TC[i][k] == 0 and TC[k][j] == 0) {
                    TC[i][j] = 0;
                }
            }
        }
    }
    return TC;
}

int main () {
    int N = 11;
    int** G = new int* [N];
    for (int i = 0; i < N; i++) {
        G[i] = new int [N];
        for (int j = 0; j < N; j++) cin >> G[i][j];
    }
    // 0 1 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++)
//            cout << G[i][j] << " ";
//        cout << endl;
//    }
    cout << endl;
    int** wynik = TransitiveClosure(G, N);
    cout << "   ";
    for (int i = 0; i < N; i++) cout << i << " ";
    cout << endl;
    for (int i = 0; i < N; i++) {
        cout << i << "| ";
        for (int j = 0; j < N; j++)
            cout << wynik[i][j] << " ";
        cout << endl;
    }
}
