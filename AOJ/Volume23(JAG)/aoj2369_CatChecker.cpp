
// ログアウト
 
// 登録・設定
// 日本語   英語
// My Statusはじめての方へ    HOME- Volume23-2369
// Tag Discussion Solution Statistics Submit
 
// CatChecker
// 時間制限 : 8 sec, メモリ制限 : 131072 KB
// Japanese
// Problem A: CatChecker
// 外見からねこかどうかわからない動物がいる. あなたは, 鳴き声がねこの鳴き声であればねこであり, そうでなければうさぎであると判定することにした.

// ねこの鳴き声は次のように定義される.

// "" (empty string) はねこの鳴き声である.
// X, Y がねこの鳴き声であれば 'm' + X + 'e' + Y + 'w' は猫の鳴き声である. ただし + は文字列の連結を表す.
// 以上で定義されるものだけがねこの鳴き声である.
// BNF で表すとねこの鳴き声 CAT は
// CAT := "" (empty string) | 'm' + CAT + 'e' + CAT + 'w'
// と定義される.

// 鳴き声を表す文字列 S が与えられる. 鳴き声から動物が何であるか判定せよ.

// Constraints
// S will contain between 1 and 500 characters, inclusive. Each character in S will be 'm', 'e' or 'w'.

// Input
// 入力は以下の形式で与えられる:

// S

// Output
// S が猫の鳴き声であれば "Cat", そうでなければ "Rabbit" と1 行に出力せよ.

#include <bits/stdc++.h>
using namespace std;
int ok[510][510];
bool cat(string s, int f) {
    if (s.size() == 0) return 1;
    int t = f + s.size() - 1;
    if (ok[f][t] != -1) return ok[f][t];
    if (s.size() % 3 != 0) return 0;
    if (s[0] != 'm' || s[s.size()-1] != 'w') return 0;

    for (int i = 1; i < s.size() - 1; i++) {
        if (cat(s.substr(1,i-1),f+1) && cat(s.substr(i+1,s.size()-i-1-1),f+i+1)) return ok[f][t] = 1;
    }
    
    return ok[f][t] = 0;
}
int main() {
    string s;
    cin >> s;
    for (int i = 0; i < 510; i++) memset(ok[i],-1,sizeof(ok[i]));
    cout << (cat(s,0)?"Cat":"Rabbit") << endl;
}