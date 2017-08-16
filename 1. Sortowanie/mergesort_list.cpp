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

node* merge (node*& a, node*& b) {
    node* tmp = new node;
    node* connecting = tmp;
    while (a != NULL and b != NULL) {
        if (a -> val < b -> val) {
            connecting -> next = a;
            a = a -> next;
        }
        else {
            connecting -> next = b;
            b = b -> next;
        }
        connecting = connecting -> next;
    }
    while (a != NULL) {
        connecting -> next = a;
        a = a -> next;
        connecting = connecting -> next;
    }
    while (b != NULL) {
        connecting -> next = b;
        b = b -> next;
        connecting = connecting -> next;
    }
    connecting -> next = NULL;
    node* deleting = tmp;
    tmp = tmp -> next;
    delete deleting;
    return tmp;
}

void split(node*& head, node*& h1, node*& h2) {
    bool flipflop = false;
    node* h1_f = h1;
    node* h2_f = h2;
    while (head != NULL) {
        if (flipflop) {
            h1_f -> next = head;
            h1_f = h1_f -> next;
        }
        else {
            h2_f -> next = head;
            h2_f = h2_f -> next;
        }
        head = head -> next;
        flipflop = !flipflop;
    }
    h1_f -> next = NULL;
    h2_f -> next = NULL;
    node* deleting = h1;
    h1 = h1 -> next;
    delete deleting;
    deleting = h2;
    h2 = h2 -> next;
    delete deleting;
}

void mergeSort (node*& head) {
    node* h1 = new node;
    node* h2 = new node;

    if (head != NULL and head -> next != NULL) {
        split(head, h1, h2);
        mergeSort(h1);
        mergeSort(h2);
        head = merge(h1, h2);
    }
}

int main() {
    int A[10] = {-2, 1, 253, -28, 0, 33, 15, 12, -28, 110};
    node* L = create(A, 10);
    mergeSort(L);
    print(L);
//    int N = 10;
//    int A[N]={-30, -10, 1, 3, 5, 7, 9, 11, 13, 17};
//    int B[N+3]={-45, -2, 4, 5, 8, 16, 18, 22, 23, 24, 37, 50, 51};
//    node* AL = create (A, N);
//    node* BL = create (B, N+3);
//    print(AL);
//    print(BL);
//    cout << endl;
//    node* merged = merge(AL, BL);
//    cout << "Merged list: " << endl;
//    print(merged);
//    print(AL);
//    print(BL);
//    node* h1 = new node;
//    node *h2 = new node;
//    split(merged, h1, h2);
//    print(h1);
//    print(h2);
}
