// Implementacja Bellmana Forda na reprezentacji list sasiedztwa
/*
Przykladowe dane (Cormen str. 666):
0 -> (1, 6) -> (3, 7)
1 -> (2, 5) -> (3, 8) -> (4, -4)
2 -> (1, -2)
3 -> (2, -3) -> (4, 9)
4 -> (2, 7) -> (0, 2)
*/
#include <iostream>
using namespace std;

struct nlist {
    int ind;
    nlist* next;
    int weight;
};

bool BellmanFord (nlist** G, int s, int prev[], int n, int d[]) {
    for (int i = 0; i < n; i++) {
        d[i] = INT_MAX;
        prev[i] = -1;
    }
    d[s] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            nlist* p = G[j];
            while (p != NULL) {
                int to = p -> ind;
                int from = j;
                int w = p -> weight;

                if (d[from] + w < d[to]) {
                    d[to] = d[from] + w;
                    prev[to] = from;
                }

                p = p -> next;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (nlist* p = G[i]; p != NULL; p = p -> next) {
            int from = i;
            int to = p -> ind;
            int w = p -> weight;
            if (d[from] + w < d[to]) return false;
        }
    }
    return true;
}


int main() {
    int N = 5;
    nlist** G = new nlist* [N];
    for (int i = 0; i < N; i++) {
        G[i] = NULL;
        cout << i << ": ";
        int flag;
        cin >> flag;
        while (flag != -10) {
            nlist* node = new nlist;
            node -> ind = flag;
            cin >> flag;
            node -> weight = flag;
            node -> next = G[i];
            G[i] = node;
            cin >> flag;
        }
        // cout << endl;
    }
    int d[N];
    int prev[N];
    cout << BellmanFord(G, 0, prev, N, d) << endl;
    if (BellmanFord(G, 0, prev, N, d)) {
        for (int i = 0; i < N; i++) cout << d[i] << " ";
        cout << endl;
        for (int i = 0; i < N; i++) cout << prev[i] << " ";
    }
}
