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
#include <queue>
using namespace std;

int BFS(bool** A, int m, int n, int y, int x) {
    int c = 0;

    queue <int> q;
    q.push(x);
    q.push(y);
    A[y][x] = false;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        int y = q.front();
        q.pop();

        if (y-1 >= 0 and A[y-1][x]) {
            A[y-1][x] = false;
            q.push(x);
            q.push(y-1);
            c++;
        }
        if (x-1 >= 0 and A[y][x-1]) {
            A[y][x-1] = false;
            q.push(x-1);
            q.push(y);
            c++;
        }
        if (y+1 < m and A[y+1][x]) {
            A[y+1][x] = false;
            q.push(x);
            q.push(y+1);
            c++;
        }
        if (x+1 < n and A[y][x+1]) {
            q.push(x+1);
            q.push(y);
            c++;        }
    }

    return c;
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

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    int x = 3;
    int y = 1; // (1, 3)
    cout << "Moze dojsc do: " << BFS(A, m, n, y, x) << " pozycji.";
}
