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
    
    int n,k;
    cin >> n >> k;
    V<double> r(n);
    rep(i,0,n) cin >> r[i];
    sort(all(r));
    reverse(all(r));
    double c = 0;
    rrep(i,0,k) {
        if (r[i] > c) {
            c = (c + r[i]) / 2.0;
        } else break;
    }
    cout << fixed << setprecision(20) << c << endl;
    return 0;
}