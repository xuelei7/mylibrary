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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int N;
    cin >> N;
    V<int> C(N);
    rep(i,0,N) cin >> C[i];
    VV<int> G(N);
    rep(i,0,N-1) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    map<int,int> mp;
    V<int> ret;
    V<bool> used(N);

    auto dfs = [&] (auto self, int n) -> void {
        if (mp.count(C[n]) == 0) ret.push_back(n+1);
        used[n] = 1;

        mp[C[n]]++;
        rep(i,0,G[n].size()) {
            int to = G[n][i];
            if (used[to]) continue;
            self(self, to);
        }
        mp[C[n]]--;
        if (mp[C[n]] == 0) mp.erase(C[n]);
    };

    dfs(dfs,0);

    sort(all(ret));
    for (auto p: ret) {
        cout << p << endl;
    }
    
    return 0;
}