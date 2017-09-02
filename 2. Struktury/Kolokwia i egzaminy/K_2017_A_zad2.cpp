/*
Dana jest struktura
    struct HT{
        int* table;
        int size;
    };
ktora opisuje tablice haszujaca rozmiaru size, przechowujaca liczby nieujemne.
Tablica korzysta z funkcji haszujacej int hash(int x) i liniowego rozwiazywania konfliktow (ujemne wartosci w tablicy table oznaczaja wolne pola).
Doskonaloscia takiej tablicy nazywamy liczbe elementow x takich, ze pozycja x w tablicy to hash(x) mod size (a wiec x jest na "swojej" pozycji).
Prosze napisac funkcje: void enlarge( HT* ht); ktora powieksza tablice dwukrotnie i wpisuje elementy w takiej kolejnosci, by doskonalosc powstalej
tablicy byla jak najwieksza. Funkcja powinna byc mozliwie jak najszybsza.
*/
#include <iostream>
#include <queue>
using namespace std;

struct HT{
    int* table;
    int size;
};

int hash (int x);

void enlarge(HT* ht) {
    queue <int> q;
    int j = ht -> size;
    ht -> size = 2 * ht -> size;

    for (int i = 0; i < j; i++) {
        if (hash(ht -> table[i]) % ht -> size == i) continue;   // zbedne
//        cout << "dupa";
//        if (ht -> table[i] > 0 and hash(ht -> table[i]) % ht -> size != i) {
//            q.push(ht -> table[i]);
//            ht -> table[i] = -1;
//        }
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        int h = hash(x) % ht -> size;
        while (ht -> table[h] >= 0) {
            h = h+1 % ht -> size;
        }
        ht -> table[h] = x;
    }
}

int hash(int x) {
    return x % 17;
}

int main() {
    HT* nju = new HT;
//    nju -> size = 2;
//    *nju -> table = 17;
//    nju -> table[1] = 19;
//    cout << *nju -> table;
//    enlarge(nju);
//    cout << nju -> size;
//    enlarge(nju);

}
