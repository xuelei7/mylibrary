// 幾何問題を解こう
// A君は今日も幾何の問題を解いている。 幾何の問題を解く時は浮動小数点誤差に気をつけることが大事である。

// 浮動小数点誤差とは、2進法の有限小数で数を表す際におこる丸めによって起きる誤差である。 例えば、10進法での 0.1 は2進法では 0.00011001100110011 ... という無限小数になるが、 これを有限の桁で丸める際に誤差が発生してしまう。

// 正の整数 p, q が10進法で与えられる。 有理数 p / q を有限桁数の小数で表現することができるような b 進法（b は2以上の整数）を求めよ。 複数ある場合は最も小さいものを出力せよ。

// Constraints
// 0<p<q<109
// Input Format
// 入力は以下の形式で標準入力から与えられる。

// p q
// Output Format
// 答えを一行に出力せよ。

#include <bits/stdc++.h>
using namespace std;

int main() {
    int p,q;
    cin >> p >> q;
    map<int,int> mp, mq;
    for (int i = 2; i * i <= q; i++) {
        if (p % i == 0) {
            while (p % i == 0) {
                p /= i;
                mp[i]++;
            }
        }
        if (q % i == 0) {
            while (q % i == 0) {
                q /= i;
                mq[i]++;
            }
        }
    }
    if (p != 1) mp[p]++;
    if (q != 1) mq[q]++;
    long long ans = 1;
    for (auto e: mq) {
        if (e.second > mp[e.first]) {
            ans *= e.first;
        }
    }
    cout << ans << endl;
    return 0;
}