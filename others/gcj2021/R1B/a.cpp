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
    ll round = 720 * 1e9 * 60; // ticks every round
    ll mx = 720 * 1e9 * 3600 * 12; // max ticks

    ll a,b,c;
    cin >> a >> b >> c;
    
    // 昇順にする
    if (a > b) swap(a,b);
    if (a > c) swap(a,c);
    if (b > c) swap(b,c);

    a %= round;
    b %= round;
    c %= round;
    
    b -= a;
    c -= a;
    a = 0;

    ll ret = 0;
    
    auto f = [&] (ll alpha, ll beta) -> bool {
        // alpha % 11 == 0
        // beta % 719 == 0
        while (alpha < mx && beta < mx) {
            if (alpha % 11 == 0) {
                ll n = alpha / 11;
                ll hope_beta = n * 719;
                if (hope_beta % round == beta) {
                    ret = n;
                    return true;
                }
            }
            alpha += round;
        }
        return false;
    };
    // h,m,s
    f(b,c);
    // h,s,m
    f(c,b);
    // m,h,s
    f(round-b, c-b);
    // m,s,h
    f(round-c, round-c+b);
    // s,h,m
    f(c-b, round-b);
    // s,m,h
    f(round-c+b, round-c);

    ll ns = ret % 1000000000;
    ret /= 1e9;
    ll s = ret % 60;
    ret /= 60;
    ll m = ret % 60;
    ret /= 60;
    ll h = ret % 12;
    cout << h << " " << m << " " << s << " " << ns << endl;
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