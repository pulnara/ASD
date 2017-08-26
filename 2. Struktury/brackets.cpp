#include <iostream>
#include <stack>
using namespace std;

bool isValid (char* n) {
    std::stack < int > s;   // std::stack < TYP_DANYCH > nazwa_stosu;
    for (int i = 0; n[i] != 0; i++) {
        switch (n[i]) {
            case '(':
                s.push(n[i]); break;
            case '[':
                s.push(n[i]); break;
            case '{':
                s.push(n[i]); break;
            case ')':
                if (s.empty() or s.top() != '(') return false;
                else if (s.top() == '(') s.pop();
                break;
            case ']':
                 if (s.empty() or s.top() != '[') return false;
                 else if (s.top() == '[') s.pop();
                 break;
            case '}':
                 if (s.empty() or s.top() != '{') return false;
                 else if (s.top() == '{') s.pop();
                 break;
        }
    }
    if (!s.empty()) return false;
}




int main() {

    char* test1 = "([()])";
    if (isValid(test1)) cout << "Nawiasowanie poprawne." << endl;
    else cout << "Nawiasowanie NIEPOPRAWNE." << endl;

}
