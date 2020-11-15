// Reverse Sequence
// Write a program which reverses a given string str.

// Input
// str (the size of str ≤ 20) is given in a line.

// Output
// Print the reversed str in a line.

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    reverse(s.begin(),s.end());
    cout << s << endl;
    return 0;
}