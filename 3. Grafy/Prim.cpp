#include <iostream>
using namespace std;

struct Vertex {
    int edges; // ile krawedzi tworzy ten wierzcholek
    int* edge; // tabela wierzcholkow sasiadujacych z tym wierzcholkiem (krawedzi)
    int* weight; // tabela wag krawedzi
};

struct queuenode {
    queuenode* next;
    int w;
    int t;
};

void insert (queuenode*& head, int t, int w) {
    queuenode* node = new queuenode;
    node -> w = w;
    node -> t = t;
    if (head == NULL) {
        node -> next = head;
        head = node;
    }
    else if (head -> w > w) {
        node -> next = head;
        head = node;
    }
    else {
        queuenode* tmp = head;
        while (tmp -> next != NULL and tmp -> next -> w < w) tmp = tmp -> next;
        node -> next = tmp -> next;
        tmp -> next = node;
    }
}

int* Prim (Vertex* V, int n, int s) {
    int* parent = new int[n];
    int w[n];
    bool processed[n];
    for (int i = 0; i < n; i++) {
        processed[i] = false;
        w[i] = INT_MAX;
        parent[i] = -1;
    }
    //////////
    w[s] = 0;
    queuenode* queue = NULL;
    insert(queue, s, w[s]);

    while (queue != NULL) {
        queuenode* front = queue;   // powinno byc tutaj prawdziwe findMin, ktore wybiera minimalna wage z kolejki, a w przypadku kilku takich samych wag, mniejszy numer wierzcholka
//        cout << front -> t << " ";
        queue = queue -> next;
        int u = front -> t;
        if (processed[u]) continue;

        processed[u] = true;
        for (int i = 0; i < V[u].edges; i++) {
            int t = V[u].edge[i];
            if (!processed[t] and V[u].weight[i] < w[t]) {
                w[t] = V[u].weight[i];
                parent[t] = u;
                insert(queue, t, w[t]);
            }
        }
    }
    cout << endl;
    return parent;
}


int main() {
    Vertex* V = new Vertex[9];
    V[0].edges = 2;
    V[1].edges = 3;
    V[2].edges = 4;
    V[3].edges = 3;
    V[4].edges = 2;
    V[5].edges = 4;
    V[6].edges = 3;
    V[7].edges = 4;
    V[8].edges = 3;

    for (int i = 0; i < 9; i++) {
        V[i].edge = new int [V[i].edges];
        V[i].weight = new int [V[i].edges];
    }

    V[0].edge[0] = 1;
    V[0].edge[1] = 7;
    V[0].weight[0] = 4;
    V[0].weight[1] = 9;

    V[1].edge[0] = 0;
    V[1].weight[0] = 4;
    V[1].edge[1] = 2;
    V[1].weight[1] = 8;
    V[1].edge[2] = 7;
    V[1].weight[2] = 11;

    V[2].edge[0] = 1;
    V[2].edge[1] = 3;
    V[2].edge[2] = 5;
    V[2].edge[3] = 8;
    V[2].weight[0] = 8;
    V[2].weight[1] = 7;
    V[2].weight[2] = 4;
    V[2].weight[3] = 2;

    V[3].edge[0] = 2;
    V[3].edge[1] = 4;
    V[3].edge[2] = 5;
    V[3].weight[0] = 7;
    V[3].weight[1] = 9;
    V[3].weight[2] = 14;

    V[4].edge[0] = 3;
    V[4].edge[1] = 4;
    V[4].weight[0] = 9;
    V[4].weight[1] = 10;

    V[5].edge[0] = 2;
    V[5].edge[1] = 3;
    V[5].edge[2] = 4;
    V[5].edge[3] = 6;
    V[5].weight[0] = 4;
    V[5].weight[1] = 14;
    V[5].weight[2] = 10;
    V[5].weight[3] = 2;

    V[6].edge[0] = 5;
    V[6].edge[1] = 7;
    V[6].edge[2] = 8;
    V[6].weight[0] = 2;
    V[6].weight[1] = 1;
    V[6].weight[2] = 6;

    V[7].edge[0] = 0;
    V[7].edge[1] = 1;
    V[7].edge[2] = 6;
    V[7].edge[3] = 8;
    V[7].weight[0] = 8;
    V[7].weight[1] = 11;
    V[7].weight[2] = 1;
    V[7].weight[3] = 7;

    V[8].edge[0] = 2;
    V[8].edge[1] = 6;
    V[8].edge[2] = 7;
    V[8].weight[0] = 2;
    V[8].weight[1] = 6;
    V[8].weight[2] = 7;

    int* par = Prim(V, 9, 0);
    for (int i = 0; i < 9; i++) cout << i << ": " << par[i] << "  ";
}
