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
    
    ll d, g;
    cin >> d >> g;
    V<ll> p(d), c(d);
    rep(i,0,d) {
        cin >> p[i] >> c[i];
    }

    ll ans = 1e9;
    rep(i,0,(1<<d)) {
        ll score_sum = 0;
        ll q_sum = 0;
        rep(j,0,d) {
            if ((i>>j) & 1) {
                score_sum += p[j] * 100 * (j+1) + c[j];
                q_sum += p[j];
            }
        }
        rrep(j,0,d) {
            if ((i>>j) & 1) continue;
            if (score_sum >= g) break;
            rep(k,0,p[j]) {
                score_sum += 100 * (j+1);
                q_sum++;
                if (score_sum >= g) break;
            }
        }
        ans = min(ans, q_sum);
    }
    cout << ans << endl;
    
    return 0;
}