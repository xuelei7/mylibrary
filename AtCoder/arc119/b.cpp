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
    string s,t;
    cin >> n >> s >> t;
    int cnt[2] = {};
    rep(i,0,n) {
        if (s[i] == '1') cnt[0]++;
        if (t[i] == '1') cnt[1]++;
    }
    if (cnt[0] != cnt[1]) {
        cout << -1 << endl;
        return 0;
    }
    
    int ans = 0;
    int zero = 0;
    int s1 = 0;
    int t1 = 0;
    rep(i,0,n) {
        if (s[i] == '1' && t[i] == '1') continue;
        if (s[i] == '1' && t[i] == '0') {
            s1++;
        } else if (s[i] == '0' && t[i] == '1') {
            t1++;
            zero++;
        } else if (s[i] == '0' && t[i] == '0') {
            if (s1 + t1 != 0)
                zero++;
        }

        if (s1 != 0 && s1 == t1) {
            s1 = t1 = 0;
            ans += zero;
            zero = 0;
        }
    }

    cout << ans << endl;


    return 0;
}