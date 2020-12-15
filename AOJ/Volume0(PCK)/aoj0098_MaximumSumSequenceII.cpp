// Maximum Sum Sequence II
// 与えられた整数の行列

// a1,1 a1,2 ... a1,n
// a2,1 a2,2 ... a2,n
// :
// an,1 an,2 ... an,n
// で、縦・横方向に１つ以上連続した項（部分行列）の和の最大値を出力して終了するプログラムを作成して下さい。

// Input
// 入力データは以下の形式で与えられます。

// n
// a1,1 a1,2 ... a1,n
// a2,1 a2,2 ... a2,n
// :
// an,1 an,2 ... an,n
// n は 1 以上 100 以下、ai,j は -10000 以上 10000 以下です。

// Output
// 最大値を 1 行に出力して下さい。

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[110][110] = {};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    int ans = -1e9;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] += a[i-1][j];
            a[i][j] += a[i][j-1];
            a[i][j] -= a[i-1][j-1];
            for (int ii = 0; ii < i; ii++) {
                for (int jj = 0; jj < j; jj++) {
                    ans = max(ans, a[i][j] - a[ii][j] - a[i][jj] + a[ii][jj]);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}