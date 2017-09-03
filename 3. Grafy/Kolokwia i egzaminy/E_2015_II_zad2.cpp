#include <iostream>
using namespace std;
// Kruskal

struct List {
    int u, v, w;
    List* next;
};

int FindSet (int ind, int parent[]) {
    if (ind != parent[ind]) parent[ind] = FindSet(parent[ind], parent);
    return parent[ind];
}

List* extractMax(List* L) {
    int max = L -> next -> w;
    List* maxNode = L;
    while (L -> next != NULL) {
        if (L -> next -> w > max) {
            max = L -> next -> w;
            maxNode = L;
        }
        L = L -> next;
    }
    List* result = maxNode -> next;
    maxNode -> next = maxNode -> next -> next;
    return result;
}

List* sort (List* L) {
    List* sorted = NULL;
    while (L -> next != NULL) {
        List* node = extractMax(L);
        node -> next = sorted;
        sorted = node;
    }
    return sorted;
}

void Union (int i1, int i2, int parent[], int rank[]) {
    i1 = FindSet(i1, parent);
    i2 = FindSet(i2, parent);
    if (rank[i1] > rank[i2]) swap (i1, i2);
    parent[i2] = i1;
    if (rank[i2] == rank[i1]) rank[i1]++;
}

int MST(int **G,  int n)  {
    int parent[n];
    int rank[n];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    List* list = NULL;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (G[i][j] > 0) {
                List* node = new List;
                node -> u = i;
                node -> v = j;
                node -> w = G[i][j];
                node -> next = list;
                list = node;

            }
        }
    }

    List* node = new List;
    node -> next = list;
    list = node;

    List* rem = sort(list);

//    while (rem != NULL) {
//        cout << rem -> u << " " << rem -> v << endl;
//        rem = rem -> next;
//    }

    while (rem != NULL) {
        if (FindSet(rem -> u, parent) != FindSet(rem -> v, parent)) {
            Union(rem -> u, rem -> v, parent, rank);
            sum += rem -> w;
        }
//        cout << parent[rem -> u] << " " << parent[rem -> v] << endl;
        rem = rem -> next;
    }
    return sum;
}


int main() {
    int N = 8;
    int** G = new int* [N];
    for (int i = 0; i < N; i++) G[i] = new int [N];
    int G1[N][N] = {
	// 0  1  2  3  4  5  6  7
	{ 0, 5, 0, 9, 0, 0, 3, 0 },  // 0
	{ 0, 0, 9, 0, 8, 6, 0, 7 },  // 1
	{ 0,  0, 0, 9, 4, 0, 5, 3 }, // 2
	{ 0,  0, 0, 0, 0, 0, 8, 0 }, // 3
	{ 0,  0, 0, 0, 0, 2, 1, 0 }, // 4
	{ 0,  0, 0, 0, 0, 0, 6, 0 }, // 5
	{ 0,  0, 0, 0, 0, 0, 0, 9 }, // 6
	{ 0,  0, 0, 0, 0, 0, 0, 0 }  // 7
};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) G[i][j] = G1[i][j];
    }

    cout << MST(G, N);
}
