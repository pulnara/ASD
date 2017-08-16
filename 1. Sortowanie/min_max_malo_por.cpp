#include <iostream>
using namespace std;

void minMax(int A[], int n, int& Max, int& Min) {
    Max = A[0];
    Min = A[0];
    int tmpMin, tmpMax;
    for (int i = 1; i+1 < n; i += 2) {
        if (A[i] < A[i+1]) {
            tmpMin = A[i];
            tmpMax = A[i+1];
        }
        else {
            tmpMin = A[i+1];
            tmpMax = A[i];
        }
        if (tmpMin < Min) Min = tmpMin;
        if (tmpMax > Max) Max = tmpMax;
    }
    if (n%2 == 0) {
        if (A[n-1] < Min) Min = A[n-1];
        if (A[n-1] > Max) Max = A[n-1];
    }
}

int main() {
    int A[10] = {-2, 1, 253, -28, 0, 33, 15, 12, -328, -1180};
    int Max, Min;
    minMax(A, 10, Max, Min);
    cout<<"Min value: "<<Min<<endl;
    cout<<"Max value: "<<Max;
}
