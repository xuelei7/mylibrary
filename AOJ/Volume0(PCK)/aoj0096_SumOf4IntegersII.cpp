// ４つの整数の和 II
// 4,000 以下の正の整数 n を入力し、0 〜 1000 の範囲の整数 a,b,c,d の組で

// a+b+c+d=n
// を満たすものの組み合わせ数を出力するプログラムを作成して下さい。

// Input
// 複数のデータセットが与えられます。各データセットに n が１行に与えられます。入力の最後まで処理して下さい。

// データセットの数は 50 を超えません。

// Output
// 各データセットごとに、a,b,c,d の組み合わせの個数を１行に出力して下さい。

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int dp[5][4010] = {};
    dp[0][0] = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j <= 4000; j++) {
            for (int k = 0; k <= 1000; k++) {
                if (j + k <= 4000) {
                    dp[i+1][j+k] += dp[i][j];
                }
            }
        }
    }
    while (cin >> n) {
        cout << dp[4][n] << endl;
    }
    return 0;
}