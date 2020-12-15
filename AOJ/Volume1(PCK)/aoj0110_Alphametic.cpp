// 覆面算
// 数式の一部を隠してしまって、隠した数字を探す問題を覆面算といいます。今回は、数式の中のある数字のいくつかを X で隠してしまった式を扱います。以下の数式を入力して、結果を出力するプログラムを作成してください。

// 数式

// 「数字列 + 数字列 = 数字列」の形で、1 行の単純な足し算式です。
// 「数字列」は、数字 0 から 9 と文字 X の並びです。
// 2 桁以上の「数字列」の左端の数字は 0 ではないものとします。
// X は、数式全体の中で必ず 1 つ以上含まれます。
// 結果

// 覆面算の答えです。数式が成り立つ様な X の値で 0 ~ 9 のどれか 1 つです。2 つ以上の答えはないものとします。
// 答えがない場合、結果は“NA”としてください。
// Input
// 複数のデータセットが与えられます。各データセットとして、X を 1 つ以上含む足し算式(空白を含まない 126 文字以内の文字列) が１行に与えられます。データセットの数は 150 を超えません。

// Output
// 各データセットについて、覆面算の結果を１行に出力してください。数字 0 ~ 9 または NA を出力してください。

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    while (cin >> s) {
        string a,b,c;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '+') a = s.substr(0,i);
            else if (s[i] == '=') {
                b = s.substr(a.size()+1,i-a.size()-1);
                c = s.substr(i+1,s.size() - b.size() - a.size() - 2);
                break;
            }
        }
        if (a.size() > c.size() || b.size() > c.size()) {
            cout << "NA" << endl;
            continue;
        }
        int len = c.size();
        bool firstX = 0;
        if (a.size() > 1 && a[0] == 'X') firstX = 1;
        if (b.size() > 1 && b[0] == 'X') firstX = 1;
        if (c.size() > 1 && c[0] == 'X') firstX = 1;

        bool ok = 0;
        for (int i = firstX; i < 10; i++) {
            string ta = a, tb = b, tc = c;
            for (auto &ch:ta) if (ch == 'X') ch = '0' + i;
            for (auto &ch:tb) if (ch == 'X') ch = '0' + i;
            for (auto &ch:tc) if (ch == 'X') ch = '0' + i;
            ok = 1;
            reverse(ta.begin(),ta.end());
            reverse(tb.begin(),tb.end());
            reverse(tc.begin(),tc.end());
            while (ta.size() < len) ta.push_back('0');
            while (tb.size() < len) tb.push_back('0');
            int ad = 0;
            for (int j = 0; j < len; j++) {
                int res = ta[j] + tb[j] + ad - '0' * 2;
                if (res >= 10) {
                    res -= 10;
                    ad = 1;
                } else ad = 0;
                if (res != tc[j] - '0') {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                cout << i << endl;
                break;
            }
        }
        if (!ok) {
            cout << "NA" << endl;
        }
    }
    return 0;
}