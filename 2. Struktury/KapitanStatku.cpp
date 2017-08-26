/*
Mamy dwuwymiarowa tablice A[m][n] reprezentujaca zatoke. Musimy przemiescic sie statkiem z punktu (0, 0) do portu (m, n).
W kazdej komorce jest okreslony poziom wody. Jesli jest on >= T, statek moze wplynac do portu.
Napisz funkcje bool canEnter (Bay B, int T) sprawdzajaca czy moze wplynac.
*/
#include <iostream>
using namespace std;

struct Bay {
    int m, n; // wymiary tablicy A
    int**  A; // poziomy
    int** rank;
    int** px;
    int** py; // parenty

};

struct Pair {
    int x, y;
};

Pair findSet(Bay B, int x, int y);
void Union(Bay B, int x, int y, int x_good, int y_good);

bool canEnter (Bay B, int T) {
    for (int i = 0; i < B.n; i++) {
        for (int j = 0; j < B.m; j++) {
            B.px[i][j] = i;
            B.py[i][j] = j;
            B.rank[i][j] = 0;
        }
    }
    for (int i = 0; i < B.n; i++) {
        for (int j = 0; j < B.m; j++) {
            if (i == 0 and j == 0) continue;
            if (B.A[i][j] < T) continue;
            if (i == B.n and j == B.m) break;
            else {
                if(i > 0 and B.A[i-1][j] >= T) Union(B, i, j, i-1, j);
                else if(j > 0 and B.A[i][j-1] >= T) Union(B, i, j, i, j-1);
            }
        }
    }
    if (findSet(B, 0, 0).x == findSet(B, B.n-1, B.m-1).x and findSet(B, 0, 0).y == findSet(B, B.n-1, B.m-1).y) return true;
    return false;
}

Pair findSet (Bay B, int x, int y) {
    if (B.px[x][y] == x and B.py[x][y] == y) {
        Pair pair;
        pair.x = x;
        pair.y = y;
        return pair;
    }

    Pair p = findSet(B, B.px[x][y], B.py[x][y]);
    B.px[x][y] = p.x;
    B.py[x][y] = p.y;
    return p;
}

void Union(Bay B, int x, int y, int x_good, int y_good) {
    Pair a = findSet(B, x_good, y_good);
    Pair b = findSet(B, x, y);
    if (a.x == b.x and a.y == b.y) return;

    if(B.rank[b.x][b.y] < B.rank[a.x][a.y]) swap (a, b);
    B.px[a.x][a.y] = b.x;
    B.py[a.x][a.y] = b.y;
    if (B.rank[a.x][a.y] == B.rank[b.x][b.y]) B.rank[b.x][b.y]++;
}

int main() {
    Bay bay;
    bay.n = 5;
    bay.m = 4;

}
