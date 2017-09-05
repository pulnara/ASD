#include <iostream>
using namespace std;

struct nlist {
    nlist* next;
    int val;
};

nlist** create (int** G, int n) {
    nlist** graph = new nlist* [n];
    for (int i = 0; i < n; i++) {
        graph[i] = NULL;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (G[i][j] == 1) {
                nlist* node1 = new nlist;
                node1 -> val = j;
                node1 -> next = graph[i];
                graph[i] = node1;

                nlist* node2 = new nlist;
                node2 -> val = i;
                node2 -> next = graph[j];
                graph[j] = node2;
            }
        }
    }
    return graph;
}

void reset (int d[], bool visited[], int n) {
    for (int i = 0; i < n; i++) {
        d[i] = 0;
        visited[i] = false;
    }
}

int getMax (int d[], int n) {
    int max = 0;
    for (int i = 0; i < n; i++) {
//        cout << d[i] << " ";
        if (d[i] > d[max]) max = i;
    }
//    cout << endl;
    return max;
}

void DFS (nlist** G, int d[], bool visited[], int start) {
    nlist* p = G[start];
    visited[start] = true;
    while (p != NULL) {
        if (!visited[p -> val]) {
            d[p -> val] = d[start] + 1;
            DFS(G, d, visited, p -> val);
        }
        p = p -> next;
    }
}

int diagonal (nlist** G, int n) {
    int d[n];
    bool visited[n];
    reset(d, visited, n);

    DFS(G, d, visited, 1); // dowolny numer wierzcholka
    int max1 = getMax(d, n);
//    cout << max1 << endl;
    reset(d, visited, n);

    DFS(G, d, visited, max1);
    int max2 = getMax(d, n);

    return d[max2];
}

int main() {
//    int N = 7;
//    int** G = new int* [N];
//    for (int i = 0; i < N; i++) {
//        G[i] = new int [N];
//        for (int j = 0; j < N; j++)
//            G[i][j] = 0;
//    }
//    G[0][1] = G[1][0] = 1;
//    G[0][2] = G[2][1] = 1;
//    G[1][3] = G[3][1] = 1;
//    G[1][4] = G[4][1] = 1;
//    G[2][5] = G[5][2] = 1;
//    G[2][6] = G[6][2] = 1;

    int N = 6;
    int gr[N][N] = {
	// 0  1  2  3  4  5
	{ 0, 0, 1, 0, 0, 0 }, // 0
	{ 0, 0, 1, 0, 0, 0 }, // 1
	{ 1, 1, 0, 1, 1, 0 }, // 2
	{ 0, 0, 1, 0, 0, 1 }, // 3
	{ 0, 0, 1, 0, 0, 0 }, // 4
	{ 0, 0, 0, 1, 0, 0 }
	};  // 5
	int** G = new int* [N];
	 for (int i = 0; i < N; i++) {
        G[i] = new int [N];
        for (int j = 0; j < N; j++)
            G[i][j] = gr[i][j];
    }
    nlist** g = create(G, N);

    cout << diagonal(g, N);
}
