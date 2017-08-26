#include <iostream>
using namespace std;

enum Status {
    free, taken, keep_looking
};

struct HT {
    Key* key;
    Status* status;
    int size;
};


int hash (Key k, int size); // funkcja haszujaca

int find (HT* ht, Key k) {
    int h = hash(k, ht -> size); // indeks
    int i = 0;  // licznik, czy sprawdzilismy juz wszystkie mozliwe pola w tablicy
    while (i < ht -> size) {
        if (ht -> key[h] == k and ht -> status[h] == taken) return h; // zwraca indeks, pod ktorym jest konkretny klucz
        if (ht -> status[h] == free) return -1; // jesli nie ma go w tablicy

        i++;
        h = (h+1) % (ht -> size);
    }
    return -1; // jesli tablica pelna
}

bool insert (HT* ht, Key k, Data d) {
    int h = find(ht, k); // nie wpisujemy w pola keep_looking
    if (h != -1) return false; // w tablicy juz jest ten element

    int i = 0;  // licznik, czy sprawdzilismy juz wszystkie mozliwe pola w tablicy
    while (i < ht -> size) {
        if (ht -> status[h] != taken) {
            ht -> status[h] = taken;
            ht -> data[h] = data;
            ht -> key[h] = key;
            return true;
        }
        i++;
        h = (h+1) % (ht -> size);
    }
    return false;
}

void deleteElem (HT* ht, Key k) {
    int h = find (ht, k);
    if (h == -1) return;
    ht -> status[h] = keep_looking;
}


int main() {

}

