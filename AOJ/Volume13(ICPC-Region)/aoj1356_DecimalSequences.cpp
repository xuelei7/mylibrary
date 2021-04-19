// Problem A Decimal Sequences
// Hanako learned the conjecture that all the non-negative integers appear in the infinite digit sequence of the decimal representation of π = 3.14159265..., the ratio of a circle's circumference to its diameter. After that, whenever she watches a sequence of digits, she tries to count up non-negative integers whose decimal representations appear as its subsequences.

// For example, given a sequence "3 0 1", she finds representations of five non-negative integers 3, 0, 1, 30 and 301 that appear as its subsequences.

// Your job is to write a program that, given a finite sequence of digits, outputs the smallest non-negative integer not appearing in the sequence. In the above example, 0 and 1 appear, but 2 does not. So, 2 should be the answer.

// Input
// The input consists of a single test case.

// n
// d1 d2 ... dn

// n is a positive integer that indicates the number of digits. Each of dk's (k=1,...,n) is a digit. There is a space or a newline between dk and dk+1 (k=1,...,n−1).

// You can assume that 1≤n≤1000.

// Output
// Print the smallest non-negative integer not appearing in the sequence.

#include <bits/stdc++.h>
using namespace std;

int n;
int a[1010];

void solve() {
    set<int> st;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        st.insert(a[i]);
        if (i - 1 >= 0) {
            st.insert(a[i] + a[i-1] * 10);
        }
        if (i - 2 >= 0) {
            st.insert(a[i] + a[i-1] * 10 + a[i-2] * 100);
        }
    }
    for (int i = 0; i <= 999; i++) {
        if (st.find(i) == st.end()) {
            cout << i << endl;
            return;
        }
    }
}
int main() {
    while (cin >> n) {
        if (n == 0) break;
        solve();
    }
    return 0;
}