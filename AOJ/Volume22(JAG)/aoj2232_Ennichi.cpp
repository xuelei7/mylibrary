// Problem A: Ennichi
// 縁日に来たうさぎが, ある出店のゲームの景品がキャロットケーキであるのを見つけた. このゲームのルールは以下の通りである.

// 縦h マス× 横w マスの格子状のフィールドがあり, 各マスにつき高々1 個のブロックが置かれる. 各ブロックにはアルファベット大文字(‘A’ - ‘Z’) のいずれかで表される色がついている. 同色のブロックが縦または横に一直線上にn 個以上連続して並ぶと, それらのブロックは消滅する.

// 参加者は横に隣り合う2 つのマスを選んで, それらの状態を互いに入れ替える操作ができる. ブロックの入れ替え, 消滅, 落下によってブロックの有るマスの1 つ下のマスにブロックが無くなると, このブロックは落下する. このときふたたび同色のブロックがn 個以上並ぶと消滅する. ただし, ブロックの消滅は, 落下するブロックが存在する間は起こらず, すべてのブロックの落下が終了したタイミングで同時に起こる.

// 1 回の操作でフィールド上のすべてのブロックを消滅させると, このゲームは成功となり景品のケーキを得ることができる. うさぎは1 回分の参加費で確実にケーキを手に入れたく, それができない場合は参加したくない. ゲーム開始時のフィールドの状態から, うさぎがこのゲームに参加すべきであるか答えよ.

// Input
// 入力の一行目にはh, w, n がスペースで区切られて与えられる.

// 2 ≤ h,w, n ≤ 30

// 続くh 行にはフィールドの状態が上から順に与えられる. アルファベット大文字はブロックを, ‘.’ は空きマスを表す. 与えられるフィールドの状態には, 縦あるいは横にn 個以上連続する同色のブロックはなく, 落下する状態にあるブロックもない. 1 個以上のブロックが存在する.

// Output
// うさぎがこのゲームに参加すべきであるなら”YES”を, そうでないなら”NO”を一行に出力せよ.

#include <bits/stdc++.h>
using namespace std;
int h,w,n;
char maze[33][33];
char m[33][33];
bool e[33][33];
bool debug = 0;
void printe() {
    cout << "e:" << endl;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << e[i][j];
        }
        cout << endl;
    }
}
void print() {
    cout << "m:" << endl;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << m[i][j];
        }
        cout << endl;
    }
}
bool check(int a, int b, int c, int d) {
    if (debug) cout << a << " " << b << " " << c << " " << d << endl;
    for (int i = 0; i <= h; i++) {
        for (int j = 0; j <= w; j++) {
            m[i][j] = maze[i][j];
            if (i == h || j == w) m[i][j] = '.';
        }
    }
    swap(m[a][b],m[c][d]);

    while (1) {
        // fall
        for (int j = 0; j < w; j++) {
            int bs = h - 1, p = h;
            while (p-- > 0) if (m[p][j] != '.') swap(m[bs--][j],m[p][j]);
        }
        // find erase
        for (int i = 0; i < h; i++) memset(e[i],0,sizeof(e[i]));
        int l;
        char bf;
        for (int i = 0; i < h; i++) {
            bf = '.';
            l = 0;
            for (int j = 0; j <= w; j++) {
                if (m[i][j] == bf) l++;
                else {
                    if (bf != '.' && l >= n) {
                        for (int k = 0; k < l; k++) {
                            e[i][j-k-1] = 1;
                        }
                        // if (debug) printe();
                    }
                    l = 1;
                    bf = m[i][j];
                }
            }
        }
        for (int j = 0; j < w; j++) {
            l = 0;
            bf = '.';
            for (int i = 0; i <= h; i++) {
                if (m[i][j] == bf) l++;
                else {
                    if (bf != '.' && l >= n) {
                        for (int k = 0; k < l; k++) {
                            e[i-k-1][j] = 1;
                        }
                    }
                    l = 1;
                    bf = m[i][j];
                }
            }
        }
        if (debug) print();
        if (debug) printe();
        // erase
        bool ee = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (m[i][j] != '.' && e[i][j]) {
                    m[i][j] = '.';
                    ee = 1;
                }
            }
        }
        if (!ee) break;
        if (debug) print();
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (m[i][j] != '.') return 0;
        }
    }
    return 1;
}

int main(int arg, char* argv[]) {
    // if (arg > 1) debug = 1;
    cin >> h >> w >> n;
    for (int i = 0; i < h; i++) cin >> maze[i];
    bool ok = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (j+1 < w) {
                ok |= check(i,j,i,j+1);
            }
        }
    }
    cout << (ok?"YES":"NO") << endl;
    return 0;
}