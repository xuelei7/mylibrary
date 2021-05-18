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
    
    int n;
    cin >> n;
    V<ll> a(n), b(n), c(n);
    ll sum = 0;
    rep(i,0,n) {
        cin >> a[i] >> b[i];
        c[i] = 2 * a[i] + b[i];
        sum -= a[i];
    }

    sort(all(c));
    reverse(all(c));

    rep(i,0,n) {
        sum += c[i];
        if (sum > 0) {
            cout << i+1 << endl;
            return 0;
        }
    }


    return 0;
}