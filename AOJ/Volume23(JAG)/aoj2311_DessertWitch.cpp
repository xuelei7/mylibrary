// 問題文
// お菓子の魔女 CHARLOTTE は巴マミとクッキーゲームを楽しんでいる．クッキーゲームは 8×8 の格子状に区切られたテーブルクロスの上にチーズクッキーとチョコレートクッキーを置いて行われる．各格子には高々 1 個のチョコレートクッキーまたはチーズクッキーしか置くことはできない．

// お菓子の魔女はチーズクッキーを，巴マミはチョコレートクッキーを交互に置いてゲームを行う．自分のクッキーを置いたあと，そのクッキーから上下左右斜めの各 8 方向について，置くクッキーとすでに置いていた自分のクッキーの間に相手のクッキーのみが直線に並んでいた場合に，その挟まれた相手のクッキーのすべてが自分のクッキーで置き換えられる．クッキーゲームのプレイヤーは自分のターンが回ってきた時，1 つ自分のクッキーを置くことができる．ただし，相手のクッキーを少なくとも 1 つ以上自分のクッキーに置き換えられなければならない．そのような置き場がない場合，自分のターンをパスをしなければならない．

// お菓子の魔女も巴マミも考えるのが少々苦手である．そこで，回ってきたターン毎にそのターンの中で置き換えられるクッキーの数を最大化することを考えることにした．巴マミのターンのときに置き換えられるクッキーの数を最大にするようなクッキーを置く場所の候補が複数ある場合は，より上の場所を，それでも複数ある場合はより左の場所を選択することにした．また同様に，お菓子の魔女のターンのときに候補が複数ある場合はより下の場所を，それでも複数ある場合はより右の場所を選択することにした．

// テーブルクロスに置かれたクッキーの状態が与えられるので，巴マミからはじめ，彼女たちがそこからクッキーゲームを行い，共に新たなクッキーが置けなくなるまでゲームを続けた時のテーブルクロスの上に置かれたクッキーの状態を求めよ．

// 入力形式
// 入力は以下の形式で与えられる．

// s11s12…s18
// s21s22…s28
// …
// s81s82…s88
// sij はテーブルクロスに置かれたクッキーの初期状態を表す文字で，上から i 行目，左から j 列目の格子の状態を表す．チョコレートクッキーが置かれているときsijは 'o' であり，チーズクッキーが置かれているときは 'x', 何も置かれていないときは '.' となる．

// 出力形式
// クッキーゲームが行われた後のテーブルクロスの上に置かれたクッキーの状態を，入力形式と同じ形式で出力せよ．

// 制約
// sij は 'o', 'x', '.' のいずれかである．

#include <bits/stdc++.h>
using namespace std;
char maze[8][8];
int h = 8, w = 8;
int dh[8] = {1,0,-1,0,1,1,-1,-1};
int dw[8] = {0,1,0,-1,1,-1,1,-1};
int fd(int hh, int ww, int kk, char c1, char c2) {
    int ret = 0;
    // cout << "fd " << hh << " " << ww << " " << kk << " " << c2 << endl;
    while (1) {
        hh += dh[kk];
        ww += dw[kk];
        if (hh < 0 || hh >= h || ww < 0 || ww >= w) break;
        if (maze[hh][ww] == c2) {
            // cout << ret << endl;
            return ret;
        }
        if (maze[hh][ww] == '.') return 0;
        ret++;
    }
    // cout << 0 << endl;
    return 0;
}
void fil(int hh, int ww, int kk, char c1, char c2) {
    // cout << "fil " << hh << " " << ww << " " << kk << " " << c1 << endl;
    while (1) {
        hh += dh[kk];
        ww += dw[kk];
        if (maze[hh][ww] == c1) break;
        maze[hh][ww] = c1;
    }
}
void mfill(int hh, int ww, char c1, char c2) {
    // cout << "mfill " << hh << " " << ww << " " << c1 << endl;
    maze[hh][ww] = c1;
    for (int i = 0; i < 8; i++) {
        if (fd(hh,ww,i,c2,c1)) {
            fil(hh,ww,i,c1,c2);
        }
    }
}
int main() {
    for (int i = 0; i < 8; i++) cin >> maze[i];
    int t = 1, fail = 0;
    while (1) {
        if (t == 1) {
            int mx = 0, hh = 0, ww = 0, kk = 0;
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if (maze[i][j] != '.') continue;
                    int sum = 0;
                    for (int k = 0; k < 8; k++) {
                        sum += fd(i,j,k,'x','o'); 
                    }
                    if (sum > mx) {
                        mx = sum;
                        hh = i;
                        ww = j;
                    }
                }
            }
            if (mx != 0) {
                mfill(hh,ww,'o','x');
                fail = 0;
            } else {
                fail++;
                if (fail == 2) break;
            }
        } else {
            int mx = 0, hh = 0, ww = 0, kk = 0;
            for (int i = 7; i >= 0; i--) {
                for (int j = 7; j >= 0; j--) {
                    if (maze[i][j] != '.') continue;
                    int sum = 0;
                    for (int k = 0; k < 8; k++) {
                        sum += fd(i,j,k,'o','x');
                    }
                    if (sum > mx) {
                        mx = sum;
                        hh = i;
                        ww = j;
                    }
                }
            }
            if (mx != 0) {
                mfill(hh,ww,'x','o');
                fail = 0;
            } else {
                fail++;
                if (fail == 2) break;
            }
        }
        if (t == 1) t = 2;
        else t = 1;
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++){
            cout << maze[i][j];
        }
        cout << endl;
    }
}