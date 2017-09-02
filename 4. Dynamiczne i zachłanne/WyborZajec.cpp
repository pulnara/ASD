#include <iostream>
#include <queue>
using namespace std;

struct Activity {
    int start;
    int end;
};

int Partition (Activity A[], int p, int r) {
    int x = A[r].end;
    int j = p-1;
    for (int i = p; i < r; i++) {
        if (A[i].end <= x) {
            j++;
            swap (A[i], A[j]);
        }
    }
    swap (A[r], A[j+1]);
    return j+1;
}

void QuickSort (Activity A[], int p, int r) {
    if (p < r) {
        int q = Partition(A, p, r);
        QuickSort(A, p, q-1);
        QuickSort(A, q+1, r);
    }
}

queue <Activity> greedyActivitySelector (Activity A[], int N) {
    QuickSort(A, 0, N-1);

    queue <Activity> q;

    q.push(A[0]);
    int j = 0;
    for (int i = 1; i < N; i++) {
        if (A[i].start >= A[j].end) {
            j = i;
            q.push(A[i]);
        }
    }
    return q;
}

int main() {
    Activity A[9] = {3, 7, 2, 3, 1, 2, 3, 4, 2, 6, 7, 9, 0, 5, 8, 10, 3, 9};
    queue <Activity> q = greedyActivitySelector(A, 9);
    while (!q.empty()) {
        cout << q.front().start << " " << q.front().end << endl;
        q.pop();
    }
}
