// Problem A: Ginkgo Numbers
// We will define Ginkgo numbers and multiplication on Ginkgo numbers.

// A Ginkgo number is a pair <m, n> where m and n are integers. For example, <1, 1>, <-2, 1> and <-3,-1> are Ginkgo numbers.

// The multiplication on Ginkgo numbers is defined by <m, n> · <x, y> = <mx − ny, my + nx>. For example, <1, 1> · <-2, 1> = <-3,-1>.

// A Ginkgo number <m, n> is called a divisor of a Ginkgo number <p, q> if there exists a Ginkgo number <x, y> such that <m, n> · <x, y> = <p, q>.

// For any Ginkgo number <m, n>, Ginkgo numbers <1, 0>, <0, 1>, <-1, 0>, <0,-1>, <m, n>, <-n,m>, <-m,-n> and <n,-m> are divisors of <m, n>. If m2+n2 > 1, these Ginkgo numbers are distinct. In other words, any Ginkgo number such that m2 + n2 > 1 has at least eight divisors.

// A Ginkgo number <m, n> is called a prime if m2+n2 > 1 and it has exactly eight divisors. Your mission is to check whether a given Ginkgo number is a prime or not.

// The following two facts might be useful to check whether a Ginkgo number is a divisor of another Ginkgo number.

// Suppose m2 + n2 > 0. Then, <m, n> is a divisor of <p, q> if and only if the integer m2 + n2 is a common divisor of mp + nq and mq − np.
// If <m, n> · <x, y> = <p, q>, then (m2 + n2)(x2 + y2) = p2 + q2.
// Input
// The first line of the input contains a single integer, which is the number of datasets.

// The rest of the input is a sequence of datasets. Each dataset is a line containing two integers m and n, separated by a space. They designate the Ginkgo number <m, n>. You can assume 1 < m2 + n2 < 20000.

// Output
// For each dataset, output a character 'P' in a line if the Ginkgo number is a prime. Output a character 'C' in a line otherwise.

#include <bits/stdc++.h>
using namespace std;
int dp[150][150];
void init() {
    for (int m = 0; m < 150; m++) {
        for (int n = m; n < 150; n++) {
            int db = m*m+n*n;
            if (db<=1) continue;
            for (int p = 0; p < 150; p++) {
                for (int q = p; q < 150; q++) {
                    int ddb = p*p+q*q;
                    if (ddb<=1) continue;
                    if (ddb % db != 0) continue;
                    if (m == p && n == q) continue;
                    int a = m*p+n*q;
                    int b = m*q-n*p;
                    int c = n*p+m*q;
                    int d = n*q-m*p;
                    if (a % db == 0 && b % db == 0) {
                        dp[p][q]++;
                    } else if (c % db == 0 && d % db == 0) {
                        dp[p][q]++;
                    }
                }
            }
        }
    }
}
int main() {
    init();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a,b;
        cin >> a >> b;
        a = abs(a);
        b = abs(b);
        if (a > b) swap(a,b);
        cout << (dp[a][b]==0?"P":"C") << endl;
    }
}