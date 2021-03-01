// QQ
// Write a program which prints multiplication tables in the following format:
// 1x1=1
// 1x2=2
// .
// .
// 9x8=72
// 9x9=81

// Input
// No input.

// Output
// 1x1=1
// 1x2=2
// .
// .
// 9x8=72
// 9x9=81

#include <bits/stdc++.h>
using namespace std;

int main() {
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            cout << i << "x" << j << "=" << i*j << endl;
        }
    }
    return 0;
}