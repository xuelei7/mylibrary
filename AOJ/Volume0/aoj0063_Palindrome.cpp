// 回文
// 半角アルファベット文字列からなる、1 行あたり 100 文字以内のデータがあります。いくつかの行は対称（左端から読んでも右端から読んでも同じ）です。このデータを読み込んで、その中の対称な文字列の数を出力するプログラムを作成してください。なお、１文字だけからなる行は対称であるとします。

// Input
// 複数の文字列が複数行にわたって与えられます。各行に１つの文字列が与えられます。文字列の数は 50 を超えません。

// Output
// 対称な文字列の数を１行に出力します。

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int cnt = 0;
    while (cin >> s) {
        bool ok = 1;
        for (int i = 0; i < (s.size() + 1) / 2; i++) {
            if (s[i] != s[s.size() - 1 - i]) {
                ok = 0;
                break;
            }
        }
        cnt += ok;
    }
    cout << cnt << endl;
    return 0;
}