// 最短経路


// 図１に例示するように整数（0 以上 99 以下）をひしがたに並べます。このような、ひしがたを表すデータを読み込んで、一番上からスタートして一番下まで次のルールに従って進むとき、通過する整数の和の最大値を出力するプログラムを作成してください。

// 各ステップで、対角線上の左下か対角線上の右下に進むことができます。
// 例えば図1の例では、図2に示すように、7,3,8,7,5,7,8,3,7を選んで通ったとき、その和は最大の 55 （7+3+8+7+5+7+8+3+7=55） となります。

// Input
// 入力例に示すように、カンマで区切られた整数の並びが、ひし形状に与えられます。各行に空白文字は含まれません。入力例は図１に対応しています。 データの行数は 100 行未満です。

// Output
// ルールに従って通過する整数の和の最大値を１行に出力します。

// from string

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
    int pre[110] = {};
    int now[110] = {};
    int n;
    cin >> n;
    now[0] = n;
    int cnt = 1;
    while (cin >> s) {
        vector<int> v = split_string_to_int(s,',');
        for (int i = 0; i < 110; i++) {
            pre[i] = now[i];
            now[i] = 0;
        }
        int delta;
        if (v.size() > cnt) delta = -1;
        else delta = 1;
        cnt = v.size();
        for (int i = 0; i < v.size(); i++) {
            if (i + delta >= 0) now[i] = max(now[i], pre[i + delta] + v[i]);
            now[i] = max(now[i], pre[i] + v[i]);
        }
    }
    cout << now[0] << endl;
    return 0;
}