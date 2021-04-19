// ヘビ
// ある世界には，文字だけでできた不思議なヘビが住んでいます。このヘビには現在A種とB種の2種類が確認されていますが、それ以外の種類がいる可能性もあります。

// A種は，">'"の後に"="が1個以上並んだ後、"#"が来て、さらに前と同じ個数の"="が来た後、"~"（半角チルダ）で終わります。

// B種は，">^"の後に "Q="が1個以上並んだ後、"~~"で終わります。

// A種の例： >'====#====~        >'==#==~
// B種の例： >^Q=Q=Q=Q=~~        >^Q=Q=~~
// ヘビを文字列データとして受け取り、それがどんな種類であるかを判別して、A種の場合は「A」、B種の場合は「B」、それ以外の種類の場合は「NA」を出力するプログラムを作成してください。

// Input
// 入力は以下の形式で与えられます。

// n
// S1
// S2
// :
// Sn
// 1 行目に判別されるヘビの数 n（1 ≤ n ≤ 10000）、続く n 行に i 匹目のヘビを表す文字列 Si (200文字以下の、空白を含まない文字列) がそれぞれ１行に与えられます。

// Output
// i 行目に i 匹目のヘビの種類 A、B または NA を出力してください。

#include <bits/stdc++.h>
using namespace std;

bool A(string s) {
    int sz = s.size();
    if (s[sz-1] != '~') return 0;
    if (sz % 2 != 0) return 0;
    int i = 2, j = sz - 2;
    for (; i != j; i++, j--) {
        if (s[i] != '=') return 0;
        if (s[j] != '=') return 0;
    }
    return s[i] == '#';
}

bool B(string s) {
    int sz = s.size();
    if (s[sz-1] != '~') return 0;
    if (s[sz-2] != '~') return 0;
    if (sz % 2 != 0) return 0;
    for (int i = 2; i < sz - 2; i+=2) {
        if (s[i] != 'Q') return 0;
        if (s[i+1] != '=') return 0;
    }
    return 1;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s.size() < 6) {
            cout << "NA" << endl;
            continue;
        }
        int f = 0;
        if (s[0] == '>' && s[1] == '\'') f = A(s);
        else if (s[0] == '>' && s[1] == '^') f = (int)B(s) * 2;
        
        cout << (f==0?"NA":(f==1?"A":"B")) << endl;
    }
    return 0;
}