// 血液型
// ある学級の生徒の出席番号と ABO 血液型を保存したデータを読み込んで、おのおのの血液型の人数を出力するプログラムを作成してください。なお、ABO 血液型には、A 型、B 型、AB 型、O 型の４種類の血液型があります。

// Input
// カンマで区切られた出席番号と血液型の組が、複数行に渡って与えられます。出席番号は 1 以上 50 以下の整数、血液型は文字列 "A", "B", "AB" または "O" のいずれかです。生徒の人数は 50 を超えません。

// Output
// １行目に A 型の人数
// ２行目に B 型の人数
// ３行目に AB 型の人数
// ４行目に O 型の人数
// を出力します。

// from string

#include <bits/stdc++.h>
using namespace std;
vector<string> split_string(string s, char c) {
    vector<string> v;
    int left_side = 0;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == c) {
            v.push_back(s.substr(left_side, i-left_side));
            left_side = i+1;
        }
        if (i == s.size() - 1) {
            v.push_back(s.substr(left_side, i-left_side+1));
        }
    }
    return v;
}
int main() {
    string s;
    map<string,int> mp;
    while (cin >> s) {
        vector<string> v = split_string(s,',');
        mp[v[1]]++;
    }
    cout << mp["A"] << "\n" << mp["B"] << "\n" << mp["AB"] << "\n" << mp["O"] << endl;
    return 0;
}