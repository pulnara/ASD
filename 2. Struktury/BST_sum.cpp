/* Node
{
	Node* left;
	Node* right;
	int val;
	//nie mamy wskaŸnika na rodzica
};

IN: Root
Mamy strukture drzewa binarnego i mamy obliczyæ sumê drzewa.
Nie mo¿na u¿ywaæ dodatkowej pamiêci.
*/
#include <iostream>
using namespace std;


struct BSTnode {
    int val;
    BSTnode* left;
    BSTnode* right;
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

int sum (BSTnode* head) {
    if (head -> left == NULL and head -> right == NULL) return head -> val;
    if (head -> left != NULL and head -> right != NULL) {
        return head -> val + sum(head -> left) + sum(head -> right);
    }
    if (head -> left != NULL) return head -> val + sum(head -> left);
    if (head -> right != NULL) return head -> val + sum(head -> right);
}

int main() {
    int N = 9;
    int A[N] = {12, 18, 19, 5, 9, 15, 2, 17, 13};
    BSTnode* head = create(A, N);
    cout << endl;
    cout << "Sum(head) = " << sum(head) << endl;
}
