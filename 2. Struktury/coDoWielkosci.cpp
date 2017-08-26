#include <iostream>
using namespace std;

struct BSTnode {
    int val;
    int subtree_Size;
    BSTnode* left;
    BSTnode* right;
    BSTnode* parent;
};

void insertNode(BSTnode*& F, BSTnode* inserted) {
    BSTnode* follower = NULL;
    BSTnode* flyer = F;
    while (flyer != NULL) {
        follower = flyer;
        if (inserted -> val < flyer -> val)
            flyer = flyer -> left;
        else flyer = flyer -> right;
    }
    inserted -> parent = follower;
    if (follower == NULL) { // insert to an empty tree
        F = inserted;
    }
    else if (inserted -> val < follower -> val) {
        follower -> left = inserted;
    }
    else {
        follower -> right = inserted;
    }
}

int subtreeSize (BSTnode* head) {
    if (head == NULL) return 0;
    return 1 + subtreeSize(head -> left) + subtreeSize(head -> right);
}

void sizes (BSTnode* F) {
    if (F != NULL) {
        sizes(F -> left);
        F -> subtree_Size = subtreeSize(F);
        sizes(F -> right);
    }
}

BSTnode* create(int T[], int n) {
    BSTnode* first = NULL;
    for (int i = 0; i < n; i++) {
        BSTnode* insert = new BSTnode;
        insert -> val = T[i];
        insert -> left = NULL;
        insert -> right = NULL;
        insertNode(first, insert);
    }
    sizes(first);
    return first;
}

void inOrder (BSTnode* F) {
    if (F != NULL) {
        inOrder(F -> left);
        cout << F -> subtree_Size << " ";
        inOrder(F -> right);
    }
}

BSTnode* search (BSTnode* head, int v) {
    if (head -> val == v) return head;
    while (head != NULL and head -> val != v) {
        if (v < head -> val) head = head -> left;
        else head = head -> right;
    }
    return head;
}

int find (BSTnode* head, int i) { // znajduje i-ty co do wielkosci wezel
    int leftSize = 0;
    if (head -> left != NULL) leftSize = head -> left -> subtree_Size;
    if (leftSize + 1 == i) return head -> val;
    else if (leftSize + 1 < i) return find(head -> right, i - leftSize - 1);
    else return find(head -> left, i);
}

int which (BSTnode* n) { // ktorym wezlem co do wielkosci jest n?
    int s = 1;
    if (n -> left != NULL) s += n -> left -> subtree_Size;
    while (n -> parent != NULL) {
        if (n == n -> parent -> right) {
            if (n -> parent -> left != NULL) s = s + n-> parent -> left -> subtree_Size + 1;
            else s += 1;
        }
        n = n -> parent;
    }
    return s;
}


int main() {
    int N = 6;
    int A[N] = {6, 7, 4, 5, 2, 8};
    BSTnode* head = create(A, N);
//    cout << subtreeSize(search(head, 2));
//    inOrder(head);
    cout << which(search(head, 8));
}

