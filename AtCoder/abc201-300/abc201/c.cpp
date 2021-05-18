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
    
    string s;
    cin >> s;
    int ans = 0;
    int ok[10] = {};
    rep(i,0,s.size()) {
        if (s[i] == 'o') {
            ok[i] = 1;
        } else if ( s[i] == 'x') {
            ok[i] = -1;
        }
    }
    rep(i,0,10000) {
        int tmp = i;
        bool f = 1;
        rep(j,0,4) {
            int k = tmp % 10;
            tmp /= 10;
            if (ok[k] == -1) f = 0;
        }

        rep(j,0,10) {
            if (ok[j] != 1) continue;
            tmp = i;
            bool instring = 0;
            rep(k,0,4) {
                int kk = tmp % 10;
                tmp /= 10;
                if (kk == j) instring = 1;
            }
            if (!instring) f = 0;
        }
        if (f) ans++;
    }
    cout << ans << endl;

    return 0;
}