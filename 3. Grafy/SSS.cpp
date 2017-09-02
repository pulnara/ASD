#include <iostream>
using namespace std;

struct helping {
    int ind;
    int val;
};

struct Graph {
    int** G;
    int* parent;
    int* tpocz;
    int* tzak;
    helping* helper;
    bool* visited;
    int N;
};

void DFS_visit (Graph G, int u, int& time) {
    time++;
    G.tpocz[u] = time;
    G.visited[u] = true;
    for (int i = 0; i < G.N; i++) {
        if (G.G[u][i] == 1 and !G.visited[i]) {
            G.parent[i] = u;
            DFS_visit(G, i, time);
        }
    }
    time++;
    G.tzak[u] = time;
}

int DFS (Graph G) {
    int time = -1;
    for (int i = 0; i < G.N; i++) {
        if (!G.visited[i]) {
            DFS_visit(G, i, time);
        }
    }
}

void transposition (Graph G) {
    for (int i = 0; i < G.N; i++) {
        int j = 0;
        while (j < i) {
            swap(G.G[i][j], G.G[j][i]);
            j++;
        }
    }
}

int Partition (helping A[], int p, int r) {
    int q = A[r].val;
    int pw = p-1;
    for (int i = p; i < r; i++) {
        if (A[i].val <= q) {
            pw++;
            swap (A[i], A[pw]);
        }
    }
    swap (A[r], A[pw + 1]);
    return pw + 1;
}

void QuickSort(helping A[], int p, int r) {
    if (p < r) {
        int q = Partition(A, p, r);
        QuickSort(A, p, q - 1);
        QuickSort(A, q+1, r);
    }
}

void DFS_visit_mod (Graph G, int u, int& time) {
    cout << u << " ";
    time++;
    G.tpocz[u] = time;
    G.visited[u] = true;
    for (int i = 0; i < G.N; i++) {
        if (G.G[u][i] == 1 and !G.visited[i]) {
            G.parent[i] = u;
            DFS_visit_mod(G, i, time);
        }
    }
    time++;
    G.tzak[u] = time;
}

int DFS_mod (Graph G) {
    int time = -1;
    int counter = 0;
    for (int i = 0; i < G.N; i++) {
        G.visited[i] = false;
        G.helper[i].ind = i;
        G.helper[i].val = G.tzak[i];
    }
    QuickSort(G.helper, 0, G.N - 1);
    for (int i = 0; i < G.N/2; i++) swap (G.helper[i], G.helper[G.N - 1 - i]);
//    for (int i = 0; i < G.N; i++) cout << G.helper[i].val << " ";
    cout << endl;
    for (int i = 0; i < G.N; i++) {
        int u = G.helper[i].ind;
//        cout << "u" << u << " ";
        if (!G.visited[u]) {
            DFS_visit_mod(G, u, time);
            counter++;
            cout << endl;
        }
//        cout << endl;
    }
    return counter;
}


int main() {
//    Graph G;
//    G.N = 8;
//    G.G = new int* [G.N];
//    for (int i = 0; i < G.N; i++) G.G[i] = new int [G.N];
//    G.parent = new int[G.N];
//    G.tpocz = new int[G.N];
//    G.tzak = new int [G.N];
//    G.visited = new bool [G.N];
//    G.helper = new helping [G.N];
//    for (int i = 0; i < G.N; i++) {
//        G.visited[i] = false;
//        for (int j = 0; j < G.N; j++)
//            cin >> G.G[i][j];
//    }
//    // Dziala dla:      0 1 0 0 0 0 0 0 0 0 1 0 1 1 0 0 0 0 0 1 0 0 1 0 0 0 1 0 0 0 0 1 1 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 1
//    // Dziala dla:      0 1 1 0 0 0 0 0 0 0 0 1 1 0 0 0 1 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 1 0 0 1 0 0 0 1 0 0 0 1 0 1 0 0
//    cout << endl;
//    for (int i = 0; i < G.N; i++) {
//        for (int j = 0; j < G.N; j++)
//            cout << G.G[i][j] << " ";
//        cout << endl;
//    }
//    cout << endl;
//    DFS(G);
////    for (int i = 0; i < G.N; i++) cout << G.tpocz[i] << " ";
//    cout << endl;
////    for (int i = 0; i < G.N; i++) cout << G.tzak[i] << " ";
//    transposition(G);
//    DFS_mod(G);
    // 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 1 0 1 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0
    Graph G;
    G.N = 7;
    G.G = new int* [G.N];
    for (int i = 0; i < G.N; i++) G.G[i] = new int [G.N];
    G.parent = new int[G.N];
    G.tpocz = new int[G.N];
    G.tzak = new int [G.N];
    G.visited = new bool [G.N];
    G.helper = new helping [G.N];
    for (int i = 0; i < G.N; i++) {
        G.visited[i] = false;
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
    DFS(G);
    for (int i = 0; i < G.N; i++) cout << G.tpocz[i] << " ";
    cout << endl;
    for (int i = 0; i < G.N; i++) cout << G.tzak[i] << " ";
    transposition(G);
    cout << endl << endl << "SSS to: ";
    cout << "Liczba SSS: " << DFS_mod(G) << endl;
}
