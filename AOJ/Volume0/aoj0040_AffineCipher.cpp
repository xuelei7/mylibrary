// アフィン暗号
// 簡単な暗号法の一つに、アフィン暗号というものがあります。まず、アルファベット a〜z を a = 0, b = 1, c = 2,..., x = 23, y = 24, z = 25 と 0〜25 の数字に置き換えます。そして、以下の式で、原文のアルファベットを置換します。

// F(γ)=(α⋅γ+β) mod 26

// ただし、mod 26 は 26 で割った余りを表します。例えば、α=3,β=2 のとき、アルファベットの 'a' (=0) は、F(0)=(3⋅0+2) mod 26=2 で 'c' に、アルファベットの 'n' (=13) は F(13)=(3⋅13+2) mod 26=15 で 'p' に置換されます。 このとき、γ に対する F(γ) が必ず 1 対 1 で対応付けられるように、α と β は慎重に選ばれているものとします（α と 26 が互いに素であることが条件）。α=4,β=7 のときのように、F(′a′)=7,F(′n′)=7 と、'a' も 'n' も同じ 'h' に置換されるようなことはありません。また、アルファベット以外の文字は置換されません。

// 暗号化された文字列を元の文章に復号したものを出力するプログラムを作成してください。元の文章には、キーワードとして

// that
// this
// のいずれかが必ず含まれているものとします。

// Input
// 複数のデータセットが与えられます。１行目にデータセット数 
// n (n≤30) が与えられます。続いて n 行のデータが与えられます。各データセットに英小文字と空白からなる 256 文字以内の暗号化された文章が１行に与えられます。

// Output
// 各データセットに対して、復号した元の文章を１行に出力して下さい。

// utils

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int n;
    cin >> n;
    getline(cin,s);
    while (n--) {
        getline(cin, s);
        bool ok = 0;
        for (int a = 1; a < 26; a++) {
            if (__gcd(a,26) != 1) continue;
            for (int b = 0; b < 26; b++) {
                string v = s;
                for (int i = 0; i < v.size(); i++) {
                    if (v[i] == ' ') continue;
                    v[i] = (char)(((v[i] - 'a') * a + b) % 26 + 'a');
                }
                if (v.find("this") != -1 || v.find("that") != -1) ok = 1;
                if (ok) {
                    cout << v << endl;
                    break;
                }
            }
            if (ok) break;
        }
    }
    return 0;
}