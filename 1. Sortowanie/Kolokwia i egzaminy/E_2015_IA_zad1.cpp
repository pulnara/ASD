/*
Prosze zaimplementowac funkcje scalajaca swie posortowane listy (obie bez wartownika).
Listy sa opisane przez struktury typu
    struct node {
        node* next;
        int val;
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
    if (head == NULL) cout << "NULL";
    while (head != NULL) {
        cout<< head -> val << " ";
        head = head -> next;
    }
    cout << endl;
}

node* mergeLists (node*& A, node*& B) {
    node * merged;
    if (A -> val < B -> val) {
        merged = A;
        A = A -> next;
    }
    else {
        merged = B;
        B = B -> next;
    }

    node* tmp = merged;

    while (A != NULL and B != NULL) {
        if (A -> val < B -> val) {
            tmp -> next = A;
            A = A -> next;
        }
        else {
            tmp -> next = B;
            B = B -> next;
        }
        tmp = tmp -> next;
    }

    while (A != NULL) {
        tmp -> next = A;
        A = A -> next;
        tmp = tmp -> next;
    }

    while (B != NULL) {
        tmp -> next = B;
        B = B -> next;
        tmp = tmp -> next;
    }

    tmp -> next = NULL;
    return merged;
}

int main() {
    int N = 10;
    int A[N]={-30, -10, 1, 3, 5, 7, 9, 11, 13, 17};
    int B[N+3]={-45, -2, 4, 5, 8, 16, 18, 22, 23, 24, 37, 50, 51};
    node* AL = create (A, N);
    node* BL = create (B, N+3);
    print(AL);
    print(BL);
    cout << endl;
    node* merged = mergeLists(AL, BL);
    print(merged);
    print(AL);
    print(BL);

}
