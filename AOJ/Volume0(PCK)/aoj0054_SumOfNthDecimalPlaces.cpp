// 小数位の和
// a, b, n は、いずれも正の整数であるとします。分数 a / b の小数第 i 位の数を f(i) とします (0 ≤ f(i) ≤ 9)。このとき、i=1 から n までの f(i) の和を s とします。

// s=f(1)+f(2)+ ... +f(n)
// a, b, n を読み込んで、 s を出力して終了するプログラムを作成してください。

// Input
// 入力は複数のデータセットからなります。各データセットとして、3 つの整数 a (1 ≤ a ≤ 1000), b (1 ≤ b ≤ 10000), n (1 ≤ n ≤ 100) が空白区切りで１行に与えられます。

// データセットの数は 100 を超えません。

// Output
// データセットごとに、s を１行に出力します。

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,n;
    while (cin >> a >> b >> n) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            a %= b;
            a *= 10;
            sum += a / b;
        }
        cout << sum << endl;
    }
    return 0;
}