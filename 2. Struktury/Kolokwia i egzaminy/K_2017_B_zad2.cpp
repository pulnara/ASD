#include <iostream>
#include <queue>
using namespace std;

struct HT {
    int size;
    int* table;
    int a;
};


int hash (int x, int a) {
    return a*x % 17;
}

void rearrange (HT* ht, int new_a) {
    int A[ht -> size];
    for (int i = 0; i < ht -> size; i++) A[i] = -1;
    queue <int> q;
    for (int i = 0; i < ht -> size; i++) {
        int x = hash(ht -> table[i], new_a) % ht -> size;
        if (A[x] == -1) A[x] = ht -> table[i];
        else q.push(ht -> table[i]);
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        int h = hash(x, new_a) % ht -> size;
        while (A[h] >= 0) {
            h = h+1 % ht -> size;
        }
        A[h] = x;
    }
    for (int i = 0; i < ht -> size; i++) ht -> table[i] = A[i];
}

int main() {

}
