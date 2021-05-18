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
    V<int> k(m);
    VV<int> s(m);
    rep(i,0,m) {
        cin >> k[i];
        rep(j,0,k[i]) {
            int tmp;
            cin >> tmp;
            tmp--;
            s[i].push_back(tmp);
        }
    }
    
    int ans = 0;
    V<int> p(m);
    rep(i,0,m) cin >> p[i];
    rep(i,0,(1<<n)) {
        bool f = 1;
        rep(j,0,m) {
            int cnt = 0;
            rep(kk,0,k[j]) {
                if ((i>>s[j][kk])&1) cnt++;
            }
            if (cnt%2 != p[j]) f = 0;
        }
        if (f) ans++;
    }
    cout << ans << endl;
    return 0;
}