// Problem A: Equal Sum Sets
// Let us consider sets of positive integers less than or equal to n. Note that all elements of a set are different. Also note that the order of elements doesn't matter, that is, both {3, 5, 9} and {5, 9, 3} mean the same set.

// Specifying the number of set elements and their sum to be k and s, respectively, sets satisfying the conditions are limited. When n = 9, k = 3 and s = 23, {6, 8, 9} is the only such set. There may be more than one such set, in general, however. When n = 9, k = 3 and s = 22, both {5, 8, 9} and {6, 7, 9} are possible.

// You have to write a program that calculates the number of the sets that satisfy the given conditions.

// Input
// The input consists of multiple datasets. The number of datasets does not exceed 100.

// Each of the datasets has three integers n, k and s in one line, separated by a space. You may assume 1 ≤ n ≤ 20, 1 ≤ k ≤ 10 and 1 ≤ s ≤ 155.

// The end of the input is indicated by a line containing three zeros.

// Output
// The output for each dataset should be a line containing a single integer that gives the number of the sets that satisfy the conditions. No other characters should appear in the output.

// You can assume that the number of sets does not exceed 231 - 1.

#include <bits/stdc++.h>
using namespace std;
int n,k,s;

int dp[21][11][160];

int dfs(int a, int b, int c) {
    if (c > s) return 0;
    if (c == s) return b == k;
    // c < s
    if (b >= k) return 0;
    // b < k
    if (a > n) return 0;
    // a <= n

    if (dp[a][b][c] != -1) return dp[a][b][c];

    int ans = 0;
    // put
    ans += dfs(a+1,b+1,c+a);
    // no put
    ans += dfs(a+1,b,c);
    
    return dp[a][b][c] = ans;
}

int main() {
    while (cin >> n >> k >> s) {
        if (n == 0 && k == 0 && s == 0) break;
        for (int i = 0; i < 21; i++) {
            for (int j = 0; j < 11; j++) {
                for (int c = 0; c < 160; c++) {
                    dp[i][j][c] = -1;
                }
            }
        }
        cout << dfs(1,0,0) << endl;
    }
}