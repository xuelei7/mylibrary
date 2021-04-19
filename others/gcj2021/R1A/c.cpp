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

auto solve () -> void {
    int n,q;
    cin >> n >> q;
    V<int> score(n);
    int fullscore = q * n;
    V<string> v(n);
    rep(i,0,n) {
        cin >> v[i] >> score[i];
    }
    
    VV<bool> vv(n,V<bool>(q));
    rep(i,0,n) {
        rep(j,0,q) {
            vv[i][j] = (v[i][j] == 'T');
        }
    }

    V<bool> ret(q);
    rep(i,0,q) {
        int sum = 0;
        rep(j,0,n) {
            sum += (vv[j][i]? score[j]: q - score[j]);
        }
        
        int rsum = fullscore - sum;
        ret[i] = (sum >= rsum);
    }

    // output answer
    rep(i,0,q) {
        cout << (ret[i]? 'T': 'F');
    }
    cout << " ";

    

    // expected score
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int t;
    cin >> t;
    rep(i,0,t) {
        cout << "Case #" << i+1 << ": ";
        solve();
        cout << endl;
    }
    
    return 0;
}