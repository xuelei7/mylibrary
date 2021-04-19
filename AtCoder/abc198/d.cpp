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
    
    string s[3];
    rep(i,0,3) cin >> s[i];
    map<char,int> v;
    rep(i,0,3) {
        rep(j,0,s[i].size()) {
            v[s[i][j]] = 0;
        }
    }
    string ss = "";
    for (auto e: v) {
        ss.push_back(e.first);
    }
    V<bool> used(10);

    auto dfs = [&] (auto self, int k) -> bool {
        if (k == v.size()) {
            ll n[3] = {};
            rep(i,0,3) {
                rep(j,0,s[i].size()) {
                    if (j == 0 && v[s[i][j]] == 0) return false;
                    n[i] *= 10;
                    n[i] += v[s[i][j]]; 
                }
            }
            return n[0] + n[1] == n[2];
        }
        rep(i,0,10) {
            if (used[i]) continue;
            v[ss[k]] = i;
            used[i] = 1;
            if (self(self, k+1)) return true;
            used[i] = 0;
        }
        return false;
    };

    bool result = dfs(dfs, 0);
    if (v.size() > 10) result = 0;

    if (!result) {
        cout << "UNSOLVABLE" << endl;
    } else {
        rep(i,0,3) {
            rep(j,0,s[i].size()) {
                cout << v[s[i][j]];
            }
            cout << endl;
        }
    }
    return 0;
}