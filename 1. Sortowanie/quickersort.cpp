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
    while (head != NULL) {
        cout<< head -> val << " ";
        head = head -> next;
    }
    if (head == NULL) cout << "NULL";
    cout << endl;
}

node* QuickerSort(node* L) {
    if (L == NULL) return NULL;      // empty list
    int pivot = L -> val;           // na wejsciu lista z wartownikiem
    node* smaller = NULL;
    node* equal = NULL;
    node* bigger = NULL;

    while (L != NULL) {
        node* tmp = L -> next;
        if (L -> val < pivot) {
            L -> next = smaller;
            smaller = L;
        }
        else if (L -> val == pivot) {
            L -> next = equal;
            equal = L;
        }
        else {
            L -> next = bigger;
            bigger = L;
        }
        L = tmp;
    }
    smaller = QuickerSort(smaller);
    bigger = QuickerSort(bigger);

    node* tmp = new node;
    tmp -> next == NULL;
    node* connector = tmp;

    connector -> next = smaller;
    while (connector -> next != NULL) connector = connector -> next;
    connector -> next = equal;
    while (connector -> next != NULL) connector = connector -> next;
    connector -> next = bigger;
//    print(smaller);
    tmp = tmp -> next;
    return tmp;
}

int main() {
    int A[10] = {-2, 1, 253, -28, 0, 33, 15, 12, -28, 110};
    node* L = create(A, 10);
    L = QuickerSort(L);
    print(L);
}
