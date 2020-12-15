// 四角すいの表面積
// 1 辺が x の正方形を底面とする、高さ h の四角すいの表面積 S を出力するプログラムを作成して下さい。ただし、頂点と底面の中心を結ぶ線分は底面と直交しているとします。また、 x、h は 100 以下の正の整数とします。

// Input
// 複数のデータセットが与えられます。各データセットは以下の形式で与えられます。

// x
// h
// x,h が共に 0 のとき入力の終了を示します。

// Output
// 各データセットごとに、S（実数）を１行に出力して下さい。出力は0.00001以下の誤差を含んでもよい。

#include <bits/stdc++.h>
using namespace std;

int main() {
    double x,h;
    while (cin >> x >> h) {
        if (x == 0 && h == 0) break;
        cout << setprecision(20) << x * x + 2 * x * sqrt(x*x/4+h*h) << endl;
    }
    return 0;
}