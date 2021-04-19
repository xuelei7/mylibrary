#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (int)(a); (i) < (int)(b); (i)++)
#define rrep(i, a, b) for (int i = (int)(b) - 1; (i) >= (int)(a); (i)--)
#define all(v) v.begin(), v.end()

typedef long long ll;
template <class T> using V = vector<T>;
template <class T> using VV = vector<V<T>>;

/* 提出時これをコメントアウトする */
// #define LOCAL true

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define dbg(x) true
#endif

auto solve (int n, int c) -> V<int> {
    if (c > (n * n + n - 2) / 2 || c < n - 1) return V<int>();

    int swp = (n * n + n - 2) / 2;

    V<int> v(n);
    rep(i,0,n) v[i] = i; // ABCDE...
    
    V<int> ret(n);
    rep(i,0,n-1) {
        int left = swp - c; // 余計にスワップしたもの
        int pos = max(i,(n-1)-left);
        swp -= (n-1) - pos;
        ret[v[pos]] = i + 1;
        reverse(v.begin() + i, v.begin() + pos + 1);
#ifdef LOCAL
        cerr << "v[" << pos << "] = " << i+1 << endl;
        rep(j,0,n) {
            cerr << v[j] << " ";
        }
        cerr << endl;
#endif
    }
    ret[v[n-1]] = n;

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int t;
    cin >> t;
    rep(test_case,1,t+1) {
        int x,y;
        cin >> x >> y;
        auto ret = solve(x,y);
        if (ret.size() == 0) {
            cout << "Case #" << test_case << ": IMPOSSIBLE" << endl;
        } else {
            cout << "Case #" << test_case << ":";
            rep(i,0,x) {
                cout << " " << ret[i];
            }
            cout << endl;
        }
    }
    
    return 0;
}