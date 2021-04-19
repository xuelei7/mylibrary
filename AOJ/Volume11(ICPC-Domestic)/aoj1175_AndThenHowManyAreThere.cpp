// そして，いくつになった？
// 有名な一人遊びゲームの作家であるソリタリウス氏は，今日もまた新しいアイデアを思いついた． ソリタリウス氏の新しいゲームでは，さまざまな色と大きさの平らな円盤を使う．

// まず最初に，全部の円盤をテーブル中央付近にばらまく． 別の円盤が上に重なっていない円盤の中に同じ色のものが2枚あれば，それらを同時に取り除くことができる． なお，円盤同士が1点で接しているだけなら，それらを重なっているとはみなさない．



// 図 D-1: テーブル上の7枚の円盤
// たとえば，図 D-1 の場合，まず最初に取り除けるのは2枚の黒い円盤だけである． これらを取り除くことで，今度は2枚の白い円盤を取り除けるようになる． しかし，グレーの円盤は決して取り除くことができない．

// この問題では，与えられた円盤の色，大きさ，初期の位置関係から，最大何枚の円盤を取り除くことができるか計算するプログラムを作成して欲しい．

// Input
// 入力は複数のデータセットからなり，それぞれが以下のような形式でテーブル上に円盤をばらまいた直後の状態を表す．

// n
// x1 y1 r1 c1
// x2 y2 r2 c2
// ...
// xn yn rn cn
// 最初の行のnは円盤の枚数を表す正整数である． 続くn行は，それぞれが空白文字1個で区切られた4個の整数からなり，n枚の円盤の色，大きさ，初期の位置関係を次のように表す．

// (xi, yi), ri, ci はi番目の円盤の中心のxy座標，半径，色番号をそれぞれ表し，
// i番目の円盤がj番目の円盤の上に重なるときには，必ずi < jが成り立つ．
// 色番号は1以上4以下であり，一つのデータセット中に同じ色の円盤は高々6枚しか出現しないと仮定して良い． また，円盤の中心のxy座標は常に0以上100以下，半径は常に1以上100以下と仮定して良い．
// 入力の終わりは1個のゼロで示される．

// Output
// 各データセットについて，取り除ける円盤の最大枚数をそれぞれ1行に出力しなさい．

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll x[30],y[30],r[30],c[30];
set<ll> dp;
bool on[30][30];
int mx;
// 1: the plate is gone
void go(ll s, int cnt) {
    // cout << "s " << bitset<8>(s) << " " << cnt << endl;
    mx = max(mx,cnt);
    if (dp.count(s)) return;
    dp.insert(s);
    for (int i = 0; i < n; i++) {
        if ((s>>i)&1) continue;
        for (int j = i + 1; j < n; j++) {
            if ((s>>j)&1) continue;
            // insure that they are the same color
            if (c[i] != c[j]) continue;
            // now, both plates are there

            // insure that there is none plate above i and j
            bool ok = 1;
            if (on[i][j]) continue;
            for (int k = 0; k < n; k++) {
                if ((s>>k)&1) continue;
                if (k < i && on[k][i]) {
                    ok = 0;
                    break;
                }
                if (k < j && on[k][j]) {
                    ok = 0; 
                    break;
                }
            }
            if (!ok) continue;
            
            go(s|(1LL<<i)|(1LL<<j),cnt+2);
        }
    }
    return;
}

int main() {
    while (cin >> n) {
        if (n == 0) break;
        for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> r[i] >> c[i];
        dp.clear();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ll dx = abs(x[i] - x[j]);
                ll dy = abs(y[i] - y[j]);
                ll dd = dx * dx + dy * dy;
                ll dr = (r[i] + r[j]) * (r[i] + r[j]);
                on[i][j] = (dd < dr);
            }
        }
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         cout << on[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        mx = 0;
        go(0,0);
        cout << mx << endl;
    }

    return 0;
}