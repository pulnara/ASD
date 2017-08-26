#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct SLnode {
    SLnode** next;
    int val;
    int level;
};

struct SkipList {
    SLnode* first;
    SLnode* last;
    int maxLevel;
};

int getLevel (double p) {
    srand(time(NULL));
    int lvl = 0;
    while (rand()/RAND_MAX < p) lvl++;
    return lvl;
}

SLnode* find (SkipList* S, int key) {
    SLnode* v = S -> first;
    int i;
    for (i = S -> maxLevel - 1; i >= 0; i--) {
        while (v -> next[i] -> val < key ) v = v -> next[i];
    }
    v = v -> next[0];
    if (v -> val == key) return v;
    else return NULL;
}

void insertNode (SkipList* S, int key) {
    SLnode* prev[S -> maxLevel];
    SLnode* v = S -> first;
    int i;
    for (i = S -> maxLevel - 1; i >= 0; i--) {
        while (v -> next[i] -> val < key) v = v -> next[i];
        prev[i] = v;
    }
    if (v -> next[0] -> val == key) return;

    SLnode* inserting = new SLnode;
    inserting -> val = key;

    int insertingLevel = getLevel(0.5);
    if (insertingLevel > S -> maxLevel) insertingLevel = S -> maxLevel;
    inserting -> level = insertingLevel;

    inserting -> next = new SLnode*[insertingLevel];
    for (int j = 0; j < insertingLevel; j++) {
        inserting -> next[j] = prev[j] -> next[j];
        prev[j] -> next[j] = inserting;
    }
}

void deleteNode (SkipList* S, int key) {
    SLnode* v = S -> first;
    int i;
    SLnode* deleting = NULL;
    for (i = S -> maxLevel - 1; i >= 0; i--) {
        while (v -> next[i] -> val < key) v = v -> next[i];

        if (v -> next[i] -> val == key) {
            deleting = v -> next[i];
            v -> next[i] = v -> next[i] -> next[i];
        }
    }
//    if (deleting -> val == NULL) return;
//    else
    delete deleting;
}

int main() {

}
