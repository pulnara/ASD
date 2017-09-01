#include <iostream>
using namespace std;

int** FloydWarshall (int** G, int N) {
    int** d = new int* [N];
    for (int i = 0; i < N; i++) {
        d[i] = new int [N];
        for (int j = 0; j < N; j++) {
            if (G[i][j] != 0) d[i][j] = G[i][j];
            else d[i][j] = 100100;
        }
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (d[k][j] == 100100) continue;
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    return d;
}


int main() {
    int N = 5;
    int** G = new int* [N];
    for (int i = 0; i < N; i++) G[i] = new int [N];
    // 0 6 0 7 0 0 0 5 8 -4 0 -2 0 0 0 0 0 -3 0 9 2 0 7 0 0
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> G[i][j];
    }
    int** d = FloydWarshall(G, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
}
