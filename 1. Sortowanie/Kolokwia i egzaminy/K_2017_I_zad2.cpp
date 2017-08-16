/*
Prosze zaimplementowac funkcje:
    int SumBetween (int T[], int from, int to, int n);
Zadaniem tej  funkcji jest obliczyc sume liczb z n-elementowej tablicy T,
ktore w posortowanej tablicy znajdywalyby sie na pozycjach o indeksach od from do to (wlacznie).
Mozna przyjac, ze liczby w tablicy T sa parami rozne (ale nie mozna przyjmowac zadnego innego rozkladu danych).
Zaimplementowana funkcja powinna byc mozliwie jak najszybsza. Prosze oszacowac jej zlozonosc czasowa (oraz bardzo krotko uzasadnic to oszacowanie).
*/

#include <iostream>
using namespace std;

void print (int A[], int n) {
    for (int i = 0; i < n; i++) cout<<A[i]<<" ";
    cout<<endl;
}

int Partition (int A[], int p, int r) {
    int x = A[r];
    int q = p - 1;
    for (int i = p; i < r; i++) {
        if (A[i] <= x) {
            q++;
            swap(A[q], A[i]);
        }
    }
    swap(A[q+1], A[r]);
    return q+1;
}

int Select (int A[], int n, int k) {
    if (n == 1) return A[0];
    int q = Partition(A, 0, n-1);
    if (q == k) return A[q];
    else if (q <= k) return Select(A+q+1, n-(q+1), k-(q+1));
    else return Select(A, q, k);
}

//int SumBetween (int T[], int from, int to, int n) {
//    int sum = Select(T, n, from);
//    for (int i = from+1; i <= to; i++) {
//        sum += Select(T+i, n-i, 0);
////        print(T, n);
////        cout<< sum << endl;
//    }
//    return sum;
//}

int SumBetween (int T[], int from, int to, int n) {
    int sum = Select(T, n, from) + Select(T+from+1, n-(from+1), to-(from+1));
    for (int i = from+1; i < to; i++) sum+= T[i];
    return sum;
}

int main() {
    int A[10] = {-2, 11, 253, -28, 0, 33, 15, 12, -28, 1};
    print(A, 10);
    cout << "Suma od 3 do 7: " << SumBetween(A, 3, 7, 10) << endl;
//    print(A, 10);
}

/* Zlozonosc: O(2*n)=O(n), bo 2 wywolania Selecta, ktory ma zlozonosc O(n). */

