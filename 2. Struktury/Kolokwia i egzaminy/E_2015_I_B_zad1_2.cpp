/* Drzewo BST jest opisane przez strukture:
    struct BSTnode {
    int val;
    BSTnode* left;
    BSTnode* right;
};
Zaimplementuj funkcje double average (BSTnode* T) obliczajaca srednia wartosc elementow w drzewie T.
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

int Sum (BSTnode* T) {
    if (T != NULL) {
        return T -> val + Sum(T -> left) + Sum(T -> right);
    }
    else
        return 0;
}

//int Sum2 (BSTnode* T) {
//    if (T == NULL) return 0;
//    return T -> val + Sum(T -> left) + Sum(T -> right);
//}

int howMany (BSTnode* T) {
    if (T == NULL) return 0;
    return 1 + howMany(T -> left) + howMany(T -> right);
}

double average (BSTnode* T) {
    return (double)(Sum(T)/howMany(T));
}

// 2. sposob:

int helper(BSTnode* T, int& x) {
    if (T == NULL) return 0;
    x++;
    return T -> val + helper(T -> left, x) + helper(T -> right, x);
}

double average1 (BSTnode* T) {
    int howMany = 0;
    return (double)helper(T, howMany)/howMany;
}

int main() {
    int N = 6;
    int A[N] = {6, 7, 5, 8, 2, 5};
    BSTnode* head1 = create(A, N);
//    cout << "Sum = " << Sum(head1);
//    cout << "How many = " << howMany(head1);
    cout << average1(head1);
}
