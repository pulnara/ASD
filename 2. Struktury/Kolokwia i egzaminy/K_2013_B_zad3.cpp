/* Dana jest tablica:
    int n = ...
    int m = ...
    bool A[m][n];
Gracz poczatkowo znajduje sie na (zadanej) pozycji (x,y), dla ktorej zachodzi A[y][x] == true.
Z danej pozycji wolno bezposrednio przejsc jedynie na pozycje, ktorej dokladnie jedna wspolrzedna rozni sie o 1,
oraz ktorej wartosc w tablicy A wynosi true. Prosze napisac program obliczajacy do ilu roznych pozycji moze dojsc gracz startujac z zadanej pozycji (x,y).
1 0 0 1 0 0 0 1 1 0 0 1 1 0 1 0 0 1 1 0
*/
#include <iostream>
using namespace std;

struct Pair {
    int x;
    int y;
};

Pair FindSet (int** px, int** py, int x, int y) {
    if (px[x][y] == x and py[x][y] == y) {
        Pair p;
        p.x = x;
        p.y = y;
        return p;
    }

    Pair p = FindSet(px, py, px[x][y], py[x][y]);
    px[x][y] = p.x;
    py[x][y] = p.y;
    return p;
}

void Union (int** rank, int** px, int** py, int x, int y, int x_good, int y_good) {
    Pair a = FindSet(px, py, x_good, y_good);
    Pair b = FindSet(px, py, x, y);
    if (a.x == b.x and a.y == b.y) return;

    if (rank[a.x][a.y] < rank[b.x][b.y]) {
        px[a.x][a.y] = b.x;
        py[a.x][a.y] = b.y;
    }
    else {
        px[b.x][b.y] = a.x;
        py[b.x][b.y] = a.y;
        if (rank[a.x][a.y] == rank[b.x][b.y]) rank[b.x][b.y]++;
    }
}

int howManyPos (int m, int n, bool** A, int x, int y) {
    int howMany = 0;
    int** px = new int* [m];
    int** py = new int* [m];
    int** rank = new int* [m];

    for (int i = 0; i < m; i++) {
        px[i] = new int[n];
        py[i] = new int[n];
        rank[i] = new int[n];
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            px[i][j] = i;
            py[i][j] = j;
            rank[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 and j == 0) continue;
            else if (i > 0 and (A[i][j] and A[i-1][j])) {
//                cout << i << " " << j << "  " << i-1 << " " << j << endl;
                Union(rank, px, py, i, j, i-1, j);
//                cout << px[i][j] << " " << py[i][j] << "  " << px[i-1][j] << " " << py[i-1][j] << endl;
            }

            if (j > 0 and (A[i][j] and A[i][j-1]))  {
//                cout << i << " " << j << "  " << i << " " << j-1 <<endl;
                Union(rank, px, py, i, j, i, j-1);
//                cout << px[i][j] << " " << py[i][j] << "  " << px[i][j-1] << " " << py[i][j-1] << endl;
                if (i > 0 and (A[i][j] and A[i-1][j])) Union(rank, px, py, i-1, j, i, j-1);
            }
        }
    }

    int ppx = FindSet(px, py, x, y).x;
    int ppy = FindSet(px, py, x, y).y;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == x and j == y) continue;
            if (FindSet(px, py, i, j).x == ppx and FindSet(px, py, i, j).y == ppy) {
//              cout << i << " " << j << endl;
                howMany++;
            }
        }
    }

    return howMany;
}

int main() {
    int n = 5;
    int m = 4;
    bool** A = new bool* [m];
    for (int i = 0; i < m; i++) A[i] = new bool[n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cin >> A[i][j];
    }

    int x = 1;
    int y = 3; // (1, 3)
    cout << "Moze dojsc do: " << howManyPos(m, n, A, x, y) << " pozycji.";
}
