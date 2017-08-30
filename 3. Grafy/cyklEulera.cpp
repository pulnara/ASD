/* Algorytm znajdowania cyklu Eulera.
Dziala dla:
0 -> 4 -> 2
1 -> 0
3 -> 0 -> 1
4 -> 3
*/
#include <iostream>
using namespace std;


struct nlist {
    nlist* next;
    int val;
};

int DFS(nlist** G, int n, int s, int cykl[], int k) {
    while (G[s] != NULL) {
        nlist* v = G[s];
        G[s] = G[s] -> next;
        k = DFS(G, n, v -> val, cykl, k);
        delete v;
    }
    cykl[k] = s;
    return k-1;
}

int* Euler (nlist** G, int n) {
    int E = 0;
    int* in = new int[n];
    int* out = new int[n];
    for (int i = 0; i < n; i++) {
        in[i] = 0;
        out[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        nlist* p = G[i];
        while (p != NULL) {
            in[p -> val]++;
            p = p -> next;
            E++;
            out[i]++;
        }
    }
    for (int i = 0; i < n; i++) { // abu grafy skierowany mial cykl Eulera, do kazdego wierzcholka musi wchodzic tyle krawedzi, ile z niego wychodzi
        if (in[i] != out[i]) {
            delete [] in;
            delete [] out;
            return NULL;
        }
    }

//    int ile = 0;  // aby graf skierowany byl poleulerowski, musi miec max w wierzcholki dla ktorych in[i] rozni sie max o 1 od out[i]
//    for (int i = 0; i < n; i++) {
//        if (in[i] +1 == out[i] or in[i] == out[i] + 1) {
//            ile++;
//        }
//    }
//    if (ile > 2) {
//            delete [] in;
//            delete [] out;
//            return NULL;
//    }

    int* cykl = new int [E+1];
    delete [] in;
    delete [] out;
    int k = DFS(G, n, 0, cykl, E);
    if (k != -1) {
        delete cykl;
        return NULL;
    }
    return cykl;
}

int main() {
    int N = 5;
    nlist** G = new nlist* [N];
    for (int i = 0; i < N; i++) {
        G[i] = NULL;
        cout << i << " ";
        int flag;
        cin >> flag;
        while (flag >= 0) {
            nlist* node = new nlist;
            node -> val = flag;
            node -> next = G[i];
            G[i] = node;
            cin >> flag;
        }
        cout << endl;
    }
    int* sciezka = Euler(G, N);
    if (sciezka == NULL) cout << "Pusta";
    else {
        cout << "Cykl to: ";
        for (int i = 0; i < 8; i++) cout << sciezka[i] << " ";
    }
}
