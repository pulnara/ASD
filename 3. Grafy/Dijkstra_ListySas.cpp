/*
Przykladowe dane wejsciowe (Cormen str. 672):
0 -> (1, 2) -> (2, 9) -> (4, 3)
1 -> (2, 6) -> (3, 7)
2 -> (1, 4)
3 -> (0, 5) -> (4, 10)
4 -> (0, 2) -> (2, 1)
*/
#include <iostream>
using namespace std;

struct nlist {
    int ind;
    int weight;
    nlist* next;
};

int getMin (bool visited[], int d[], int N) {
    int min = INT_MAX;
    int minInd = -1;
    for (int i = 0; i < N; i++) {
        if (!visited[i] and d[i] < min) {
            min = d[i];
            minInd = i;
        }
    }
    return minInd;
}

void Dijkstra (nlist** G, int N, int parent[], int d[], int s) {
    bool visited[N];
    for (int i = 0; i < N; i++) {
        d[i] = INT_MAX;
        parent[i] = -1;
        visited[i] = false;
    }
    d[s] = 0;
    for (int i = 0; i < N; i++) {
        int ind = getMin(visited, d, N);
        visited[ind] = true;
        while (G[ind] != NULL) {
            if(!visited[G[ind] -> ind] and d[G[ind] -> ind] > d[ind] + G[ind] -> weight) {
                d[G[ind] -> ind] = d[ind] + G[ind] -> weight;
                parent[G[ind] -> ind] = ind;
            }
            G[ind] = G[ind] -> next;
        }
    }
}


int main() {
    int N = 5;
    nlist** G = new nlist* [N];
    for (int i = 0; i < N; i++) {
        G[i] = NULL;
        cout << i << ": ";
        int flag;
        cin >> flag;
        while (flag >= 0) {
            nlist* node = new nlist;
            node -> ind = flag;
            cin >> flag;
            node -> weight = flag;
            node -> next = G[i];
            G[i] = node;
            cin >> flag;
        }
    }
    int parent[N];
    int d[N];
    Dijkstra(G, N, parent, d, 3);
    for (int i = 0; i < N; i++) cout << parent[i] << " ";
}
