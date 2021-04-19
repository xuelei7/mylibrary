// 表計算
// 以下の表のように、与えられた表の縦・横の値の合計を、それぞれの行・列で求め出力するプログラムを作成してください。ただし、縦・横のデータ数は 10 以下とし、それぞれの数字は 100 以下の整数とします。 出力は右詰め 5 桁で出力してください。



// Input
// 複数のデータセットが与えられます。各データセットは以下の形式で与えられます。

// n
// a1,1 a1,2 ... a1,n
// a2,1 a2,2 ... a2,n
// :
// an,1 an,2 ... an,n
// n は縦・横のデータ数、ai,j は表の i 行 j 列目の値（整数）を表します。

// n が 0 のとき入力の終わりを示します。データセットの数は 50 を超えません。

// Output
// 各データセットについて、入力データに縦と横の合計のデータを付加した表(半角右詰め 5 桁)を出力してください。

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        int a[15][15] = {};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += a[i][j];
            }
            a[i][n] = sum;
        }
        for (int j = 0; j <= n; j++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += a[i][j];
            }
            a[n][j] = sum;
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                cout << setw(5) << a[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}