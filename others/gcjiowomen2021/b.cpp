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

auto solve () -> string {
    int n;
    cin >> n;
    V<int> v(n);
    rep(i,0,n) cin >> v[i];



    string ret = "A";
    rep(i,0,n) {
        if (i % 2 == 0) { // go up
            rep(j,0,v[i]) {
                ret.push_back(ret.back() + 1);
            }
        } else { // go down
            string ss = "A";
            rep(j,1,v[i]) {
                ss.push_back(ss.back() + 1);
            }
            if (ret.back() <= ss.back()) {
                ret.back() = ss.back() + 1;
            }
            reverse(ss.begin(), ss.end());
            ret += ss;
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int t;
    cin >> t;
    rep(i,1,t+1) {
        cout << "Case #" << i << ": " << solve() << endl;
    }
    
    
    return 0;
}