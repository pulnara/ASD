#include <iostream>
using namespace std;

int** FloydWarshall (int** G, int N) {
    int** d = new int* [N];
    for (int i = 0; i < N; i++) {
        d[i] = new int [N];
        for (int j = 0; j < N; j++) d[i][j] = G[i][j];
    }

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    return d;
}

int main() {

}
