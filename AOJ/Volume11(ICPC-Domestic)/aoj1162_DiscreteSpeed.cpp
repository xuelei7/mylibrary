// Problem D: 離散的速度
// 摩擦のない国での自動車旅行を考える． この国の自動車にはエンジンがない． ある速さで動き出したら，その速さをずっと維持する（摩擦がないから）． 道路上の固定設備として加減速装置が設置してあって， ここを通る時に速さを1だけ増やしたり，減らしたりすることができる． 速さを変えないことも可能である． このような世界で，出発地から目的地まで最短の時間で移動するルートを決定するプログラムを書くことがあなたの仕事である．

// この国には複数の都市があり，それらの間を結ぶ道路網が整備されている． 加減速装置はそれぞれの都市に設置してある． 上に述べたとおり，ある都市に速さv で到着した場合，その都市から次の都市に移動する時の速さはv - 1，v ，v + 1 のいずれかである． 出発地を出た直後の道路を走る速さは1に限られる． 同様に目的地に到着する直前の道路を走る速さも1でなければならない．

// 出発地と目的地（それぞれ都市である）が与えられる． いくつかの都市を経由しながら目的地に到達する最善のルートを求めることが問題である． ある都市に到着した直後に，今来たばかりの道路を引き返すことはできない（Uターン禁止）． この制限を除けば，経路の選び方は自由である． 同じ都市や同じ道路を何度も通ってよいし，出発地や目的地を途中で通過してもかまわない．

// 都市と都市を結ぶ道路のそれぞれに対して，その距離と制限速度が与えられる． その道路を走る時の速さは制限速度以下でなければならない． 道路を通り抜ける所要時間は，距離÷速さである． 都市の通過や加減速に要する時間は無視する．

// Input
// 入力は複数のデータセットから構成される． 各データセットの形式は次に示すとおりである．

// n m
// s g
// x 1 y 1 d 1 c 1
// ...
// xm ym dm cm
// データセットの中の入力項目は，すべて非負の整数である． 行中の入力項目の区切りは空白1個である．

// 最初の行は，道路網の大きさを規定する． n は，都市の数である． 2以上30以下と仮定してよい． m は，都市間道路の本数である． 道路の本数が0のこともある．

// 2行目は，実現したい旅行の記述である． s は，出発地の都市番号である． g は，目的地の都市番号である． s はg と等しくない． この二つを含めて，データセット中に現れる都市番号は1以上n 以下と仮定してよい．

// これに続くm 行が都市間道路の記述である． xi とyi が両端の都市番号， di がその道路に沿った距離である（1 ≤ i ≤ m ）． 距離は1以上100以下と仮定してよい． ci は道路の制限速度である． 制限速度は1以上30以下と仮定してよい．

// ある二つの都市を直接結ぶ道路が2本以上存在することはない． 1本の道路の両端が同じ都市であることはない． それぞれの道路は，どちら向きの移動にも使うことができる．

// 最後のデータセットの直後に，空白で区切られた二つのゼロからなる行がある．

// Output
// 入力の各データセットに対して，以下に規定する結果を一つの行として出力しなさい． 出力行の中に，結果を表す文字以外のもの（たとえば空白）が含まれていてはならない．

// 目的地に到達できる場合は，最も所要時間の短いルートを選んだ時の所要時間を出力すること． 答には，0.001を越える誤差があってはいけない． この条件を守る限り，小数点以下に何個の数字を出力してもよい．

// 目的地に到達できない場合は，unreachableと出力すること． unreachableの文字はすべて小文字であることに注意．

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

struct edge {
    int to;
    double len;
    int limit;
    edge(int to=0, double len=0, int limit=0) : to(to), len(len), limit(limit) {}
};

auto solve (int n, int m, int s, int g, VV<edge>& G) -> string {
    double inf = 1e9;
    V<VV<double>> dp(n,VV<double>(n,V<double>(31,inf)));

    struct S {
        double time;
        int id, from;
        double v;
        S(double time=0, int id=0, int from=0, int v=0) : time(time), id(id), from(from), v(v) {}
        bool operator >(const S& other) const {
            if (time != other.time) return time > other.time;
            return id > other.id;
        }
    };

    priority_queue<S,vector<S>,greater<S>> pq;
    pq.push(S(0,s,s,0));
    dp[s][s][0] = 0;
    while (!pq.empty()) {
        auto tp = pq.top(); pq.pop();
#ifdef LOCAL
    cerr << "* " << tp.id << " " << tp.from << " " << tp.v << " " << tp.time << endl;
#endif
        if (dp[tp.id][tp.from][tp.v] < tp.time) continue;

        rep(i,0,G[tp.id].size()) {
            auto e = G[tp.id][i];
            if (e.to == tp.from) continue;

            rep(j,-1,2) {
                int new_v = tp.v + j;
                if (new_v <= 0 || new_v > e.limit) continue;
                double time_add = (double)e.len / (double)new_v;
#ifdef LOCAL
    cerr << e.to << " " << e.limit << " " << new_v << " " << dp[e.to][tp.id][new_v] << " " << tp.time + time_add << endl;
#endif
                if (dp[e.to][tp.id][new_v] > tp.time + time_add) {
                    dp[e.to][tp.id][new_v] = tp.time + time_add;
                    pq.push(S(dp[e.to][tp.id][new_v], e.to, tp.id, new_v));
                }
            }
        }
    }

    // answer
    double ans = inf;
    rep(i,0,G[g].size()) {
        ans = min(ans, dp[g][G[g][i].to][1]);
    }
    if (abs(ans-inf) < 1e-10) return "unreachable";
    else return to_string(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    // input
    int n,m;
    int s,g;
    while (cin >> n >> m >> s >> g) {
        s--; g--;
        VV<edge> G(n);
        rep(i,0,m) {
            int x,y,c;
            double d;
            cin >> x >> y >> d >> c;
            x--;
            y--;
            G[x].push_back(edge(y,d,c));
            G[y].push_back(edge(x,d,c));
        }

        // solve
        auto ans = solve(n,m,s,g,G);

        // output
        cout << ans << endl;
    }
    return 0;
}