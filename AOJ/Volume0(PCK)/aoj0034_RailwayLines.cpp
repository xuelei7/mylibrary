// 鉄道路線
// 複線（上りと下りが別の線路になっていてどこででもすれ違える）の鉄道路線があります。この路線には終端駅を含めて11 の駅があり、それぞれの駅と駅の間は図で示す区間番号で呼ばれています。

// この路線の両方の終端駅から列車が同時に出発して、途中で停まらずに走ります。各区間の長さと2 本の列車の速度を読み込んで、それぞれの場合について列車がすれ違う区間の番号を出力するプログラムを作成してください。ただし、ちょうど駅のところですれ違う場合は、両側の区間番号のうち小さいほうの数字を出力します。また、列車の長さ、駅の長さは無視できるものとします。

// Input
// 複数のデータセットが与えられる。各データセットは以下のような形式で与えられる。

// l1,l2,l3,l4,l5,l6,l7,l8,l9,l10,v1,v2
// li (1 ≤ li ≤ 2,000) は区間 i の長さ(km)を表す整数である。v1 は区間 1 側の終端駅を出発した列車の速度(km/h)、v2 は区間 10 側の終端駅を出発した列車の速度(km/h)を表す整数である (1 ≤ v1, v2 ≤ 2,000)。

// データセットの数は 50 を超えない。

// Output
// データセットごとに、列車がすれちがう区間の番号を１行に出力する。

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
    while (cin >> s) {
        vector<int> v = split_string_to_int(s,',');
        double sum = 0, v1 = v[10], v2 = v[11];
        for (int i = 0; i < 10; i++) sum += v[i];
        double point = sum * v1 / (v1 + v2);
        sum = 0;
        for (int i = 0; i < 10; i++) {
            sum += v[i];
            if (sum >= point) {
                cout << i + 1 << endl;
                break;
            }
        }
    }
    return 0;
}