#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void print (int A[], int n) {
    for (int i = 0; i < n; i++) cout<<A[i]<<" ";
    cout<<endl;
}

int Partition (int A[], int p, int r) {
    int k = A[r];
    int q = -1;

    for (int i = p; i < r; i++) {
        if (A[i] < k) {
            swap(A[q+1], A[i]);
            q++;
        }
    }
    swap(A[q+1], A[r]);
    return q+1;
}

int randPartition (int A[], int p, int r) {
    srand(time(NULL));
    int i = p + rand()%(r+1);
    swap (A[i], A[r]);
    return Partition(A, p, r);
}

int Select (int A[], int n, int k) {
    if (n == 1) return A[0];
    int q = randPartition(A, 0, n-1);
    if (q == k) return A[q];
    else if (q <= k) {
        return Select(A+q+1, n-(q+1), k-(q+1));
    }
    else return Select(A, q, k);
}


int main() {
    int A[10] = {-2, 11, 253, -28, 0, 33, 15, 12, -28, 1};
    int ind;
    cout << "Choose an index between 0 and 9" <<  endl;
    cin >> ind;
    cout << "At this index there's: " << Select(A, 10, ind);

}
