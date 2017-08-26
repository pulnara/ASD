/*
W ramach obchodow miedzynarodowego swieta cyklistow organizatorzy przewidzieli gorska wycieczke rowerowa.
Bedzie sie ona odbywac po bardzo waskiej sciezce, na ktorej rowery moga jechac tylko jeden za drugim.
W ramach zapewnienia bezpieczenstwa kazdy rowerzysta bedzie mial numer identyfikacyjny oraz male urzadzenie,
przez ktore bedzie mogl przekazac identyfikator rowerzysty przed nim (lub -1 jesli nie widzi przed soba nikogo).
Nalezy napisac funkcje, ktora na wejsciu otrzymuje informacje wyslane przez rowerzystow i oblicza rozmiar najmniejszej grupy
(organizatorzy obawiaja sie, ze na male grupy moglyby napadac dzikie zwierzeta). Dane sa nastepujace struktury danych:
    struct Cyclist {
        int id, n_id; // identyfikator rowerzysty oraz tego, ktorego widzi
    };
Funkcja powinna miec prototyp
    int smallestGroup( Cyclist cyclist[], int n ),
gdzie cyclist to tablica n rowerzystow. Funkcja powinna byc mozliwie jak najszybsza.
Mozna zalozyc, ze identyfikatory rowerzystow to liczby z zakresu 0 do 10^8 (osiem cyfr napisanych w dwoch rzedach na koszulce rowerzysty)
i ze pamiec nie jest ograniczona. Rowerzystow jest jednak duzo mniej niz identyfikatorow (nie bez powodu boja sie dzikich zwierzat).
Nalezy zaimplementowac wszystkie potrzebne struktury danych.
*/
#include <iostream>
#include <queue>
using namespace std;

////3. Tworze zmienna int licznik = 0. Bedzie on wkrotce zawieral liczbe grup.
//6. Tworze funkcje:
//        findSet (int T[], int id) {
//            if (T[id] != id) {
//                T[id] = findset(T, T[id]);
//            }
//            return id;
//        }

struct Cyclist {
    int id, n_id; // identyfikator rowerzysty oraz tego, ktorego widzi
};

struct Node {
    int val;
    Node* next;
};

//  W tablicy T sa 'poukrywane' nasze zbiory rozlaczne. Funkcja ta ma za zadanie pod kazdy indeks rowerzysty wpisac indeks pierwszego rowerzysty z jego grupy.
int findSet (int T[], int id) {
    if (T[id] != id) {
        T[id] = findSet(T, T[id]);
    }
    return id;
}

int smallestGroup (Cyclist cyclist[], int n) {
    //1. Skoro pamiec nie jest ograniczona - tworze tablice T intow o rozmiarze 10^8.
    int N = 10000;
    int T[N];

    //2. Przechodzac raz przez dana do funkcji tablice cyclist, zeruje kazde pole w tablicy T o indeksie cyclist[i].id. id kazdego z rowerzystow wrzucam na liste 'cyclists' tradycyjnych node'ow z intem i nextem.
    Node* cyclists = NULL;
    for (int i = 0; i < n; i++) {
        T[cyclist[i].id] = 0;
        Node* node = new Node;
        node -> val = cyclist[i].id;
        node -> next = cyclists;
        cyclists = node;
    }

    //3. Przechodzac raz przez dana do funkcji tablice cyclist, wpisuje 1 w w kazdym polu tablicy T o indeksie cyclist[i].n_id, jesli n_id != -1
    for (int i = 0; i < n; i++) {
        if (cyclist[i].n_id != -1) T[cyclist[i].n_id] = 1;
    }


    //4. Przechodzac raz przez liste cyclists, szukam w tablicy T pol o indeksie l1 -> val, w ktorych pozostaly '0'.
    //   Sa to cyklisci zamykajacy kazda z grup, ktorych nikt nie widzi. Jesli napotkamy takiego cykliste, wrzucamy go na kolejke q.
    Node* flyer = cyclists;
    queue <int> q;
    while (flyer != NULL) {
        if (T[flyer -> val] == 0) q.push(flyer -> val);
        flyer = flyer -> next;
    }

    // Skonczylismy juz szukac ostatnich cyklistow zamykajacych grupy. Teraz bedziemy traktowac rowerzystow jako elementy zbiorow.
    //5. Przechodzac raz przez dana do funkcji tablice cyclist, pod kazdy napotkany indeks cyclist[i].id wpisuje cyclist[i].n_id (gdy cyclist[i].n_id == -1, wpisuje id).
    for (int i = 0; i < n; i++) {
        if (cyclist[i].n_id != -1) {
            T[cyclist[i].id] = cyclist[i].n_id;
        }
        else {
            T[cyclist[i].id] = cyclist[i].id;
        }
    }

    //6. Po kolei wyciagajac z kolejki ostatnich rowerzystow, wywoluje findSet(T, numer_ostatniego_rowerzysty).
    // Od teraz pod konkretnym indeksem rowerzysty w tablicy T bedzie indeks pierwszego rowerzysty z jego grupy.
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        findSet(T, x);
    }

    //7. Tworze tablice licznikow liczebnosci grup - A[10^8] i przechodzac przez liste cyclists i korzystajac z informacji w tablicy T, zeruje pola w tablicy A pod tymi indeksami,
    //ktore w tablicy T maja wartosc rowna swojemu indeksowi (pierwsi rowerzysci, czyli reprezentanci naszych grup).
    int A[N];
    flyer = cyclists;
    while (flyer != NULL) {
        if (T[flyer ->val] == flyer -> val) A[flyer -> val] = 0;
        flyer = flyer -> next;
    }

    //8. Drugi raz przechodzac przez liste cyclists i korzystajac z informacji w tablicy T, inkrementuje pola w tablicy A pod tymi indeksami, jaka wartosc wystepuje w T[l1 -> val].
    flyer = cyclists;
    while (flyer != NULL) {
        A[T[flyer -> val]]++;
        flyer = flyer -> next;
    }

    //10. Ostatni raz przechodczac przez liste cyclists, szukam minimalnej wartosci A[l1 -> val].
    int min = n;
    flyer = cyclists;
    while (flyer != NULL) {
        if (A[flyer -> val] < min) min = A[flyer -> val];
        flyer = flyer -> next;
    }

    return min;
}

int main() {




}
