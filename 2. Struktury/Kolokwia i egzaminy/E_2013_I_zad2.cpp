/* Prosze zaimplementowac algorytm, ktory majac na wejsciu dwa drzewa BST (przechowujace liczby typu int; prosze zadeklarowac odpowiednie struktury danych)
zwraca nowe drzewo BST, zawierajace wylacznie te liczby, ktore wystepuja w obu drzewach.
Algorytm powinien byc jak najszybszy i wykorzystywac jak najmniej pamieci.
Jaka jest zlozonosc zaproponowanego algorytmu?
Co mozna powiedziec o zrownowazeniu drzew tworzonych przez zaproponowany algorytm?
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
    inserted -> left = inserted -> right = NULL;
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

int ind, N = 6;

void inOrderTab (BSTnode* T, int A[]) {
    if (T != NULL) {
        inOrderTab(T -> left, A);
        A[ind++] = T -> val;
        inOrderTab(T -> right, A);
    }
}

int Merge (int A[], int B[], int C[], int n1, int n2) {
    int i = 0, j = 0, k = 0;
    while (i < n1 and j < n2) {
        if (A[i] < B[j]) i++;
        else if (B[j] < A[i]) j++;
        else {
            C[k++] = B[j];
            j++;
            i++;
        }
    }
    return k;
}

void Build(int C[], int p, int k, BSTnode*& F) { // tworzymy drzewo zrownowazone
    if(p < k) {
        int r = (p+k)/2;
        BSTnode* NEW = new BSTnode;
        NEW -> val = C[r];
        insertNode(F, NEW);
        Build(C, p, r-1, F);
        Build(C, r+1, k, F);
    }
}

BSTnode* newTree (BSTnode* h1, BSTnode* h2) {
    int A[N];
    int B[N+3];

    ind = 0;
    inOrderTab(h1, A);
    ind = 0;
    inOrderTab(h2, B);

    int C[N];
    int size = Merge(A, B, C, N, N+3);
    BSTnode* Third = NULL;
    Build(C, 0, size, Third);
    return Third;
}

int main() {
    int A[N] = {6, 7, 5, 8, 2, 5};
    BSTnode* head1 = create(A, N);
    inOrder(head1);
    cout << endl;
    int B[N+3] = {2, 12, 3, 3, 8, 4, 7, 6, 1};
    BSTnode* head2 = create(B, N+3);
    inOrder(head2);
    cout << endl;
//////    int G[] = {2, 2, 3, 4, 16, 17, 21, 37, 41, 44, 53, 53, 127};
//////    int sizeG = sizeof(G)/sizeof(int);
//////    int H[] = {1, 4, 7, 12, 22, 37, 45, 53, 129, 212};
//////    int sizeH = sizeof(H)/sizeof(int);
//////    int I[min(sizeG, sizeH)];
//////    int k = Merge(G, H, I, sizeG, sizeH);
//////    for (int i = 0; i < k; i++) cout << I[i] << " ";
//
//    int C[N] = {};
////    inOrderTab(head1, C);
////    for (int i = 0; i < N; i++) cout << C[i] << " ";
    BSTnode* newTreeHurra = newTree(head1, head2);
    inOrder(newTreeHurra);
}
