#include <iostream>
using namespace std;

struct BSTnode {
    int val;
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

int isAVL (BSTnode* head) {
    if (head == NULL) return 0;
    int right = isAVL(head -> right);
    int left = isAVL(head -> left);

    if (right == -1) return -1;
    if (left == -1) return -1;

    int diff = right - left;
    if (diff >= -1 and diff <= 1) return max (left, right) + 1;

    return -1;
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
    return first;
}

int main() {
    int N = 8;
    int A[N] = {6, 7, 5, 8, 2, 5, 1, 0};
    BSTnode* head = create(A, N);
    cout << isAVL(head) << endl;
    if (isAVL(head) != -1) cout << "Drzewo JEST drzewem AVL." << endl;
    else cout << "NIE JEST drzewem AVL." << endl;
}
