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

void solve() {
    int n,a,b;
    cin >> n >> a >> b;
    V<int> v(2010);
    rep(i,1,n+1) cin >> v[i];
    rep(i,n,2000) {
        V<int> vv(2010);
        vv[i] = 1;
        bool f = 1;
        rrep(j,1,i+1) {
            if (vv[j] < v[j]) {
                f = 0;
                break;
            }
            vv[j] -= v[j];
            if (j-a > 0) {
                vv[j-a] += vv[j];
            }
            if (j-b > 0) {
                vv[j-b] += vv[j];
            }
            vv[j] = 0;
        }
        if (f) {
            cout << i << endl;
            return;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int t;
    cin >> t;
    rep(i,1,t+1) {
        cout << "Case #" << i << ": ";
        solve();
    }
    
    return 0;
}