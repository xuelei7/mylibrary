// 取引
// 取引先の顧客番号と取引日を月ごとに記録したデータがあります。今月のデータと先月のデータを読み込んで、先月から２ヶ月連続で取引のある会社の顧客番号と取引のあった回数を出力するプログラムを作成してください。ただし、月々の取引先数は 1,000 社以内です。

// Input
// 今月のデータと、先月のデータが１行の空行で区切られて与えられます。それぞれのデータは以下のような形式で与えられます。

// c1,d1
// c2,d2
// ...
// ...
// ci (1 ≤ ci ≤ 1,000) は顧客番号を表す整数、 di (1 ≤ di ≤ 31) は取引日を表す整数です。

// Output
// ２ヶ月連続で取引のある会社について、顧客番号が小さい順に顧客番号と取引回数の総数を空白で区切って出力します。

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
    int p[1010][2] = {};
    int m = 0;
    while (getline(cin,s)) {
        if (s.size() == 0) {
            m = 1;
            continue;
        }
        vector<int> v = split_string_to_int(s,',');
        p[v[0]][m]++;
    }
    for (int i = 1; i <= 1000; i++) {
        if (p[i][0] > 0 && p[i][1] > 0) {
            cout << i << " " << p[i][0] + p[i][1] << endl;
        }
    }
    return 0;
}