/*
Dana jest struktura danych opisujaca tablice haszujaca, ktora przechowuje liczby typu int indeksowane napisami.
Tablica wykorzystuje funkcje haszujaca:
    int hash (string key, int size),
ktora zwraca pozycje w tablicy, na ktorej powinny znalezc sie dane o kluczu key.
Stosowane jest liniowe rozwiazywanie kolizji. Prosze zaimplementowac funkcje:
    double averageAccess (HT* ht),
ktora oblicza jaka jest srednia ilosc pol w tablicy, ktore musi sprawdzic standardowy algorytm wyszukujacy
gdy poszukuje losowo wybranego klucza znajdujacego sie w tablicy ht.
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct HT {
    string* key;
    int* data;
    bool* free;
    int size;
};

int hash(string key, int size) {    // tak sobie randomowo napisalam, zeby nie krzyczal
    int sum = 0;
    for (int i = 0; key[i] != 0; i++) {
        sum = sum + i*7 + 11*key[i];
    }
    sum = sum % size;
    return sum;
}

HT* init (string keys[], int N) {
    srand(time(NULL));

    HT* HashArray = new HT;
    HashArray -> key = new string [N];
    HashArray -> data = new int [N];
    HashArray -> free = new bool [N];
    for (int i = 0; i < N; i++) HashArray -> free[i] = true;
    HashArray -> size = N;

    for (int i = 0; i < N; i++) {
        int h = hash(keys[i], N);

        if (HashArray -> free[h]) {
            HashArray -> key[h] = keys[i];
            HashArray -> data[h] = rand () % 1000;
            HashArray -> free[h] = false;
        }

        else {
            int k = (h+1) % HashArray -> size;
            int m = 0;
            while (m != N) {
                if (HashArray -> free[k]) {
                    HashArray -> key[k] = keys[i];
                    HashArray -> data[k] = rand () % 1000;
                    HashArray -> free[k] = false;
                    break;
                }
                m++;
                k = (k+1) % HashArray -> size;
            }
        }

    }
    return HashArray;
}

int find (HT* ht, string key) {
    int h = hash(key, ht -> size);
    int k = h;
    int i = 0;

    while (i != ht -> size) {
        if (ht -> free[k] == true) return -1;
        if (ht -> key[k] == key) return k;
        i++;
        k = (k+1) % ht -> size;
    }

    return -1;
}

bool add (HT* ht, string key, int data) {
    int h = hash(key, ht -> size);

    if (ht -> free[h]) {
        ht -> key[h] = key;
        ht -> data[h] = data;
        ht -> free[h] = false;
        return true;
    }

    int k = (h+1) % ht -> size;
    int i = 0;
    while (i != ht -> size) {
        if (ht -> free[k]) {
            ht -> free[k] = false;
            ht -> data[k] = data;
            ht -> key[h] = key;
        }
        i++;
        k = (k+1) % ht -> size;
    }
    return false;
}

int getCount(HT* ht, int random) {
    int ind = hash(ht -> key[random], ht -> size);

    if (ind == random) return 0;
    int counter = 0;
    int k = (ind+1) % ht -> size;
    while (counter != ht -> size) {
        if (k == random) return counter;
        counter++;
        k = (k+1) % ht -> size;
    }
    return -1;
}

double averageAccess (HT* ht) {
    double average;
    long int sum = 0;
    int testNum = 10e3;
    srand(time(NULL));

    for (int i = 0; i < testNum; i++) {
        int key_ind = rand() % ht -> size;

        int c = getCount(ht, key_ind);
        if (c == -1) break;
        sum += c;
    }
    average = (double)sum / testNum;
    return average;
}

////////// rozwiazanie z kierunkowego gita
//int findCount(HT * ht, string key) {
//	int h = hash(key, ht->size);
//	int i = h;
//	int count = 0;
//	for (int j = 0; j < ht->size; j++) {
//		if (ht->free[i]) break;
//		if (ht->key[i] == key)
//			return count;
//
//		count++;
//		i = (i + 1) % ht->size;
//	}
//	return -1;
//}
//double averageAccess1(HT * ht, string keys[], int n) {
//	srand(time(NULL));
//	const int testNum = 10e3;
//	double avr = 0;
//	for (int i = 0; i < testNum; i++) {
//		string rkey = keys[rand() % n];
//		int c = findCount(ht, rkey);
//		if (c == -1) break;
//		avr += c;
//	}
//	return avr/testNum;
//}


int main() {
	int n = 20;
	string keys[20] = {"Bill Gates", "Amancio Ortega", "Warren Buffett", "Carlos Slim Helu", "Jeff Bezos", "Charles Koch", "Mark Zuckerberg", "Larry Ellison", "Michael Bloomberg", "David Koch",
		"Marek Iksniwel", "Najmad Kajsunah", "Aztekwoj Chmiel", "Grzegorz Jasiiksn", "Ducdam Ianke", "Heszke Wmeszke", "Gwynbleidd", "Larry Czerwonooki", "dQw4w9WgXcQ", "SbAVowo2fXE"};
	HT* ht = init(keys, n);
	for (int i = 0; i < 20; i++) cout << ht -> key[i] << endl;

	cout.precision(17);

	cout << averageAccess(ht) << endl;
//    cout << averageAccess1(ht, keys, ht -> size) << endl;
//    cout << find(ht, "Ball Gates");

}
