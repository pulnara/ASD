#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* parent;
    int rank;   // drzewo, dla ktorego rank == k, ma:
                // - wysokosc co najwyzej k
                // - co najmniej 2^k elementow
};

Node* MakeSet (int v) {
    Node* node = new Node;
    node -> parent = node;
    node -> val = v;
    node -> rank = 0;
    return node;
}

Node* FindSet (Node* n) {
    if (n -> parent != n) {
        n -> parent = FindSet(n -> parent);
    }
    return n -> parent;
}

void Union (Node* x, Node* y) {
    x = FindSet(x);
    y = FindSet(y);
    if (x == y) return;

    if (x -> rank < y -> rank) x -> parent = y;
    else {
        y -> parent = x;
        if (x -> rank == y -> rank) x -> rank ++;
    }
}


int main() {

}
