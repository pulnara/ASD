// selection sort on an integer list
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

void insertNode(node*& head, node* n) {
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

node* findAndPickMin(node*& head) {
    node* minPred = NULL;

    int minVal = head -> val;

    node* tmp = head;

    while (tmp -> next != NULL) {
        if (tmp -> next -> val < minVal) {
            minPred = tmp;
            minVal = tmp -> next -> val;
            //cout<<minVal<<" ";
        }
        tmp = tmp -> next;
    }

    if (minPred == NULL) {
        node* help = head;
        head = head -> next;
        return help;
    }

    node* help = minPred -> next;
    minPred -> next = minPred -> next -> next;
    return help;
}

void ssort_list(node*& head) {

    if (head == NULL or head -> next == NULL) return;

    node* sorted = NULL;

    while (head != NULL) {
        insertNode(sorted, findAndPickMin(head));
    }
    head = sorted;
}

int main() {
    int A[10] = {-2, 1, 253, -28, 33, 0, 15, 12, -28, 110};
    node* head = create(A, 10);
    print(head);
    cout<<endl;
    ssort_list(head);
    print(head);
}
