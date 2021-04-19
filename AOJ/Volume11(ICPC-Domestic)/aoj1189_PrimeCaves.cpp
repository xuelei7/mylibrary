// 素数洞穴
// 砂漠の中の巨大な崖の中腹に，石窟寺院が残されているのを国際調査隊が発見しました．垂直にそびえ立つ崖のちょうど真ん中あたりに，無数の洞穴が縦横にきれいに並んでおり，それぞれの中に仏像が残されていたのです．さらにすごいことに，いくつかの洞穴には仏教の教典が隠されていました．千年以上も前に書かれたと見られる教典の価値は，それこそ計り知れません．

// 調査隊の隊長は，できるだけ多くの教典を持ち帰ることを決めました．ただ，洞穴は崖の中ほどにあるため，簡単には入れません．唯一の方法は，あなたの体をヘリコプターで吊るして1つの洞穴に入って調査をし，その洞穴から縄を使ってすぐ下にある3つの洞穴(直下の洞穴か，直下の洞穴の右または左に隣り合う洞穴)のどれかに降りるということを繰り返して降りてくるというものです．最後の洞穴からは長い縄を使って地面に降りることができます．

// 一度に何個かの洞穴を調査できるとは言うものの，どの洞穴を調査すればよいのでしょうか? そんな折，数学者のメンバーが予備調査の結果から教典が隠された洞穴にはある規則性があることを見つけました．彼によれば(1)洞穴には，中央のものに1番，そこから図D-1のように外向きに渦を巻くように番号を付けると，(2)教典が隠されているのは図中丸で囲まれているような素数番目の洞穴(以降素数洞穴と呼びます)に他ならない，というのです．次回からはあなたが最初の洞穴に入ったら，素数洞穴を最も多く調査するように降りてくることができるでしょう．



// 図D-1: 洞穴の番号と素数洞穴
// 洞穴の総数と最初に入る洞穴の番号が与えられたときに，素数洞穴をできるだけ多く調査できる降下経路を見つけるプログラムを作ってください．

// Input
// 入力は複数のデータセットからなる．1つのデータセットは整数 m (1 ≤ m ≤ 106)と n (1 ≤ n ≤ m)を空白で区切った1行である．m は洞穴の総数を表し，n は最初に入る洞穴の番号を表す．最後のデータセットの次の行には2つのゼロが書かれている．

// Output
// 各データセットについて，洞穴 n から始めて，最も多く素数洞穴を調査する経路について，素数洞穴の個数と経路上最後に通過した素数洞穴の番号を空白で区切って1行に出力せよ．ただし最初に入る洞穴nも経路上の洞穴に含める．最も多くの素数洞穴を調査する経路が複数ある場合は，最後に通過した素数洞穴の番号が最も大きい経路について出力せよ．素数洞穴を調査する経路が1つもない場合には"0 0"を(引用符を除いて)出力せよ．

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
vector<bool> getPrimeList() {
    const int MAXN = 1000010;
    vector<bool> isprime(MAXN);
    for (int i = 0; i < MAXN; i++) isprime[i] = 1;
    for (int i = 2; i < MAXN; i++) {
        if (!isprime[i]) continue;
        for (int j = i + i; j < MAXN; j+=i) isprime[j] = 0;
    }
    isprime[0] = isprime[1] = 0;
    return isprime;
}
struct P {
    int y, x;
    P(int y=0, int x=0):y(y),x(x){}
    bool operator <(const P& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};
VV<int> maze(3000,V<int>(3000));
V<int> x(2000010), y(2000010);
V<bool> primeList;

auto solve (int m, int n) -> string {
    // 初期メンバー
    V<int> dp(m+1,0);
    V<int> rec(m+1,0);
    V<bool> used(m+1,0);
    dp[n] = primeList[n];
    used[n] = 1;
    if (primeList[n]) rec[n] = n;

    int mx = dp[n];
    int last = rec[n];

    // bfs
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
        auto tp = q.front(); q.pop();
#ifdef LOCAL
    dbg(tp);
    cerr << y[tp] << " " << x[tp] << endl;
    cerr << dp[tp] << " " << rec[tp] << endl;
#endif
        auto go = [&](int k) -> void {
            if (k > m) return;
            if (primeList[k]) {
                dp[k] = max(dp[k], dp[tp] + 1);
                rec[k] = k;
            } else {
                if (dp[tp] > dp[k]) {
                    dp[k] = dp[tp];
                    rec[k] = rec[tp];
                }
            }
            if (dp[k] > mx) {
                mx = dp[k];
                last = rec[k];
            } else if (dp[k] == mx) {
                last = max(last, rec[k]);
            }
            if (!used[k]) {
                q.push(k);
                used[k] = 1;
            }
        };

        rep(i,-1,2) go(maze[y[tp]+1][x[tp]+i]);
    }

    // answer
    return to_string(mx) + " " + to_string(last);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';

    // prepare map
    {
        int h = 1500, w = 1500;
        x[1] = w;
        y[1] = h;
        maze[h][w] = 1;
        int id = 1;
        int length = 0;
        bool flg = 1;
        int d = 1;
        int dh[4] = {-1,0,1,0};
        int dw[4] = {0,1,0,-1};
        
        while (id < 2e6) {
            // 直線の長さを管理
            if (!flg) {
                flg = 1;
            } else {
                flg = 0;
                length++;
            }

            rep(i,0,length) {
                id++;
                if (id >= 2e6) break;
                h += dh[d];
                w += dw[d];
                maze[h][w] = id;
                x[id] = w;
                y[id] = h;
            }

            // 方向の管理
            d = (d + 3) % 4;         
        }
    }

    // prepare prime list
    primeList = getPrimeList();

    // input
    int n,m;
    while (cin >> m >> n) {
        if (m+n == 0) break;

        // solve
        auto ans = solve(m,n);

        // output
        cout << ans << endl;
    }
    
    return 0;
}