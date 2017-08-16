/*
2. Dany jest typ:
    struct List {
        List* next;
        int val;
    };
    realizujacy liste jednokierunkowa. Prosze zaimplementowac funkcje List* reverse(List * L), ktora odwraca kierunek listy L
    i zwraca wskaznik na jej glowe.
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
}

node* reverse(node* L) {
    if (L == NULL or L -> next == NULL) return L;
    node* reversed = L;
    node* tmp = L -> next;
    reversed -> next = NULL;
    while (tmp != NULL) {
        node* helper = tmp;
        tmp = tmp -> next;
        helper -> next = reversed;
        reversed = helper;
    }
    return reversed;
}



int main() {
    int A[10]={-20, -7, 3, 13, 23, 44, 64, 128, 256, 1000};
    node* head = create (A, 10);
    print(head);
    cout<<endl;
    head = reverse(head);
    print(head);
}
