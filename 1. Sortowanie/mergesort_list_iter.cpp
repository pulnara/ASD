#include <iostream>
#include <stack>
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
    h1 = h2 = new node;
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

void mergeSortStack (node*& head) {
    std::stack < node* > s1, s2, *s_from, *s_to;

//    node* h1, *h2;
//    split(head, h1, h2);
//    s2.push(h2);
//    s2.push(h1);

//    while (s2.top() != NULL and s2.top() -> next != NULL) {
//        while (!s2.empty()) {
//            node* helper = s2.top();
//            s2.pop();
//            split(helper, h1, h2);
//            s1.push(h2);
//            s1.push(h1);
//        }
//        while (!s1.empty()) {
//            node* helper = s1.top();
//            s1.pop();
//            split(helper, h1, h2);
//            s2.push(h2);
//            s2.push(h1);
//        }
//    }
    while (head != NULL) {
        node* tmp = head -> next;
        head -> next = NULL;
        s1.push(head);
        head = tmp;
    }

//    cout << "dupa" << endl;
    while (s1.size() != 1 and s2.size() != 1) {
        while (s1.size() > 1) {
            node* helper = s1.top();
            s1.pop();
            node* helper1 = s1.top();
            s1.pop();
            s2.push(merge(helper, helper1));
        }
        if (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        while (s2.size() > 1) {
//            cout << "haha" << endl;
            node* helper = s2.top();
            s2.pop();
            node* helper1 = s2.top();
            s2.pop();
            s1.push(merge(helper, helper1));
        }
        if (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
//        cout << "supa1" << endl;

    }
    if (s1.size() == 1) head = s1.top();
    else head = s2.top();

//    if (head != NULL and head -> next != NULL) {
//        split(head, h1, h2);
//        mergeSort(h1);
//        mergeSort(h2);
//        head = merge(h1, h2);
//    }
}

int main() {
    int A[10] = {-2, 1, 253, -28, 0, 33, 15, 12, -28, 110};
    node* L = create(A, 10);
    mergeSortStack(L);
    print(L);
}
