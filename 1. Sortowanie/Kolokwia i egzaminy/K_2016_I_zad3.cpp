/*
Dana jest struktura Node opisujaca liste jednokierunkowa:
    struct Node {
        Node * next;
        int value;
    };
Prosze zaimplementowac funkcje Node* fixSortedList( Node* L ), ktora otrzymuje na wejsciu liste jednokierunkow¹ bez wartowanika.
Lista ta jest prawie posortowana w tym sensie, ¿e powstala z listy posortowanej przez zmianê jednego losowo wybranego elementu na losowa wartosc.
Funkcja powinna przepiac elementy listy tak, by lista stala sie posortowana i zwrocic wskaznik do g³owy tej listy.
Mozna zalozyc, ze wszystkie liczby na liscie sa rozne i ze lista ma co najmniej dwa elementy. Funkcja powinna dzialac w czasie liniowym wzgledem dlugosci listy wejsciowej.
*/
#include <iostream>
using namespace std;

struct node {
    int val;
    node* next;
};

node* create(int A[], int n) {
    if (n == 0) return NULL;

    node* first = new node;
    first -> val = A[0];

    node* tmp = first;

    for (int i = 1; i < n; i++) {
        tmp -> next = new node;
        tmp -> next -> val = A[i];
        tmp = tmp -> next;
    }
    tmp -> next = NULL;

    return first;
}

void print(node* head) {
    if (head == NULL) return;
    while (head != NULL) {
        cout<< head -> val << " ";
        head = head -> next;
    }
    cout << endl;
}

void insertNode (node*& head, node* n) {
    if (head == NULL) {
        head = n;
        n -> next = NULL;
    }
    else if (n -> val < head -> val) {
        n -> next = head;
        head = n;
    }
    else {
        node* tmp = head;
        while (tmp -> next != NULL and tmp -> next -> val < n -> val) tmp = tmp -> next;
        n -> next = tmp -> next;
        tmp -> next = n;
    }
}

node* findBad (node*& head) {
    if (head == NULL or head -> next == NULL) return NULL;
    node* bad = NULL;
    if (head -> next -> val < head -> val) {
        bad = head;
        head = head -> next;
        return bad;
    }
    node* tmp = head;
    while (tmp -> next -> next -> next != NULL and tmp -> next -> val < tmp -> next -> next -> val) tmp = tmp -> next; // ustaw wskaznik na 1 lub 2 miejsca przed szukanym node'm

    if (tmp -> next -> next -> next == NULL) {
        if (tmp -> next -> val > tmp -> next -> next -> val) {
            bad = tmp -> next -> next;
            tmp -> next -> next = NULL;
            return bad;
        }
        else return NULL;
    }

    if (tmp -> next -> val < tmp -> next -> next -> next -> val) {  // zamieniono na mniejsza wartosc
        bad = tmp -> next -> next;
        tmp -> next -> next = tmp -> next -> next -> next;
    }
    else {                          // zamieniono na wieksza wartosc
        bad = tmp -> next;
        tmp -> next = tmp -> next -> next;
    }
    return bad;

}

node* fixSortedList(node* L) {
    node* q = findBad(L);
//    cout << q -> val << endl;
    if (q != NULL) insertNode(L, q);
    return L;
}


int main() {
    int A[10]={-28, -28, -2, 0, 1, 11, 12, 15, 30, 256};
    node* L = create(A, 10);
    print(L);
    L = fixSortedList(L);
    print(L);

}
