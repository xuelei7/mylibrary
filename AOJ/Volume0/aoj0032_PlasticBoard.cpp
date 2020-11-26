// プラスティック板 Plastic Board
// 機械に辺・対角線の長さのデータを入力し、プラスティック板の型抜きをしている工場があります。この工場では、サイズは様々ですが、平行四辺形の型のみを切り出しています。あなたは、切り出される平行四辺形のうち、長方形とひし形の製造個数を数えるように上司から命じられました。

// 「機械に入力するデータ」を読み込んで、長方形とひし形の製造個数を出力するプログラムを作成してください。

// Input
// 入力は以下の形式で与えられます。

// a1,b1,c1
// a2,b2,c2
// :
// 機械に入力するデータが複数行に与えられます。i 行目に i 番目の平行四辺形の隣り合う２辺の長さを表す整数 ai, bi と対角線の長さを表す整数 ci がカンマ区切りで与えられます (1 ≤ ai,bi,ci ≤ 1000, ai+bi > ci)。データの数は 100 件を超えません。

// Output
// １行目に長方形の製造個数、２行目ひし形の製造個数を出力します。

#include <bits/stdc++.h>
using namespace std;
vector<int> split_string_to_int(string s, char c) {
    vector<int> v;
    int left_side = 0;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == c) {
            bool minus_f = false;
            if (s[left_side] == '-') minus_f = true;
            int num = stoi(s.substr(left_side + minus_f, i-left_side-minus_f));
            if (minus_f) num *= -1;
            v.push_back(num);
            left_side = i + 1;
        }
        if (i == s.size() - 1) {
            bool minus_f = false;
            if (s[left_side] == '-') minus_f = true;
            int num = stoi(s.substr(left_side + minus_f, i+1-left_side-minus_f));
            if (minus_f) num *= -1;
            v.push_back(num);
        }
    }
    return v;
}
int main() {
    string s;
    int rec = 0, dia = 0;
    while (cin >> s) {
        vector<int> v = split_string_to_int(s,',');
        int a = v[0], b = v[1], c = v[2];
        if (a * a + b * b == c * c) rec++;
        else if (a == b) dia++;
    }
    cout << rec << "\n" << dia << "\n";
    return 0;
}