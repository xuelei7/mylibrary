// Problem F: Cleaning Robot
// 家具が複数配置された長方形の部屋の床を掃除するロボットの経路計画を 行いたい．

// 掃除する床をロボットの大きさ（1 × 1）で分割したタイル平面を考える． そこには「きれいなタイル」と「汚れたタイル」があり，掃除ロボットが 「汚れたタイル」に乗ることで，きれいなタイルにすることができる． 部屋のいくつかのタイルには障害物（家具）が乗っており，ロボットはそれらのタイルに入ることはできない． ロボットは1回の移動で東西南北に1タイルのみ移動できる． ロボットは同じタイルに2回以上行ってもよい．

// このとき部屋の「汚れたタイル」すべてを「きれいなタイル」にすることが 可能ならば，それに必要な最少移動回数を求めよ．

// Input
// 入力は部屋サイズと構成を表した複数のマップからなる．各マップの 形式は以下のとおりである．

// w h
// c11 c12 c13 ... c1w
// c21 c22 c23 ... c2w
// ...
// ch1 ch2 ch3 ... chw
// wとhは正の整数で，それぞれマップの横幅タイル数，縦幅 タイル数を表す． wとhは最大でも20以下である． 文字cyx は以下のように座標 (x, y) の位置 の状態を表す．

// '.' : きれいなタイル
// '*' : 汚れたタイル
// 'x' : 家具（障害物）
// 'o' : ロボット（初期位置を表す）
// マップには1つのロボットと最大10個の汚れたタイルを含む．

// 入力の終わりは，0 0 で表される．

// Output
// それぞれのマップについて，掃除ロボットの最少移動回数を出力しなさい． もしロボットが到達できない「汚れたタイル」がある場合は，-1を出力し なさい．

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

auto solve (int w, int h, VV<char>& maze) -> int {
    // 汚れ間の距離を計算
    int inf = 1e9;
    VV<int> dp(h*w,V<int>(h*w,inf));

    // 経路構築
    rep(i,0,h) rep(j,0,w) { // p1
        if (maze[i][j] == 'x') continue;
        rep(ii,0,h) rep(jj,0,w) { // p2
            if (maze[ii][jj] == 'x') continue;

            // 同じ点
            if (i == ii && j == jj) {
                dp[i*w+j][ii*w+jj] = 0;
            }
            // 隣接する点
            if (abs(ii-i) + abs(jj-j) == 1) {
                dp[i*w+j][ii*w+jj] = 1;
            }
        }
    }

// #ifdef LOCAL
//     rep(i,0,h*w) {
//         rep(j,0,h*w) {
//             if (dp[i][j] == inf) cerr << "inf";
//             else cerr << dp[i][j];
//             cerr << " ";
//         }
//         cerr << endl;
//     }
// #endif
    // 距離計算
    for (int k = 0; k < h*w; k++) {
        for (int i = 0; i < h*w; i++) {
            for (int j = 0; j < h*w; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    // 汚れを見つける
    V<int> hh, ww;
    int sh,sw;
    rep(i,0,h) rep(j,0,w) {
        if (maze[i][j] == '*') {
            hh.push_back(i);
            ww.push_back(j);
        }
        if (maze[i][j] == 'o') {
            sh = i;
            sw = j;
        }
    }

    // 到着可能かを見る
    rep(i,0,hh.size()) {
        if (dp[sh*w+sw][hh[i]*w+ww[i]] == inf) return -1;
    }

    // BitDPで最小経路を計算
    int n = hh.size();
    VV<int> d(1<<n,V<int>(n,inf));

    struct S{
        int id,s,dist;
        S(int id=0, int s=0, int dist=0) : id(id),s(s),dist(dist) {}
        bool operator <(const S& other) const {
            if (dist != other.dist) return dist < other.dist;
            if (id != other.id) return id < other.id;
            return s < other.s;
        }
        bool operator >(const S& other) const {
            if (dist != other.dist) return dist > other.dist;
            if (id != other.id) return id > other.id;
            return s > other.s;
        }
    };
    
    priority_queue<S,vector<S>,greater<S>> pq;
    // 始点
    rep(i,0,n) {
        d[1<<i][i] = dp[sh*w+sw][hh[i]*w+ww[i]];
        pq.push(S(i,1<<i,d[1<<i][i]));
    }

    while (!pq.empty()) {
        auto tp = pq.top(); pq.pop();
        if (d[tp.s][tp.id] < tp.dist) continue;
        
        int tph = hh[tp.id];
        int tpw = ww[tp.id];

        rep(i,0,n) {
            if ((tp.s>>i)&1) continue; // cleaned point
            int th = hh[i];
            int tw = ww[i];
            int cost = dp[tph*w+tpw][th*w+tw];
            if (d[tp.s + (1<<i)][i] > tp.dist + cost) {
                d[tp.s + (1<<i)][i] = tp.dist + cost;
                pq.push(S(i,tp.s+(1<<i),tp.dist+cost));
            }
        }
    }

    // 結果
    int mi = inf;
    rep(i,0,n) mi = min(mi, d[(1<<n)-1][i]);
    return mi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    // input
    int w,h;
    while (cin >> w >> h) {
        if (w + h == 0) break;
        VV<char> maze(h,V<char>(w));
        rep(i,0,h) rep(j,0,w) cin >> maze[i][j];

        // solve
        auto ans = solve(w,h,maze);

        // output
        cout << ans << endl;
    }
    return 0;
}