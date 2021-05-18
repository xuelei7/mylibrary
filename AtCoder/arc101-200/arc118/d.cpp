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

bool used[100010];
V<int> G[100010];
V<int> ans;


void dfs(int k) {
    rep(i,0,G[k].size()) {
        if (used[G[k][i]]) continue;
        used[G[k][i]] = 1;
        dfs(G[k][i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int p,a,b;
    cin >> p >> a >> b;
    rep(i,1,p) {
        G[i].push_back((i*a)%p);
        G[i].push_back((i*b)%p);
    }

    dfs(1);
    rep(i,1,p) {
        if (!used[i]) {
            cout << "No" << endl;
            return 0;
        }
    }

    memset(used,0,sizeof(used));
    int now = 1;
    while (ans.size() < p-1) {
        ans.push_back(now);
        used[now] = 1;
        rep(i,0,G[now].size()) {
            if (used[G[now][i]]) continue;
            now = G[now][i];
            break;
        }
    }
    ans.push_back(1);
    rep(i,0,ans.size()) {
        cout << ans[i] << " \n"[i==ans.size()-1];
    }
    return 0;
}