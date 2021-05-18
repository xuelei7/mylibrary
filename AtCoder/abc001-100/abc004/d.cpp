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
    
    int r,g,b;
    cin >> r >> g >> b;

    int ans = 1e9;
    rep(gL,-300,301) {
        int gR = gL + g;

        int rR = min(gL, -100 + (r+1) / 2);
        int rL = rR - r;

        int bL = max(gR, 100 - (b-1) / 2);
        int bR = bL + b;
        
        int gN = 0, rN = 0, bN = 0;
        rep(i,rL,rR) rN += abs(-100 - i);
        rep(i,gL,gR) gN += abs(i);
        rep(i,bL,bR) bN += abs(100 - i);
        // cout << rL << " " << rR << ", " << gL << " " << gR << ", " << bL << " " << bR << endl;
        // cout << rN+gN+bN << endl;
        ans = min(ans, rN+gN+bN);
    }
    cout << ans << endl;
    return 0;
}