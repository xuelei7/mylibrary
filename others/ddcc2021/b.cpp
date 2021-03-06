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
    
    // input
    string s;
    rep(i,0,5) {
        V<int> a,b;
        getline(cin,s);
        for (auto& c: s) {
            if (c == '{' || c == '}' || c == ',') c = ' ';
        }
        stringstream sa(s);
        int x;
        while (sa >> x) {
            if (x == 0) break;
            a.push_back(x);
        }

        while (sa >> x) {
            if (x == 0) break;
            b.push_back(x);
        }

        int ans = 0;
        rep(i,-210, 210) {
            int cnt = 0;
            rep(j,0,a.size()) {
                rep(k,0,b.size()) {
                    int aa = a[j] + i;
                    cnt += aa == b[k];
                }
            }
            ans = max(ans, cnt);
        }
        cout << ans << ",\n"[i==4];
    }

    return 0;
}