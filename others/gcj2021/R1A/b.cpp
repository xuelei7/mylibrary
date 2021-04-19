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

auto solve () -> ll {
    int m;
    cin >> m;
    
    struct S {
        ll p, n;
        S() {}
    };

    V<S> v(m);
    ll sum = 0, sumn = 0;
    rep(i,0,m) {
        cin >> v[i].p >> v[i].n;
        sum += v[i].n * v[i].p;
        sumn += v[i].n;
    }

    auto dfs = [&](auto self, int id, ll mulsum, ll addsum) -> ll {
#ifdef LOCAL
    cerr << id << " " << mulsum << " " << addsum << endl;
#endif
        if (id == m) {
            if (mulsum == addsum) return mulsum;
            return 0;
        }
        
        ll ret = 0;
        // do not use this kind of card
        ret = max(ret, self(self, id+1, mulsum, addsum));
        
        // used card
        ll mul = max(1LL, mulsum);
        rep(i,1,v[id].n+1) {
            if (mul > (addsum - v[id].p) / v[id].p) break;
            mul *= v[id].p;
            addsum -= v[id].p;
            if (mul > addsum) break;
            ret = max(ret, self(self, id+1, mul, addsum));
        }

        return ret;
    };

    return dfs(dfs, 0, 0, sum);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int t;
    cin >> t;
    rep(i,0,t) {
        cout << "Case #" << i+1 << ": " << solve() << endl;
    }
    
    
    return 0;
}