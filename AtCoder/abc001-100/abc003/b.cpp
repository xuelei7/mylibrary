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
    string str = "atcoder";
    bool f = 1;
    rep(i,0,s.size()) {
        if (s[i] == t[i]) continue;
        if (s[i] != '@' && t[i] != '@') {
            if (s[i] != t[i]) f = 0;
        } else {
            char c = (s[i] == '@'? t[i]: s[i]);
            bool aru = 0;
            for (auto e: str) {
                if (e == c) aru = 1;
            }
            if (!aru) f = 0;
        }
    }
    cout << (f? "You can win": "You will lose") << endl;
    return 0;
}