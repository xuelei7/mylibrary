// 整数の和
// 0 から 9 の数字から異なる n 個の数を取り出して合計が s となる組み合わせの数を出力するプログラムを作成してください。n 個の数はおのおの 0 から 9 までとし、１つの組み合わせに同じ数字は使えません。たとえば、n が 3 で s が 6 のとき、3 個の数字の合計が 6 になる組み合わせは、

// 1 + 2 + 3 = 6
// 0 + 1 + 5 = 6
// 0 + 2 + 4 = 6

// の 3 通りとなります。

// Input
// 複数のデータセットが与えられます。各データセットに n (1 ≤ n ≤ 9) と s (0 ≤ s ≤ 100) が１つのスペースで区切られて１行に与えられます。n と s が共に 0 のとき入力の最後とします（この場合は処理せずにプログラムを終了する）。

// データセットの数は 50 を超えません。

// Output
// 各データセットに対して、n 個の整数の和が s になる組み合わせの数を１行に出力して下さい。

#include <bits/stdc++.h>
using namespace std;

int dp[10][11][110];

// int dfs(int n, int s, int cnt, int ts, int mx) {
//     if (n == 1) return s <= 9;
//     if (ts == s && cnt == n) return 1;
//     if (ts == s) return 0;
//     if (cnt >= n) return 0;
//     int ans = 0;
//     for (int i = mx + 1; i <= 9; i++) {
//         if (ts + i > s) break;
//         ans += dfs(n,s,cnt+1,ts+i,i);
//     }
//     return ans;
// }

// int main() {
//     int n,s;
//     while (cin >> n >> s) {
//         if (n == 0 && s == 0) break;
//         cout << dfs(n,s,0,0,-1) << endl;
//     }
//     return 0;
// }

int main() {
    dp[0][0][0] = 1;
    dp[0][1][0] = 1;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j <= i+1; j++) {
            for (int k = 0; k <= 45; k++) {
                dp[i+1][j][k] += dp[i][j][k];
                dp[i+1][j+1][k+i+1] += dp[i][j][k];
            }
        }
    }
    int n,s;
    while (cin >> n >> s) {
        if (n == 0 && s == 0) break;
        cout << dp[9][n][s] << endl;
    }
    return 0;
}