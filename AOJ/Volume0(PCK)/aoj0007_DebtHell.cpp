// Debt Hell
// Your friend who lives in undisclosed country is involved in debt. He is borrowing 100,000-yen from a loan shark. The loan shark adds 5% interest of the debt and rounds it to the nearest 1,000 above week by week.

// Write a program which computes the amount of the debt in n weeks.

// Input
// An integer n (0 ≤ n ≤ 100) is given in a line.

// Output
// Print the amout of the debt in a line.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long k = 100000;
    while (n--) {
        long long ad = k / 20;
        ad = (ad + 999) / 1000 * 1000;
        k += ad;
    }
    cout << k << endl;
    return 0;
}