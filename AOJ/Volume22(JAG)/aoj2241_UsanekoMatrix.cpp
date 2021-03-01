<<<<<<< HEAD
// Problem J: Usaneko Matrix
// うさぎとねこが勝負をしている. ルールは以下の通りである.

// まず2 匹はそれぞれn 行n 列の正方形状にn2 個の整数を紙に書き, トランプを1 枚ずつ引く. 次に, 1 から 1 000 000 までの数が1 つずつ書かれた1 000 000 枚のカードを2 匹でシャッフルし, これを1 枚ずつ交互に引いていく. 2 匹はカードが引かれるたび, カードと同じ数が自分の紙に書かれていたらそれに印をつける. 「印がついたn 個の数の組であって, 一直線上に並んでいるもの」の個数が, はじめに引いたトランプの数以上になることを勝利条件とする.

// 与えられたm 枚目のカードまでで, うさぎとねこのどちらが勝つか答えよ. ただし勝敗は, あるカードが引かれて印をつけ終わった段階で2 匹のうち片方のみが勝利条件をみたしたときに決まるものとし, それ以外の場合は引き分けとする. いずれかが勝利条件をみたした後でもカードが引かれることはあるが, これは勝敗に影響しない.

// Input
// 1 行目：“n u v m” (正方形のサイズ, うさぎのトランプの数, ねこのトランプの数, 引かれるカードの枚数) 2-(N + 1) 行目：うさぎが紙に書くn2 個の数(N + 2)-(2N + 1) 行目：ねこが紙に書くn2 個の数(2N + 2)-(2N +M + 1) 行目：引かれるm 枚のカード
// 1 ≤ n ≤ 500
// 1 ≤ u, v ≤ 13
// 1 ≤ m ≤ 100 000
// 1 ≤ (書かれる数) ≤ 1 000 000
// うさぎが紙に書くn2 個の数, ねこが紙に書くn2 個の数, 引かれるm 枚のカードに書かれた数はそれぞれの中で異なる.

// Output
// うさぎが勝つ場合には”USAGI”を, ねこが勝つ場合には”NEKO”を, 引き分けならば”DRAW”, それぞれ 一行に出力せよ.

=======
// Problem J: Usaneko Matrix
// うさぎとねこが勝負をしている. ルールは以下の通りである.

// まず2 匹はそれぞれn 行n 列の正方形状にn2 個の整数を紙に書き, トランプを1 枚ずつ引く. 次に, 1 から 1 000 000 までの数が1 つずつ書かれた1 000 000 枚のカードを2 匹でシャッフルし, これを1 枚ずつ交互に引いていく. 2 匹はカードが引かれるたび, カードと同じ数が自分の紙に書かれていたらそれに印をつける. 「印がついたn 個の数の組であって, 一直線上に並んでいるもの」の個数が, はじめに引いたトランプの数以上になることを勝利条件とする.

// 与えられたm 枚目のカードまでで, うさぎとねこのどちらが勝つか答えよ. ただし勝敗は, あるカードが引かれて印をつけ終わった段階で2 匹のうち片方のみが勝利条件をみたしたときに決まるものとし, それ以外の場合は引き分けとする. いずれかが勝利条件をみたした後でもカードが引かれることはあるが, これは勝敗に影響しない.

// Input
// 1 行目：“n u v m” (正方形のサイズ, うさぎのトランプの数, ねこのトランプの数, 引かれるカードの枚数) 2-(N + 1) 行目：うさぎが紙に書くn2 個の数(N + 2)-(2N + 1) 行目：ねこが紙に書くn2 個の数(2N + 2)-(2N +M + 1) 行目：引かれるm 枚のカード
// 1 ≤ n ≤ 500
// 1 ≤ u, v ≤ 13
// 1 ≤ m ≤ 100 000
// 1 ≤ (書かれる数) ≤ 1 000 000
// うさぎが紙に書くn2 個の数, ねこが紙に書くn2 個の数, 引かれるm 枚のカードに書かれた数はそれぞれの中で異なる.

// Output
// うさぎが勝つ場合には”USAGI”を, ねこが勝つ場合には”NEKO”を, 引き分けならば”DRAW”, それぞれ 一行に出力せよ.

#include <bits/stdc++.h>
using namespace std;

int n,v,u,m;
int maze[2][550][550];
bool used[2][550][550];
int cntl[2][100010];
int cnt[2][100010];
int a[100010];
pair<int,int> pos[2][1000010];
void in(int k) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[k][i][j];
            pos[k][maze[k][i][j]] = {i,j};
        }
    }
}
int dh[4] = {0,1,1,1};
int dw[4] = {1,0,1,-1};
void count(int k, int i) {
    if (i > 0) cntl[k][i] = max(cntl[k][i], cntl[k][i-1]);
    auto p = pos[k][a[i]];
    int h = p.first;
    int w = p.second;
    // cout << i << " " << a[i] << " " << h << " " << w << endl;
    if (h == -1 && w == -1) return;
    if (n == 1) {
        cnt[k][i]++;
        return;
    }
    if (used[k][h][w]) return;
    used[k][h][w] = 1;
    int base = 0;
    if (i > 0) base = cntl[k][i-1];
    int increase = 0;
    for (int j = 0; j < 4; j++) {
        int th = h + dh[j];
        int tw = w + dw[j];
        int lft = 0;
        while (th >= 0 && th < n && tw >= 0 && tw < n && used[k][th][tw]) {
            lft++;
            th += dh[j];
            tw += dw[j];
        }
        th = h - dh[j];
        tw = w - dw[j];
        int rt = 0;
        while (th >= 0 && th < n && tw >= 0 && tw < n && used[k][th][tw]) {
            rt++;
            th -= dh[j];
            tw -= dw[j];
        }
        if (lft + rt + 1 >= n)
            increase += lft + rt + 1 - n + 1 - (lft >= n? lft - n + 1: 0) - (rt >= n? rt - n + 1: 0);
        // cout << increase << endl;
    }
    // cout << k << " " << i << " " << h << " " << w << " " << cntl[k][i] << endl;
    cntl[k][i] = max(cntl[k][i], base + increase);
}
int main() {
    cin >> n >> u >> v >> m;
    for (int i = 0; i <= 1000000; i++) {
        for (int k = 0; k < 2; k++) {
            pos[k][i] = {-1,-1};
        }
    }
    in(0); in(1);
    int ans = -1;
    for (int i = 0; i < m; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
        count(0,i); count(1,i);
        bool wina = cntl[0][i] >= u;
        bool winb = cntl[1][i] >= v;
        if (n == 1) {
            wina = cnt[0][i] >= u;
            winb = cnt[1][i] >= v;
        }
        // cout << cntl[0][i] << " " << cntl[1][i] << endl;
        if (wina && !winb) {
            cout << "USAGI" << endl;
            return 0;
        }
        if (!wina && winb) {
            cout << "NEKO" << endl;
            return 0;
        }
        if (wina && winb) {
            cout << "DRAW" << endl;
            return 0;
        }
    }
    cout << "DRAW" << endl;
    return 0;
}
>>>>>>> 3d537af6c6d6d0e6fecbb17c7d1aa89a0ea36d59
