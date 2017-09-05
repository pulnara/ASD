// zaimplementowalam, bo nie moglam zrozumiec ;)
#include <iostream>
using namespace std;


struct edge {
    char whostarts;
    int ind;
    int weight;
    edge* next;
};

int extractMin (bool taken[], int d[], int N) {
    int min = INT_MAX;
    int minInd = -1;
    for (int i = 0; i < N; i++) {
        if (!taken[i] and d[i] < min) {
            min = d[i];
            minInd = i;
        }
    }
    return minInd;
}

void printPath(int parent[], int y) {
    if (parent[y] != -1) printPath(parent, parent[y]);
    cout << " " << y;
}

int Dijkstra(char who, bool taken[], int parent[], edge* Tab[], int d[], int N, int x, int y) {
    char* BobOrAla = new char [N];
    BobOrAla[x] = who;
    for (int i = 0; i < N; i++) {
        taken[i] = false;
        d[i] = INT_MAX;
        parent[i] = -1;
    }
    d[x] = 0;

    for (int i = 0; i < N; i++) {
        int n = extractMin(taken, d, N);
        taken[n] = true;
        who = BobOrAla[n];
        edge* p = Tab[n];
        while (p != NULL) {
            if (p -> whostarts != who and !taken[p -> ind]) {
                if (d[p -> ind] > d[n] + p -> weight) {
                    if (who == 'A') BobOrAla[p -> ind] = 'B';
                    else BobOrAla[p -> ind] = 'A';
                    d[p -> ind] = d[n] + p -> weight;
                    parent[p -> ind] = n;
                }
            }
            p = p -> next;
        }
    }
    return d[y];
}



int BobAndAla (int** G, int N, int x, int y) {
    edge* Tab[N];
    for (int i = 0; i < N; i++) Tab[i] = NULL;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (G[i][j] != 0) {

                edge* info1 = new edge;
                info1 -> whostarts = 'B';
                info1 -> weight = G[i][j];
                info1 -> ind = j;

                edge* info2 = new edge;
                info2 -> whostarts = 'A';
                info2 -> weight = 0;
                info2 -> ind = j;

                info1 -> next = Tab[i];
                info2 -> next = info1;
                Tab[i] = info2;

                edge* info3 = new edge;
                info3 -> whostarts = 'A';
                info3 -> ind = i;
                info3 -> weight = G[i][j];

                edge* info4 = new edge;
                info4 -> whostarts = 'B';
                info4 -> ind = i;
                info4 -> weight = 0;

                info3 -> next = Tab[j];
                info4 -> next = info3;
                Tab[j] = info4;
            }

        }
    }

    bool taken[N];
    int d[N];
    int* parentA = new int[N];
    int* parentB = new int[N];

    int a = Dijkstra('A', taken, parentA, Tab, d, N, x, y);
    int b = Dijkstra('B', taken, parentB, Tab, d, N, x, y);
    if (a > b) {
        cout << "Zaczyna Bob. Trasa: ";
        printPath(parentB, y);
        return b;
    } else {
        cout << "Zaczyna Ala. Trasa: ";
        printPath(parentA, y);
        return a;
    }
}



int main() {
    int N = 10;
    int** G = new int* [N];
    for (int i = 0; i < N; i++) {
        G[i] = new int [N];
        for (int j = 0; j < N; j++) G[i][j] = 0;
    }

    G[0][1] = 12;
    G[0][2] = 5;
    G[1][3] = 9;
    G[2][3] = 18;
    G[3][4] = 16;
    G[3][5] = 4;
    G[4][7] = 17;
    G[5][6] = 5;
    G[5][7] = 19;
    G[6][7] = 20;
    G[7][8] = 19;
    G[7][9] = 3;
    G[9][8] = 7;
    cout << endl << "Ala przejedzie: " << BobAndAla(G, N, 0, 8) << " km." << endl;
}
