// 0 1 1 0 0 0 0 0 0 0 0 0 0 1 1 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0
#include <iostream>
#include <stack>
using namespace std;

void DFS_stack (int** G, int N, int start) {
    stack <int> s;
    bool visited[N];
    for (int i = 0; i < N; i++) visited[i] = false;
    s.push(start);
    while (!s.empty()) {
        int v = s.top();
        cout << v << " ";
        s.pop();
        visited[v] = true;
        for (int i = N-1; i >= 0; i--) {
            if (G[v][i] != 0 and !visited[i]) {
                s.push(i);
            }
        }
    }
}


int main() {
    int N = 10;
    int** G = new int* [N];
    for (int i = 0; i < N; i++) G[i] = new int [N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> G[i][j];
    }
    cout << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << G[i][j] << " ";
    cout << endl;
    }
    cout << endl;
    DFS_stack(G, N, 0);
//    for (int i = 0; i < G.N; i++) cout << G.tpocz[i] << " ";
//    cout << endl;
//    for (int i = 0; i < G.N; i++) cout << G.tzak[i] << " ";

}
