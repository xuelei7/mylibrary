// Problem D: 崖登り
// 17:00, 特別捜査官 Jack が敵のキャンプから脱出を開始した． 最寄りの安全地帯に逃れるには，途中にある崖を登る必要がある． その急な崖はブロックで覆われており， Jack はブロックに足を置きながら崖を登ることになる． 表面が滑りやすいブロックに進むには時間をかける必要があり， もろいブロックは体重で崩れてしまうので避ける必要がある． あなたの使命は，崖を登りきるために必要な最短の時間を求めるプログラムを作成することである．

// 図 D-1 は，あなたが受け取るであろう崖に関する地形データの例を図示したものである． 崖は，正方形のブロックで覆われており， Jack の崖登りは， 崖下の地面から， 一番下の段の 'S' とマークされたブロックに片足を置くことで開始される． 最初のステップは，左右のどちらの足であっても良い． ブロックにマークされた数字は，そのブロックの「滑りやすさ」を意味する． t (1 ≤ t ≤ 9) とマークされたブロックに足を安全に置くには， t 単位時間が必要となる． 'X' でマークされたブロックには Jack は足を置くことはできない． どちらかの足が，最上段の 'T' とマークされたブロックに到着した時点で崖登り完了で ある．


// 図 D-1: 崖に関するデータの例
// Jack は，崖登りにおいて以下の制約をうける． 左足を動かした次は右足を，右足を動かした次は左足を動かすこと． 左足の座標 (lx, ly)と 右足の座標 (rx, ry) に関し， lx < rx 及び | lx - rx | + | ly - ry | ≤ 3 が成り立つこと． つまり，左足が図 D-2 (a) の位置にある場合は， 青色で示された9つの位置にしか右足を置くことができない． 同様に，右足が図 D-2 (b) の位置にある場合も， 青色で示された9つの位置にしか左足を置くことができない．


// 図 D-2: 可能な足の配置
// Input
// 入力は，複数のデータセットからなり， 入力の終わりはスペースで区切られたゼロ二つからなる行である． 各データセットは，次の形式をしている．

// w h
// s(1,1) ... s(1,w)
// s(2,1) ... s(2,w)
// ...
// s(h,1) ... s(h,w)
// w と h は，それぞれ崖を表現する行列データの幅と高さを示す整数であり， それぞれ2 ≤ w ≤ 30, 5 ≤ h ≤ 60 と仮定して良い． 続く h 行はそれぞれ，スペースで区切られた w 個の文字から構成されており， 文字s(y,x) は，座標 (x, y)のブロックの状態を示す． その意味は，以下の通り：

// 'S': Jack が崖登りを開始可能なブロック．
// 'T': Jack が崖登りを終了可能なブロック．
// 'X': Jack が足を置くことができないブロック．
// '1'-'9' (= t): Jack がどちらかの足を置く際に， t 単位時間を必要とするブロック．
// 'S' や 'T' でマークされたブロックに足を置くための時間は，0 と考えてよい．

// Output
// 各データセットについて，崖登りに必要な最小時間を求め， 十進の整数値として，それぞれ1行に出力しなさい． 崖登りを完了できない場合は，代わりに -1 のみを含む行を出力しなさい． 各出力行はこれらの数値以外の文字を含んではならない．

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
    int inf = 1e9;
    V<VV<int>> dp(h,VV<int>(w,V<int>(2,inf)));

    struct S{
        int h,w,foot,dist;
        S(int h, int w, int foot, int dist) : h(h),w(w),foot(foot),dist(dist) {}
        bool operator <(const S& other) const {
            if (dist != other.dist) return dist < other.dist;
            if (h != other.h) return h < other.h;
            if (w != other.w) return w < other.w;
            return foot < other.foot;
        }
        bool operator >(const S& other) const {
            if (dist != other.dist) return dist > other.dist;
            if (h != other.h) return h > other.h;
            if (w != other.w) return w > other.w;
            return foot > other.foot;
        }
    };

    priority_queue<S,vector<S>,greater<S>> pq;
    
    // set start
    V<int> sh,sw,gh,gw;
    rep(i,0,h) rep(j,0,w) {
        if (maze[i][j] == 'S') {
            sh.push_back(i);
            sw.push_back(j);

            // begin point
            pq.push(S(i,j,0,0));
            pq.push(S(i,j,1,0));
            dp[i][j][0] = 0;
            dp[i][j][1] = 0;
        }
        if (maze[i][j] == 'T') {
            gh.push_back(i);
            gw.push_back(j);
        }
    }

    while (!pq.empty()) {
        auto tp = pq.top(); pq.pop();

        if (dp[tp.h][tp.w][tp.foot] < tp.dist) continue;
#ifdef LOCAL
    cerr << "search: " << tp.h << " " << tp.w << " " << tp.foot << " " << tp.dist << endl;
#endif
        int hh = tp.h;
        int ww = tp.w + (tp.foot?-1:1);
        rep(i,-2,3) {
            rep(j,-2,3) {
                if (abs(i) + abs(j) > 2) continue;
                int th = hh + i;
                int tw = ww + j;
                if (th < 0 || th >= h || tw < 0 || tw >= w) continue;
                if (maze[th][tw] == 'X') continue;

                int tf = (tp.foot?0:1); // next foot

                if (tf == 0) { // left <- right
                    if (j > 0) continue;
                }
                else { // left -> right
                    if (j < 0) continue;
                }

                if (maze[th][tw] == 'T') {
                    dp[th][tw][tf] = min(dp[th][tw][tf], tp.dist);
                    continue;
                }
                int cost = maze[th][tw] - '0';
                if (dp[th][tw][tf] > tp.dist + cost) {
                    dp[th][tw][tf] = tp.dist + cost;
#ifdef LOCAL
    cerr << "renew: " << th << " " << tw << " " << tf << " " << tp.dist + cost << endl;
#endif
                    pq.push(S(th,tw,tf,dp[th][tw][tf]));
                }
            }
        }

    }

#ifdef LOCAL
    rep(i,0,h) {
        rep(j,0,w) {
            rep(k,0,2) {
                if (dp[i][j][k] == inf) cerr << "inf";
                else cerr << dp[i][j][k];
                cerr << ", "[k==1];
            }
        }
        cerr << endl;
    }
#endif

    // result
    int mi = inf;
    rep(i,0,gh.size()) {
        rep(j,0,2) {
            mi = min(mi, dp[gh[i]][gw[i]][j]);
        }
    }
    if (mi == inf) return -1;
    else return mi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    // input
    int w,h;
    while (cin >> w >> h) {
    if (w+h == 0) break;
    VV<char> maze(h,V<char>(w));
    rep(i,0,h) rep(j,0,w) cin >> maze[i][j];

    // solve
    auto ans = solve(w,h,maze);

    // output
    cout << ans << endl;
    }
    
    return 0;
}