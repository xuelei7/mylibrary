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
    
    ll r, x, y;
    cin >> r >> x >> y;
    ll dist = x * x + y * y;
    if (dist % (r * r) == 0) {
        ll k2 = dist / (r * r);
        ll k = sqrt(k2);
        if (k * k == k2) {
            cout << k << endl;
            return 0;
        }
    }
    if (dist < r * r) {
        cout << 2 << endl;
        return 0;
    }
    ll tmpk = sqrt(dist / (r * r));
    while (tmpk * tmpk * r * r < dist) {
        tmpk++;
    }
    // cout << tmpk * r << endl;
    cout << tmpk << endl;
    return 0;
}