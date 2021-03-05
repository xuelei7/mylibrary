// Problem D: ちょろちょろロボット
// ロボットを使ったゲームをしよう． ロボットが 1 台，マス目状に区切られた長方形の盤面上に置かれている（図 D-1）． ロボットは，最初北西隅にあるスタート地点のマスに東方向を向いて配置されている． ゲームの目的は，ロボットを南東隅にあるゴールのマスまで誘導することである．



// 図 D-1: 盤面の例
// ロボットは，次の 5 種類の命令を実行することができる．

// 「直進 (Straight)」:
// 現在の進行方向のまま，次のマスに前進する．
// 「右折 (Right)」:
// 進行方向を 90 度右に変えて，次のマスに前進する．
// 「反転 (Back)」:
// 進行方向を 180 度変えて，次のマスに前進する．
// 「左折 (Left)」:
// 進行方向を 90 度左に変えて，次のマスに前進する．
// 「停止 (Halt)」:
// 現在のマスで止まって，ゲームを終了する．
// 各マスには，上述の命令のいずれかが割り当てられている（例：図 D-2）． 代わりに実行すべき別の命令をプレイヤーが与えない限り， ロボットは，現在いるマスの命令を実行する． プレイヤーが明示的に命令を与える際は，その都度， 命令の種類に応じたコストを支払う必要がある．



// 図 D-2: 各マスに割り当てられた命令の例
// ロボットは，同じ場所を何度も訪れることが許されている． 一方で，ロボットが盤面外に前進するような命令を実行した場合や， ゴールに着く前に停止命令を実行した場合は，失格となる．

// あなたの仕事は， ロボットをスタート地点からゴール地点に誘導するために必要な最小コストを求めるプログラムを書くことである．

// Input
// 入力は，複数のデータセットからなり， 入力の終わりはスペースで区切られたゼロ 2 つからなる行である． 各データセットは，次の形式をしている．

// w h
// s(1,1) ... s(1,w)
// s(2,1) ... s(2,w)
// ...
// s(h,1) ... s(h,w)
// c0 c1 c2 c3
// h と w は，それぞれ盤面の行および列の数を示す整数であり， 2 ≤ h ≤ 30, 2 ≤ w ≤ 30 と仮定してよい． 続く h 行はそれぞれ，スペースで区切られた w 個の文字から構成されており， 文字 s(i, j) は， i 行 j 列目に位置するマスに割り当てられた命令を示す． その意味は，以下の通り．

// 0: 「直進」命令
// 1: 「右折」命令
// 2: 「反転」命令
// 3: 「左折」命令
// 4: 「停止」命令
// ゴールのマス目には，「停止」命令が割り当てられているが， 他のマス目にも「停止」命令が割り当てられていることがあるので，注意せよ．

// データセットの最後の行は，スペースで区切られた c0, c1, c2, c3 の 4 つの整数値を含んでおり， それぞれ，「直進」，「右折」，「反転」，「左折」命令を与える際に， プレイヤーが支払うべきコストを示している． プレイヤーが「停止」命令を与えることはできない． また， c0, c1, c2, c3 の値は， 1 以上 9 以下と仮定してよい．

// Output
// 各データセットについて，ロボットをゴールに誘導するために必要な最小コストを求め， 十進数の整数としてそれぞれ 1 行に出力しなさい． 出力行には他の文字があってはならない．

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

auto solve (int w, int h, VV<int>& maze, V<int>& cost) -> int {
    int inf = 1e9;
    VV<V<int>> dp(h,VV<int>(w,V<int>(4,inf)));
    int dh[4] = {-1,0,1,0};
    int dw[4] = {0,1,0,-1};

    struct status {
        int h, w, d, dist;
        status(int h=0, int w=0, int d=0, int dist=0):h(h),w(w),d(d),dist(dist) {}
        bool operator <(const status& other) const {
            if (dist != other.dist) return dist < other.dist;
            if (h != other.h) return h < other.h;
            if (w != other.w) return w < other.w;
            return d < other.d;
        }
        bool operator >(const status& other) const {
            if (dist != other.dist) return dist > other.dist;
            if (h != other.h) return h > other.h;
            if (w != other.w) return w > other.w;
            return d > other.d;
        }
    };

    priority_queue<status,vector<status>,greater<status>> q;
    q.push(status(0,0,1,0));
    dp[0][0][1] = 0;
    while (!q.empty()) {
        auto tp = q.top(); q.pop();
        if (tp.h == h-1 && tp.w == w-1) continue;
        if (dp[tp.h][tp.w][tp.d] > tp.dist) continue;
#ifdef LOCAL
    cerr << tp.h << " " << tp.w << " " << tp.d << " " << tp.dist << endl;
#endif
        rep(i,0,4) {
            int c = cost[i];
            int d = (tp.d + i) % 4;
            if (i == maze[tp.h][tp.w]) c = 0;

            int th = tp.h + dh[d];
            int tw = tp.w + dw[d];
            if (th < 0 || th >= h || tw < 0 || tw >= w) continue;
            if (dp[th][tw][d] > dp[tp.h][tp.w][tp.d] + c) {
                dp[th][tw][d] = dp[tp.h][tp.w][tp.d] + c;
                q.push(status(th,tw,d,dp[th][tw][d]));
            }
        }
    }

#ifdef LOCAL
    rep(i,0,h) {
        rep(j,0,w) {
            rep(k,0,4) {
                if (dp[i][j][k] == inf) cerr << "inf,";
                else cerr << dp[i][j][k] << ",";
            }
            cerr << "  ";
        }
        cerr << endl;
    }
#endif

    int mi = inf;
    rep(i,0,4) mi = min(mi, dp[h-1][w-1][i]);
    return mi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    // input
    int w,h;
    while (cin >> w >> h) {
        if (w == 0 && h == 0) break;
        VV<int> maze(h,V<int>(w));
        rep(i,0,h) {
            rep(j,0,w) {
                cin >> maze[i][j];
            }
        }
        V<int> cost(4);
        rep(i,0,4) cin >> cost[i];
        // solve
        auto ans = solve(w,h,maze,cost);

        // output
        cout << ans << endl;
    }
    return 0;
}