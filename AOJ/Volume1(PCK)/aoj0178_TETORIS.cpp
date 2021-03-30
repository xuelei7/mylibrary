// テトリス
// テトリスは、落ちてくるブロックを盤面上に並べて消すゲームです。ここでは、それを少しアレンジしたゲームを考えましょう。

// このゲームの盤面の大きさは横 5 コマで、出現するブロックがすべて入るだけの高さがあります。落ちてくるブロックは直線状で、横向き、縦向きの 2 種類があり、長さは 1 から 5 までの 5 種類です。

// 以下に例を示します。Step(イ) からStep(ホ)までの図はブロックが落ちて消えていく様子を表したものです。 Step(イ)から順にStep(ロ)、Step(ハ)と順に進んでいきます。

// ブロックを落とすときに、Step(イ)のようにブロックのどこかが下に積んであるブロックに引っかかったときには、Step(ロ)のように落ちたブロックはその場所で止まります。また、ブロックを落とした結果、盤面の横一行の全てのコマにブロックが詰まった場合には、Step(ニ)で示されるように、その行のブロックが消えます。この後、消えた行の上にあるブロックが、そのままの形で1行下にしずみます(Step(ホ))。



// 1 ゲームは 1000 個以内のブロックが順に落ちてくることとします。例えば、落ちるブロックの長さが順番に横向き 4 コマ, 横向き 3 コマ, 縦向き 2 コマ, 縦向き 3 コマで、落ちる場所が左端から 1 コマ目、1 コマ目、4 コマ目、5 コマ目であった場合には、下図のStep(イ)~(ト)のように落ち、最後に残るブロックは 2 コマになります。



// 順番に落ちてくるブロックの情報を入力とし、全てのブロックが落ちた時に残るコマ数を出力するプログラムを作成してください。

// Input
// 複数のデータセットの並びが入力として与えられます。入力の終わりはゼロひとつの行で示されます。各データセットは以下の形式で与えられます。

// n
// d1 p1 q1
// d2 p2 q2
// :
// dn pn qn
// １行目にブロックの数 n (1 ≤ n ≤ 1000) が与えられます。続く n 行に i 個目のブロックの向き di (1 または2)、ブロックの長さ pi (1 ≤ pi ≤ 5)、ブロックの位置 qi が与えられます。ブロックの向き di は 1 が横向きを、2 が縦向きを表します。ブロックの位置 qi は盤面上の左端から1 ~ 5 までの整数とし、横向きのブロックの場合は左端のコマの落ちる位置とします。

// データセットの数は 20 を超えません。

// Output
// データセット毎に最後に残るブロックの占めるコマ数を１行に出力します。

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (int)(a); (i) < (int)(b); (i)++)
#define rrep(i, a, b) for (int i = (int)(b) - 1; (i) >= (int)(a); (i)--)
#define all(v) v.begin(), v.end()

typedef long long ll;
template <class T> using V = vector<T>;
template <class T> using VV = vector<V<T>>;

/* 提出時これをコメントアウトする */
// #define LOCAL true

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define dbg(x) true
#endif

struct tetoris {
    int p,q,d,h,w;
    tetoris(int p=0, int q=0, int d=0) : p(p), q(q), d(d) {}
};

auto solve (int n, V<tetoris>& v) -> int {
    VV<bool> maze(5000, V<bool>(5));
    int mxh[5] = {};

    auto go = [&](tetoris t) {
        int h = 0;
        int w = t.q;
        
        // 下にどこまで行けるかを調べる
        rep(i,0,t.w) {
            h = max(h, mxh[w + i]);
        }

        // ピースを置く
        rep(i,0,t.w) {
            rep(j,0,t.h) {
                maze[h+j][w+i] = 1;
            }
        }
#ifdef LOCAL
        rep(i,0,5) {
            rep(j,0,5) {
                cerr << maze[j][i];
            }
            cerr << endl;
        }
        cerr << "-----" << endl;
#endif

        // 行を消す
        rrep(i,0,t.h) {
            int cnt = 0;
            rep(j,0,5) {
                cnt += maze[h+i][j];
            }
            if (cnt != 5) continue;
            // block fall
            int hh = h+i;
            while (1) {
                cnt = 0;
                rep(j,0,5) {
                    cnt += maze[hh+1][j];
                    maze[hh][j] = maze[hh+1][j];
                }
                if (cnt == 0) break;
                hh++;

            }
        }
        memset(mxh,0,sizeof(mxh));
        rep(i,0,5000) {
            rep(j,0,5) {
                if (maze[i][j]) {
                    mxh[j] = i+1;
                }
            }
        }
#ifdef LOCAL
        rep(i,0,5) {
            rep(j,0,10) {
                cerr << maze[j][i];
            }
            cerr << endl;
        }
        cerr << "-----" << endl;
#endif

    };

    rep(i,0,n) {
        go(v[i]);
    }

    int ret = 0;
    rep(i,0,5000) {
        int cnt = 0;
        rep(j,0,5) {
            cnt += maze[i][j];
        }
        if (cnt != 5) ret += cnt;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int n;
    while (cin >> n) {
        if (n == 0) break;
        V<tetoris> v(n);
        rep(i,0,n) {
            cin >> v[i].d >> v[i].p >> v[i].q;
            v[i].q--;
            if (v[i].d == 1) {
                v[i].h = 1;
                v[i].w = v[i].p;
            } else {
                v[i].h = v[i].p;
                v[i].w = 1;
            }
        }
        cout << solve(n,v) << endl;
    }
    
    return 0;
}