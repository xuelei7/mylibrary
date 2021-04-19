// Problem D: Traveling by Stagecoach
// 昔，昔のことである． 一人の旅人がいた． 彼は，馬車（駅馬車）を使っての旅行を計画している． 出発地と目的地は決まっているのだが，ルートが決まらなくて困っている． 彼のためにルートを決定するプログラムを書くことがあなたの仕事である．

// この国には複数の都市があり，それらの間を結ぶ道路網が整備されている． 道路で直結されている二つの都市の間は，馬車で移動することができる． 馬車に乗るには，馬車券が必要である． それぞれの馬車券には，馬の頭数が指定されている． 当然ながら，頭数の多い馬車ほど速い．

// 旅人は，出発時に何枚かの馬車券を持っている． 道路網と手持ちの馬車券に関する情報から， どのようなルートを選べば最も早く目的地に着けるかを求めたい． この際，馬車券をどう使えばよいかも考える必要がある．

// 次のような条件を仮定する．

// 1台の馬車で移動できるのは，1区間（道路で直結された都市間）だけである． すなわち，都市に到着するたびに馬車を乗り換えなければならない．
// 1区間に使える馬車券は1枚だけである．
// 1枚の馬車券は一度しか使えない．
// 都市間の所要時間は，距離を頭数で割った値である．
// 乗り換えに要する時間は無視する．
// Input
// 入力は複数のデータセットから構成される． 各データセットの形式は次に示すとおりである． 最後のデータセットの直後に，空白で区切られた五つの0からなる行がある．

// n m p a b
// t1 t2 ... tn
// x1 y1 z1
// x2 y2 z2
// ...
// xp yp zp
// データセットの中の入力項目は，すべて非負の整数である． 1行の中に二つ以上の入力項目がある場合の区切りは空白1個である．

// nは，馬車券の枚数である． 1以上8以下と仮定してよい． mは，都市の数である． 2以上30以下と仮定してよい． pは，都市間道路の本数である． 道路の本数が0のこともある．

// aは，出発地の都市番号である． bは，目的地の都市番号である． aはbと等しくない． この二つを含めて，データセット中に現れる都市番号は1以上m以下と仮定してよい．

// データセットの2行目は，出発時に持っている馬車券それぞれに関する情報を表す． tiは，i番目の馬車券（1<=i<=n） に指定された頭数である． 頭数は1以上10以下であると仮定してよい．

// これに続くp行が都市間道路の記述である． xiとyiが両端の都市番号， ziがその道路に沿った距離である（1<=i<=p）． 距離は1以上100以下と仮定してよい．

// ある二つの都市を結ぶ道路が2本以上存在することはない． 1本の道路の両端が同じ都市であることはない． それぞれの道路は，どちら向きの移動にも使うことができる．

// Output
// 入力の各データセットに対して，以下に規定する結果を一つの行として出力しなさい． 出力行の中に，結果を表す文字以外のもの（たとえば空白）が含まれていてはならない．

// 目的地に到達できる場合は， 最も所要時間の短いルートを選んだ時の所要時間を出力すること． 答には，0.001を越える誤差があってはいけない． この条件を守る限り，小数点以下に何個の数字を出力してもよい．

// 目的地に到達できない場合は，Impossibleと出力すること． これに該当するのは， 到達できるルートが存在しない場合と馬車券の枚数が足りない場合である． Impossibleは，最初の文字が大文字，ほかが小文字であることに注意．

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

auto solve (int n, int m, int p, int a, int b, V<int>& t, VV<pair<int,int>>& G) -> string {
    double inf = 1e9;
    VV<double> dp(m,V<double>(1<<n,inf));

    struct status {
        int id, s;
        double dist;
        status(int id, int s, double dist):id(id),s(s),dist(dist) {}
        bool operator <(const status& other) const {
            if (dist != other.dist) return dist < other.dist;
            if (id != other.id) return id < other.id;
            else return s < other.s;
        }
        bool operator >(const status& other) const {
            if (dist != other.dist) return dist > other.dist;
            if (id != other.id) return id > other.id;
            else return s > other.s;
        }
    };

    dp[a][0] = 0;
    priority_queue<status,vector<status>,greater<status>> pq;
    pq.push(status(a,0,0));

    while (!pq.empty()) {
        auto tp = pq.top(); pq.pop();
        if (dp[tp.id][tp.s] > tp.dist) continue;

#ifdef LOCAL
    cerr << tp.id << " " << bitset<8>(tp.s) << " " << tp.dist << endl;
#endif
        rep(i,0,G[tp.id].size()) {
            int to = G[tp.id][i].first;
            double length = G[tp.id][i].second;

            // 馬券ごと
            rep(j,0,n) {
                if ((tp.s >> j) & 1) continue; // used
                int ts = tp.s + (1<<j);
                double time = length / (double)t[j];
                if (dp[to][ts] > tp.dist + time) {
                    dp[to][ts] = tp.dist + time;
                    pq.push(status(to,ts,dp[to][ts]));
                }
            }
        }
    }

    double mi = inf;
    rep(i,0,(1<<n)) {
        mi = min(mi, dp[b][i]);
    }

    if (mi == inf) return "Impossible";
    else return to_string(mi);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    // input
    int n,m,p,a,b;
    while (cin >> n >> m >> p >> a >> b) {
        if (n+m+p+a+b == 0) break;
        a--; b--;
        V<int> t(n);
        rep(i,0,n) cin >> t[i];
        VV<pair<int,int>> G(m);
        rep(i,0,p) {
            int x,y,z;
            cin >> x >> y >> z;
            x--; y--;
            G[x].push_back({y,z});
            G[y].push_back({x,z});
        }

        // solve
        auto ans = solve(n,m,p,a,b,t,G);

        // output
        cout << ans << endl;
    }
    return 0;
}