#include <iostream>
#include <stack>
using namespace std;

void print (int A[], int n) {
    for (int i = 0; i < n; i++) cout<<A[i]<<" ";
    cout<<endl;
}

int Partition (int A[], int p, int r) {
    int q = p-1;
    for (int i = p; i < r; i++) {
        if (A[i] <= A[r]) {
            swap(A[i], A[q+1]);
            q++;
        }
    }
    swap(A[q+1], A[r]);
    return q+1;
}

void QuickSortBetterMemStack(int A[], int p, int r) {
     std::stack < int > s;   // std::stack < TYP_DANYCH > nazwa_stosu;

     s.push(p);
     s.push(r);

     while (!s.empty()) {
        r = s.top();
        s.pop();
        p = s.top();
        s.pop();
        if (p < r) {
            int q = Partition(A, p, r);
            if (q-p-1 < r-q-1) {
                s.push(q+1);
                s.push(r);
                s.push(p);
                s.push(q-1);

            }
            else {
                s.push(p);
                s.push(q-1);
                s.push(q+1);
                s.push(r);
            }
        }

     }
}

int main() {
    int A[9] = {-2, 11, 253, 0, 33, 15, 12, -28, 1};
    print(A, 10);
    QuickSortBetterMemStack(A, 0, 9);
    print(A, 10);
}
