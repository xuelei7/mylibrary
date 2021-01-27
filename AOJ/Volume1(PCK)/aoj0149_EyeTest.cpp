// 視力検査
// 視力検査の検査結果データを入力とし、下記の視力判定表に基づいて各判定に当てはまる人数を、左右の視力別に出力するプログラムを作成してください。

// 判定	視力
// A	1.1 以上
// B	0.6 以上 1.1 未満
// C	0.2 以上 0.6 未満
// D	0.2 未満

// Input
// 入力は以下の形式で与えられます。

// l1 r1
// l2 r2
// l3 r3
// :
// :
// i 行目に i 人目の左の視力を表す実数 li と右の視力を表す実数 ri が空白区切りで与えられます。ただし、視力は 0.1 以上 2.0 以下で、 0.1 刻みで与えられます。

// 入力の行数は 40 を超えません。

// Output
// 以下の形式で、判定表を出力してください。

// 1行目 左の視力がAの人数 右の視力がAの人数（空白区切り）
// 2行目 左の視力がBの人数 右の視力がBの人数（空白区切り）
// 3行目 左の視力がCの人数 右の視力がCの人数（空白区切り）
// 4行目 左の視力がDの人数 右の視力がDの人数（空白区切り）

#include <bits/stdc++.h>
using namespace std;

int a[4],b[4];
string l,r;
int main() {
    while (cin >> l >> r) {
        for (int i = 0; i < l.size(); i++) if (l[i] == '.') l[i] = ' ';
        for (int i = 0; i < r.size(); i++) if (r[i] == '.') r[i] = ' ';
        stringstream sl(l);
        stringstream sr(r);
        int c,d;
        sl >> c >> d;
        c = c * 10 + d;
        if (c >= 11) a[0]++;
        else if (c >= 6) a[1]++;
        else if (c >= 2) a[2]++;
        else a[3]++;
        sr >> c >> d;
        c = c * 10 + d;
        if (c >= 11) b[0]++;
        else if (c >= 6) b[1]++;
        else if (c >= 2) b[2]++;
        else b[3]++;
    }
    for (int i = 0; i < 4; i++) {
        cout << a[i] << " " << b[i] << endl;
    }
    return 0;
}