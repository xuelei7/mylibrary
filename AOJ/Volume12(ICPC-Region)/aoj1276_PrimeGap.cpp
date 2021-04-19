// Problem B: Prime Gap
// The sequence of n - 1 consecutive composite numbers (positive integers that are not prime and not equal to 1) lying between two successive prime numbers p and p + n is called a prime gap of length n. For example, (24, 25, 26, 27, 28) between 23 and 29 is a prime gap of length 6.

// Your mission is to write a program to calculate, for a given positive integer k, the length of the prime gap that contains k. For convenience, the length is considered 0 in case no prime gap contains k.

// Input
// The input is a sequence of lines each of which contains a single positive integer. Each positive integer is greater than 1 and less than or equal to the 100000th prime number, which is 1299709. The end of the input is indicated by a line containing a single zero.

// Output
// The output should be composed of lines each of which contains a single non-negative integer. It is the length of the prime gap that contains the corresponding positive integer in the input if it is a composite number, or 0 otherwise. No other characters should occur in the output.

#include <bits/stdc++.h>
using namespace std;


vector<int> getPrimeList() {
    const int MAXN = 1500000;
    bool isprime[MAXN];
    for (int i = 0; i < MAXN; i++) isprime[i] = 1;
    for (int i = 2; i < MAXN; i++) {
        if (!isprime[i]) continue;
        for (int j = i + i; j < MAXN; j+=i) isprime[j] = 0;
    }
    vector<int> v;
    for (int i = 2; i < MAXN; i++) if (isprime[i]) v.push_back(i);
    return v;
}
vector<bool> getPrimeList1() {
    const int MAXN = 1500000;
    vector<bool> isprime(MAXN);
    for (int i = 0; i < MAXN; i++) isprime[i] = 1;
    for (int i = 2; i < MAXN; i++) {
        if (!isprime[i]) continue;
        for (int j = i + i; j < MAXN; j+=i) isprime[j] = 0;
    }
    return isprime;
}
int main() {
    int k;
    vector<int> v = getPrimeList();
    vector<bool> v1 = getPrimeList1();
    while (cin >> k) {
        if (k == 0) break;
        if (v1[k]) {
            cout << 0 << endl;
            continue;
        }
        auto it = lower_bound(v.begin(),v.end(),k);
        int rt = *it;
        it--;
        int lft = *it;
        cout << rt - lft << endl;
    }
    return 0;
}