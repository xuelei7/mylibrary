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

auto solve (int x, int y, string s) -> int {
    set<pair<int,int>> ok[2]; // {CJ, JC}
    if (s[0] == 'C') {
        ok[0].insert({0,0});
    }
    else if (s[0] == 'J') {
        ok[1].insert({0,0});
    }
    else {
        ok[0].insert({0,0});
        ok[1].insert({0,0});
    }

    int n = s.size();
    rep(i,1,n) {
        if (s[i] == 'C') {
            for (auto p: ok[1]) { // J->C
                ok[0].insert({p.first, p.second + 1});
            }
            ok[1].clear();
        } else if (s[i] == 'J') {
            for (auto p: ok[0]) { // C->J
                ok[1].insert({p.first + 1, p.second});
            }
            ok[0].clear();
        } else {
            set<pair<int,int>> new_ok[2];
            new_ok[0] = ok[0]; // C->C
            new_ok[1] = ok[1]; // J->J
            for (auto p: ok[0]) { // C->J
                new_ok[1].insert({p.first + 1, p.second});
            }
            for (auto p: ok[1]) { // J->C
                new_ok[0].insert({p.first, p.second + 1});
            }
            ok[0] = new_ok[0];
            ok[1] = new_ok[1];
        }
    }
    
    int ans = 1e9;
    rep(i,0,2) {
        for (auto p: ok[i]) {
            ans = min(ans, p.first * x + p.second * y);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int t;
    cin >> t;
    rep(test_case,1,t+1) {
        int x,y;
        string s;
        cin >> x >> y >> s;
        cout << "Case #" << test_case << ": " << solve(x,y,s) << endl;
    }
    
    return 0;
}