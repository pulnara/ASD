#include <iostream>
using namespace std;
// 0 1 1 0 0 0 0 0 0 0 0 0 0 1 1 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0

struct Graph {
    int** G;
    int* parent;
    int* tpocz;
    int* tzak;
    int N;
};

void DFS_visit (Graph G, int u, int &time);

void DFS (Graph G, int s) {
    for (int i = 0; i < G.N; i++) {
        G.tpocz[i] = -1;
        G.parent[i] = -1;
    }
    int time = -1;
    for (int i = 0; i < G.N; i++) {
        if (G.tpocz[i] < 0) DFS_visit(G, i, time);
    }
}

void DFS_visit (Graph G, int u, int &time) {
    time++;
    G.tpocz[u] = time;
    for (int i = 0; i < G.N; i++) {
        if (G.G[u][i] == 1 and G.tpocz[i] < 0) {
            G.parent[i] = u;
            DFS_visit(G, i, time);
        }
    }
    time++;
    G.tzak[u] = time;
}

int main() {
    Graph G;
    G.N = 10;
    G.G = new int* [G.N];
    for (int i = 0; i < G.N; i++) G.G[i] = new int [G.N];
    G.parent = new int[G.N];
    G.tpocz = new int[G.N];
    G.tzak = new int [G.N];
    for (int i = 0; i < G.N; i++) {
        for (int j = 0; j < G.N; j++)
            cin >> G.G[i][j];
    }
        cout << endl;
    for (int i = 0; i < G.N; i++) {
        for (int j = 0; j < G.N; j++)
            cout << G.G[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    DFS(G, 0);
    for (int i = 0; i < G.N; i++) cout << G.tpocz[i] << " ";
    cout << endl;
    for (int i = 0; i < G.N; i++) cout << G.tzak[i] << " ";

}
