/* Student musi zaliczyc n przedmiotow (numerowane od 0 do n-1). Zeby zaliczyc dany przedmiot, musi miec zaliczone wszystkie (poza najwyzej 1) przedmioty poprzedzajace.
Zaimplementuj:
    int* PassThemAll (Prerequisities* list, int n)
gdzie list to lista z info, ktore przedmioty poprzedzaja ktore (nie zawiera powtorzen):
    struct Prerequisities {
        Prerequisities* next;
        int sub;
        int prereq;
    };
Funkcja powinna zwrocic n-elementowa tablice z numerami przedmiotow w kolejnosci zaliczania
lub NULL, jesli taka kolejnosc nie istnieje.
Oszacuj zlozonosc.
*/
#include <iostream>
#include <queue>
using namespace std;

struct Prerequisities {
    Prerequisities* next;
    int sub;
    int prereq;
};

struct Help {
    int who;
    int needs;
 };

Prerequisities* create (Help A[], int n) {
    Prerequisities* first = NULL;
    for (int i = 0; i < n; i++) {
        Prerequisities* node = new Prerequisities;
        node -> sub = A[i].who;
        node -> prereq = A[i].needs;
        node -> next = first;
        first = node;
    }
    return first;
 }

int* PassThemAll (Prerequisities* list, int n) {
    int G[n][n] = {};

    Prerequisities* flyer = list;
    while (flyer != NULL) {
        G[flyer -> sub][flyer -> prereq] = 1;
        flyer = flyer -> next;
    }

    int Counters[n] = {};
    queue <int> q;

    for (int i = 0; i < n; i++) {
        int ones = 0;
        for (int j = 0; j < n; j++) {
            if (G[i][j] == 1) ones++;
        }
        if (ones <= 1) q.push(i);
        Counters[i] = ones;
    }

    int* Kol = new int[n];
    int i = 0;
    for (int j = 0; j < n; j++) Kol[j] = -1;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        Kol[i] = x;
        i++;
        for (int j = 0; j < n; j++) {
            if (G[j][x] == 1 and Counters[j] > 1) {
                Counters[j]--;
                if (Counters[j] <= 1) {
                    q.push(j);
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (Kol[i] == -1) return NULL;
    }

    return Kol;
}

int main() {
    // Dziala dla:
    //int N = 11;
    //Help A[N] = {0, 3, 0, 5, 1, 0, 1, 2, 2, 3, 2, 4, 3, 4, 4, 5, 3, 5, 5, 1, 4, 1};
    //int N = 8;
    // Help A[N] = {0, 3, 0, 5, 1, 0, 1, 2, 2, 3, 2, 4, 3, 4, 4, 5};
    // Nie dziala dla:
    int N = 12;
    Help A[N] = {0, 3, 0, 5, 1, 0, 1, 2, 2, 3, 2, 4, 3, 4, 4, 5, 3, 5, 5, 1, 4, 1, 5, 2};
    Prerequisities* list = create(A, N);
    int* wyn = PassThemAll(list, 6);
    if (wyn == NULL) cout << "Nie da sie.";
    else for (int i = 0; i < 6; i++) cout << wyn[i] << " ";
}
