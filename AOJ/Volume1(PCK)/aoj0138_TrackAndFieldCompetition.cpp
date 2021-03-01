// 陸上競技大会
// 陸上競技大会 200M の準決勝 3 組のレースが行われました。それぞれの組に 8 名（計 24 名）の選手が出場します。各組上位 2 位までの選手と、各組の 3 位以下の全選手の中から上位 2 名の計 8 名が決勝に進出します。

// 選手番号とタイムを入力とし、決勝進出者 8 名の番号とそのタイムを出力するプログラムを作成してください。

// Input
// 入力は以下の形式で与えられます。

// p1 t1
// p2 t2
// :
// p24 t24
// 1 行目から 8 行目に１組目の選手番号 pi (整数、1 ≤ pi ≤ 10000) とタイム ti (1/100 まで計測した実数、1 ≤ ti ≤ 100)、9 行目から 16 行目に２組目の選手番号 pi とタイム ti、17 行目から 24 行目に３組目の選手番号 pi とタイム ti が与えられます。同じ選手番号の選手、同タイムの選手はいないものとします。

// Output
// 以下の順番で、決勝進出者の選手番号とタイムを空白区切りでそれぞれ１行に出力してください。

// 1 組目の 1 位の選手
// 1 組目の 2 位の選手
// 2 組目の 1 位の選手
// 2 組目の 2 位の選手
// 3 組目の 1 位の選手
// 3 組目の 2 位の選手
// 各組で 3 位以下の選手の中でタイムが 1 位の選手
// 各組で 3 位以下の選手の中でタイムが 2 位の選手

#include <bits/stdc++.h>
using namespace std;

struct Rec {
    int p, s, ms;
    Rec(int p, int s, int ms) : p(p), s(s), ms(ms) {}
    bool operator < (const Rec& rec) const {
        if (s != rec.s) return s < rec.s;
        return ms < rec.ms;
    }
};

void out(Rec r) {
    printf("%d %02d.%02d\n",r.p,r.s,r.ms);
}

int main() {
    vector<Rec> v[4];
    for (int i = 0; i < 3; i++) {
        for (int k = 0; k < 8; k++) {
            string str;
            getline(cin,str);
            for (int j = 0; j < str.size(); j++) if (str[j] == '.') str[j] = ' ';
            stringstream ss(str);
            int p,s,ms;
            ss >> p >> s >> ms;
            v[i].push_back(Rec(p,s,ms));
        }
        sort(v[i].begin(),v[i].end());
        out(v[i][0]);
        out(v[i][1]);
        for (int k = 2; k < 8; k++) {
            v[3].push_back(v[i][k]);
        }
    }
    sort(v[3].begin(),v[3].end());
    out(v[3][0]);
    out(v[3][1]);
    return 0;
}