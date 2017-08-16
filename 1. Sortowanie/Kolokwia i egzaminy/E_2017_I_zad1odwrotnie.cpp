/*
Egzamin 2016/17 Termin I
zad.1. Zaimplementuj funkcje node* sortList(node* L), ktora sortuje liste wejsciowa w kolejnosci nierosnacej i zwraca wskaznik na element,
ktory po posortowaniu zostal glowa tej listy (wejsciowa lista nie ma wartownika). Funkcja ma byc mozliwie jak najszybsza
(wiadomo, ze liczby w wejsciowej liscie zostaly wygenerowane z rozkladem jednostajnym na przedziale (0; 4).
*/
#include <iostream>
using namespace std;

struct node {
    double val;
    node* next;
};

node* create (double A[], int n) {
    if (n == 0) return NULL;

    node* head = new node;
    head -> val = A[0];
    node* tmp = head;

    for (int i = 1; i < n; i++) {
        tmp -> next = new node;
        tmp -> next -> val = A[i];
        tmp = tmp -> next;
    }
    tmp -> next = NULL;
    return head;
}

void print (node* L) {
    while (L != NULL) {
        cout << L -> val << " -> ";
        L = L -> next;
    }
    cout << "NULL" << endl;
}

int nodesNum (node* L) {
    int i = 0;
    while (L != NULL) {
        i++;
        L = L -> next;
    }
    return i;
}

void insertNode (node*& L, node* Q) {   // inserts a new node to a sorted list
    if (L == NULL or Q -> val < L -> val) {
        Q -> next = L;
        L = Q;
    }
    else {
        node* tmp = L;
        while (tmp -> next != NULL and tmp -> next -> val < Q -> val) {
            tmp = tmp -> next;
        }
        Q -> next = tmp -> next;
        tmp -> next = Q;
    }
}

node* select (node*& L) {       // selects the smallest value
    node* smallestPred = NULL;

    node* tmp = L;

    int minVal = L -> val;

    while (tmp -> next != NULL) {
        if (tmp -> next -> val < minVal) {
            smallestPred = tmp;
            minVal = smallestPred -> next -> val;
        }
        tmp = tmp -> next;
    }

    if (smallestPred == NULL) {     // head contains the smallest value
        node* selected = L;
        L = L -> next;
        return selected;
    }

    else {
        node* selected = smallestPred -> next;
        smallestPred -> next = smallestPred -> next -> next;
        return selected;
    }
}

void ssort (node*& L) {         // selection sort
    if (L == NULL or L -> next == NULL) return;

    node* sorted = NULL;
    while (L != NULL) {
        insertNode(sorted, select(L));
    }

    L = sorted;
}

node* sortList (node* L) {      // bucket sort

    int n = nodesNum(L);

    node* T[n];

    for (int i = 0; i < n; i++) T[i] = NULL;

    while (L != NULL) {
        node* tmp = L -> next;
        L -> next = T[int(0.25*n*(L->val))];
        T[int(0.25*n*(L->val))] = L;
        L = tmp;
    }

    for (int i = 0; i < n; i++) {
        ssort(T[i]);
    }

//    for (int i = 0; i < n; i++) {
//        print(T[i]);
//        cout<<endl;
//    }
    int i = 0;
    while (T[i] == NULL) i++;
    L = T[i];

    while (i < n-1) {           // connect all of the small sorted parts
        while (T[i] -> next != NULL) T[i] = T[i] -> next;
        int j = i+1;
        while (j < n and T[j] == NULL) j++;
        T[i] -> next = T[j];
        i = j;
    }

//
//    for (int i = 0; i < n; i++) {
//        print(T[i]);
//        cout<<endl;
//    }

    return L;
}

int main() {
    double A[10] = {2.7, 0.01, 3.71, 2.6, 1.33, 0.49, 0.41, 3.97, 3.09, 1.52};
    node* head = create(A, 10);
    print(head);
//    cout << nodesNum(head);
    head = sortList(head);
    cout << "Sorted list:" << endl;
    print(head);

}
