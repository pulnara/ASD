#include <iostream>
using namespace std;

struct BSTNode {
    int val;
    BSTNode* up;
    BSTNode* left, * right;
};

void insertNode(BSTNode*& head, BSTNode* x) {
    BSTNode* follower = NULL;
    BSTNode* flyer = head;
    while (flyer != NULL) {
        follower = flyer;
        if (flyer -> val > x -> val) flyer = flyer -> left;
        else flyer = flyer -> right;
    }
    x -> up = follower;
    if (follower == NULL) head = x;
    else if (x -> val < follower -> val) follower -> left = x;
    else follower -> right = x;
    x -> left = x -> right = NULL;
}

BSTNode* create (int A[], int N) {
    BSTNode* head = NULL;
    for (int i = 0; i < N; i++) {
        BSTNode* node = new BSTNode;
        node -> val = A[i];
        insertNode(head, node);
    }
    return head;
}

int n;

void BSTintoTab (int T[], BSTNode* head) {
    if (head != NULL) {
        BSTintoTab(T, head -> left);
        T[n] = head -> val;
        n++;
        BSTintoTab(T, head -> right);
    }
}

int Merge(int T1[], int T2[], int T3[], int s1, int s2) {
    int size = 0;

    int i = 0, j = 0;
    while (i < s1 and j < s2) {
        if (T1[i] < T2[j]) {
//            cout << T1[i] << " ";
            T3[size] = T1[i];
            size++;
            i++;
        }
        else if (T2[j] < T1[i]) {
//            cout << T2[j] << " ";
            T3[size] = T2[j];
            j++;
            size++;
        }
        else {
            i++;
            j++;
        }
    }
    while (i < s1) T3[size++] = T1[i++];
    while (j < s2) T3[size++] = T2[j++];

    return size;
}

void Build (int Tab[], BSTNode*& head, int p, int r) {
    if (p <= r) {
        int q = (p+r)/2;
//        cout << q << " ";
        BSTNode* node = new BSTNode;
        node -> val = Tab[q];
        insertNode(head, node);
        Build(Tab, head, p, q-1);
        Build(Tab, head, q+1, r);
    }
}

BSTNode* newTree (BSTNode* A, BSTNode* B, int N) {
    int T1[N], T2[N+3];
    n = 0;
    BSTintoTab(T1, A);

    n = 0;
    BSTintoTab(T2, B);
    int T3[2*N+3];
    int size = Merge(T1, T2, T3, N, N+3);
//    for (int i = 0; i < size; i++) cout << T3[i] << " ";
    BSTNode* third = NULL;
    Build(T3, third, 0, size);
//    cout << endl;
    return third;
}

void inOrder (BSTNode* F) {
    if (F != NULL) {
        inOrder(F -> left);
        cout << F -> val << " ";
        inOrder(F -> right);
    }
}

int main() {
    int N = 6;
    int A[N] = {6, 7, 5, 8, 2, 5};
    BSTNode* head1 = create(A, N);

    int B[N+3] = {2, 12, 3, 3, 8, 4, 7, 6, 1};
    BSTNode* head2 = create(B, N+3);

    BSTNode* result = newTree(head1, head2, N);
    inOrder(result);
}
