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
    
    string s,t;
    cin >> s >> t;
    bitset<1000000> a(s), b(t), mask(0);
    int ans = s.size();
    rep(i,0,t.size()) mask.set(i);
    rep(i,0,s.size() - t.size() + 1) {
        ans = min(ans, (int)(((a&mask)^b).count()));
        b <<= 1;
        mask <<= 1;
    }
    cout << ans << endl;
    return 0;
}