/* Drzewo BST jest opisane przez strukture:
    struct BSTnode {
    int val;
    BSTnode* left;
    BSTnode* right;
};
Zaimplementuj funkcje int countInterval (BSTnode* T, int a, int b) obliczajaca
ile liczb z zadanego przedzialu domknietego [a, b] znajduje sie w drzewie T.
*/
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

int countInterval (BSTnode* T, int a, int b) {
    if (T != NULL) {
        if (T -> val < a) return countInterval(T -> right, a, b);
        if (T -> val > b) return countInterval(T -> left, a, b);
        if (T -> val <= b and T -> val >= a) return 1 + countInterval(T -> left, a, b) + countInterval(T -> right, a, b);
    }
}

int main() {
    int N = 6;
    int A[N] = {6, 7, 5, 8, 2, 5};
    BSTnode* head = create(A, N);
    cout << countInterval(head, 10, 100);
}
