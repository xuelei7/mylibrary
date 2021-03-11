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
    rep(i,0,3) {
        getline(cin,s);
        for (auto& c: s) {
            if (c == '{' || c == '}' || c == ',') c = ' ';
        }
        stringstream ss(s);
        int ans = 0;
        rep(i,0,10) {
            int a,b;
            ss >> a >> b;
            ans += (a != 10 && a + b == 10);
        }
        cout << ans << ",\n"[i==2];
    }

    return 0;
}