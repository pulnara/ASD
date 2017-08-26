#include <iostream>
#include <stack>
using namespace std;

struct queue {
    std::stack < int > s1;   // std::stack < TYP_DANYCH > nazwa_stosu;
    std::stack < int > s2;   // std::stack < TYP_DANYCH > nazwa_stosu;
};

void put (queue &q, int x) {
    q.s1.push(x);
}

int get (queue &q) {
    if (q.s2.empty())
        while (!q.s1.empty()) {
            q.s2.push(q.s1.top());
            q.s1.pop();
        }
    int x = q.s2.top();
    q.s2.pop();
    while (!q.s2.empty()) {
        q.s1.push(q.s2.top());
        q.s2.pop();
    }
    return x;
}

bool empty (queue q) {
    return (q.s1.empty() and q.s2.empty());
}


int main() {
     int A[9] = {-2, 11, 253, 0, 33, 15, 12, -28, 1};
     queue que;
//     for (int i = 0; i < 9; i++) put(que, A[i]);
//     cout << get(que) << endl;
//     cout << get(que) << endl;
//    for (int i = 0; i < 9; i++) {
//        cout << que.s1.top() << endl;
//        que.s1.pop();
//    }
    if (empty(que)) cout << "Kolejka jest pusta.";
    else cout << "Kolejka NIE jest pusta.";
}
