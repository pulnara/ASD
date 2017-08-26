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

void recInsert (BSTnode*& F, BSTnode* inserted) {
    if (F -> left != NULL and inserted -> val < F -> val) recInsert(F -> left, inserted);
    else if (F -> right != NULL and inserted -> val >= F -> val) recInsert(F -> right, inserted);
    else if (F -> right == NULL or F -> left == NULL) {
        inserted -> parent = F;
        if (inserted -> val < F -> val) {
            F -> left = inserted;
        }
        else F -> right = inserted;
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

void inOrder (BSTnode* F) {
    if (F != NULL) {
        inOrder(F -> left);
        cout << F -> val << " ";
        inOrder(F -> right);
    }
}

BSTnode* searchRec (BSTnode* head, int v) {
    if (head -> val == v) return head;
    if (v < head -> val and head -> left != NULL) return searchRec(head -> left, v);
    else if (v >= head -> val and head -> right != NULL) return searchRec(head -> right, v);
    return NULL;
}

BSTnode* search (BSTnode* head, int v) {
    if (head -> val == v) return head;
    while (head != NULL and head -> val != v) {
        if (v < head -> val) head = head -> left;
        else head = head -> right;
    }
    return head;
}

BSTnode* minimum (BSTnode* head) {
    while (head -> left != NULL) head = head -> left;
    return head;
}

BSTnode* maximum (BSTnode* head) {
    while (head -> right != NULL) head = head -> right;
    return head;
}

BSTnode* minimumRec (BSTnode* head) {
    if (head -> left != NULL) return minimumRec(head -> left);
    return head;
}

BSTnode* maximumRec (BSTnode* head) {
    if (head -> right != NULL) return maximumRec(head -> right);
    return head;
}

BSTnode* succesor (BSTnode* head, BSTnode* ourNode) {
    if (ourNode == maximum(head)) {                     // obsluga wyjatku gdy wywolujemy succesor dla maxa
        cout << "Nie ma sukcesora dla tej wartosci." << endl;
        return NULL;
    }
    if (ourNode -> right != NULL) return minimum(ourNode -> right);
    else {
        BSTnode* ourPar = ourNode -> parent;
        while (ourPar != NULL and ourPar -> left != ourNode) {
            ourNode = ourPar;
            ourPar = ourNode -> parent;
        }
        return ourPar;
    }
}

BSTnode* predecessor (BSTnode* ourNode) {
    if (ourNode -> left != NULL) return maximum(ourNode -> left);
    else {
        BSTnode* ourPar = ourNode -> parent;
        while (ourPar != NULL and ourPar -> right != ourNode) {
            ourNode = ourPar;
            ourPar = ourNode -> parent;
        }
        return ourPar;
    }
}

void Transplant (BSTnode* u, BSTnode* v) {
    if (u -> parent == NULL) {
        u = v;
    }
    else if (u == u -> parent -> left) {
        u -> parent -> left = v;
    }
    else u -> parent -> right = v;
    if (v != NULL) v -> parent = u -> parent;
}

void deleteNode (BSTnode* head, BSTnode* ourNode) {
    if (ourNode -> left == NULL) Transplant(ourNode, ourNode -> right);
    else if (ourNode -> right == NULL) Transplant(ourNode, ourNode -> left);
    else {
        BSTnode* y = minimum(ourNode -> right);
        if (y -> parent != ourNode) {
            Transplant(y, y -> right);
            y -> right = ourNode -> right;
            y -> right -> parent = y;
        }
        Transplant(ourNode, y);
        y -> left = ourNode -> left;
        y -> left -> parent = y;
    }
    delete ourNode;
}

int main() {
    int N = 6;
    int A[N] = {6, 7, 5, 8, 2, 5};
    BSTnode* head = create(A, N);
    inOrder(head);
    cout << endl;
//    BSTnode* flag = searchRec(head, 1);
//    (flag == NULL) ? cout << "W drzewie nie wystepuje podana wartosc. " << endl : cout << "Wystepuje!!!" << endl;
//    BSTnode* flag1 = search(head, 1);
//    (flag1 == NULL) ? cout << "W drzewie nie wystepuje podana wartosc. " : cout << "Wystepuje!!!";
//    cout << "Minimum: " << minimumRec(head) -> val << endl;
//    cout << "Maksimum: " << maximumRec(head) -> val;
//    cout << "Succ(5) = " << succesor(head, search(head, 5)) -> val;
//    cout << "Pred(8) = " << predecessor(search(head, 8)) -> val;
//    deleteNode(head, search(head, 5));
    BSTnode* helper = new BSTnode;
    helper -> left = helper -> right = NULL;
    helper -> val = 1;
    recInsert(head, helper);
    inOrder(head);
}
