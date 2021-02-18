// マンハッタンでは，道路がx 座標またはy 座標が整数のところに通っている．すぬけ君の家とすめけ君の家はどちらも道路上にあり，直線距離(ユークリッド距離) はちょうど d である．すぬけ君の家からすめけ君の家まで道路に沿って移動するときの最短距離として考えられる最大値を求めよ．

// Constraints
// 0 < d ≤ 10
// d は小数点以下ちょうど三桁まで与えられる
// Input
// d
// Output
// 答えを一行に出力せよ．絶対誤差または相対誤差が 10−9 以下のとき正答と判定される．

#include <bits/stdc++.h>
using namespace std;

int main() {
    double d;
    cin >> d;
    double eps = 1e-12;
    double ans = d;
    for (int i = 0; i * i < d * d + eps; i++) {
        double j = sqrt(d * d - i * i);
        if (j < 1) {
            ans = max(ans,i+1.0);
            continue;
        }
        ans = max(ans, i+j);
    }
    double j = d / sqrt(2);
    j *= 2;
    ans = max(ans, j);
    cout << fixed << setprecision(20) << ans << endl;
    return 0;
}