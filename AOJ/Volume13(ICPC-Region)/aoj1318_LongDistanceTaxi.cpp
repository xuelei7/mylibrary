// Problem D: Long Distance Taxi
// A taxi driver, Nakamura, was so delighted because he got a passenger who wanted to go to a city thousands of kilometers away. However, he had a problem. As you may know, most taxis in Japan run on liquefied petroleum gas (LPG) because it is cheaper than gasoline. There are more than 50,000 gas stations in the country, but less than one percent of them sell LPG. Although the LPG tank of his car was full, the tank capacity is limited and his car runs 10 kilometer per liter, so he may not be able to get to the destination without filling the tank on the way. He knew all the locations of LPG stations. Your task is to write a program that finds the best way from the current location to the destination without running out of gas.

// Input
// The input consists of several datasets, and each dataset is in the following format.

// N M cap
// src dest
// c1,1 c1,2 d1
// c2,1 c2,2 d2
// .
// .
// .
// cN,1 cN,2 dN
// s1
// s2
// .
// .
// .
// sM

// The first line of a dataset contains three integers (N, M, cap), where N is the number of roads (1 ≤ N ≤ 3000),M is the number of LPG stations (1≤ M ≤ 300), and cap is the tank capacity (1 ≤ cap ≤ 200) in liter. The next line contains the name of the current city (src) and the name of the destination city (dest). The destination city is always different from the current city. The following N lines describe roads that connect cities. The road i (1 ≤ i ≤ N) connects two different cities ci,1 and ci,2 with an integer distance di (0 < di ≤ 2000) in kilometer, and he can go from either city to the other. You can assume that no two different roads connect the same pair of cities. The columns are separated by a single space. The next M lines (s1,s2,...,sM) indicate the names of the cities with LPG station. You can assume that a city with LPG station has at least one road.

// The name of a city has no more than 15 characters. Only English alphabet ('A' to 'Z' and 'a' to 'z', case sensitive) is allowed for the name.

// A line with three zeros terminates the input.

// Output
// For each dataset, output a line containing the length (in kilometer) of the shortest possible journey from the current city to the destination city. If Nakamura cannot reach the destination, output "-1" (without quotation marks). You must not output any other characters. The actual tank capacity is usually a little bit larger than that on the specification sheet, so you can assume that he can reach a city even when the remaining amount of the gas becomes exactly zero. In addition, you can always fill the tank at the destination so you do not have to worry about the return trip.

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

auto solve (int n, int Cap, int f, int t, VV<pair<int,int>>& G, V<bool>& lpg) -> int {

    /*
        n:    ノードの数 (3000以下)
        cap:  給油せず最大移動距離 (2000以下)
        f, t: 始点，終点のid
        G:    グラフ
        lpg:  給油できる駅のid
    */
    
    struct S{
        int id, dist, cap;
        S(){}
        S(int id, int dist, int cap): id(id), dist(dist), cap(cap) {}
        bool operator > (const S& other) const {
            return dist > other.dist;
        }
    };

    VV<int> dp(n, V<int>(Cap+1,1e9));
    priority_queue<S,vector<S>,greater<S>> pq;
    dp[f][Cap] = 0;
    pq.push(S(f,0,Cap));

    while (!pq.empty()) {
        auto tp = pq.top(); pq.pop();
        int v = tp.id;
        int dist = tp.dist;
        int cap = tp.cap;

        if (dp[v][cap] < dist) continue;

        rep(i,0,G[v].size()) {
            int to = G[v][i].first;
            int cost = G[v][i].second;
            bool gas = lpg[to];
            if (cap < cost) continue; // ガス不足
            int new_cap = cap - cost;
            if (gas) new_cap = Cap;

            if (dp[to][new_cap] > dp[v][cap] + cost) {
                dp[to][new_cap] = dp[v][cap] + cost;
                pq.push(S(to,dp[to][new_cap],new_cap));
            }
        }
    }

#ifdef LOCAL
    rep(i,0,n) {
        rep(j,0,Cap+1) {
            if (dp[i][j] != 1e9) {
                cerr << i << " " << j << " " << dp[i][j] << endl;
            }
        }
    }
#endif
    // result
    int mi = 1e9;
    rep(i,0,Cap+1) {
        mi = min(mi, dp[t][i]);
    }
    if (mi == 1e9) return -1;
    else return mi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';

    int n,m,cap;
    while (cin >> n >> m >> cap) {
        if (n+m+cap == 0) break;
        string src, dest; // 起点, 終点
        int f,t; // 起点，終点id
        VV<pair<int,int>> G(6010); // グラフ
        map<string,int> id; // 名前をidに変換する

        cap *= 10;
        cin >> src >> dest;
        int cnt = 0;
        
        // input part 1
        rep(i,0,n) {
            string c1,c2;
            int d;
            cin >> c1 >> c2 >> d;
            if (!id.count(c1)) id[c1] = cnt++;
            if (!id.count(c2)) id[c2] = cnt++;
            G[id[c1]].push_back({id[c2], d});
            G[id[c2]].push_back({id[c1], d});
        }
        if (!id.count(src)) id[src] = cnt++;
        if (!id.count(dest)) id[dest] = cnt++;
        f = id[src];
        t = id[dest];

        V<bool> lpg(cnt); // lpgのリスト
        // input part 2
        rep(i,0,m) {
            string s;
            cin >> s;
            if (!id.count(s)) continue;
            lpg[id[s]] = true;
        }

        auto ans = solve(cnt,cap,f,t,G,lpg);
        cout << ans << endl;
    }
    
    return 0;
}