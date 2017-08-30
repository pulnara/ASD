/* Algorytm Kruskala znajdowania Minimalnego Drzewa Rozpinajacego */
#include <windows.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

struct helping {
    int w;
    int from;
    int to;
};

struct sets {
    int* parent;
    int* rank;
    int** A;
};

int Partition(helping A[], int p, int r);
void QuickSort(helping A[], int p, int r);
int FindSet(sets K, int i);
void Union(sets K, int i, int j);

void Kruskal (int** G, int N) {
    sets K;
    K.parent = new int [N];
    K.rank = new int [N];
    K.A = new int* [N];
    int e = 0;
    for (int i = 0; i < N; i++) {
        K.A[i] = new int [N];
        K.parent[i] = i;
        K.rank[i] = 0;
        for (int j = 0; j < N; j++) {
            K.A[i][j] = 0;
            if (G[i][j] > 0) e++;
        }
    }
    helping T[e];
    int k = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (G[i][j] > 0) {
                T[k].w = G[i][j];
                T[k].from = i;
                T[k].to = j;
                k++;
            }
        }
    }
    /// CZESC WLASCIWA /////
    QuickSort(T, 0, e-1);
//    for (int i = 0; i < e; i++) cout << T[i].w << " ";
    int i = 0;
    for (int i = 0; i < e; i++) {
        if (FindSet(K, T[i].from) != FindSet(K, T[i].to)) {
            K.A[T[i].from][T[i].to] = 1;
            Union(K, T[i].from, T[i].to);
        }
    }

    HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    for (int i = 0; i < N; i++) {
        cout << i << "| ";
        for (int j = 0; j < N; j++) {
            if (K.A[i][j] == 1) SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
            else SetConsoleTextAttribute( hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
            cout << K.A[i][j] << " ";
        }
        cout << endl;
    }

}

int Partition(helping A[], int p, int r) {
    int x = A[r].w;
    int j = p-1;
    for (int i = p; i < r; i++) {
        if (A[i].w <= x) {
            j++;
            swap(A[i], A[j]);
        }
    }
    swap (A[r], A[j+1]);
    return j+1;
}

void QuickSort(helping A[], int p, int r) {
    if (p < r) {
        int q = Partition(A, p, r);
        QuickSort(A, p, q - 1);
        QuickSort(A, q + 1, r);
    }
}

int FindSet(sets K, int i) {
    if (K.parent[i] != i) K.parent[i] = FindSet(K, K.parent[i]);
    return K.parent[i];
}

void Union(sets K, int i, int j) {
    i = FindSet(K, i);
    j = FindSet(K, j);
    if (K.rank[j] < K.rank[i]) swap(i, j);
    K.parent[i] = j;
    if (K.rank[i] == K.rank[j]) K.rank[j]++;
}

int main() {
    int N = 9;
    int** A = new int* [N];
    for (int i = 0; i < N; i++) A[i] = new int[N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) A[i][j] = 0;
    }
    // 4 0 8 0 0 7 0 0 0 9 0 0 4 14 10 0 0 0 0 0 2 8 11 0 0 0 0 1 0 0 2 0 0 0 6 7
    for (int i = 0; i < N; i++) {
        int j = 0;
        while (j < i) {
            cin >> A[i][j];
            j++;
        }
    }

//    for (int i = 0; i < N; i++) {
//        for (int j = 0; j < N; j++) {
//            cout << A[i][j] << " ";
//        }
//        cout << endl;
//    }
    Kruskal(A, N);
}
