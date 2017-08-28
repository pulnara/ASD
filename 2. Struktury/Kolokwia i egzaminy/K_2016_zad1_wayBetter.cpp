#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct SLNode {
    int val; // wartosc przechowywana w wezle
    int level; // poziom wezla
    SLNode** next; // level-elementowa tablica wskazników na nastepniki
};

struct SkipList {
    SLNode* first; // wartownik przedni (pole value ma wartosc -oo)
    SLNode* last; // wartownik tylny (pole value ma wartosc+oo)
};

const int MAX_LEVEL = 13;

void printSkipList (SkipList A) {
    SLNode* flyer = A.first -> next[0];
    while (flyer != A.last) {
        for (int i = flyer -> level - 1; i >= 0; i--) {
            cout << flyer -> val << " -> " << endl;
        }
        flyer = flyer -> next[0];
        cout << endl;
    }
}

void insertAfter(SkipList A, SLNode* prev[], int k, int height) {
    SLNode* inserting = new SLNode;
    inserting -> val = k;
    inserting -> level = height;
    inserting -> next = new SLNode* [height];
    for (int i = 0; i < height; i++) {
        prev[i] -> next[i] = inserting;
        inserting -> next[i] = A.last;
        prev[i] = inserting;
    }
}

SkipList merge (SkipList A, SkipList B) {
    SkipList C;
    C.first = new SLNode;
    C.first -> next = new SLNode* [MAX_LEVEL];
    C.last = new SLNode;
    SLNode* node = new SLNode;


    for (int i = 0; i < MAX_LEVEL; i++) {
        C.first -> next[i] = C.last;
    }

    SLNode* flyerA = A.first -> next[0];
    SLNode* flyerB = B.first -> next[0];

    SLNode* prev[MAX_LEVEL];
    for (int i = MAX_LEVEL - 1; i >= 0; i--) {
        prev[i] = C.first;
    }

    while (flyerA != A.last and flyerB != B.last) {
        if (flyerA -> val < flyerB -> val) {
            insertAfter(C, prev, flyerA -> val, flyerA -> level);
            flyerA = flyerA -> next[0];
        }
        else {
            insertAfter(C, prev, flyerB -> val, flyerB -> level);
            if (flyerA -> val == flyerB -> val) flyerA = flyerA -> next[0];
            flyerB = flyerB -> next[0];
        }
    }

    while (flyerA != A.last) {
        insertAfter(C, prev, flyerA -> val, flyerA -> level);
        flyerA = flyerA -> next[0];
    }

    while (flyerB != B.last) {
        insertAfter(C, prev, flyerB -> val, flyerB -> level);
        flyerB = flyerB -> next[0];
    }

    return C;
}

int main() {
    /////////
//    cout << "A:" << endl;
    SkipList A;
    SLNode* node = new SLNode;
    node -> level = 3;
    node -> val = 12;
    node -> next = new SLNode* [node -> level];
    A.first = new SLNode;
    A.first -> next = new SLNode* [MAX_LEVEL];
    A.last = new SLNode;
    for (int i = 0; i < node -> level; i++) {
        node -> next[i] = A.last;
        A.first -> next[i] = node;
    }
//    printSkipList(A);
    /////////
//    cout << "B:" << endl;
    SkipList B;
    SLNode* node1 = new SLNode;
    node1 -> level = 5;
    node1 -> val = 1;
    node1 -> next = new SLNode* [node1 -> level];
    B.first = new SLNode;
    B.first -> next = new SLNode* [MAX_LEVEL];
    B.last = new SLNode;
    for (int i = 0; i < node1 -> level; i++) {
        node1 -> next[i] = B.last;
        B.first -> next[i] = node1;
    }
//    printSkipList(B);
    //////////
    cout << "C:" << endl;
    SkipList C = merge(B, A);
    printSkipList(C);
    /////////
    cout << "D:" << endl;
    SkipList D;
    SLNode* node2 = new SLNode;
    node2 -> level = 4;
    node2 -> val = 5;
    node2 -> next = new SLNode* [node2 -> level];
    D.first = new SLNode;
    D.first -> next = new SLNode* [MAX_LEVEL];
    D.last = new SLNode;
    for (int i = 0; i < node2 -> level; i++) {
        node2 -> next[i] = D.last;
        D.first -> next[i] = node2;
    }
    printSkipList(D);
    /////////
    cout << "E:" << endl;
    SkipList E;
    SLNode* node3 = new SLNode;
    node3 -> level = 1;
    node3 -> val = 7;
    node3 -> next = new SLNode* [node3 -> level];
    E.first = new SLNode;
    E.first -> next = new SLNode* [MAX_LEVEL];
    E.last = new SLNode;
    for (int i = 0; i < node3 -> level; i++) {
        node3 -> next[i] = E.last;
        E.first -> next[i] = node3;
    }
    printSkipList(E);
    //////////
    cout << "F:" << endl;
    SkipList F = merge(D, E);
    printSkipList(F);
    ////////
    cout << "G:" << endl;
    SkipList G;
    SLNode* node4 = new SLNode;
    node4 -> level = 6;
    node4 -> val = 3;
    node4 -> next = new SLNode* [node4 -> level];
    G.first = new SLNode;
    G.first -> next = new SLNode* [MAX_LEVEL];
    G.last = new SLNode;
    for (int i = 0; i < node4 -> level; i++) {
        node4 -> next[i] = G.last;
        G.first -> next[i] = node4;
    }
    printSkipList(G);
    ////////
    cout << "H:" << endl;
    SkipList H = merge(G, F);
    printSkipList(H);
    //////////
    cout << "I:" << endl;
    SkipList I = merge(H, C);
    printSkipList(I);
}
