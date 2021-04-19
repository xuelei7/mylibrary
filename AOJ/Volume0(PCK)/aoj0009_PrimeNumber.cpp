// Prime Number
// Write a program which reads an integer n and prints the number of prime numbers which are less than or equal to n. A prime number is a natural number which has exactly two distinct natural number divisors: 1 and itself. For example, the first four prime numbers are: 2, 3, 5 and 7.

// Input
// Input consists of several datasets. Each dataset has an integer n (1 ≤ n ≤ 999,999) in a line.

// The number of datasets is less than or equal to 30.

// Output
// For each dataset, prints the number of prime numbers.

// to number

#include <bits/stdc++.h>
using namespace std;

int main() {
    const int MAXN = 1000000;
    bool isprime[MAXN];
    for (int i = 0; i < MAXN; i++) isprime[i] = 1;
    for (int i = 2; i < MAXN; i++) {
        if (!isprime[i]) continue;
        for (int j = i + i; j < MAXN; j+=i) isprime[j] = 0;
    }
    vector<int> v;
    for (int i = 2; i < MAXN; i++) if (isprime[i]) v.push_back(i);
    int n;
    while (cin >> n) {
        int k = upper_bound(v.begin(), v.end(), n) - v.begin();
        cout << k << endl;
    }
    return 0;
}