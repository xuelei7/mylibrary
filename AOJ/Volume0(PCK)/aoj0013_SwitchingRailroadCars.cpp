// Switching Railroad Cars

// For each 0, print the car number.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    stack<int> stk;
    while (cin >> n) {
        if (n == 0) {
            cout << stk.top() << endl;
            stk.pop();
        } else {
            stk.push(n);
        }
    }
    return 0;
}