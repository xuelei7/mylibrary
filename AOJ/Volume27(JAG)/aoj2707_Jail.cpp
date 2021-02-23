// 監獄
// 無限人の囚人たちがいる。はじめ、囚人たちは 0,1,2, ... と番号が振られている。

// 次の操作を N 回行う。

// 0 番目の囚人を釈放し、k,2k,3k, ... 番目の囚人たちを処刑する。
// その後、残った囚人たちに番号を振り直す。このとき、元の番号が小さい囚人から順に 0,1,2, ... と番号を振る。
// N 回目の操作で釈放される囚人がはじめに振られていた番号を求めよ。

// Constraints
// 1 ≤ N ≤ 105
// 2 ≤ k ≤ 105
// 答えは 1018 以下である。
// Input Format
// 入力は以下の形式で標準入力から与えられる。

// N k
// Output Format
// 答えを一行に出力せよ。

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
ll f (ll num) {
    ll ret = 0;
    // cout << num << " ";
    for (ll i = 1; i < n; i++) {
        ll minus = num / k + 1;
        ret += minus;
        num -= minus;
        if (num < 0) break;
    }
    // cout << ret << " " << endl;
    return ret;
}
int main () {
    cin >> n >> k;
    ll l = 0, r = 2e18;
    while (l < r) {
        ll mid = l + r >> 1;
        ll num = f(mid);
        if (num == mid + 1) l = mid + 1;
        else r = mid;
    }
    cout << l << endl;
    return 0;
}