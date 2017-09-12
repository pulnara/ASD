#include <iostream>
using namespace std;
// f(i) = min(P[k] + f(k)), k < i if R[k] + k >= i
// f(0) = 0
// f(1) = P[0]


int wayHome (int P[], int R[], int n) {
    int Tab[n];
    Tab[0] = 0;
    Tab[1] = P[0];
    for (int i = 2; i < n; i++) {
        int min = INT_MAX;
        for (int j = 0; j < i; j++) {
            if (R[j] + j >= i and P[j] + Tab[j] < min) {
                min = P[j] + Tab[j];
            }
        }
        Tab[i] = min;
    }

    return Tab[n-1];
}


int main() {

}
