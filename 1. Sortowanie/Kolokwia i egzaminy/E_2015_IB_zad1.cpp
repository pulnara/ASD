/*
Prosze zaimplementowac funkcje usuwajaca z listy wszystkie elementy
o podanej wartosci x. Lista (bez wartownika) jest opisana przez struktury typu
    struct node {
        node* next;
        int value;
    };
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

node* deleteAll(node* L, int x) {
    while (L -> val == x) {
        node* tmp = L;
        L = L -> next;
        delete tmp;
    }
    node* flyer = L;
    while (flyer -> next != NULL) {
        if (flyer -> next -> val == x) {
            node* tmp = flyer -> next;
            flyer -> next = flyer -> next -> next;
            delete tmp;
            continue;
        }
        flyer = flyer -> next;
    }
    return L;
}

int main() {
    int N = 20;
    int A[N]={5, 3, -20, -7, 3, 3, 3, 13, 18, 22, 23, 3, 44, 64, 3, 128, 256, 1000, 3, 12};
    node* head = create (A, N);
    print(head);
    head = deleteAll(head, 3);
    print(head);
}
