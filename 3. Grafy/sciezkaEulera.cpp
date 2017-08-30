/* Algorytm znajdowania sciezki Eulera w grafie skierowanym
Dziala dla:
0 -> 2
1 -> 0
2 -> 4 -> 3
3 -> 1
4 -> 1
Albo dla:
0 -> 1 -> 4
1 -> 2
2 -> 3 -> 0
3 -> 4
4 -> 2
*/
#include <iostream>
#include <cmath>
using namespace std;

struct nlist {
    nlist* next;
    int val;
};

int DFS_mod (nlist** G, int s, int sciezka[], int k) { // zmodyfikowany nierekurencyjny DFS, ktory idzie najdalej jak moze
    while (G[s] != NULL) {
//        cout << G[s] -> val << " ";
        nlist* v = G[s];
        G[s] = G[s] -> next;
        sciezka[k] = v -> val;
//        sciezka[k] = s;
        k++;
        s = v -> val;
    }
    return k;
}

int* sciezkaEuler (nlist** G, int n, int& e) {
    int in[n];
    int out [n];
    for (int i = 0; i < n; i++) {
        in[i] = 0;
        out[i] = 0;
    }
    nlist* p;
    int E = 0;
    for (int i = 0; i < n; i++) {
        p = G[i];
        while (p != NULL) {
            out[i]++;
            E++;
            in[p -> val]++;
            p = p -> next;
        }
    }
    int ile = 0;
    for (int i = 0; i < n; i++) { // aby graf byl poleulerowski musi miec max 2 wierzcholki o roznicy in[i] i out[i] rownej max 1
        if (out[i] != in[i]) {
            if (abs(out[i] - in[i]) == 1) ile++;
            else {
                delete [] in;
                delete [] out;
                return NULL;
            }
        }
    }
    if (ile > 2) {
        delete [] in;
        delete [] out;
        return NULL;
    }
    delete [] in;
    delete [] out;
    //////////
    e = E;
    int* sciezka = new int[E+1];
    for (int i = 0; i < n; i++) {
        nlist* G_flyer[n];
        for (int j = 0; j < n; j++) {
            G_flyer[j] = G[j];
        }
        sciezka[0] = i;
        int k = DFS_mod(G_flyer, i, sciezka, 1);
//        cout << endl;
        if (k == E + 1) break;
//        for (int j = 0; j < E + 1; j++) sciezka[i] = -1;
        if (i == n-1) sciezka = NULL;
    }
    return sciezka;
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
    int e = 0;
    int* sciezka = sciezkaEuler(G, N, e);
//    cout << endl;
    if (sciezka == NULL) cout << "Nie ma sciezki Eulera.";
    else {
        cout << "Sciezka to: ";
        for (int i = 0; i < e + 1; i++)
            cout << sciezka[i] << " ";
    }
//    for (int i = 0; i < N; i++) {
//        while (G[i] != NULL) {
//            cout << G[i] -> val << " ";
//            G[i] = G[i] -> next;
//        }
//        cout << endl;
//    }
}
