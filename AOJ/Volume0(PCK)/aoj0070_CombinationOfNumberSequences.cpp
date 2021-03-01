// Combination of Number Sequences
// 0 から 9 までの整数を使った n 個の数の並び k1, k2, ..., kn を考えます。正の整数 n と s を読み込んで、

// k1+2×k2+3×k3+ ... +n×kn=s

// となっているような n 個の数の並びが何通りあるかを出力するプログラムを作成してください。ただし、1 つの「n 個の数の並び」には同じ数が 2 回以上現われないものとします。

// Input
// 入力は複数のデータセットからなります。各データセットとして、n (1 ≤ n ≤ 10) と s (0 ≤ s ≤ 10,000)が空白区切りで１行に与えられます。

// データセットの数は 100 を超えません。

// Output
// データセットごとに、n 個の整数の和が s になる組み合わせの個数を１行に出力します。

// [new]: fill's usage

#include <bits/stdc++.h>
using namespace std;
int dp[1100][1000][11];
int n,s;
int f(int sta, int sum, int num) {
    if (dp[sta][sum][num] != -1) return dp[sta][sum][num];
    if (num == n) return sum == s;
    if (sum > s) return 0;
    int ret = 0;
    for (int i = 0; i < 10; i++) {
        if ((sta >> i) & 1) continue;
        ret += f(sta | (1 << i), sum + i * (num + 1), num + 1);
    }
    return dp[sta][sum][num] = ret;
}
int main() {
    while (cin >> n >> s) {
        fill(dp[0][0],dp[1099][999],-1);
        cout << f(0,0,0) << endl;
    }
    return 0;
}