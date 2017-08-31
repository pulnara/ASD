#include <iostream>
using namespace std;

int getMin (int d[], bool visited[], int N) {
    int min = INT_MAX;
    int minInd = -1;
    for (int i = 0; i < N; i++) {
        if (d[i] < min and visited[i] == false) {
            min = d[i];
            minInd = i;
        }
    }
    return minInd;
}

void Dijkstra (int** G, int d[], int parent[], int N, int s) {
    bool visited[N];
    for (int i = 0; i < N; i++) {
        d[i] = INT_MAX;
        parent[i] = -1;
        visited[i] = false;
    }
    d[s] = 0;

    for (int i = 0; i < N; i++) {
        int ind = getMin(d, visited, N);
        visited[ind] = true;
        for (int j = 0; j < N; j++) {
            if (G[ind][j] >= 0) {
                if (d[ind] + G[ind][j] < d[j]) {
                    d[j] = G[ind][j] + d[ind];
                    parent[j] = ind;
                }
            }
        }
    }

}


int main() {
    int N = 5;
    int** G = new int* [N];
    for (int i = 0; i < N; i++) G[i] = new int [N];
    int d[N];
    int parent[N];
    // -1 2 9 -1 3 -1 -1 6 7 -1 -1 4 -1 -1 -1 5 -1 -1 -1 10 2 -1 1 -1 -1
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> G[i][j];
    }
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++)
//            cout << G[i][j] << "\t";
//        cout << endl;
//    }
    Dijkstra(G, d, parent, N, 3);
    for (int i = 0; i < N; i++) cout << d[i] << " ";

}
