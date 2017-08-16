/*
 Dane sa nastepuj¹ce struktury:
        struct Node {
            Node* next;
            int val;
        };
        struct TwoLists {
            Node* even;
            Node* odd;
        };
    Napisac funkcje:
        TwoLists split(Node* list);
    Funkcja rozdziela liste na dwie: jedna zawierajac¹ liczby parzyste i druga zawierajaca liczby nieparzyste. Listy nie zawieraja wartownikow.
*/
#include <iostream>
using namespace std;

struct node {
    int val;
    node* next;
};

struct TwoLists {
    node* even;
    node* odd;
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
        cout << head -> val << " ";
        head = head -> next;
    }
    cout << endl;
}

TwoLists split(node*& L) {
    TwoLists result;
    result.even = NULL;
    result.odd = NULL;
    while (L != NULL) {
        node* tmp = L -> next;
        if (L -> val % 2 == 0) {
            L -> next = result.even;
            result.even = L;
        }
        else {
            L -> next = result.odd;
            result.odd = L;
        }
        L = tmp;
    }
    return result;
}


int main() {
    int A[10]={-20, -7, 3, 13, 23, 44, 64, 128, 256, 1000};
    node* head = create (A, 10);
    print(head);
    TwoLists separate;
    separate = split(head);
    cout << "Even: "; print(separate.even); // parzyste
    cout << "Odd: "; print(separate.odd);   // nieparzyste
    print(head);
}
