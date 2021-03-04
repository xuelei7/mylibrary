// Problem J. Prime Routing
// Fox Jiro is one of the staffs of the ACM-ICPC 2018 Asia Yokohama Regional Contest and is responsible for designing the network for the venue of the contest. His network consists of [Math Processing Error] computers, which are connected by [Math Processing Error] cables. The [Math Processing Error]-th cable connects the [Math Processing Error]-th computer and the [Math Processing Error]-th computer, and it carries data in both directions. Your team will use the [Math Processing Error]-th computer in the contest, and a judge server is the [Math Processing Error]-th computer.

// He decided to adjust the routing algorithm of the network to maximize the performance of the contestants through the magical power of prime numbers. In this algorithm, a packet (a unit of data carried by the network) is sent from your computer to the judge server passing through the cables a prime number of times if possible. If it is impossible, the contestants cannot benefit by the magical power of prime numbers. To accomplish this target, a packet is allowed to pass through the same cable multiple times.

// You decided to write a program to calculate the minimum number of times a packet from [Math Processing Error] to [Math Processing Error] needed to pass through the cables. If the number of times a packet passes through the cables cannot be a prime number, print [Math Processing Error].

// Input
// The input consists of a single test case, formatted as follows.

// [Math Processing Error] [Math Processing Error] [Math Processing Error] [Math Processing Error]
// [Math Processing Error] [Math Processing Error]
// [Math Processing Error]
// [Math Processing Error] [Math Processing Error]
// The first line consists of four integers [Math Processing Error] and [Math Processing Error] ([Math Processing Error]). The [Math Processing Error]-th line of the following [Math Processing Error] lines consists of two integers [Math Processing Error] and [Math Processing Error] ([Math Processing Error]), which means the [Math Processing Error]-th cables connects the [Math Processing Error]-th computer and the [Math Processing Error]-th computer in the network. You can assume that the network satisfies the following conditions.

// The network has no multi-edge, i.e.,[Math Processing Error] for all [Math Processing Error] ([Math Processing Error]).
// The packets from [Math Processing Error] computers are reachable to [Math Processing Error] by passing through some number of cables. The number is not necessarily a prime.
// Output
// If there are ways such that the number of times a packet sent from [Math Processing Error] to [Math Processing Error] passes through the cables is a prime number, print the minimum prime number of times in one line. Otherwise, print [Math Processing Error].

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (int)(a); (i) < (int)(b); (i)++)
#define rrep(i, a, b) for (int i = (int)(b) - 1; (i) >= (int)(a); (i)--)
#define all(v) v.begin(), v.end()

typedef long long ll;
template <class T> using V = vector<T>;
template <class T> using VV = vector<V<T>>;

/* 提出時これをコメントアウトする */
#define LOCAL true

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define dbg(x) true
#endif
vector<int> getPrimeList() {
    const int MAXN = 1000000;
    bool isprime[MAXN];
    for (int i = 0; i < MAXN; i++) isprime[i] = 1;
    for (int i = 2; i < MAXN; i++) {
        if (!isprime[i]) continue;
        for (int j = i + i; j < MAXN; j+=i) isprime[j] = 0;
    }
    vector<int> v;
    for (int i = 2; i < MAXN; i++) if (isprime[i]) v.push_back(i);
    return v;
}
auto solve (int n, int m, int s, int t, VV<int>& G) -> int {
    int inf = 1e9;
    VV<int> d(n,V<int>(2,inf));

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,s});
    d[s][0] = 0;

    while (!pq.empty()) {
        auto tp = pq.top(); pq.pop();

        if (d[tp.second][tp.first&1] < tp.first) continue;

        rep(i,0,G[tp.second].size()) {
            auto to = G[tp.second][i];
            auto cost = tp.first + 1;
            if (d[to][cost&1] > cost) {
                d[to][cost&1] = cost;
                pq.push({cost,to});
            }
        }
    }

    auto list = getPrimeList();

    int mi = inf;
    int odd = d[t][1];
    int even = d[t][0];
    if (even == 2) mi = min(mi, even);
    if (odd == 1) mi = min(mi, odd+2);
    else if (odd != inf) mi = min(mi, *(lower_bound(all(list),odd)));
    if (mi == inf) return -1;
    return mi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    // input
    int n,m,s,t;
    cin >> n >> m >> s >> t;
    s--;
    t--;
    VV<int> G(n);
    rep(i,0,m) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        assert(a<n && b < n);
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // solve
    auto ans = solve(n,m,s,t,G);

    // output
    cout << ans << endl;
    
    return 0;
}