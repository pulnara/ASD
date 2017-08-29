#include <iostream>
#include <queue>
using namespace std;
// 0 1 1 0 0 0 0 0 0 0 0 0 0 1 1 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0

int* BFS (int** G, int N, int s) {
    int* d = new int[N];

    for (int i = 0; i < N; i++) d[i] = -1;
    d[s] = 0;

    queue <int> q;
    q.push(s);

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < N; i++) {
            if (i != x and G[x][i] and d[i] < 0) {
                d[i] = d[x] + 1;
                q.push(i);
            }
        }

    }
    return d;
}

int main() {
    int N = 10;
    int** G = new int* [N];
    for (int i = 0; i < N; i++) G[i] = new int[N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> G[i][j];
    }
//    cout << endl;
//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++)
//            cout << G[i][j] << " ";
//        cout << endl;
//    }
    cout << endl;
    int* d = BFS(G, N, 0);
    for (int i = 0; i < N; i++) cout << d[i] << " ";
}
