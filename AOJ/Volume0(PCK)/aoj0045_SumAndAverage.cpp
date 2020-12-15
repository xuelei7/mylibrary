// Sum and Average
// 販売単価と販売数量を読み込んで、販売金額の総合計と販売数量の平均を出力するプログラムを作成してください。

// Input
// 入力は以下の形式で与えられます。

// 販売単価,販売数量
// 販売単価,販売数量
// :
// :
// カンマで区切られた販売単価と販売数量の組が、複数行に渡って与えられます。入力される値はすべて 0 以上 1,000 以下で、販売単価と販売数量の組の数は 100 を超えません。

// Output
// １行目に販売金額の総合計（整数）、２行目に販売数量の平均(整数）を出力してください。 販売数量の平均に端数（小数点以下の数）が生じた場合は小数点以下第 1 位を四捨五入してください。

// from string, to number

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
int rounding(double n) {
    int intn = n * 2;
    return (intn + 1) / 2;
}
int main() {
    string s;
    int sum1 = 0, sum2 = 0, cnt = 0;
    while (cin >> s) {
        vector<int> v = split_string_to_int(s,',');
        sum1 += v[0] * v[1];
        sum2 += v[1];
        cnt++;
    }
    cout << sum1 << endl;
    double avg = (double)sum2 / (double)cnt;
    cout << rounding(avg) << endl;
    return 0;
}