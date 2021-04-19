// ぐるぐる模様
// 「ぐるぐる模様」を表示するプログラムを作成することにしました。「ぐるぐる模様」は以下のようなものとします。

// 1 辺の長さが n の場合、n 行 n 列の文字列として表示する。
// 左下隅を基点とし，時計回りに回転する渦状の模様とする。
// 線のある部分は #（半角シャープ）、空白部分は " "（半角空白）で表現する。
// 線と線の間は空白を置く。
// 整数 n を入力とし，1 辺の長さが n の「ぐるぐる模様」を出力するプログラムを作成してください。

// Input
// 入力は以下の形式で与えられます。

// d
// n1
// n2
// :
// nd
// １行目にデータセットの数 d (d ≤ 20)、続く d 行に i 個目のぐるぐる模様の辺の長さ ni (1 ≤ ni ≤ 100) がそれぞれ１行に与えられます。

// Output
// データセットごとに、ぐるぐる模様を出力してください。データセットの間に１行の空行を入れてください。

#include <bits/stdc++.h>
using namespace std;

int dh[4] = {-1,0,1,0};
int dw[4] = {0,1,0,-1};
bool a[110][110];

void draw (int h, int w, int d) {
    if (d == 1) {
        a[h][w] = 1;
    } else if (d == 2) {
        a[h][w] = 1;
        a[h-1][w] = 1;
        a[h-1][w+1] = 1;
    } else if (d == 3) {
        for (int i = 0; i < 3; i++) {
            a[h-i][w] = 1;
            a[h-2][w+i] = 1;
            a[h-i][w+2] = 1;
        }
    } else {
        for (int i = 0; i < d; i++) {
            a[h-i][w] = 1;
            a[h-d+1][w+i] = 1;
            a[h-i][w+d-1] = 1;
            a[h][w+i] = 1;
        }
        a[h][w+1] = 0;
        if (d != 4) {
            a[h-1][w+2] = 1;
        }
    }
}

void solve(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) memset(a[i],0,sizeof(a[i]));
    int h = n-1, w = 0, d = n;
    while (d > 0) {
        draw(h,w,d);
        h -= 2;
        w += 2;
        d -= 4;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (a[i][j]?'#':' ');
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    bool bg = 1;
    while (n--) {
        if (!bg) cout << endl;
        bg = 0;
        solve();
    }
    return 0;
}