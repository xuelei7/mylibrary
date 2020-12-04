// 式
// 与えられた 4 つの 1 から 9 の整数を使って、答えが 10 になる式をつくります。 4 つの整数 a,b,c,d を入力したとき、下記の条件に従い、答えが 10 になる式を出力するプログラムを作成してください。また、答えが複数ある時は、最初に見つかった答えだけを出力するものとします。答えがない時は、0 と出力してください。

// 演算子として、加算 (+)、減算 (-)、乗算 (*) だけを使います。除算 (/) は使いません。使用できる演算子は３個です。
// 数を4つとも使わなければいけません。
// 4つの数の順番は自由に入れ換えてかまいません。
// カッコを使ってもかまいません。使用できるカッコは３組（６個）以下です。
// Input
// 複数のデータセットが与えられます。各データセットの形式は以下のとおり：

// a b c d
// 入力は４つの 0 で終了します。データセットの数は 40 を超えません。

// Output
// 各データセットについて、与えられた 4 つの整数と上記の演算記号およびカッコを組み合わせて値が 10 となる式または 0 を１行に出力してください。式の文字列が 1024 文字を超えてはいけません。

// to utils

#include <bits/stdc++.h>
using namespace std;

int calc(int a, int b, int sign) {
    if (sign == 0) return a + b;
    if (sign == 1) return a - b;
    if (sign == 2) return a * b;
}
bool try_signs(int a, int b, int c, int d, int res) {
    string sign = "+-*";
    for (int i = 0; i < 3*3*3; i++) {
        int tmp = i;
        int f[3];
        for (int j = 0; j < 3; j++) {
            f[j] = tmp % 3;
            tmp /= 3;
        }
        if (calc(calc(calc(a,b,f[0]),c,f[1]),d,f[2]) == res) {
            cout << "((" << a << sign[f[0]] << b << ")" << sign[f[1]] << c << ")" << sign[f[2]] << d << endl;
            return 1;
        }
        if (calc(calc(a,b,f[0]), calc(c,d,f[2]), f[1]) == res) {
            cout << "(" << a << sign[f[0]] << b << ")" << sign[f[1]] << "(" << c << sign[f[2]] << d << ")" << endl;
            return 1;
        }
        if (calc(calc(a,calc(b,c,f[1]),f[0]),d,f[2]) == res) {
            cout << "(" << a << sign[f[0]] << "(" << b << sign[f[1]] << c << "))" << sign[f[2]] << d << endl;
            return 1;
        }
        if (calc(a,calc(calc(b,c,f[1]),d,f[2]),f[0]) == res) {
            cout << a << sign[f[0]] << "((" << b << sign[f[1]] << c << ")" << sign[f[2]] << d << ")" << endl;
            return 1;
        }
        if (calc(a,calc(b,calc(c,d,f[2]),f[1]),f[0]) == res) {
            cout << a << sign[f[0]] << "(" << b << sign[f[1]] << "(" << c << sign[f[2]] << d << "))" << endl;
            return 1;
        }
    }
    return 0;
}

int main() {
    vector<int> v(4);
    while (cin >> v[0] >> v[1] >> v[2] >> v[3]) {
        if (v[0] == 0 && v[1] == 0 && v[2] == 0 && v[3] == 0) break;
        vector<int> p(4);
        p[0] = 0;
        p[1] = 1;
        p[2] = 2;
        p[3] = 3;
        bool ok = 0;
        do {
            if (solve(v[p[0]], v[p[1]], v[p[2]], v[p[3]], 10)) {
                ok = 1;
                break;
            }
        } while (next_permutation(p.begin(),p.end()));
        if (!ok) cout << 0 << endl;
    }
    return 0;
}