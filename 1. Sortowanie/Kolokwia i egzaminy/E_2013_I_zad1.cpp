/*
Dana jest struktura danych
    Struct Point {
        double x, y;
    };
Opisujaca punkty w przestrzeni. Prosze zaimplementowac funkcje
    Void heapsort(Point* A, int n);
Ktora otrzymuje na wejsciu n-elementowa tablice struktur typu Point i sortuje ja w kolejnosci rosnacej wzgledem odleg³osci punktu od poczatku ukladu wspolrzednych, korzystajac z algorytmu heapsort.
*/
#include <iostream>
using namespace std;

struct Point {
    double x, y;
};

double distanceSquare(Point a) {
    return (a.x)*(a.x) + (a.y)*(a.y);
}

void print (double A[], int n) {
    for (int i = 0; i < n; i++) cout<<A[i]<<" ";
    cout<<endl;
}

void print1 (Point A[], int n) {
    for (int i = 0; i < n; i++) cout<<A[i].x << " " << A[i].y << "\tSUMA " << distanceSquare(A[i]) << endl;
    cout<<endl;
}

int Parent(int i) {
    return (i-1)/2;
}

int LSon(int i) {
    return 2*i+1;
}

int RSon(int i) {
    return 2*i+2;
}

void heapify(Point* A, int n, int i) {
    int maxKey = i;
    if (LSon(i) < n and distanceSquare(A[i]) < distanceSquare(A[LSon(i)])) maxKey = LSon(i);
    if (RSon(i) < n and distanceSquare(A[maxKey]) < distanceSquare(A[RSon(i)])) maxKey = RSon(i);
    if (maxKey != i) {
        swap (A[i], A[maxKey]);
        heapify(A, n, maxKey);
    }
}

void buildHeap(Point* A, int n) {
    for (int i = Parent(n-1); i >= 0; i--) {
        heapify(A, n, i);
    }
}

void heapsort(Point* A, int n) {
    buildHeap(A, n);
    for (int i = n-1; i > 0; i--) {
        swap(A[0], A[i]);
        heapify(A, i, 0);
    }
}

int main() {
    Point A[10] = {3.7, -5.8, -1.2, 1.7, 12.3, 0.3, -2.8, -1.4, 9.1, 5.1, 3.1, 7.2, 0.2, 20.1, 2.9, 8.1, 7.3, 0.1, -5.6, 1.4};
    double TabDist[10];
    for (int i = 0; i < 10; i++) TabDist[i] = distanceSquare(A[i]);
    print(TabDist, 10);
    heapsort(A, 10);
    print1(A, 10);

}
