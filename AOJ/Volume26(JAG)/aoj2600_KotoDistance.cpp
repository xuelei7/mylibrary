// 問題 A : Koto Distance
// 問題文
// Koto は言わずと知れた碁盤の目の街である． この街は東西方向に W メートル，南北方向に H メートルに伸びる長方形の領域によってできている． この街の西端から x メートル，南端から y メートルの点は (x, y) と記される． ここの街に住む人は古くから伝わる独自の文化を重んじており，その一つにKoto距離という変わった距離尺度がある． 2つの点 (x1,y1)，(x2,y2) の Koto 距離は，min(|x1−x2|, |y1−y2|) によって定義される．

// 最近この街全体に Wifi を使えるようにする計画が立ち上がった． 現在の計画では，親機を N 個作ることになっている． i 番目の親機は点 (xi, yi) に設置され，Koto距離が wi 以下の領域に対して Wifi を提供する．

// 親機を計画どおり建てた場合に，街の内部及び境界上に Wifi を提供できるかどうかを判定せよ．

// なお，Koto距離は一般に三角不等式を満たさないため，距離の公理を満たさないということはここだけの秘密である．

// 入力形式
// 入力は以下の形式で与えられる．

// N W H
// x1 y1 w1
// …
// xN yN wN
// 出力形式
// 街の内部および境界上に Wifi を提供できるなら “Yes” を，そうでない場合は “No” を出力せよ．

// 制約
// 1≤N≤105
// 1≤W≤105
// 1≤H≤105
// 0≤xi≤W
// 0≤yi≤H
// 1≤wi≤105
// 同一座標に親機は複数存在しない

#include <bits/stdc++.h>
using namespace std;

int n,H[2];

struct S {
    int x,w;
    S(int x=0, int w=0):x(x),w(w) {}
    bool operator < (const S s) const {
        if (x-w != s.x-s.w) return x-w < s.x-s.w;
        return w < s.w;
    }
} s[2][100010];

int main() {
    cin >> n >> H[0] >> H[1];
    for (int i = 0; i < n; i++) {
        cin >> s[0][i].x >> s[1][i].x >> s[0][i].w;
        s[1][i].w = s[0][i].w;
    }
    sort(s[0],s[0]+n);
    sort(s[1],s[1]+n);
    for (int ss = 0; ss < 2; ss++) {
        int l = 0;
        bool ok = 1;
        for (int i = 0; i < n; i++) {
            int x = s[ss][i].x;
            int w = s[ss][i].w;
            if (x - w > l) {
                ok = 0;
                break;
            } else {
                l = max(l, w + x);
            }
        }
        if (l < H[ss]) continue;
        if (ok) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}