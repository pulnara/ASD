// Ustawia wierzcholki w takim porzadku, ze gdybysmy narysowali je w 1 linii, wszystkie krawedzie skierowane bylyby z lewej na prawa (->)
/*
Przykladowe dane:
0 -> 1 | 2
1 -> 4 | 5
2 -> 3 | 5 | 6
3 ->
4 -> 3
5 ->
6 -> 1
*/
#include <iostream>
#include <stack>
using namespace std;

struct Vertex {
    int edges_num;
    int* edges;
    bool visited;
};

stack <int> S;

void DFS_visit (Vertex* Table, int N, int i) {
    Table[i].visited = true;

    for (int j = 0; j < Table[i].edges_num; j++) {
        int x = Table[i].edges[j];
        if (!Table[x].visited) DFS_visit(Table, N, x);
    }

    S.push(i);
}

void TopolSort (Vertex* Table, int N) {
    for (int i = 0; i < N; i++)
        Table[i].visited = false;

    for (int i = 0; i < N; i++) {
        if (!Table[i].visited) DFS_visit(Table, N, i);
    }

    while (!S.empty()) {
        cout << S.top() << " ";
        S.pop();
    }
}

int main() {
    int N = 7;
    Vertex* A = new Vertex [N];
    A[0].edges_num = 2;
    A[1].edges_num = 2;
    A[2].edges_num = 3;
    A[3].edges_num = 0;
    A[4].edges_num = 1;
    A[5].edges_num = 0;
    A[6].edges_num = 1;
    for (int i = 0; i < N; i++) {
        A[i].edges = new int [A[i].edges_num];
        for (int j = 0; j < A[i].edges_num; j++) {
            cin >> A[i].edges[j];
        }
    }
    TopolSort(A, N);
}
