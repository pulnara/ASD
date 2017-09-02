// Ustawia wierzcholki w takim porzadku, ze gdybysmy narysowali je w 1 linii, wszystkie krawedzie skierowane bylyby z lewej na prawa (->)
/*
Przykladowe dane:
0 -> 2 -> 1
1 -> 5 -> 4
2 -> 6 -> 5 -> 3
3 ->
4 -> 3
5 ->
6 -> 1
*/
#include <iostream>
using namespace std;

struct nlist {
    int ind;
    nlist* next;
};

void DFS_vis (nlist** G, int tpocz[], int tzak[], int parent[], bool visited[], int n, int s, int& time, int topol[], int& ind) {
    time++;
    tpocz[s] = time;
    visited[s] = true;
//    cout << time << " ";
    while (G[s] != NULL) {
        if (!visited[G[s] -> ind]) {
            nlist* v = G[s];
            G[s] = G[s] -> next;
            DFS_vis(G, tpocz, tzak, parent, visited, n, v -> ind, time, topol, ind);
            delete v;
        }
        else G[s] = G[s] -> next;
    }

    time++;
//    cout << time << " ";
    tzak[s] = time;
    topol[ind] = s;
    ind--;
}

int* DFS_sortTopol (nlist** G, int n) {
    int* topol = new int [n];
    int ind = n-1;

    int tpocz[n] = {};
    int tzak[n] = {};
    bool visited[n] = {};
    int parent[n];
    for (int i = 0; i < n; i++) parent[i] = -1;

    int time = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) DFS_vis(G, tpocz, tzak, parent, visited, n, i, time, topol, ind);
    }
    cout << endl;
//    for (int i = 0; i < n; i++) cout << tzak[i] << " ";
    return topol;
}


int main() {
    int N = 7;
    nlist** G = new nlist* [N];
    for (int i = 0; i < N; i++) {
        G[i] = new nlist[N];
        cout << i << ": ";
        G[i] = NULL;
        int x;
        cin >> x;
        while (x >= 0) {
            nlist* node = new nlist;
            node -> ind = x;
            node -> next = G[i];
            G[i] = node;
            cin >> x;
        }
        cout << endl;
    }
    int* kol = DFS_sortTopol(G, N);
    for (int i = 0; i < N; i++) cout << kol[i] << " ";
}

