/*
Prosze zaimplementowac funkcje void SumSort(int A[], int B[], int n). Funkcja ta przyjmuje na wejsciu dwie n^2-elementowe tablice (A i B) i zapisuje w tablicy B taka permutacje elementow z A, ze:
    Suma B[i] od 0 do n-1 <= Suma B[i] od n do 2n-1 <= ... <= Suma B[i] od n^2 - n do n^2 - 1
Prosze zaimplementowac funkcje SumSort tak, by dzialala mozliwie jak najszybciej. Prosze oszacowac i podac jej z³o¿onosc czasowa.
*/

#include <iostream>
using namespace std;

void print (int A[], int n) {
    for (int i = 0; i < n; i++) cout<<A[i]<<" ";
    cout<<endl;
}

struct Block {
    int Sum;
    int index;
};

void Sum(int A[], int n) {
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) sum+=A[i*n + j];
        cout << sum << " ";
    }
}

int Partition (Block A[], int p, int r) {
    int q = p - 1;
    for (int i = p; i < r; i++) {
        if (A[i].Sum <=  A[r].Sum) {
            q++;
            swap(A[q], A[i]);
        }
    }
    swap(A[q+1], A[r]);
    return q+1;
}

void QuickSort (Block A[], int p, int r) {
    if (p < r) {
        int q = Partition(A, p, r);
        QuickSort(A, p, q-1);
        QuickSort(A, q+1, r);
    }
}

void SumSort(int A[], int B[], int n) {
    Block T[n];
    for (int i = 0; i < n; i++) T[i].Sum = 0;
//    cout << "gggggggggggggggg";
    for (int i = 0; i < n; i++) {
        T[i].index = i*n;

        for (int j = 0; j < n; j++) {
            T[i].Sum += A[i*n + j];
//            if (i == 2) cout<< "fajno";
        }

    }
//    cout << "sffffffff";
    QuickSort(T, 0, n-1);
//    cout<< "dddddddddd";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            B[i*n + j] = A[T[i].index + j];
    }
}

int main() {
    int A[9] = {-2, 11, 253, 0, 33, 15, 12, -28, 1};
    print(A, 9);
    int B[9];
    for (int i = 0; i < 9; i++) B[i] = 0;
    SumSort(A, B, 3);
    print(B, 9);
    Sum(A, 3);
}
