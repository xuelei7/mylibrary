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
    
    double xa,xb,xc,ya,yb,yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    xb -= xa;
    xc -= xa;
    yb -= ya;
    yc -= ya;
    cout << fixed << setprecision(20) << abs(xb * yc - yb * xc) / 2.0 << endl;
    
    return 0;
}