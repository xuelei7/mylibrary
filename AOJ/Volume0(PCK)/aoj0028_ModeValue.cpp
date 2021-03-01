// Mode Value
// Your task is to write a program which reads a sequence of integers and prints mode values of the sequence. The mode value is the element which occurs most frequently.

// Input
// A sequence of integers ai (1 ≤ ai ≤ 100). The number of integers is less than or equals to 100.

// Output
// Print the mode values. If there are several mode values, print them in ascending order.

// statistic

#include <bits/stdc++.h>
using namespace std;

int main() {
    int cnt[101] = {};
    int n;
    while (cin >> n) {
        cnt[n]++;
    }
    int mx = 0;
    for (int i = 1; i <= 100; i++) mx = max(mx, cnt[i]);
    for (int i = 1; i <= 100; i++) {
        if (cnt[i] == mx) cout << i << endl;
    }
    return 0;
}