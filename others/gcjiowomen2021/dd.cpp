#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (int)(a); (i) < (int)(b); (i)++)
#define rrep(i, a, b) for (int i = (int)(b) - 1; (i) >= (int)(a); (i)--)
#define all(v) v.begin(), v.end()

typedef long long ll;
template <class T> using V = vector<T>;
template <class T> using VV = vector<V<T>>;

/* 提出時これをコメントアウトする */
// #define LOCAL true

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define dbg(x) true
#endif

enum Result {
    WIN,
    LOSE,
    DEPEND,
};

struct Status {
    Result result = DEPEND;
    int score = 0;
    char winner;
};

auto solve () -> void {
    string s;
    cin >> s;
    string io = "OI";
    auto dfs = [&] (auto self, int l, int r, int c) -> Status {
        cout << l << " " << r << " " << c << " " << s.substr(l,r-l+1) << endl;
        if (l > r) return (Status){WIN, 1, io[!c]};

        if (s[l] == s[r] && s[l] == io[!c]) {
            return (Status){WIN, r - l + 1, io[!c]};
        }

        if (s[l] == s[r]) {
            Status a = self(self, l+1, r, !c);
            Status b = self(self, l, r-1, !c);
            if (a.winner == b.winner && a.winner == io[c]) {
                return (Status){WIN, max(a.result, b.result), io[c]};
            } else if (a.winner == b.winner) {
                return (Status){WIN, min(a.result, b.result), io[!c]};
            } else {
                if (a.winner == io[c]) return a;
                else return b; 
            }
        } else {
            if (s[l] == io[c]) return self(self, l+1, r, !c);
            else return self(self, l, r-1, !c);
        }
    };

    auto ret = dfs(dfs, 0, s.size() - 1, 1);
    cout << ret.winner << " " << ret.score << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    constexpr char endl = '\n';
    
    int t;
    cin >> t;
    rep(i,1,t+1) {
        cout << "Case #" << i << ": ";
        solve();
    }    
    
    return 0;
}