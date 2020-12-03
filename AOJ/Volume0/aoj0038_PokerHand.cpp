// ポーカー
// ポーカーの手札データを読み込んで、それぞれについてその役を出力するプログラムを作成してください。ただし、この問題では、以下のルールに従います。

// ポーカーはトランプ 5 枚で行う競技です。
// 同じ数字のカードは 5 枚以上ありません。
// ジョーカーは無いものとします。
// 以下のポーカーの役だけを考えるものとします。(番号が大きいほど役が高くなります。)
// 役なし(以下に挙げるどれにも当てはまらない)
// ワンペア（2 枚の同じ数字のカードが1 組ある）
// ツーペア（2 枚の同じ数字のカードが2 組ある）
// スリーカード（3 枚の同じ数字のカードが1 組ある）
// ストレート（5 枚のカードの数字が連続している）
// ただし、A を含むストレートの場合、A で終わる並びもストレートとします。つまり、A を含むストレート は、A 2 3 4 5 　と　10 J Q K A 　の２種類です。J Q K A 2 などのように、A をまたぐ並び はストレートではありません。（この場合、「役なし」になります）。
// フルハウス（3 枚の同じ数字のカードが1 組と、残りの2 枚が同じ数字のカード）
// フォーカード（4 枚の同じ数字のカードが1 組ある）
// Input
// 入力は複数のデータセットからなります。各データセットは以下の形式で与えられます。

// 手札1,手札2,手札3,手札4,手札5
// 手札は、トランプのJ(ジャック) を11、Q(クイーン) を12、K(キング) を13、A（エース）を 1、その他はそれぞれの数字で表すこととします。

// データセットの数は 50 を超えません。

// Output
// データセットごとに、手札によってできる最も高い役をひとつ出力してください。役の表記については出力例に従ってください。

// string, util

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

string poker_hand(vector<int> v) {
    sort(v.begin(), v.end());
    if (v[0] == v[1] && v[1] == v[2] && v[2] == v[3]) return "four card";
    if (v[1] == v[2] && v[2] == v[3] && v[3] == v[4]) return "four card";
    if (v[0] == v[1] && v[2] == v[3] && v[3] == v[4]) return "full house";
    if (v[0] == v[1] && v[1] == v[2] && v[3] == v[4]) return "full house";
    if (v[0] == v[1] - 1 && v[1] == v[2] - 1 && v[2] == v[3] - 1 && v[3] == v[4] - 1) return "straight";
    if (v[0] == 1 && v[1] == 10 && v[2] == 11 && v[3] == 12 && v[4] == 13) return "straight";
    if (v[0] == v[1] && v[1] == v[2]) return "three card";
    if (v[1] == v[2] && v[2] == v[3]) return "three card";
    if (v[2] == v[3] && v[3] == v[4]) return "three card";
    if (v[0] == v[1] && (v[2] == v[3] || v[3] == v[4])) return "two pair";
    if (v[1] == v[2] && v[3] == v[4]) return "two pair";
    if (v[0] == v[1] || v[1] == v[2] || v[2] == v[3] || v[3] == v[4]) return "one pair";
    return "null";
}

int main() {
    string s;
    while (cin >> s) {
        vector<int> v = split_string_to_int(s,',');
        cout << poker_hand(v) << endl;
    }
    return 0;
}