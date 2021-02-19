// Problem E: Mirror Cave
// 双子の冒険者 Rin と Len は鏡の洞窟でお宝を探している．この洞窟には鏡の間という対になった 2 つの部屋があり，その部屋の扉の向こうには高価な宝が眠っているという．

// 便宜上，2 つの部屋はそれぞれ W × H のセルが格子状に並んだものとみなす．部屋の外側は壁で囲まれている．また，部屋の内側にもところどころ壁が設置されており，壁の配置されているセルには進入することができない．宝の部屋への扉を開くためには，2 人が左右対称の動きをして，同時に特定のセルに到達しなければならない．しかも，片方だけが先に到達した場合は，扉はロックされて開かなくなってしまう．

// 左右対称の動きとは，北と北，西と東，東と西，南と南にそれぞれ同時に動くことを意味する．ただし，片方が動こうとしている先に壁があり，もう一方の先に壁が無いといった状況下でも左右対称の動きであると認められる．この場合は壁がある方はその場にとどまり，壁が無い方は隣のセルに動くことになる．

// 入力として，双子の初期位置，目的地，障害物の配置が与えられる．あなたの仕事は，この双子が扉を開けることが可能であるか判定するプログラムを書くことである．

// Input
// 入力は複数のデータセットからなる．各データセットは次の形式で与えられる．

// W H
// RoomL1 RoomR1
// RoomL2 RoomR2
// ...
// RoomLH RoomRH
// 最初の行では 2 つの正の整数 W, H (1 ≤ W, H ≤ 50) が 1 つの空白で区切られて与えられる．その後，H 行に渡って 2 つの部屋の情報が与えられる．RoomLi，RoomRi はそれぞれ左側，右側の部屋の i 番目の行に対応する．両者とも長さ W の文字列で，j 番目の文字が部屋の j 番目の列に対応する．それぞれの文字は以下のいずれかである．

// . : 自由に移動できるセル
// # : 壁のあるセル（進入できない）
// % : 目的地
// R : Rin の初期位置
// L : Len の初期位置
// 各部屋とも 1 行目が部屋の北端，1 列目が部屋の西端に対応する．また，各部屋は必ずちょうど 1 つの目的地があり，左側の部屋には Len，右側の部屋には Rin の初期位置がちょうど 1 つ存在する．

// 入力の終わりは，空白で区切られた 2 つの 0 を含む行で示される．

// Output
// 各データセットについて，双子が扉を開くことができるなら Yes，できなければ No をそれぞれ 1 行に出力せよ．

#include <bits/stdc++.h>
using namespace std;
int h,w;
char maze[2][55][55];
bool d[55][55][55][55];
int sh[2], sw[2], gh[2], gw[2];
void init() {
    for (int i = 0; i < 55; i++) {
        for (int j = 0; j < 55; j++) {
            for (int k = 0; k < 55; k++) {
                for (int l = 0; l < 55; l++) {
                    d[i][j][k][l] = 0;
                }
            }
        }
    }
    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (maze[k][i][j] == 'L' || maze[k][i][j] == 'R') {
                    sh[k] = i;
                    sw[k] = j;
                }
                if (maze[k][i][j] == '%') {
                    gh[k] = i;
                    gw[k] = j;
                }
            }
        }
    }
}
struct P {
    int hh, ww;
    P(int hh, int ww): hh(hh), ww(ww) {;}
    bool operator == (const P &p) const {
        return hh == p.hh && ww == p.ww;
    }
    bool operator != (const P &p) const {
        return hh != p.hh || ww != p.ww;
    }
};
struct PP {
    P a, b;
    PP(P a, P b): a(a), b(b) {}
};
int dh[4] = {0,0,1,-1};
int dw[4] = {1,-1,0,0};
P mv(P p, int dir, int k) {
    int th = p.hh + dh[dir];
    int tw = p.ww + dw[dir] * (k?1:-1);
    if (th < 0 || th >= h || tw < 0 || tw >= w) return p;
    if (maze[k][th][tw] == '#') return p;
    return P(th,tw);
}
int main() {
    while (cin >> w >> h) {
        if (w == 0 && h == 0) break;
        for (int i = 0; i < h; i++) cin >> maze[0][i] >> maze[1][i];
        init();
        queue<PP> pq;
        pq.push(PP(P(sh[0],sw[0]),P(sh[1],sw[1])));
        bool ok = 0;
        while (!pq.empty()) {
            auto tp = pq.front();
            pq.pop();
            P a = tp.a;
            P b = tp.b;
            for (int i = 0; i < 4; i++) {
                P ta = mv(a,i,0);
                P tb = mv(b,i,1);
                if (ta == a && tb == b) continue;
                if (d[ta.hh][ta.ww][tb.hh][tb.ww]) continue;
                if (ta == P(gh[0],gw[0]) && tb == P(gh[1],gw[1])) {
                    ok = 1;
                    break;
                }
                if (ta == P(gh[0],gw[0]) || tb == P(gh[1],gw[1])) continue;
                d[ta.hh][ta.ww][tb.hh][tb.ww] = 1;
                pq.push(PP(ta,tb));
            }
            if (ok) break;
        }
        cout << (ok?"Yes":"No") << endl;
    }
}