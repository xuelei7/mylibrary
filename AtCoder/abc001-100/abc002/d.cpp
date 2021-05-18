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
    
    int n,m;
    cin >> n >> m;
    VV<bool> a(n, V<bool>(n));
    rep(i,0,m) {
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        a[x][y] = a[y][x] = 1;
    }

    int ans = 0;
    rep(i,0,(1<<n)) {
        bool ok = 1;
        V<int> v;
        rep(j,0,n) {
            if ((i>>j)&1) v.push_back(j);
        }

        int nv = v.size();
        rep(i,0,nv) {
            rep(j,i+1,nv) {
                if (!a[v[i]][v[j]]) ok = 0;
            }
        }
        if (ok) ans = max(ans, nv);
    }
    cout << ans << endl;
    return 0;
}