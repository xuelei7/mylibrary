// Rank Checker
// 時は2020 年。パソコン甲子園 2020 の予選結果を保存したデータがあります。このデータには、各チームに振られる整理番号と正解数が保存されています。ここでは、正解数で順位を決定するものとし、正解数の多いほうから順に 1 位、2 位 ... と順位をつけていくこととします。

// 予選結果のデータと整理番号をキーボードから入力して、その番号のチームの順位を出力するプログラムを作成してください。

// Input
// 入力データは２つの部分からなります。前半の部分は、予選結果のデータ、後半の部分は順位を知りたいチーム番号の問い合わせです。予選結果のデータの形式は以下の通りです。

// p1,s1
// p2,s2
// ...
// ...
// 0,0
// pi (1 ≤ pi ≤ 100 )、 si (0 ≤ si ≤ 30) はそれぞれ i チーム目の整理番号と正解数を表す整数です。整理番号と正解数がともに 0 のときこのデータの入力が終わるものとします。

// 続いて後半の問い合わせが複数与えられます。問い合わせの形式は以下の通りです。

// q1
// q2
// :
// 各問い合わせは１行に整理番号 qi (1 ≤ qi ≤ 30) が与えられます。これを入力の最後まで処理して下さい。問い合わせの数は 100 を超えません。

// Output
// 各問い合わせについて、チームの順位を１行に出力して下さい。

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
    vector<int> a(101);
    set<int> st;
    while (cin >> s) {
        vector<int> v = split_string_to_int(s,',');
        if (v[0] == 0 && v[1] == 0) break;
        a[v[0]] = v[1];
        st.insert(-v[1]);
    }
    map<int,int> mp;
    int cnt = 1;
    for (auto p:st) {
        mp[-p] = cnt++;
    }
    int id;
    while (cin >> id) {
        cout << mp[a[id]] << endl;
    }
    return 0;
}