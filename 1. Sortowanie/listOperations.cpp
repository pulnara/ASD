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

void deleteNode(node*& head, int x) {
    if (head == NULL) return;
    if (head -> val == x) {
        node* deleting = head;
        head = head -> next;
        delete deleting;
    }
    else {
        node* tmp = head;
        while (tmp -> next != NULL and tmp -> next -> val < x) {
            tmp = tmp -> next;
        }
        if (tmp -> next == NULL or tmp -> next -> val != x) cout << "Provided value doesn't appear in the list" << endl;
        else {
            node* deleting = tmp -> next;
            tmp -> next = tmp -> next -> next;
            delete deleting;
        }
    }
}

void insertNum(node*& head, int x) {
    if (head == NULL) {
        head = new node;
        head -> val = x;
        head -> next = NULL;
    }

    else {
        node* tmp = head;
        node* follower = NULL;
        node* inserting = new node;
        inserting -> val = x;
        while (tmp != NULL && tmp -> val < x) {
            follower = tmp;
            tmp = tmp -> next;
        }
        if (follower == NULL ) {
            inserting -> next = tmp;
            head = inserting;
        }
        else {
            follower -> next = inserting;
            inserting -> next = tmp;
        }
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

node* reverseList(node* head) {
    if (head == NULL) return NULL;
    if (head -> next == NULL) return head;
    node* tmp = head;
    head = head -> next;
    tmp -> next = NULL;
    while (head != NULL) {
        node* helper = head -> next;
        head -> next = tmp;
        tmp = head;
        head = helper;
    }
    head = tmp;
    return head;
}


int main() {
    int A[10]={-20, -7, 3, 13, 23, 44, 64, 128, 256, 1000};
    node* head = create (A, 10);
    print(head);
    cout<<endl;
//    node* emptyList = create (A, 0);
//    node* insert23 = new node;
//    insert23 -> val = 23;
//    insertNode(emptyList, insert23);
//    print(emptyList);
//    cout<<endl;
//    insertNode(head, 21);
//    print(head);
//    cout<<endl;
    node* insert1200 = new node;
    insert1200 -> val = 1200;
    insertNode(head, insert1200);
    print(head);
//    cout<<endl;
//    insertNode(head, 2000);
//    print(head);
//    head = reverseList(head);
//    print(head);
//    deleteNode(head, 1000);
//    print(head);

}
