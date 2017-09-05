#include <iostream>
#include <stack>
using namespace std;

bool isCyclic (int** G, int N) {
    bool visited[N];
    stack <int> S;
    for (int i = 0; i < N; i++) visited[i] = false;

    S.push(0);
    S.push(-1);
    visited[0] = true; // startujemy z 0

    while(!S.empty()) {
        int parent = S.top(); S.pop();
        int v = S.top(); S.pop();

        for (int i = 0; i < N; i++) {
            if (G[v][i] == 1) {
                if (!visited[i]) {
                    S.push(i);
                    S.push(v);
                    visited[i] = true;
                }
                else if (parent != i) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    int N = 9;
    int** G = new int* [N];
    for (int i = 0; i < N; i++) {
        G[i] = new int [N];
        for (int j = 0; j < N; j++)
            G[i][j] = 0;
    }
    G[0][1] = G[1][0] = 1;
    G[1][8] = G[8][1] = 1;
    G[0][3] = G[3][0] = 1;
    G[3][7] = G[7][3] = 1;
    G[3][5] = G[5][3] = 1;
    G[7][5] = G[5][7] = 1;

    cout << isCyclic(G, N);
}
