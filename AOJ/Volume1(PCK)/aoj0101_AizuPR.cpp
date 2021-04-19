// Aizu PR
// 会津を世界にPRするための英文によるパンフレットが作成されました。そのパンフレットを見てみると、藩主の保科正之(ほしなまさゆき)の姓の表記が "Hoshina" ではなく "Hoshino" となっていました。そこであなたは "Hoshino" を "Hoshina" に変換する作業を任されました。

// 英文を読み込み、そこに含まれるすべての "Hoshino" を "Hoshina" に置き換え、変換後の英文を出力するプログラムを作成してください。ただし、英文は 1000 文字以下とします。

// Input
// 最初にデータセット数 n (n ≤ 50) が与えられる。続いて n 行の英文が与えられる。各データセットについて、１行に英文が与えられる。英文は半角英数字・記号を含む。

// Output
// 各データセットについて変換した英文を１行に出力する。

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    getline(cin, s);
    for (int i = 0; i < n; i++) {
        getline(cin, s);
        for (int i = 0; i + 6 < s.size(); i++) {
            if (s.substr(i,7) == "Hoshino") {
                s[i+6] = 'a';
                i += 5;
            }
        }
        cout << s << endl;
    }
    return 0;
}