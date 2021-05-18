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

V<int> lis;
V<int> ret(200010);
V<bool> used(200010);
VV<int> G(200010);
int n;
V<int> v(200010);

void dfs (int k) {
    used[k] = 1;
    int it = lower_bound(all(lis), v[k]) - lis.begin();
    if (it == lis.size()) {
        lis.push_back(v[k]);
        ret[k] = lis.size();
        rep(i,0,G[k].size()) {
            if (used[G[k][i]]) continue;
            dfs(G[k][i]);
        }
        lis.pop_back();
    } else {
        int tmp = lis[it];
        lis[it] = v[k];
        ret[k] = lis.size();
        rep(i,0,G[k].size()) {
            if (used[G[k][i]]) continue;
            dfs(G[k][i]);
        }
        lis[it] = tmp;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    cin >> n;
    rep(i,0,n) cin >> v[i];

    rep(i,0,n-1) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }


    dfs(0);
    rep(i,0,n) {
        cout << ret[i] << endl;
    }
    
    return 0;
}