/* Student chce wypuscic n roznych pok'emonow (numerowanych od 0 do n-1) z klatek (pok'eball'i).
Wypuszczony Pok'emon natychmiast atakuje swojego wybawiciela, chyba ze:
(a) jest spokojny, lub
(b) w okolicy znajduja sie co najmniej dwa uwolnione pok'emony, na ktore ten pok'emon poluje.
Prosze zaimplementowac funkcje:
    int* releaseThemAll( HuntingList* list, int n ),
gdzie list to lista z informacja, ktore pok'emony poluja na ktore (lista nie zawiera powtorzen):
    struct HuntingList {
        HuntingList* next; // nastepny element listy
        int predator; // numer pokemona, ktory poluje
        int prey; } // numer pokemona, na ktorego poluje
Funkcja powinna zwrocic n elementowa tablice z numerami pok'emonow w kolejnosci wypuszczania
tak, zeby wypuszczajacy nie zostal zaatakowany) lub NULL jesli taka kolejnosc nie istnieje.
Kazdy wypuszczony pok'emon zostaje "w okolicy".
Jesli pok'emon nie wystepuje na liscie jako predator to znaczy, ze jest spokojny.
Zaimplementowana funkcja powinna byc mozliwie jak najszybsza. Prosze krotko oszacowac jej zlozonosc. */
#include <iostream>
#include <queue>
#include <stdlib.h>
using namespace std;

 struct HuntingList {
        HuntingList* next;
        int predator;
        int prey;
 };

 struct Node {
    int val;
    Node* next;
 };

 struct Help {
    int pred;
    int prey;
 };

 HuntingList* create (Help A[], int n) {
    HuntingList* head = NULL;
    for (int i = 0; i < n; i++) {
        HuntingList* node = new HuntingList;
        node -> predator = A[i].pred;
        node -> prey = A[i].prey;
        node -> next = head;
        head = node;
    }
    return head;
 }

 int* releaseThemAll(HuntingList* list, int n) {
    queue <int> q;

    int G[n][n] = {}; // macierz reprezentujaca graf

//    int Tab[n];
//
//    for (int i = 0; i < n; i++) {
//        Tab[i] = NULL;
//    }

    HuntingList* p = list;

    while (p != NULL) {
//        node* Prey = new node;
//        Prey -> val = p -> prey;
//        Prey -> next = Tab[p -> predator];
//        Tab[p -> predator] = Prey;
        G[p -> predator][p -> prey] = 1;
        p = p -> next;
    }

//    for (int i = 0; i < n; i++) {
//        if (Tab[i] == NULL) q.push(i);
//    }

    for (int i = 0; i < n; i++) {
        bool calm = true;
        for (int j = 0; j < n; j++) {
            if (G[i][j] == 1) calm = false;
        }
        if (calm) q.push(i);
    }
    int Counters[n] = {};   // liczniki

//    int* Kol = new int[n];    // tablica wynikowa reprezentujaca kolejnosc
    int* Kol = (int*) malloc (n * sizeof(*Kol));
    for (int i = 0; i < n; i++) Kol[i] = -1;
    int i = 0;

    while (!q.empty()) {
        Kol[i] = q.front();
        q.pop();
        i++;
        for (int j = 0; j <n; j++) {
            if (G[j][Kol[i]] == 1) {
                Counters[j]++;
                if (Counters[j] == 2) q.push(j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (Kol[i] == -1) return NULL;
    }

    return Kol;
 }

 int main() {
     int N = 8;
     Help A[N] = {0, 1, 0, 2, 1, 4, 1, 5, 2, 1, 2, 4, 5, 4, 5, 6};
     HuntingList* head = create(A, N);
     int* wyn = releaseThemAll(head, 7);
//    while (head != NULL) {
//        cout << head -> prey << " ";
//        head = head -> next;
//    }
    for (int i = 0; i < 7; i++) cout << wyn[i] << " ";
 }
