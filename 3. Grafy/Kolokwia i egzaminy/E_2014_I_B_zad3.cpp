/*
Dostajemy graf w postaci listy sasiedztwa, oraz dwa wierzcholki. Znajdz najkrotsza sciezke z wierzcholka s do t.
Wagi krawedzi sa o rozmiarze maksymalnie loglogV, gdzie V ilosc wierzcholkow w grafie.
Omow zlozonosc czasowa algorytmu.
Zlozonosc: O(E*loglogV), E - liczba krawedzi, V - liczba wierzcholkow
*/
#include <iostream>
#include <queue>
using namespace std;

struct nlist {
    nlist* next;
    int ind;
    int w;
};

struct vertex {
    int w;
    int parent;
    int ind;
};

void printPath (int parent[], int t) {
    if (parent[t] != -1) printPath(parent, parent[t]);
    cout << " " << t;
}

void shortestPath (nlist** G, int N, int s, int t) {
    int parent[N];
    bool visited[N];
    for (int i = 0; i < N; i++) {
        parent[i] = -1;
        visited[i] = false;
    }

    queue <vertex> q;
    vertex x;
    x.ind = s;
    x.parent = -1;
    x.w = 1;
    q.push(x);

    while (!q.empty()) {
        x = q.front();
        q.pop();
        x.w--;
        if (x.w == 0) {     // jesli zminimalizowalismy juz wage do zera
            if (visited[x.ind]) continue;
            if (x.ind == t) {   // jesli dotarlismy do konca, konczymy
                parent[t] = x.parent;
                break;
            }
            visited[x.ind] = true;  // jesli nie, oznaczamy wierzcholek jako odwiedzony i przegladamy jego liste sasiedztwa
            parent[x.ind] = x.parent;

            nlist* p = G[x.ind];
            while (p != NULL) {
                if (!visited[p -> ind]) {
                    vertex toQueue;
                    toQueue.w = p -> w;
                    toQueue.ind = p -> ind;
                    toQueue.parent = x.ind;
                    q.push(toQueue);
                }
                p = p -> next;
            }
        }

        else q.push(x);     // jesli nie zminimalizowalismy wagi do zera, kontynuujemy jej zmniejszanie

    }
    printPath(parent, t);
}

int main() {
    int N = 7;
    int A[N][N];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            A[i][j] = -1;
        }
    }
    A[0][1] = A[1][2] = A[4][5] = 1;    // przepisywanie z tablicy do list sasiedztwa zgapione z rocznikowego gita
    A[0][2] = A[2][3] = A[3][4] = 5;
    A[2][6] = A[6][4] = 2;

    nlist** G = new nlist* [N];
    for (int i = 0; i < N; i++) {
        G[i] = NULL;
        for (int j = 0; j < N; j++) {
            if (A[i][j] != -1) {
                nlist* node = new nlist;
                node -> w = A[i][j];
                node -> ind = j;
                node -> next = G[i];
                G[i] = node;
            }
        }
    }
    shortestPath(G, N, 0, 5);
}
