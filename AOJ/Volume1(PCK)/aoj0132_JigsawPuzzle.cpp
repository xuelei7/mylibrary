// ジグソーパズル
// 子供から大人まで脳トレ系パズルゲームが流行しています。我々も遅れを取らぬよう、パズルゲームを作ってみんなで遊ぶことにしました。

// 我々が考えたのはジグソーパズルのゲームで、未完成の部分を埋めるのに必要なピースを選ぶというものです。図 1 (a) はパズルの枠の例です。黒が埋まっている部分、白が未完成の部分です。このパズルを完成するのに使えるピースが図 1 (b) のように与えられます。この中から、枠の白い部分を埋めることができる黒いピースを 1 つ以上選択します。例えば、図 2 の選択例 1 のような組み合わせなら正解となります。一方、選択例 2 のような組み合わせではパズルは完成しないので不正解となります。また、選択したピースが余ってしまう場合も不正解です。このように、プレイヤーは適切なピースを選択することでゲームをクリアします。

// そこでこのパズルゲームで用いる判定プログラムを開発することになりました。未完成のパズル、ピースの候補、そしてプレイヤーが選んだピースの組み合わせを入力とし、プレイヤーが適切なピースを選ぶことができていれば YES を、そうでなければ NO と出力するプログラムを作成してください。

// この問題では、パズルの枠は H×W の配列で表し、未完成の部分を . (半角ピリオド)、完成している部分を # (半角シャープ)によって与えます。パズルの枠の大きさは最大 20×20 とします。また、各ピースは h×w の配列で表し、ピースを構成する部分を # 、そうでない部分を . によって与えます。与えられる各ピースは、元の状態から 90 度、180 度、270 度だけ回転することができます。また、各ピースの大きさは最大 20×20 とし、与えられるピースの数 n は最大 10 とします。



// Input
// 複数のデータセットが与えられます。各データセットは以下の形式で与えられます。

// H W
// g1,1g1,2...g1,W
// g2,1g2,2...g2,W
// :
// gH,1gH,2...gH,W
// n
// h1 w1
// c11,1c11,2...c11,w1
// c12,1c12,2...c12,w1
// :
// c1h1,1c1h1,2...c1h1,w1
// :
// :
// hn wn
// cn1,1cn1,2...cn1,wn
// cn2,1cn2,2...cn2,wn
// :
// cnhn,1cnhn,2...cnhn,wn
// p
// k1 t1 t2 ... tk1
// k2 t1 t2 ... tk2
// :
// kp t1 t2 ... tkp
// 1 行目に、パズルの枠の大きさ H(縦) と W(横) が与えられます。 2 行目に、文字 gi,j (. または #) からなりパズルの盤面を表す 1 行 W 文字の文字列が H 行与えられます。

// 続いてピースの数 n、n 個のピースの情報が与えられます。各ピースの情報として、l 番目のピースの配列のサイズ hl (縦) と wl (横)、l 番目のピースの配列が与えられます。l 番目のピースの配列として文字 cli,j (. または #) からなる 1 行 wl 文字の文字列が hl 行与えられます。

// 続いてプレイヤーの人数 p、i 番目のプレイヤーの選択したピースの数 ki と選択したピースの番号 tj が与えられます。

// 入力は２つの 0 を含む行で終了します。データセットの数は 10 を超えません。

// Output
// 各データセットごとに、i 番目のプレイヤーが選択したピースの正否 YES または NO を i 行目に出力してください。

#include <bits/stdc++.h>
using namespace std;

int h,w,n,p,k,S;
bool mz[55][22][22];
int ph[55], pw[55];
bool ok[(1<<11)];

struct Puzzle {
    int s;
    bool maze[22][22];
    Puzzle(bool m[22][22] = {}, int ss = 0) {
        for (int i = 0; i < 22; i++) {
            for (int j = 0; j < 22; j++) {
                maze[i][j] = m[i][j];
            }
        }
        s = ss;
    }
    bool operator < (const Puzzle &p)const{
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (maze[i][j] != p.maze[i][j]) return maze[i][j] < p.maze[i][j];
            }
        }
        return s < p.s;
    }
};

bool maze[22][22];
map<Puzzle,bool> mp;

bool check_piece(int hh, int ww, int id) {
    if (hh + ph[id] > h || ww + pw[id] > w) return 0;
    for (int i = hh; i < hh + ph[id]; i++) {
        for (int j = ww; j < ww + pw[id]; j++) {
            if (mz[id][i-hh][j-ww] && maze[i][j]) return 0;
        }
    }
    return 1;
}

void put_piece(int hh, int ww, int id) {
    for (int i = hh; i < hh + ph[id]; i++) {
        for (int j = ww; j < ww + pw[id]; j++) {
            if (mz[id][i-hh][j-ww]) maze[i][j] = 1;
        }
    }
}

void release_piece(int hh, int ww, int id) {
    for (int i = hh; i < hh + ph[id]; i++) {
        for (int j = ww; j < ww + pw[id]; j++) {
            if (mz[id][i-hh][j-ww]) maze[i][j] = 0;
        }
    }
}

void rtt(int ida, int idb) {
    ph[idb] = pw[ida];
    pw[idb] = ph[ida];
    for (int i = 0; i < ph[ida]; i++) {
        for (int j = 0; j < pw[ida]; j++) {
            mz[idb][j][ph[ida]-i-1] = mz[ida][i][j];
        }
    }
}

void out() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << (maze[i][j]?'#':'.');
        }
        cout << endl;
    }
}

void dfs(int hh, int ww) {
    if (ww == w) {
        ww = 0;
        hh++;
    }
    if (hh == h) return;

    bool f = 1;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (!maze[i][j]) f = 0;
        }
    }
    if (f) {
        // cout << "OK " << bitset<10>(S) << endl;
        ok[S] = 1;
        return;
    }

    mp[Puzzle(maze,S)] = 1;

    // cout << setw(3) << hh;
    // cout << setw(3) << ww;
    // cout << " " << bitset<10>(S) << endl;

    for (int i = 0; i < n; i++) {
        if ((S>>i)&1) continue;
        S += (1 << i);
        for (int rotate = 0; rotate < 4; rotate++) {

            if (check_piece(hh,ww,i+n*rotate)) {
                put_piece(hh,ww,i+n*rotate);
                // cout << "put " << hh << " " << ww << " " << i+rotate*n << endl;
                // out();
                if (!mp[Puzzle(maze,S)]) dfs(hh,ww+1);
                // release piece
                release_piece(hh,ww,i+n*rotate);
                // cout << "release " << hh << " " << ww << " " << i+rotate*n << endl;
                // out();
            }

        }
        S -= (1 << i);
    }
    if (maze[hh][ww]) dfs(hh, ww+1);
}

void init() {
    mp.clear();
    memset(ok,0,sizeof(ok));
}

int main() {
    while (cin >> h >> w) {
        if (h == 0 && w == 0) break;

        init();

        // input OK
        for (int i = 0; i < h; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < w; j++) maze[i][j] = s[j] == '#';
        }

        // rotate OK
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ph[i] >> pw[i];
            for (int hh = 0; hh < ph[i]; hh++) {
                string s;
                cin >> s;
                for (int ww = 0; ww < pw[i]; ww++) {
                    mz[i][hh][ww] = s[ww] == '#';
                }
            }
            rtt(i,i+n);
            rtt(i+n,i+2*n);
            rtt(i+2*n,i+3*n);
        }

        S = 0;
        dfs(0,0);

        cin >> p;
        for (int i = 0; i < p; i++) {
            cin >> k;
            int s = 0;
            for (int j = 0; j < k; j++) {
                int t;
                cin >> t;
                t--;
                s += (1<<t);
            }
            cout << (ok[s]?"YES":"NO") << endl;
        }
    }
    return 0;
}