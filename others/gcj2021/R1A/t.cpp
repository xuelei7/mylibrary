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
    
    map<string,char> mp;
    string a,b,c,d;
    cin >> a >> b >> c >> d;
    rep(i,0,120) {
        string str = "";
        str += a[i];
        str += b[i];
        str += c[i];
        
        mp[str] = d[i];
    }

    for (auto e: mp) {
        cout << e.first << " " << e.second << endl;
    }
    
    return 0;
}