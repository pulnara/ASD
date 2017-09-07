#include <iostream>
using namespace std;


DFS(int** G, int start, bool visited[], int N, int val) {
    for (int j = 0; j < N; j++) {
        if (!visited[j] and G[start][j] > 0 and G[start][j] < val) {
            visited[j] = true;
            DFS(G, j, visited, N, G[start][j]);
        }
    }
}

bool decreasing (int** G, int N, int start, int end) {

    bool visited[N];
    for (int i = 0; i < N; i++) visited[i] = false;

    DFS(G, start, visited, N, INT_MAX);

    if (visited[end]) return true;
    else return false;
}


int main() {
    int N = 9;
    int** G = new int* [N];
    for (int i = 0; i < N; i++) {
        G[i] = new int [N];
        for (int j = 0; j < N; j++) G[i][j] = 0;
    }
    G[0][1] = G[1][0] = 9;
    G[0][2] = G[2][0] = 8;
    G[1][3] = G[3][1] = 5;
    G[2][3] = G[3][2] = 7;
    G[3][7] = G[7][3] = 6;
    G[3][4] = G[4][3] = 10;
    G[4][5] = G[5][4] = 2;
    G[4][6] = G[6][4] = 3;
    G[7][6] = G[6][7] = 4;
    G[6][8] = G[8][6] = 1;

    cout << decreasing(G, N, 2, 8);

}
